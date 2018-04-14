#include "command/settings_wifi_ap/ConnectCommand.h"

//Utils
#include "utils/Logger.h"

void ConnectCommand::execute(JsonObject& param){
  JsonObject& result = this->jsonBuffer.createObject();
  result["result"] = "Success";
  log("Execute connect wifi command!");
};

bool ConnectCommand::isApplicable(String command){
  return String("connect") == command;
};