Node.js integration
===================

This module adds Node.js integration to Drupal.

It is currently alpha software, use at your own risk. It may eat your lunch and kill your kittens.

Setup
=====

Node.js server on Ubuntu:
  1. Make sure you have the prerequisites in your ubuntu
sudo apt-get install build-essential git curl openssl libssl-dev -y

  2. Install Node.js.
mkdir -p ~/local/src && cd ~/local/src && git clone git://github.com/joyent/node.git && cd node && ./configure && make && sudo make install

  3. read socket_io\README.txt for instructions about how to install Socket.IO module.

  4. Optionally, copy 'server.js' to a directory specific to the Node.js server used by Drupal.

  5. Activate the nodejs module and optionally sub-modules.

  6. Configure nodejs at your Drupal page: Administration > Configuration > Node.js

  7. If you enabled the nodejs_config module, set the fields and save it.
     or copy 'nodejs.config.js.example' to 'nodejs.config.js' (in the same
     directory where server.js is located). Edit the values to taste.

  8. Run the node server with the command: node server.js

  9. ...
  10. Profit!

Useful links:
  - how to turn nodejs into a service http://kevin.vanzonneveld.net/techblog/article/run_nodejs_as_a_service_on_ubuntu_karmic/

