#ifndef __HELLO_COMMAND
#define __HELLO_COMMAND

//Libs
#include <ArduinoJson.h>
#include <Arduino.h>



//Commands
#include "command/BaseCommand.h"

class HelloCommand : public BaseCommand{
  public:
    virtual void execute(JsonObject& param);
    virtual bool  isApplicable(String command);
};

#endif
