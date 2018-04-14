#ifndef __CONNECT_WIFI_COMMAND
#define __CONNECT_WIFI_COMMAND
//Libs
#include <ArduinoJson.h>
#include <Arduino.h>

//Utils
#include "utils/Logger.h"

//Commands
#include "command/BaseCommand.h"
class ConnectWifiCommand : public BaseCommand{
  public:
    virtual void execute(JsonObject& param);
    virtual bool  isApplicable(String command);
  private:
    DynamicJsonBuffer jsonBuffer;
};

void ConnectWifiCommand::execute(JsonObject& param){
  JsonObject& result = this->jsonBuffer.createObject();
  result["result"] = "Success";
  log("Execute connect wifi command!");
};

bool ConnectWifiCommand::isApplicable(String command){
  return String("connect_wifi") == command;
};
#endif
