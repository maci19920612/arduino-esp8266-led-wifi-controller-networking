#ifndef __SWITCH_API_COMMAND
#define __SWITCH_API_COMMAND

//Libs
#include <ArduinoJson.h>
#include <Arduino.h>

//Utils
#include "utils/Logger.h"

//Commands
#include "command/BaseCommand.h"

class SwitchApCommand : public BaseCommand{
  public:
    virtual void execute(JsonObject& param);
    virtual bool  isApplicable(String command);
  private:
    DynamicJsonBuffer jsonBuffer;
};

void SwitchApCommand::execute(JsonObject& param){
  JsonObject& result = this->jsonBuffer.createObject();
  result["result"] = "Success";
  log("Execute settings switch ap command!");
};

bool SwitchApCommand::isApplicable(String command){
  return String("switch_ap") == command;
};
#endif
