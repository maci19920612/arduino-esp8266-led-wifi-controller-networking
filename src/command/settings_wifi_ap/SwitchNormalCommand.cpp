#include "command/settings_wifi_ap/SwitchNormalCommand.h"

#include "utils/Logger.h"
#include "utils/ArduinoUtil.h"
#include "utils/WifiAPUtil.h"

void SwitchNormalCommand::execute(JsonObject& param){
  log("Execute SwitchNormalCommand!");
  WifiAPUtil::getInstance()->stop();
  ArduinoUtil::getInstance()->sendSwitchNormal();
};

bool SwitchNormalCommand::isApplicable(String command){
  return String("switch_normal") == command;
};