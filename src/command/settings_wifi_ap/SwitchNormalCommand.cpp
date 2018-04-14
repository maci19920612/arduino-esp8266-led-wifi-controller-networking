#include "command/settings_wifi_ap/SwitchNormalCommand.h"


void SwitchNormalCommand::execute(JsonObject& param){
  JsonObject& result = this->jsonBuffer.createObject();
  result["result"] = "Success";
  log("Execute connect wifi command!");
};

bool SwitchNormalCommand::isApplicable(String command){
  return String("switch_normal") == command;
};