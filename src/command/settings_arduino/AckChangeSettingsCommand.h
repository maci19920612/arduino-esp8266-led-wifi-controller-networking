#ifndef __ACK_CHANGE_SETTINGS_COMMAND
#define __ACK_CHANGE_SETTINGS_COMMAND

//Libs
#include <ArduinoJson.h>
#include <Arduino.h>

//Utils
#include "utils/Logger.h"

//Commands
#include "command/BaseCommand.h"

class AckChangeSettingsCommand : public BaseCommand{
  public:
    virtual void execute(JsonObject& param);
    virtual bool  isApplicable(String command);
  private:
    DynamicJsonBuffer jsonBuffer;
};

void AckChangeSettingsCommand::execute(JsonObject& param){
  JsonObject& result = this->jsonBuffer.createObject();
  result["result"] = "Success";
  log("Execute change settings command!");
};

bool AckChangeSettingsCommand::isApplicable(String command){
  return String("ack_change_settings") == command;
};
#endif
