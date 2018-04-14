#include "command/led_settings_wifi/ChangeColorCommand.h"
//Utils
#include "utils/Logger.h"

void ChangeColorCommand::execute(JsonObject& param){
  JsonObject& result = this->jsonBuffer.createObject();
  result["result"] = "Success";
  log("Execute connect wifi command!");
};

bool ChangeColorCommand::isApplicable(String command){
  return String("change_color") == command;
};