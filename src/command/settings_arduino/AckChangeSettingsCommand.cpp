#include "command/settings_arduino/AckChangeSettingsCommand.h"

//Utils
#include "utils/Logger.h"
#include "utils/JsonUtil.h"


void AckChangeSettingsCommand::execute(JsonObject& message){
  if(!message.containsKey("param")){
    error("AckChangeSettingsCommand: Message doen't contains param attribute!");
    return;
  }
  JsonObject& param = message["param"];
  if(!AllAttributeExists()("ipAddress")("port").in(param)){
    error("AckChangeSettingsCommand: Params doen't contain ipAddress or port attributes");
    return;
  }
};

bool AckChangeSettingsCommand::isApplicable(String command){
  return String("ack_change_settings") == command;
};