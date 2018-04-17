#include "command/settings_arduino/AckConnectCommand.h"

//Utils
#include "utils/Logger.h"
#include "utils/ArduinoUtil.h"

void AckConnectCommand::execute(JsonObject& param){
  log("Execute settings ack connect command!");
  ArduinoUtil::getInstance()->sendConnect();  
};

bool AckConnectCommand::isApplicable(String command){
  return String("ack_connect") == command;
};