#include "command/led_settings_wifi/HelloCommand.h"

//Utils
#include "utils/Logger.h"

void HelloCommand::execute(JsonObject& param){
  JsonObject& result = this->jsonBuffer.createObject();
  result["result"] = "Success";
  log("Execute connect wifi command!");
};

bool HelloCommand::isApplicable(String command){
  return String("hello") == command;
};