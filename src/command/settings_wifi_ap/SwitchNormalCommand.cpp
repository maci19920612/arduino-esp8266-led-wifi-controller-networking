#include "command/settings_wifi_ap/SwitchNormalCommand.h"

#include "utils/Logger.h"
#include "utils/ArduinoUtil.h"
#include "utils/WifiAPUtil.h"

#include "executors/ExecutorContainer.h"

void SwitchNormalCommand::execute(JsonObject& param){
  log("Execute SwitchNormalCommand!");
  WifiAPUtil::getInstance()->stop();
  ArduinoUtil::getInstance()->sendSwitchNormal();
  ExecutorContainer::getInstance()->disable(Executor::wifiAP);
};

bool SwitchNormalCommand::isApplicable(String command){
  return String("switch_normal") == command;
};