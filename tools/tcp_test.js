var net = require('net');

var connectedMessage = JSON.stringify({
    "command": "connect"
}) + "\n";
var changeSettingsMessage = JSON.stringify({
    "command": "change_settings",
    "param": {
        "ssid": "example",
        "passwd": "EDCRVTGB"
    }
}) + "\n";
var switchToNormalMessage = JSON.stringify({
    "command": "switch_normal"
}) + '\n';


var client = new net.Socket();
client.connect(1234, '192.168.4.1', function() {
    console.log('Connected');
	client.write(switchToNormalMessage);
});

client.on('data', function(data) {

	console.log('Received: ' + data);
	client.destroy();
});

client.on('close', function() {
	console.log('Connection closed');
});