/*
Available commands:
hello
change_color(r,g,b,w)
 */

var udp = require('dgram');
var client = udp.createSocket('udp4');

 
client.on('listening', function () { 
    var address = client.address(); 
    console.log('UDP Client listening on ' + address.address + ":" + address.port); 
    client.setBroadcast(true) 
}); 
client.bind(1234);


var helloCommand = JSON.stringify({
    "command": "hello"
}) + "\n";
var changeLedSettingsCommand = JSON.stringify({
    "command": "change_color",
    "param": {
        "w": 255,
        "r": 255,
        "g": 255,
        "b": 255
    }
}) + '\n';

client.on('message',function(msg,info){
  console.log('Data received from server : ' + msg.toString());
  console.log('Received %d bytes from %s:%d\n',msg.length, info.address, info.port);
});
client.send(changeLedSettingsCommand, 0, changeLedSettingsCommand.length+1, 1234, "255.255.255.255");