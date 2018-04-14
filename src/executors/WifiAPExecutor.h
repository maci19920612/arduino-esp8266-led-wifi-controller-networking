#ifndef __WIFI_AP_EXECUTOR
#define __WIFI_AP_EXECUTOR
//Libs
#include <Arduino.h>

//Utils
#include "utils/Logger.h"

//Executors
#include "executors/BaseExecutor.h"
class WifiAPExecutor : public BaseExecutor{
    public:
        virtual void execute();
        virtual void init();
        virtual void dispose();
};

//Public functions
void WifiAPExecutor::execute(){
    log("WifiAPExecutor execute called");
};
void WifiAPExecutor::init(){
    log("WifiAPExecutor init called");
}; 
void WifiAPExecutor::dispose(){
    log("WifiAPExecutor dispose called");
};
#endif