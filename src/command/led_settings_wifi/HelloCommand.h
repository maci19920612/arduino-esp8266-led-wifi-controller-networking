#ifndef __HELLO_COMMAND
#define __HELLO_COMMAND

//Libs
#include <ArduinoJson.h>
#include <Arduino.h>

//Utils
#include "utils/Logger.h"

//Commands
#include "command/BaseCommand.h"

class HelloCommand : public BaseCommand{
  public:
    virtual void execute(JsonObject& param);
    virtual bool  isApplicable(String command);
  private:
    DynamicJsonBuffer jsonBuffer;
};

void HelloCommand::execute(JsonObject& param){
  JsonObject& result = this->jsonBuffer.createObject();
  result["result"] = "Success";
  log("Execute connect wifi command!");
};

bool HelloCommand::isApplicable(String command){
  return String("hello") == command;
};
#endif
