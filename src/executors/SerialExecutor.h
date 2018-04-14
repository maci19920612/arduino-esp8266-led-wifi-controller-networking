#ifndef __SERIAL_EXECUTOR
#define __SERIAL_EXECUTOR
#include <Arduino.h>
#include <ArduinoJson.h>

//Utils
#include "utils/list.h"
#include "utils/Logger.h"

//Executors
#include "executors/BaseExecutor.h"

//Commands
#include "command/BaseCommand.h"


class SerialExecutor : public BaseExecutor{
    public:
        SerialExecutor();
        virtual void execute();
        virtual void init();
        virtual void dispose();
    private:
        List<BaseCommand*> commands;
        DynamicJsonBuffer jsonBuffer;
};
#endif