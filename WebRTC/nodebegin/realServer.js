'use strict'
var http = require('http');
var https = require('https');
var fs = require('fs');

var express = require('express');
var serveIndex = require('serve-index');

var app = express();
app.use(serveIndex('./public'))
app.use(express.static('./public'));

var httpServer = http.createServer(app);
httpServer.listen(80, '0.0.0.0');

var options = {
    key: fs.readFileSync('./cert/localhost+2-key.pem'),
    cert: fs.readFileSync('./cert/localhost+2.pem')
}
var httpsServer = https.createServer(options, app);
httpsServer.listen(443, '0.0.0.0');