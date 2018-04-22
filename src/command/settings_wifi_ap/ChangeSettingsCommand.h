#ifndef __CHANGE_SETTINGS_COMMAND
#define __CHANGE_SETTINGS_COMMAND

//Libs
#include <ArduinoJson.h>
#include <Arduino.h>


//Commands
#include "command/BaseCommand.h"

class ChangeSettingsCommand : public BaseCommand{
  public:
    virtual void execute(JsonObject& param);
    virtual bool  isApplicable(String command);
};

#endif
