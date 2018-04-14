#ifndef __LOGGER
#define __LOGGER
#include <stdarg.h>
#include <stdio.h>
void log(const char *fmt, ...);
void error(const char* fmt, ...);
#endif
