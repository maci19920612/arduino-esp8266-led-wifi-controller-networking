#ifndef __ACK_CONNECT_COMMAND
#define __ACK_CONNECT_COMMAND

//Libs
#include <ArduinoJson.h>
#include <Arduino.h>


//Commands
#include "command/BaseCommand.h"

class AckConnectCommand : public BaseCommand{
  public:
    virtual void execute(JsonObject& param);
    virtual bool  isApplicable(String command);
  private:
    DynamicJsonBuffer jsonBuffer;
};

#endif
