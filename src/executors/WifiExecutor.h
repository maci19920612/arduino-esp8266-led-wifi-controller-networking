#ifndef __WIFI_EXECUTOR
#define __WIFI_EXECUTOR
//Executors
#include "executors/BaseExecutor.h"
class WifiExecutor : public BaseExecutor{
    public:
        virtual void execute();
        virtual void init();
        virtual void dispose();
};
#endif