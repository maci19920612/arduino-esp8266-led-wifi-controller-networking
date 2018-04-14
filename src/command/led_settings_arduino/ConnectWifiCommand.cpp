#include "command/led_settings_arduino/ConnectWifiCommand.h"

//Utils
#include "utils/Logger.h"
#include "utils/WifiUtil.h"



void ConnectWifiCommand::execute(JsonObject& message){
  if(!message.containsKey("param")){
    error("Invalid message json, doesn't have param field!");
    return;
  }
  JsonObject& param = message["param"];
  if(!param.containsKey("ssid") || !param.containsKey("passwd")){
    error("Param doesn't have ssid or passwd field!");
    return;
  }
  String  ssid = param["ssid"];
  String passwd = param["passwd"];
  ConnectionResult result = WifiUtil::getInstance()->connect(ssid.c_str(), passwd.c_str());
  //TODO: We have to ACK result

 /* if(result.success){
    ExecutorContainer::getInstance()->enable(Executor::wifi);
  }else{
    ExecutorContainer::getInstance()->disable(Executor::wifi);
  }*/
};

bool ConnectWifiCommand::isApplicable(String command){
  return String("connect_wifi") == command;
};