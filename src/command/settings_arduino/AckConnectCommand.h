#ifndef __ACK_CONNECT_COMMAND
#define __ACK_CONNECT_COMMAND

//Libs
#include <ArduinoJson.h>
#include <Arduino.h>

//Utils
#include "utils/Logger.h"

//Commands
#include "command/BaseCommand.h"

class AckConnectCommand : public BaseCommand{
  public:
    virtual void execute(JsonObject& param);
    virtual bool  isApplicable(String command);
  private:
    DynamicJsonBuffer jsonBuffer;
};

void AckConnectCommand::execute(JsonObject& param){
  JsonObject& result = this->jsonBuffer.createObject();
  result["result"] = "Success";
  log("Execute settings ack connect command!");
};

bool AckConnectCommand::isApplicable(String command){
  return String("ack_connect") == command;
};
#endif
