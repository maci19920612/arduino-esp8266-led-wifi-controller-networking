#ifndef __ACK_SWITCH_NORMAL_COMMAND
#define __ACK_SWITCH_NORMAL_COMMAND

//Libs
#include <ArduinoJson.h>
#include <Arduino.h>

//Utils
#include "utils/Logger.h"

//Commands
#include "command/BaseCommand.h"

class AckSwitchNormalCommand : public BaseCommand{
  public:
    virtual void execute(JsonObject& param);
    virtual bool  isApplicable(String command);
  private:
    DynamicJsonBuffer jsonBuffer;
};

void AckSwitchNormalCommand::execute(JsonObject& param){
  JsonObject& result = this->jsonBuffer.createObject();
  result["result"] = "Success";
  log("Execute settings ack switch normal command!");
};

bool AckSwitchNormalCommand::isApplicable(String command){
  return String("ack_switch_normal") == command;
};
#endif
