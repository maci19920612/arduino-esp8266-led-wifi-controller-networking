#ifndef __CONNECT_COMMAND
#define __CONNECT_COMMAND

//Libs
#include <ArduinoJson.h>
#include <Arduino.h>

//Commands
#include "command/BaseCommand.h"

class ConnectCommand : public BaseCommand{
  public:
    virtual void execute(JsonObject& param);
    virtual bool  isApplicable(String command);
};

#endif
