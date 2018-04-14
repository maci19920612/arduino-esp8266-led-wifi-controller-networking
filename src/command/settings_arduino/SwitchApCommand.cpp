#include "command/settings_arduino/SwitchApCommand.h"


//Utils
#include "utils/Logger.h"

void SwitchApCommand::execute(JsonObject& param){
  JsonObject& result = this->jsonBuffer.createObject();
  result["result"] = "Success";
  log("Execute settings switch ap command!");
};

bool SwitchApCommand::isApplicable(String command){
  return String("switch_ap") == command;
};