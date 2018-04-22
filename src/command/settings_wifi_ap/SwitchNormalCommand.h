#ifndef __SWITCH_TO_NORMAL_COMMAND
#define __SWITCH_TO_NORMAL_COMMAND

//Libs
#include <ArduinoJson.h>
#include <Arduino.h>

//Utils
#include "utils/Logger.h"

//Commands
#include "command/BaseCommand.h"

class SwitchNormalCommand : public BaseCommand{
  public:
    virtual void execute(JsonObject& param);
    virtual bool  isApplicable(String command);
};

#endif
