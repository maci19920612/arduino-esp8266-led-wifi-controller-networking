
#include "command/settings_wifi_ap/ChangeSettingsCommand.h"

//Utils
#include "utils/Logger.h"

void ChangeSettingsCommand::execute(JsonObject& param){
  JsonObject& result = this->jsonBuffer.createObject();
  result["result"] = "Success";
  log("Execute connect wifi command!");
};

bool ChangeSettingsCommand::isApplicable(String command){
  return String("change_settings") == command;
};