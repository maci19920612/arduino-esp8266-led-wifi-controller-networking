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
    virtual bool isApplicable(String command);
};

#endif
