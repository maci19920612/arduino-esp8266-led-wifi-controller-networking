#include "command/led_settings_arduino/AckChangeColorCommand.h"
#include "utils/ArduinoUtil.h"
#include "utils/WifiUtil.h"
#include <ESP8266WiFi.h>
void AckChangeColorCommand::execute(JsonObject& message){
  log("Execute ACK change color command!");
  if(!message.containsKey("param")){
    error("AckChangeColorCommand: Message doesn't have param attribute!");
    return;
  }
  JsonObject& param = message["param"];
  if(!param.containsKey("ipAddress") || !param.containsKey("port")){
    error("AckChangeColorCommand: params doesn't contain port or ipAddress field");
    return;
  }
  String ipAddress = param["ipAddress"];
  int port = param["port"];
  JsonObject& outMessage = this->jsonBuffer.createObject();
  outMessage["command"] = "ack_change_color";
  IPAddress ipAddressObject;
  if(!ipAddressObject.fromString(ipAddress)){
    error("AckChangeColorCommand: Invalid IP Address");
    return;
  }
  WifiUtil::getInstance()->send(ipAddressObject, port, outMessage);
};

bool AckChangeColorCommand::isApplicable(String command){
  return String("ack_change_color") == command;
};