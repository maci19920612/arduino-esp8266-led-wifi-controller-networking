
#include "command/settings_wifi_ap/ChangeSettingsCommand.h"

//Utils
#include "utils/Logger.h"
#include "utils/JsonUtil.h"
#include "utils/ArduinoUtil.h"

void ChangeSettingsCommand::execute(JsonObject& message){
  log("Execute ChangeSettingsCommand");
  if(!message.containsKey("param")){
    error("ChangeSettingsCommand: Message doen't containt param attribute");
    return;
  }
  JsonObject& param = message["param"];
  if(!AllAttributeExists()("ssid")("passwd").in(param)){
    error("ChangeSettingsCommand: Missing ssid or passwd attribute from param");
    return;
  }
  ArduinoUtil::getInstance()->sendChangeSettings(
    param["ssid"],
    param["passwd"]
  );
};

bool ChangeSettingsCommand::isApplicable(String command){
  return String("change_settings") == command;
};