'use strict'
var http = require('http');
var app = http.createServer(function(req, res){
    res.writeHead(200, {'Content-Type': 'text/plain'});
    res.end('Hello World\n');
}).listen(8082, '0.0.0.0');
// node server.js
// forever start server.js