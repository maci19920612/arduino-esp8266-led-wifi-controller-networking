#include "command/led_settings_arduino/AckHelloCommand.h"

void AckHelloCommand::execute(JsonObject& param){
  JsonObject& result = this->jsonBuffer.createObject();
  result["result"] = "Success";

  log("Execute ACK hello command!");
};

bool AckHelloCommand::isApplicable(String command){
  return String("ack_hello") == command;
};