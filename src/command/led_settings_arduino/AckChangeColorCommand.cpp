#include "command/led_settings_arduino/AckChangeColorCommand.h"

void AckChangeColorCommand::execute(JsonObject& param){
  JsonObject& result = this->jsonBuffer.createObject();
  result["result"] = "Success";

  log("Execute ACK change color command!");
};

bool AckChangeColorCommand::isApplicable(String command){
  return String("ack_change_color") == command;
};