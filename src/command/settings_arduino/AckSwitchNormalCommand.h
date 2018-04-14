#ifndef __ACK_SWITCH_NORMAL_COMMAND
#define __ACK_SWITCH_NORMAL_COMMAND

//Libs
#include <ArduinoJson.h>
#include <Arduino.h>


//Commands
#include "command/BaseCommand.h"

class AckSwitchNormalCommand : public BaseCommand{
  public:
    virtual void execute(JsonObject& param);
    virtual bool  isApplicable(String command);
  private:
    DynamicJsonBuffer jsonBuffer;
};

#endif
