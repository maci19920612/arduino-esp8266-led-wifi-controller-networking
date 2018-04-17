#include "command/settings_arduino/SwitchApCommand.h"


//Utils
#include "utils/Logger.h"
#include "utils/ArduinoUtil.h"
#include "utils/WifiUtil.h"
#include "utils/WifiAPUtil.h"


void SwitchApCommand::execute(JsonObject& param){
  log("Execute SwitchApCommand!");
  
  WifiUtil::getInstance()->disconnect();
  WifiAPUtil::getInstance()->start();
  ArduinoUtil::getInstance()->sendAckSwitchToAp();
};

bool SwitchApCommand::isApplicable(String command){
  return String("switch_ap") == command;
};