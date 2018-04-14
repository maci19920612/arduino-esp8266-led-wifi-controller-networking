#ifndef __SWITCH_TO_NORMAL_COMMAND
#define __SWITCH_TO_NORMAL_COMMAND

//Libs
#include <ArduinoJson.h>
#include <Arduino.h>

//Utils
#include "utils/Logger.h"

//Commands
#include "command/BaseCommand.h"

class SwitchNormalCommand : public BaseCommand{
  public:
    virtual void execute(JsonObject& param);
    virtual bool  isApplicable(String command);
  private:
    DynamicJsonBuffer jsonBuffer;
};

void SwitchNormalCommand::execute(JsonObject& param){
  JsonObject& result = this->jsonBuffer.createObject();
  result["result"] = "Success";
  log("Execute connect wifi command!");
};

bool SwitchNormalCommand::isApplicable(String command){
  return String("switch_normal") == command;
};
#endif
