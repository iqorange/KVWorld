'use strict'

var https = require('https');
var fs = require('fs');
const { timeStamp } = require('console');

var options = {
    key: fs.readFileSync('./cert/localhost+2-key.pem'),
    cert: fs.readFileSync('./cert/localhost+2.pem')
}

var app = https.createServer(options, function(req, res){
    res.writeHead(200, {'Content-Type': 'text/plain'});
    res.end('Hello World HTTPS~');
}).listen(443, '0.0.0.0');

// ----- localhost cert -----
// brew install mkcert
// brew install nss
// mkcert -install
// mkcert localhost 127.0.0.1 ::1

// ----- or -----
// openssl req -x509 -nodes -new -sha256 -days 3652 -newkey rsa:2048 -keyout RootCA.key -out RootCA.pem -subj "/C=US/CN=Example-Root-CA"
// openssl x509 -outform pem -in RootCA.pem -out RootCA.crt