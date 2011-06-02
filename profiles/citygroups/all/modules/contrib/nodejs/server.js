/**
 * Provides Node.js - Drupal integration. 
 *
 * This code is beta quality.
 *
 * Expect bugs, but not API changes as we prepare for 1.0 release.
 */

var http = require('http'),
    https = require('https'),
    url = require('url'),
    fs = require('fs'),
    express = require('express'),
    io = require('socket.io'),
    util = require('util'),
    vm = require('vm');

try {
  var backendSettings = vm.runInThisContext(fs.readFileSync(process.cwd() + '/nodejs.config.js'));
}
catch (exception) {
  console.log("Failed to read config file, exiting: " + exception);
  process.exit(1);
}

// Load server extensions
var extensions = [];
if (backendSettings.extensions && backendSettings.extensions.length) {
  var num = backendSettings.extensions.length,
    i,
    extfn;
  for (i = 0; i < num; i++) {
    extfn = backendSettings.extensions[i];
    try {
      // Load JS files for extensions as modules, and collect the returned
      // object for each extension.
      extensions.push(require(__dirname + '/' + extfn));
      console.log("Extension loaded: " + extfn);
    }
    catch (exception) {
      console.log("Failed to load extension " + extfn + " [" + exception + "]");
      process.exit(1);
    }
  }
}

// Initialize other default settings
backendSettings.serverStatsUrl = '/nodejs/stats/server';
backendSettings.getActiveChannelsUrl = '/nodejs/stats/channels';
backendSettings.kickUserUrl = '/nodejs/user/kick/:uid';
backendSettings.addUserToChannelUrl = '/nodejs/user/channel/add/:channel/:uid';
backendSettings.removeUserFromChannelUrl = '/nodejs/user/channel/remove/:channel/:uid';
backendSettings.addAuthTokenToChannelUrl = '/nodejs/authtoken/channel/add/:channel/:uid';
backendSettings.removeAuthTokenFromChannelUrl = '/nodejs/authtoken/channel/remove/:channel/:uid';
backendSettings.toggleDebugUrl = '/nodejs/debug/toggle';

/**
 * Check if the given channel is client-writable.
 */
var channelIsClientWritable = function (channel) {
  if (socket.channels.hasOwnProperty(channel)) {
    return socket.channels[channel].isClientWritable;
  }
  return false;
}

/**
 * Authenticate a client connection based on the message it sent.
 */
var authenticateClient = function (client, message) {
  var options = {
    port: backendSettings.backend.port,
    host: backendSettings.backend.host,
    path: backendSettings.backend.authPath + message.authToken
  };
  if (backendSettings.backend.scheme == 'https') {
    https.get(options, authenticateClientCallback)
      .on('error', authenticateErrorCallback);
  }
  else {
    http.get(options, authenticateClientCallback)
      .on('error', authenticateErrorCallback);
  }
  function authenticateClientCallback(response) {
    response.on('data', function (chunk) {
      if (response.statusCode == 404) {
        if (backendSettings.debug) {
          console.log('Backend authentication url not found, tried using these options: ');
          console.log(options);
        }
        else {
          console.log('Backend authentication url not found.');
        }
        return;
      }
      response.setEncoding('utf8');
      var authData = false;
      try {
        authData = JSON.parse(chunk);
      }
      catch (exception) {
        console.log('Failed to parse authentication message: ' + exception);
        if (backendSettings.debug) {
          console.log('Failed message string: ' + chunk);
        }
        return;
      }
      if (!checkServiceKey(authData.serviceKey)) {
        console.log('Invalid service key "' + authData.serviceKey + '"');
        return;
      }
      if (authData.nodejs_valid_auth_key) {
        if (backendSettings.debug) {
          console.log("Valid login for uid: " + authData.uid);
        }
        socket.authenticatedClients[message.authToken] = authData;
        setupClientConnection(client.sessionId, authData);
      }
      else {
        console.log('Invalid login for uid "' + authData.uid + '"');
        delete socket.authenticatedClients[message.authToken];
      }
    });
  }
  function authenticateErrorCallback(exception) {
    console.log("Error hitting backend with authentication token: " + exception);
  }
}

/**
 * Callback that wraps all requests and checks for a valid service key.
 */
var checkServiceKeyCallback = function (request, response, next) {
  if (checkServiceKey(request.header('NodejsServiceKey', ''))) {
    next();
  }
  else {
    response.send({'error': 'Invalid service key.'});
  }
}

/**
 * Check a service key against the configured service key.
 */
var checkServiceKey = function (serviceKey) {
  if (backendSettings.serviceKey && serviceKey != backendSettings.serviceKey) {
    console.log('Invalid service key "' + serviceKey + '", expecting "' + backendSettings.serviceKey + '"');
    return false;
  }
  return true;
}

/**
 * Http callback - set the debug flag.
 */
var toggleDebug = function (request, response) {
  request.setEncoding('utf8');
  request.on('data', function (chunk) {
    try {
      var toggle = JSON.parse(chunk);
      backendSettings.debug = toggle.debug;
      response.send({debug: toggle.debug});
    }
    catch (exception) {
      console.log('Invalid JSON "' + chunk + '": ' + exception);
      response.send({error: 'Invalid JSON, error: ' + e.toString()});
    }
  });
}

/**
 * Http callback - read in a JSON message and publish it to interested clients.
 */
var publishMessage = function (request, response) {
  var sentCount = 0;
  request.setEncoding('utf8');
  request.on('data', function (chunk) {
    try {
      var message = JSON.parse(chunk);
      if (backendSettings.debug) {
        console.log('publishMessage: message --> ' + message);
      }
    }
    catch (exception) {
      console.log('Invalid JSON "' + chunk + '": ' + exception);
      response.send({error: 'Invalid JSON, error: ' + exception.toString()});
      return;
    }
    if (message.broadcast) {
      if (backendSettings.debug) {
        console.log('Broadcasting message');
      }
      socket.broadcast(message);
      sentCount = socket.clients.length;
    }
    else {
      sentCount = publishMessageToChannel(message);
    }
    response.send({sent: sentCount});
  });
}

/**
 * Publish a message to clients subscribed to a channel.
 */
var publishMessageToChannel = function (message) {
  if (!message.hasOwnProperty('channel')) {
    console.log('publishMessageToChannel: An invalid message object was provided.');
    return 0;
  }
  if (!socket.channels.hasOwnProperty(message.channel)) {
    console.log('publishMessageToChannel: The channel "' + message.channel + '" doesn\'t exist.');
    return 0;
  }

  var clientCount = 0;
  for (var sessionId in socket.channels[message.channel].sessionIds) {
    if (publishMessageToClient(sessionId, message)) {
      clientCount++;
    }
  }
  if (backendSettings.debug) {
    console.log('Sent message to ' + clientCount + ' clients in channel "' + message.channel + '"');
  }
  return clientCount;
}

/**
 * Publish a message to a specific client.
 */
var publishMessageToClient = function (sessionId, message) {
  if (socket.clients[sessionId]) {
    socket.clients[sessionId].send(message);
    if (backendSettings.debug) {
      console.log('Sent message to client ' + sessionId);
    }
    return true;
  }
  return false;
};

/**
 * Sends a 404 message.
 */
var send404 = function(request, response) {
  response.send('Not Found.', 404);
};

/**
 * Kicks the given logged in user from the server.
 */
var kickUser = function(request, response) {
  if (request.params.uid) {
    // Delete the user from the authenticatedClients hash.
    for (var authToken in socket.authenticatedClients) {
      if (socket.authenticatedClients[authToken].uid == request.params.uid) {
        delete socket.authenticatedClients[authToken];
      }
    }
    // Destroy any socket connections associated with this uid.
    for (var clientId in socket.clients) {
      if (socket.clients[clientId].uid == request.params.uid) {
        delete socket.clients[clientId];
        if (backendSettings.debug) {
          console.log('kickUser: deleted socket "' + clientId + '" for uid "' + request.params.uid + '"');
        }
        // Delete any channel entries for this clientId.
        for (var channel in socket.channels) {
          delete socket.channels[channel].sessionIds[clientId];
        }
      }
    }
    response.send({'status': 'success'});
    return;
  }
  console.log('Failed to kick user, no uid supplied');
  response.send({'status': 'failed', 'error': 'missing uid'});
};

/**
 * Return a list of active channels.
 */
var getActiveChannels = function(request, response) {
  var channels = {};
  for (var channel in socket.channels) {
    channels[channel] = channel;
  }
  if (backendSettings.debug) {
    console.log('getActiveChannels: returning channels --> ' . channels.toString());
  }
  response.send(channels);
};

/**
 * Return summary info about the server.
 */
var returnServerStats = function(request, response) {
  var channels = [], clients = [];
  for (var channel in socket.channels) {
    channels.push(channel);
  }
  for (var sessionId in socket.authenticatedClients) {
    clients.push({'user': socket.authenticatedClients[sessionId], 'sessionId': sessionId});
  }
  var stats = {
    'channels': channels,
    'totalClientCount': socket.clients.length,
    'authenticatedClients': clients
  };
  if (backendSettings.debug) {
    console.log('returnServerStats: returning server stats --> ' + stats);
  }
  response.send(stats);
};

/**
 * Get the list of Node.js sessionIds for a given uid.
 */
var getNodejsSessionIdsFromUid = function(uid) {
  var sessionIds = [];
  for (var sessionId in socket.clients) {
    if (socket.clients[sessionId].uid == uid) {
      sessionIds.push(sessionId);
    }
  }
  return sessionIds;
}

/**
 * Get the list of Node.js sessionIds for a given authToken.
 */
var getNodejsSessionIdsFromAuthToken = function(authToken) {
  var sessionIds = [];
  for (var sessionId in socket.clients) {
    if (socket.clients[sessionId].authToken == authToken) {
      sessionIds.push(sessionId);
    }
  }
  return sessionIds;
}

/**
 * Add a user to a channel.
 */
var addUserToChannel = function(request, response) {
  var uid = request.params.uid || '';
  var channel = request.params.channel || '';
  if (uid && channel) {
    if (!/^\d+$/.test(uid)) {
      console.log("Invalid uid: " + uid);
      response.send({'status': 'failed', 'error': 'Invalid uid.'});
      return;
    }
    if (!/^[a-z0-9_]+$/i.test(channel)) {
      console.log("Invalid channel: " + channel);
      response.send({'status': 'failed', 'error': 'Invalid channel name.'});
      return;
    }
    socket.channels[channel] = socket.channels[channel] || {'sessionIds': {}};
    var sessionIds = getNodejsSessionIdsFromUid(uid);
    if (sessionIds.length > 0) {
      for (var i in sessionIds) {
        socket.channels[channel].sessionIds[sessionIds[i]] = sessionIds[i];
      }
      if (backendSettings.debug) {
        console.log("Added channel '" + channel + "' to sessionIds " + sessionIds.join());
      }
      response.send({'status': 'success'});
    }
    else {
      console.log("No active sessions for uid: " + uid);
      response.send({'status': 'failed', 'error': 'No active sessions for uid.'});
    }
    for (var authToken in socket.authenticatedClients) {
      if (socket.authenticatedClients[authToken].uid == uid) {
        if (backendSettings.debug) {
          console.log("Found uid '" + uid + "' in authenticatedClients, channels " + socket.authenticatedClients[authToken].channels.toString());
        }
        if (socket.authenticatedClients[authToken].channels.indexOf(channel) == -1) {
          socket.authenticatedClients[authToken].channels.push(channel);
          if (backendSettings.debug) {
            console.log("Added channel '" + channel + "' socket.authenticatedClients");
          }
        }
      }
    }
  }
  else {
    console.log("Missing uid or channel");
    response.send({'status': 'failed', 'error': 'Missing uid or channel'});
  }
};

/**
 * Add an authToken to a channel.
 */
var addAuthTokenToChannel = function(request, response) {
  var authToken = request.params.authToken || '';
  var channel = request.params.channel || '';
  if (authToken && channel) {
    if (!/^[a-z0-9_]+$/i.test(channel)) {
      console.log("Invalid channel: " + channel);
      response.send({'status': 'failed', 'error': 'Invalid channel name.'});
      return;
    }
    if (!socket.authenticatedClients[authToken]) {
      console.log("Unknown authToken : " + authToken);
      response.send({'status': 'failed', 'error': 'Invalid authToken.'});
      return;
    }
    socket.channels[channel] = socket.channels[channel] || {'sessionIds': {}};
    var sessionIds = getNodejsSessionIdsFromAuthtoken(authToken);
    if (sessionIds.length > 0) {
      for (var i in sessionIds) {
        socket.channels[channel].sessionIds[sessionIds[i]] = sessionIds[i];
      }
      if (backendSettings.debug) {
        console.log("Added sessionIds '" + sessionIds.join() + "' to channel '" + channel + "'");
      }
      response.send({'status': 'success'});
    }
    else {
      console.log("No active sessions for authToken: " + authToken);
      response.send({'status': 'failed', 'error': 'No active sessions for uid.'});
    }
    if (socket.authenticatedClients[authToken].channels.indexOf(channel) == -1) {
      socket.authenticatedClients[authToken].channels.push(channel);
      if (backendSettings.debug) {
        console.log("Added channel '" + channel + "' to socket.authenticatedClients");
      }
    }
  }
  else {
    console.log("Missing authToken or channel");
    response.send({'status': 'failed', 'error': 'Missing authToken or channel'});
  }
};

/**
 * Add a client (specified by session ID) to a channel.
 */
var addClientToChannel = function(sessionId, channel) {
  if (sessionId && channel) {
    if (!/^[0-9]+$/.test(sessionId) || !socket.clients.hasOwnProperty(sessionId)) {
      console.log("addClientToChannel: Invalid sessionId: " + sessionId);
    }
    else if (!/^[a-z0-9_]+$/i.test(channel)) {
      console.log("addClientToChannel: Invalid channel: " + channel);
    }
    else {
      socket.channels[channel] = socket.channels[channel] || {'sessionIds': {}};
      socket.channels[channel].sessionIds[sessionId] = sessionId;
      if (backendSettings.debug) {
        console.log("Added channel '" + channel + "' to sessionId " + sessionId);
      }
      return true;
    }
  }
  else {
    console.log("addClientToChannel: Missing sessionId or channel name");
  }
  return false;
};

/**
 * Remove a user from a channel.
 */
var removeUserFromChannel = function(request, response) {
  var uid = request.params.uid || '';
  var channel = request.params.channel || '';
  if (uid && channel) {
    if (!/^\d+$/.test(uid)) {
      console.log('Invalid uid: ' + uid);
      response.send({'status': 'failed', 'error': 'Invalid uid.'});
      return;
    }
    if (!/^[a-z0-9_]+$/i.test(channel)) {
      console.log('Invalid channel: ' + channel);
      response.send({'status': 'failed', 'error': 'Invalid channel name.'});
      return;
    }
    if (socket.channels[channel]) {
      var sessionIds = getNodejsSessionIdsFromUid(uid);
      for (var i in sessionIds) {
        if (socket.channels[channel].sessionIds[sessionIds[i]]) {
          delete socket.channels[channel].sessionIds[sessionIds[i]];
        }
      }
      for (var authToken in socket.authenticatedClients) {
        if (socket.authenticatedClients[authToken].uid == uid) {
          var index = socket.authenticatedClients[authToken].channels.indexOf(channel);
          if (index != -1) {
            delete socket.authenticatedClients[authToken].channels[index];
          }
        }
      }
      if (backendSettings.debug) {
        console.log("Successfully removed uid '" + uid + "' from channel '" + channel + "'");
      }
      response.send({'status': 'success'});
    }
    else {
      console.log("Non-existent channel name '" + channel + "'");
      response.send({'status': 'failed', 'error': 'Non-existent channel name.'});
      return;
    }
  }
  else {
    console.log("Missing uid or channel");
    response.send({'status': 'failed', 'error': 'Invalid data'});
  }
}

/**
 * Remove an authToken from a channel.
 */
var removeAuthTokenFromChannel = function(request, response) {
  var authToken = request.params.authToken || '';
  var channel = request.params.channel || '';
  if (authToken && channel) {
    if (!socket.authenticatedClients[authToken]) {
      console.log('Invalid authToken: ' + uid);
      response.send({'status': 'failed', 'error': 'Invalid authToken.'});
      return;
    }
    if (!/^[a-z0-9_]+$/i.test(channel)) {
      console.log('Invalid channel: ' + channel);
      response.send({'status': 'failed', 'error': 'Invalid channel name.'});
      return;
    }
    if (socket.channels[channel]) {
      var sessionIds = getNodejsSessionIdsFromAuthToken(authToken);
      for (var i in sessionIds) {
        if (socket.channels[channel].sessionIds[sessionIds[i]]) {
          delete socket.channels[channel].sessionIds[sessionIds[i]];
        }
      }
      if (socket.authenticatedClients[authToken]) {
        var index = socket.authenticatedClients[authToken].channels.indexOf(channel);
        if (index != -1) {
          delete socket.authenticatedClients[authToken].channels[index];
        }
      }
      if (backendSettings.debug) {
        console.log("Successfully removed authToken '" + authToken + "' from channel '" + channel + "'.");
      }
      response.send({'status': 'success'});
    }
    else {
      console.log("Non-existent channel name '" + channel + "'");
      response.send({'status': 'failed', 'error': 'Non-existent channel name.'});
      return;
    }
  }
  else {
    console.log("Missing authToken or channel");
    response.send({'status': 'failed', 'error': 'Invalid data'});
  }
}

/**
 * Remove a client (specified by session ID) from a channel.
 */
var removeClientFromChannel = function(sessionId, channel) {
  if (sessionId && channel) {
    if (!/^[0-9]+$/.test(sessionId) || !socket.clients.hasOwnProperty(sessionId)) {
      console.log("removeClientFromChannel: Invalid sessionId: " + sessionId);
    }
    else if (!/^[a-z0-9_]+$/i.test(channel) || !socket.channels.hasOwnProperty(channel)) {
      console.log("removeClientFromChannel: Invalid channel: " + channel);
    }
    else if (socket.channels[channel].sessionIds[sessionId]) {
      delete socket.channels[channels].sessionIds[sessionId];
      if (backendSettings.debug) {
        console.log("Removed sessionId '" + sessionId + "' from channel '" + channel + "'");
      }
      return true;
    }
  }
  else {
    console.log("removeClientFromChannel: Missing sessionId or channel name");
  }
  return false;
};

/**
 * Setup a socket.clients{}.connection with uid, channels etc.
 */
var setupClientConnection = function(sessionId, authData) {
  if (!socket.clients[sessionId]) {
    console.log("Client socket '" + sessionId + "' went away.");
    console.log(authData);
    return;
  }
  socket.clients[sessionId].authToken = authData.authToken;
  socket.clients[sessionId].uid = authData.uid;
  if (backendSettings.debug) {
    console.log("adding channels for uid " + authData.uid + ': ' + authData.channels.toString());
  }
  for (var i in authData.channels) {
    socket.channels[authData.channels[i]] = socket.channels[authData.channels[i]] || {'sessionIds': {}};
    socket.channels[authData.channels[i]].sessionIds[sessionId] = sessionId;
  }
  socket.clients[sessionId].send({'status': 'authenticated'});
  process.emit('client-authenticated', sessionId);
};

var server;
if (backendSettings.scheme == 'https') {
  if (backendSettings.debug) {
    console.log('Starting https server.');
  }
  server = express.createServer({
    key: fs.readFileSync(backendSettings.key),
    cert: fs.readFileSync(backendSettings.cert)
  });
}
else {
  if (backendSettings.debug) {
    console.log('Starting http server.');
  }
  server = express.createServer();
}
server.all('/nodejs/*', checkServiceKeyCallback)
  .post(backendSettings.publishUrl, publishMessage)
  .get(backendSettings.serverStatsUrl, returnServerStats)
  .get(backendSettings.getActiveChannelsUrl, getActiveChannels)
  .get(backendSettings.kickUserUrl, kickUser)
  .get(backendSettings.addUserToChannelUrl, addUserToChannel)
  .get(backendSettings.removeUserFromChannelUrl, removeUserFromChannel)
  .get(backendSettings.toggleDebugUrl, toggleDebug)
  .get('*', send404)
  .listen(backendSettings.port, backendSettings.host);

var socket = io.listen(server, {port: backendSettings.port, resource: backendSettings.resource});
socket.channels = {};
socket.authenticatedClients = {};
socket.statistics = {};

socket.on('connection', function(client) {
  process.emit('client-connection', client.sessionId);

  client.on('message', function(message) {
    if (!message) {
      return;
    }

    // If the message is from an active client, then process it.
    if (socket.clients[client.sessionId] && message.hasOwnProperty('type') && message.type != 'authenticate') {
      if (backendSettings.debug) {
        console.log('Received message from client ' + client.sessionId);
      }

      // If this message is destined for a channel, check that writing to 
      // channels from client sockets is allowed.
      if (message.hasOwnProperty('channel')) {
        if (backenSettings.clientsCanWriteToChannels || channelIsClientWritable(message.channel)) {
          process.emit('client-message', client.sessionId, message);
        }
        else if (backendSettings.debug) {
          console.log('Received unauthorised message from client: cannot write to channel ' + client.sessionId);
        }
      }

      // No channel, so this message is destined for one or more clients. Check
      // that this is allowed in the server configuration.
      if (backendSettings.clientsCanWriteToClients) {
        process.emit('client-message', client.sessionId, message);
      }
      else if (backendSettings.debug) {
        console.log('Received unauthorised message from client: cannot write to client ' + client.sessionId);
      }
      return;
    }

    // If the new client has an authToken that the server has verified, then
    // initiate a connection with the client
    if (socket.authenticatedClients[message.authToken]) {
      if (backendSettings.debug) {
        console.log('Reusing existing authentication data for key "' + message.authToken + '"');
      }
      setupClientConnection(client.sessionId, socket.authenticatedClients[message.authToken]);
      return;
    }

    // Otherwise, authenticate the new client with the Drupal site
    if (backendSettings.debug) {
      console.log('Authenticating client with key "' + message.authToken + '"');
    }
    authenticateClient(client, message);
  });

  client.on('disconnect', function () {
    process.emit('client-disconnect', client.sessionId);
  });
})
.on('error', function(exception) {
  console.log('Socket error [' + exception + ']');
});

/**
 * Invokes the specified function on all registered server extensions.
 */
function invokeExtensions(hook) {
  var args = arguments.length ? Array.prototype.slice.call(arguments, 1) : [];
  for (var i in extensions) {
    if (extensions[i].hasOwnProperty(hook) && extensions[i][hook].apply) {
      extensions[i][hook].apply(this, args);
    }
  }
}

/**
 * Define a configuration object to pass to all server extensions at
 * initialization. The extensions do not have access to this namespace,
 * so we provide them with references.
 */
var extensionsConfig = {
  'publishMessageToChannel': publishMessageToChannel,
  'publishMessageToClient': publishMessageToClient,
  'addClientToChannel': addClientToChannel
};
invokeExtensions('setup', extensionsConfig);

// vi:ai:expandtab:sw=2 ts=2

