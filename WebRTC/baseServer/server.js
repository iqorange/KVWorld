'use strict'

// forever stop server.js
// node server.js

var http = require('http');
var https = require('https');
var fs = require('fs');

var serveIndex = require('serve-index');

var express = require('express');
var app = express();

// 引入SocketIo
var socketIo = require('socket.io');
var log4js = require('log4js');

log4js.configure({
	appenders: {
		file: {
			type: 'file',
			filename: 'app.log',
			layout: {
				type: 'pattern',
				pattern: '%r %p - %m',
			}
		}
	},
	categories: {
		default: {
			appenders: ['file'],
			level: 'debug'
		}
	}
});

var logger = log4js.getLogger();

//顺序不能换
app.use(serveIndex('./public'));
app.use(express.static('./public'));

var options = {
	key: fs.readFileSync('./cert/localhost+2.key'),
	cert: fs.readFileSync('./cert/localhost+2.pem')
}

var https_server = https.createServer(options, app);
// 服务启动前绑定SocketIo, bind socket.io with https_server
var io = socketIo.listen(https_server);

io.sockets.on('connection', (socket) => {
	// 自己定义的消息，应用层处理
	// 用户加入房间
	socket.on('join', (room) => {
		socket.join(room);
		var myRoom = io.sockets.adapter.rooms[room];
		// 拿到用户数量
		var users = Object.keys(myRoom.socket).length;
		logger.log('the number of user in room is: ' + users);
		// 回调消息
		// 只给本人回
		// socket.emit('joined', room, socket.id);
		// 给除自己外的其他人回消息
		// socket.to(room).emit('joined', room, socket.id);
		// 给所有人发消息
		// io.in(room).emit('joined', room, socket.id);
		// 给除自己以外全站点的人发送消息
		socket.broadcast.emit('joined', room, socket.id);
	});
	// 用户离开房间
	socket.on('leave', (room) => {
		var myRoom = io.sockets.adapter.rooms[room];
		// 拿到用户数量
		var users = Object.keys(myRoom.socket).length;
		logger.log('the number of user in room is: ' + (users - 1));
		socket.leave(room);
		// 回调消息
		// 只给本人回
		// socket.emit('joined', room, socket.id);
		// 给除自己外的其他人回消息
		// socket.to(room).emit('joined', room, socket.id);
		// 给所有人发消息
		// io.in(room).emit('joined', room, socket.id);
		// 给除自己以外全站点的人发送消息
		socket.broadcast.emit('joined', room, socket.id);
	});
})
https_server.listen(443, '0.0.0.0');

var http_server = http.createServer(app);
http_server.listen(80, '0.0.0.0');