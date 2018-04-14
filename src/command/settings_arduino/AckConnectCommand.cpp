#include "command/settings_arduino/AckConnectCommand.h"

//Utils
#include "utils/Logger.h"

void AckConnectCommand::execute(JsonObject& param){
  JsonObject& result = this->jsonBuffer.createObject();
  result["result"] = "Success";
  log("Execute settings ack connect command!");
};

bool AckConnectCommand::isApplicable(String command){
  return String("ack_connect") == command;
};