#ifndef __JSON_UTIL
#define __JSON_UTIL
#include <stdarg.h>
#include <stdio.h>
#include <ArduinoJson.h>

#include "utils/list.h"
class AllAttributeExists{
    public:
        AllAttributeExists& operator()(String attribute);
        bool in(JsonObject& target);
    private:
        List<String> attributes;
};

class JsonUtil{
    public:
        static JsonUtil* getInstance();
        DynamicJsonBuffer* getBuffer();
    private:
        JsonUtil();
        DynamicJsonBuffer* jsonBuffer;
        static JsonUtil* instance;
};

#endif