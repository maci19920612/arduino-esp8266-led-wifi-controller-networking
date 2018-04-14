#include "command/settings_arduino/AckChangeSettingsCommand.h"

//Utils
#include "utils/Logger.h"

void AckChangeSettingsCommand::execute(JsonObject& param){
  JsonObject& result = this->jsonBuffer.createObject();
  result["result"] = "Success";
  log("Execute change settings command!");
};

bool AckChangeSettingsCommand::isApplicable(String command){
  return String("ack_change_settings") == command;
};