#ifndef __BASE_COMMAND
#define __BASE_COMMAND
#include <Arduino.h>
#include <ArduinoJson.h>
class BaseCommand{
public:
  virtual void execute(JsonObject& p) = 0;
  virtual bool isApplicable(String command) = 0;
};
#endif
