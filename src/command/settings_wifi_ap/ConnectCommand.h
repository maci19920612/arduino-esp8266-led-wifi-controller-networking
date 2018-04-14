#ifndef __CONNECT_COMMAND
#define __CONNECT_COMMAND

//Libs
#include <ArduinoJson.h>
#include <Arduino.h>

//Utils
#include "utils/Logger.h"

//Commands
#include "command/BaseCommand.h"

class ConnectCommand : public BaseCommand{
  public:
    virtual void execute(JsonObject& param);
    virtual bool  isApplicable(String command);
  private:
    DynamicJsonBuffer jsonBuffer;
};

void ConnectCommand::execute(JsonObject& param){
  JsonObject& result = this->jsonBuffer.createObject();
  result["result"] = "Success";
  log("Execute connect wifi command!");
};

bool ConnectCommand::isApplicable(String command){
  return String("connect") == command;
};
#endif
