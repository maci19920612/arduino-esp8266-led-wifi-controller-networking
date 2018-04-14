#include "command/settings_arduino/AckSwitchNormalCommand.h"


//Utils
#include "utils/Logger.h"

void AckSwitchNormalCommand::execute(JsonObject& param){
  JsonObject& result = this->jsonBuffer.createObject();
  result["result"] = "Success";
  log("Execute settings ack switch normal command!");
};

bool AckSwitchNormalCommand::isApplicable(String command){
  return String("ack_switch_normal") == command;
};