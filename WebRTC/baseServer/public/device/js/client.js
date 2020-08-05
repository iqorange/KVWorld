'use strict'

var audioSource = document.querySelector("select#audioSource");
var audioOutput = document.querySelector("select#audiooutput");
var videoSource = document.querySelector("select#videoSource");

if (!navigator.mediaDevices || !navigator.mediaDevices.enumerateDevices) {
    console.log('enumerateDevices is not supported~');
} else {
    navigator.mediaDevices.enumerateDevices()
        .then((deviceInfos) => {
            deviceInfos.forEach((deviceInfo) => {
                // console.log(deviceInfo.kind + ": label = " + deviceInfo.label + ", id = " + deviceInfo.deviceId + ", groupId = " + deviceInfo.groupId);
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
        .catch((err) => {
            console.log(err.name + ", " + err.message);
        });
}