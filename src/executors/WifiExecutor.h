#ifndef __WIFI_EXECUTOR
#define __WIFI_EXECUTOR

//Libs
#include <ArduinoJson.h>

//Executors
#include "executors/BaseExecutor.h"

//Commands
#include "command/BaseCommand.h"

//Utils
#include "utils/list.h"
#include "utils/WifiUtil.h"

class WifiExecutor : public BaseExecutor{
    public:
        virtual void execute();
        virtual void init();
        virtual void dispose();
        WifiExecutor();
    private:
        WifiUtil* wifiUtil;
        List<BaseCommand*> commands;
};
#endif