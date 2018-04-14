#ifndef __ACK_CHANGE_COLOR_COMMAND
#define __ACK_CHANGE_COLOR_COMMAND
//Libs
#include <ArduinoJson.h>
#include <Arduino.h>

//Utils
#include "utils/Logger.h"

//Commands
#include "command/BaseCommand.h"
class AckChangeColorCommand : public BaseCommand{
  public:
    virtual void execute(JsonObject& param);
    virtual bool  isApplicable(String command);
  private:
    //TODO: We have to move it into a global container!
    DynamicJsonBuffer jsonBuffer;
};

void AckChangeColorCommand::execute(JsonObject& param){
  JsonObject& result = this->jsonBuffer.createObject();
  result["result"] = "Success";

  log("Execute ACK change color command!");
};

bool AckChangeColorCommand::isApplicable(String command){
  return String("ack_change_color") == command;
};
#endif
