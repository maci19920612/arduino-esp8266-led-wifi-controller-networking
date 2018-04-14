#ifndef __ACK_HELLO_COMMAND
#define __ACK_HELLO_COMMAND

//Libs
#include <ArduinoJson.h>
#include <Arduino.h>

//Utils
#include "utils/Logger.h"

//Commands
#include "command/BaseCommand.h"
class AckHelloCommand : public BaseCommand{
  public:
    virtual void execute(JsonObject& param);
    virtual bool  isApplicable(String command);
  private:
    //TODO: We have to move it into a global container!
    DynamicJsonBuffer jsonBuffer;
};

void AckHelloCommand::execute(JsonObject& param){
  JsonObject& result = this->jsonBuffer.createObject();
  result["result"] = "Success";

  log("Execute ACK hello command!");
};

bool AckHelloCommand::isApplicable(String command){
  return String("ack_hello") == command;
};
#endif
