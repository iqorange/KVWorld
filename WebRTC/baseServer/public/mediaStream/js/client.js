'use strict'

var player = document.querySelector('video#player');

var audioSource = document.querySelector("select#audioSource");
var audioOutput = document.querySelector("select#audiooutput");
var videoSource = document.querySelector("select#videoSource");

var filtersSeletc = document.querySelector("select#filter");

var snapshoot = document.querySelector('button#snapshoot');
var picture = document.querySelector("canvas#picture");
picture.width = 640;
picture.height = 360;

var divConstraints = document.querySelector('div#constraints')

function start() {
    if (!navigator.mediaDevices || !navigator.mediaDevices.getUserMedia) {
        console.log('getUserMedia is not supported~');
        return;
    } else {
        var deviceID = videoSource.value;
        // 设备参数设置
        navigator.mediaDevices.getUserMedia({
            video: {
                width: 1280,
                height: 720,
                frameRate: {
                    min: 30,
                    max: 60
                },
                facingMode: 'enviroment', // user
                deviceId: deviceID ? deviceID : undefined
            },
            audio: {
                volume: 95,
                sampleRate: 96000,
                sampleSize: 24,
                echoCancellation: true,
                noiseSuppression: true,
                latency: 40,
                channelCount: 2,
            },
            // deviceID groupID 设备切换
        })
        // 处理音视频流
        .then((stream) => {
            player.srcObject = stream;
            var videoTrack = stream.getVideoTracks()[0];
            var videoConstraints = videoTrack.getSettings();
            divConstraints.textContent = JSON.stringify(videoConstraints, null, 2);
            return navigator.mediaDevices.enumerateDevices();
        })
        .then((deviceInfos) => {
            deviceInfos.forEach((deviceInfo) => {
                console.log(deviceInfo);
                var option = document.createElement('option');
                option.text = deviceInfo.label;
                option.value = deviceInfo.deviceId;
                if (deviceInfo.kind === 'audioinput') {
                    audioSource.appendChild(option);
                } else if (deviceInfo.kind === 'audiooutput') {
                    audioOutput.appendChild(option);
                } else if (deviceInfo.kind === 'viceoinput') {
                    videoSource.appendChild(option);
                }
            })
        })
        .catch((e) => {
            console.log('getUserMedia error: ' + e);
        });
    }
}

start();

videoSource.onchange = start;

filtersSeletc.onchange = () => {
    player.className = filtersSeletc.value;
}

snapshoot.onclick = () => {
    picture.className = filtersSeletc.value;
    picture.getContext('2d').drawImage(player, 0, 0, picture.width, picture.height);
}