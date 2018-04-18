#ifndef __WIFI_AP_EXECUTOR
#define __WIFI_AP_EXECUTOR
//Executors
#include "executors/BaseExecutor.h"

#include "command/BaseCommand.h"


//Utils
#include "utils/WifiAPUtil.h"
#include "utils/list.h"
class WifiAPExecutor : public BaseExecutor{
    public:
        virtual void execute();
        virtual void init();
        virtual void dispose();
        WifiAPExecutor();
    private:
        WifiAPUtil* wifiAPUtil;
        DynamicJsonBuffer jsonBuffer;
        List<BaseCommand*> commands;
};
#endif