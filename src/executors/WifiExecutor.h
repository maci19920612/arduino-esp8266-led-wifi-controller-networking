#ifndef __WIFI_EXECUTOR
#define __WIFI_EXECUTOR
//Libs
#include <Arduino.h>

//Utils
#include "utils/Logger.h"

//Executors
#include "executors/BaseExecutor.h"
class WifiExecutor : public BaseExecutor{
    public:
        virtual void execute();
        virtual void init();
        virtual void dispose();
};

//Public functions
void WifiExecutor::execute(){
    log("WifiExecutor execute called");
};
void WifiExecutor::init(){
    log("WifiExecutor init called");
}; 
void WifiExecutor::dispose(){
    log("WifiExecutor dispose called");
};
#endif