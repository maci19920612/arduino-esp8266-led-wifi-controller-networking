#include "command/settings_arduino/AckChangeSettingsCommand.h"

//Utils
#include "utils/Logger.h"
#include "utils/JsonUtil.h"
#include "utils/WifiAPUtil.h"


void AckChangeSettingsCommand::execute(JsonObject& message){
  log("Execute AckChangeSettingsCommand"); 
  
  String messageString;
  message.printTo(messageString);
  WifiAPUtil::getInstance()->send(messageString);
};

bool AckChangeSettingsCommand::isApplicable(String command){
  return String("ack_change_settings") == command;
};