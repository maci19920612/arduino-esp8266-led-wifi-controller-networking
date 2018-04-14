#ifndef __LOGGER
#define __LOGGER

#include <Arduino.h>
#include <stdarg.h>
#include <stdio.h>
void log(const char *fmt, ...) {
    #if DEBUG
    static char buffer[256];
    va_list args;
    va_start(args, fmt);
    vsprintf(buffer, fmt, args);
    va_end(args);
    Serial.print(buffer);
    #endif
};

void error(const char* fmt, ...){
    #if DEBUG
    String format = "Error: " + String(fmt);
    static char buffer[256];
    va_list args;
    va_start(args, fmt);
    vsprintf(buffer, format.c_str(), args);
    va_end(args);
    Serial.print(buffer);
    #endif
}
#endif
