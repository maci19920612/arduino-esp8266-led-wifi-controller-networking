#ifndef __WIFI_AP_EXECUTOR
#define __WIFI_AP_EXECUTOR
//Executors
#include "executors/BaseExecutor.h"
class WifiAPExecutor : public BaseExecutor{
    public:
        virtual void execute();
        virtual void init();
        virtual void dispose();
};
#endif