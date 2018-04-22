#ifndef __CONNECT_WIFI_COMMAND
#define __CONNECT_WIFI_COMMAND
//Libs
#include <ArduinoJson.h>
#include <Arduino.h>

//Commands
#include "command/BaseCommand.h"
class ConnectWifiCommand : public BaseCommand{
  public:
    virtual void execute(JsonObject& param);
    virtual bool  isApplicable(String command);
};
#endif
