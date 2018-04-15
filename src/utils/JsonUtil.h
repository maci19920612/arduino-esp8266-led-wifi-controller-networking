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

#endif