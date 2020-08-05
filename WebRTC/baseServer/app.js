'use strict'
const http = require('http');
const https = require('https');
const fs = require('fs');

const express = require('express');
const serveIndex = require('serve-index');

const adapter = require('webrtc-adapter');

// console.log(adapter.browserDetails.browser);
// console.log(adapter.browserDetails.version);

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