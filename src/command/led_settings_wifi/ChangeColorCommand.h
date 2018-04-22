#ifndef __CHANGE_COLOR_COMMAND
#define __CHANGE_COLOR_COMMAND

//Libs
#include <ArduinoJson.h>
#include <Arduino.h>



//Commands
#include "command/BaseCommand.h"

class ChangeColorCommand : public BaseCommand{
  public:
    virtual void execute(JsonObject& param);
    virtual bool  isApplicable(String command);
};

#endif
