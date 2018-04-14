#ifndef __SERIAL_EXECUTOR
#define __SERIAL_EXECUTOR
#include <Arduino.h>
#include <ArduinoJson.h>

//Utils
#include "utils/list.h"
#include "utils/Logger.h"

//Executors
#include "executors/BaseExecutor.h"

//Commands
#include "command/BaseCommand.h"
#include "command/led_settings_arduino/ConnectWifiCommand.h"
#include "command/led_settings_arduino/AckHelloCommand.h"
#include "command/led_settings_arduino/AckChangeColorCommand.h"
#include "command/settings_arduino/AckChangeSettingsCommand.h"
#include "command/settings_arduino/AckConnectCommand.h"
#include "command/settings_arduino/AckSwitchNormalCommand.h"
#include "command/settings_arduino/SwitchApCommand.h"

class SerialExecutor : public BaseExecutor{
    public:
        SerialExecutor();
        virtual void execute();
        virtual void init();
        virtual void dispose();
    private:
        List<BaseCommand*> commands;
        DynamicJsonBuffer jsonBuffer;
};

//Public functions
SerialExecutor::SerialExecutor(){
    //Led settings commands
    this->commands.add(new ConnectWifiCommand());
    this->commands.add(new AckHelloCommand());
    this->commands.add(new AckChangeColorCommand());
    
    //Settings commands
    this->commands.add(new AckChangeSettingsCommand());
    this->commands.add(new AckConnectCommand());
    this->commands.add(new AckSwitchNormalCommand());
    this->commands.add(new SwitchApCommand());
}

void SerialExecutor::init(){
    log("Serial executor init!");
};

void SerialExecutor::dispose(){
    log("Serial executor disposed!");
}

void SerialExecutor::execute(){
    if(Serial.available() > 0){
        String serialJson = Serial.readStringUntil('\n');
        JsonObject& jsonObject = this->jsonBuffer.parseObject(serialJson);
        if(!jsonObject.success()){
            error("Invalid json received: %s\n", serialJson.c_str());
        }else{
            log("Valid json received: %s\n", serialJson.c_str());
            String command = jsonObject["command"];
            bool found = false;

            for(int i = 0; i < commands.size(); i++){
                if(commands[i]->isApplicable(command)){
                    commands[i]->execute(jsonObject);
                    found = true;
                    break;
                }
            }

            if(!found){
                error("Not found applicable command executor for this command: %s", command.c_str());
            }
        }
    }
};
#endif