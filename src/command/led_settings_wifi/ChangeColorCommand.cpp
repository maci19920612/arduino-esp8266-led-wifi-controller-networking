#include "command/led_settings_wifi/ChangeColorCommand.h"
//Utils
#include "utils/Logger.h"
#include "utils/ArduinoUtil.h"
#include "utils/JsonUtil.h"
#include <ESP8266WiFi.h>

void ChangeColorCommand::execute(JsonObject& message){
  log("Execute connect wifi command!");
  if(!message.containsKey("param")){
    error("ChangeColorCommand: message doen't containt param attribute");
    return;
  }
  JsonObject& param = message["param"];
  if(!AllAttributeExists()("ipAddress")("port")("r")("g")("b")("w").in(param)){
    error("ChangeColorCommand: ipAddress, port, r, g, b, w params are missing from message's params attribute");
    return;
  }
  String ipAddress = param["ipAddress"];
  int port = param["port"];
  int r = param["r"];
  int g = param["g"];
  int b = param["b"];
  int w = param["w"];

  ArduinoUtil::getInstance()->sendChangeColor(ipAddress, port, r, g, b, w);
};

bool ChangeColorCommand::isApplicable(String command){
  return String("change_color") == command;
};