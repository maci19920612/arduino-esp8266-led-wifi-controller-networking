#include "executors/WifiExecutor.h"

//Libs
#include <Arduino.h>

//Utils
#include "utils/Logger.h"
#include "utils/WifiUtil.h"
#include "command/led_settings_wifi/ChangeColorCommand.h"
#include "command/led_settings_wifi/HelloCommand.h"

#include "utils/JsonUtil.h"


//Public functions
WifiExecutor::WifiExecutor(){
    this->wifiUtil = WifiUtil::getInstance();
}

void WifiExecutor::execute(){
    if(this->wifiUtil->isConnected()){
        if(this->wifiUtil->receive()){
            UdpPacket receivedPacket = this->wifiUtil->getReceivedPacket();
            JsonObject& receivedObject = JsonUtil::getInstance()->getBuffer()->parseObject(receivedPacket.content);
            if(!receivedObject.success()){
                error("WifiExecutor: Invalid json received: (%s:%d) %s",receivedPacket.remoteIp.toString().c_str(), receivedPacket.remotePort, receivedPacket.content);
                return;
            }
            if(!receivedObject.containsKey("command")){
                error("WifiExecutor: command attribute is missing!");
                return;
            }
            if(!receivedObject.containsKey("param")){
                JsonObject& paramObject = receivedObject.createNestedObject("param");
                paramObject["ipAddress"] = receivedPacket.remoteIp.toString();
                paramObject["port"] = receivedPacket.remotePort;
            }else{
                receivedObject["param"]["ipAddress"] = receivedPacket.remoteIp.toString();
                receivedObject["param"]["port"] = receivedPacket.remotePort;
            }
            String command = receivedObject["command"];
            //DEBUG purpose
            Serial.println("Modified JSON: ");
            receivedObject.printTo(Serial);
            Serial.println();
            //end

            bool found = false;
            for(int i = 0; i < this->commands.size(); i++){
                if(this->commands[i]->isApplicable(command)){
                    found = true;
                    this->commands[i]->execute(receivedObject);
                    break;
                }
            }

            if(!found){
                error("WifiExecutor: Not found command: %s", command.c_str());
            }
        }
    }else{
        error("WifiExecutor execute called but Wifi isn't connected yet!");
    }
};
void WifiExecutor::init(){
    log("WifiExecutor init called");
    this->commands.add(new HelloCommand());
    this->commands.add(new ChangeColorCommand());
}; 
void WifiExecutor::dispose(){
    log("WifiExecutor dispose called");
    
    for(int i = 0; i < this->commands.size(); i++){
        delete this->commands[i];
    }

    this->commands.clear();
};