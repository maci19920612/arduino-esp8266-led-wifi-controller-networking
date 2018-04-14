#include "executors/WifiExecutor.h"

//Libs
#include <Arduino.h>

//Utils
#include "utils/Logger.h"


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