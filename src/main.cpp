//Libs
#include <Arduino.h>
//#include <ArduinoJson.h>

//Utils
#include "utils/list.h"
#include "utils/Logger.h"

//Executors
#include "executors/ExecutorContainer.h"


ExecutorContainer* executorContainer;
void setup() {
  Serial.begin(115200);
  executorContainer = ExecutorContainer::getInstance();
  log("\n\nServer started...\n");
  Serial.println("\n<BOOT_COMPLETE>");
}

void loop() {
  executorContainer->execute();
}
