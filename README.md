## ESP8266 Led strip controller module firmware
### Communication
#### Package structure
Every serial or network packages seems like this:
```javascript
{
    "command": "command", //Executable command
    "param": {
        //Params
    }
}
```
The delimiter char is '\n', so we have to send one line messages.
The following param names will be override because the network layer has to modify the incoming package: ipAddress, port
#### Messages specification (source -> direction)
##### Internal messages
- (Arduino -> ESP8266): connect_wifi(ssid,passwd): ESP8266 try to connect to a Wifi AP
- (ESP8266 -> Arduino): ack_connect_wifi(success, status): ESP8266 send connection result to Arduino
- (Arduino -> ESP8266): switch_ap(): This will be disconnect the wifi connection and start an Wifi AP
- (ESP8266 -> Arduino): ack_switch_ap(): ACK Wifi AP started
##### LED settings messages
- (Wifi -> ESP8266 -> Arduino): change_color(r,g,b,w): ESP8266 get a color change package and send it to Arduino
- (Arduino -> ESP8266 -> Wifi:  ack_change_color: (): Arduino ACK led color setting changes
- (Wifi -> ESP8266): hello (): This is a discovery package, the network layer can handle it.
- (ESP8266 -> Wifi): ack_hello (): Response the discovery package
##### Settings messages
- (Wifi -> ESP8266): connect(): This package indicates a valid client connection
- (ESP8266 -> Wifi): ack_connect(): ACK TCP connection
- (Wifi -> ESP8266 -> Arduino): change_settings(ssid, passwd): This command will be change the currently stored wifi configuraton (We send it with connect_wifi command)
- (Arduino -> ESP8266 -> Wifi): ack_change_settings(): ACK settings changes
- (Wifi -> ESP8266 -> Arduino): switch_normal(): This command will be shutdown the WifiAP and try to connect wifi again
- (Arduino -> ESP8266 -> Wifi): ack_switch_normal(): ACK switch normal connection