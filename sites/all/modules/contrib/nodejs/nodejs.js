
(function ($) {

Drupal.Nodejs = Drupal.Nodejs || {'callbacks': {}, 'socket': false, 'connectionSetupHandlers': {}};

Drupal.behaviors.nodejs = {
  attach: function (context, settings) {
    window.WEB_SOCKET_SWF_LOCATION = Drupal.settings.nodejs.websocketSwfLocation;
    if (!Drupal.Nodejs.socket) {
      if (Drupal.Nodejs.connect()) {
        Drupal.Nodejs.sendAuthMessage();
      }
    }
  }
};

Drupal.Nodejs.runCallbacks = function (message) {
  if (message.callback && $.isFunction(Drupal.Nodejs.callbacks[message.callback].callback)) {
    try {
      Drupal.Nodejs.callbacks[message.callback].callback(message);
    }
    catch (exception) {}
  }
  else {
    $.each(Drupal.Nodejs.callbacks, function () {
      if ($.isFunction(this.callback)) {
        try {
          this.callback(message);
        }
        catch (exception) {}
      }
    });
  }
};

Drupal.Nodejs.runSetupHandlers = function (type, error) {
  $.each(Drupal.Nodejs.connectionSetupHandlers, function () {
    if ($.isFunction(this[type])) {
      try {
        if (typeof(error) == 'undefined') {
          this[type]();
        }
        else {
          this[type](error);
        }
      }
      catch (exception) {}
    }
  });
};

Drupal.Nodejs.connect = function () {
  try {
    var socketSettings = {
      secure: Drupal.settings.nodejs.secure, 
      port: Drupal.settings.nodejs.port, 
      resource: Drupal.settings.nodejs.resource
    }
    Drupal.Nodejs.socket = new io.Socket(Drupal.settings.nodejs.host, socketSettings);
    Drupal.Nodejs.socket.connect();
    Drupal.Nodejs.runSetupHandlers('connectionSuccess');
    Drupal.Nodejs.socket.on('message', Drupal.Nodejs.runCallbacks);
    return true;
  }
  catch (exception) {
    Drupal.Nodejs.socket = false;
    Drupal.Nodejs.runSetupHandlers('connectionFailure', exception);
    return false;
  }
};

Drupal.Nodejs.sendAuthMessage = function () {
  try {
    var authMessage = {
      type: 'authenticate',
      authToken: Drupal.settings.nodejs.authToken
    };
    Drupal.Nodejs.socket.send(authMessage);
    Drupal.Nodejs.runSetupHandlers('authSuccess');
    return true;
  }
  catch (exception) {
    Drupal.Nodejs.socket = false;
    Drupal.Nodejs.runSetupHandlers('authFailure', exception);
    return false;
  }
};

})(jQuery);

// vi:ai:expandtab:sw=2 ts=2

