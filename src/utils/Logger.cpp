#include <Arduino.h>
#include <stdarg.h>
#include <stdio.h>
#include "utils/Logger.h"
#include "Config.h"

void log(const char *fmt, ...) {
    #if DEBUG
    String format = String(fmt) + "\n";
    static char buffer[256];
    va_list args;
    va_start(args, fmt);
    vsprintf(buffer, format.c_str(), args);
    va_end(args);
    Serial.print(buffer);
    #endif
    
};

void error(const char* fmt, ...){
    #if DEBUG

    String format = "Error: " + String(fmt) + "\n";
    static char buffer[256];
    va_list args;
    va_start(args, fmt);
    vsprintf(buffer, format.c_str(), args);
    va_end(args);
    Serial.print(buffer);
    #endif
}