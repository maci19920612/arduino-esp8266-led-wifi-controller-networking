#ifndef __SWITCH_API_COMMAND
#define __SWITCH_API_COMMAND

//Libs
#include <ArduinoJson.h>
#include <Arduino.h>


//Commands
#include "command/BaseCommand.h"

class SwitchApCommand : public BaseCommand{
  public:
    virtual void execute(JsonObject& param);
    virtual bool  isApplicable(String command);
};

#endif
