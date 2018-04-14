#include "executors/WifiAPExecutor.h"

//Libs
#include <Arduino.h>

//Utils
#include "utils/Logger.h"

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