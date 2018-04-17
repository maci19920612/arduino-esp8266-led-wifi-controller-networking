#include "command/settings_wifi_ap/ConnectCommand.h"

//Utils
#include "utils/Logger.h"
#include "utils/ArduinoUtil.h"

void ConnectCommand::execute(JsonObject& param){
  log("Execute ConnectCommand");
  ArduinoUtil::getInstance()->sendConnect();
};

bool ConnectCommand::isApplicable(String command){
  return String("connect") == command;
};