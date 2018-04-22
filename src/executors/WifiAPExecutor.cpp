#include "executors/WifiAPExecutor.h"

//Libs
#include <Arduino.h>

//Utils
#include "utils/Logger.h"
#include "command/settings_wifi_ap/ChangeSettingsCommand.h"
#include "command/settings_wifi_ap/ConnectCommand.h"
#include "command/settings_wifi_ap/SwitchNormalCommand.h"
#include "utils/JsonUtil.h"

//Public functions
WifiAPExecutor::WifiAPExecutor(){
    this->wifiAPUtil = WifiAPUtil::getInstance();
}
void WifiAPExecutor::execute(){
    if(this->wifiAPUtil->available()){
        String receivedPacket = this->wifiAPUtil->read();
        JsonObject& receivedObject = JsonUtil::getInstance()->getBuffer()->parseObject(receivedPacket);
        if(!receivedObject.success()){
            error("WifiAPExecutor: Invalid json received: %s", receivedPacket.c_str());
            return;
        }

        if(!receivedObject.containsKey("command")){
            error("WifiAPExecutor: Command attribute missing from incoming packet");
            return;
        }

        bool found = false;
        String command = receivedObject["command"];
        for(int i = 0; i < this->commands.size(); i++){
            if(this->commands[i]->isApplicable(command)){
                this->commands[i]->execute(receivedObject);
                found = true;
                break;
            }
        }
        if(!found){
            error("WifiAPExecutor: Not found command: %s", command.c_str());
        }
    }
};
void WifiAPExecutor::init(){
    log("WifiAPExecutor init called");
    this->commands.add(new ChangeSettingsCommand());
    this->commands.add(new ConnectCommand());
    this->commands.add(new SwitchNormalCommand());
}; 
void WifiAPExecutor::dispose(){
    log("WifiAPExecutor dispose called");
    for(int i = 0; i < this->commands.size(); i++){
        delete this->commands[i];
    }
    this->commands.clear();
};