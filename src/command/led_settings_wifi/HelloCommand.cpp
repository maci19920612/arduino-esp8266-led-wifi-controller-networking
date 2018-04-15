#include "command/led_settings_wifi/HelloCommand.h"

//Utils
#include "utils/Logger.h"
#include "utils/JsonUtil.h"
#include "utils/WifiUtil.h"

void HelloCommand::execute(JsonObject& message){
  log("Execute connect wifi command!");
  if(!message.containsKey("param")){
    error("HelloCommand: messages's param doesn't exists");
    return;
  }
  JsonObject& param = message["param"];
  if(!AllAttributeExists()("ipAddress")("port").in(param)){
    error("HelloCommand: param doesn't contains ipAddress and port attribute");
    return;
  }
  String ipAddress = param["ipAddress"];
  int port = param["port"];

  IPAddress ipAddressObject;
  if(!ipAddressObject.fromString(ipAddress)){
    error("HelloCommand: Invalid ipAddress format");
    return;
  }
  JsonObject& outMessage  = this->jsonBuffer.createObject();
  outMessage["command"] = "ack_hello";
  WifiUtil::getInstance()->send(ipAddressObject, port, outMessage);
};

bool HelloCommand::isApplicable(String command){
  return String("hello") == command;
};