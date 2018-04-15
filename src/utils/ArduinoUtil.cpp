#include "utils/ArduinoUtil.h"
#include <Arduino.h>

ArduinoUtil* ArduinoUtil::instance = 0;

//Static functions
ArduinoUtil* ArduinoUtil::getInstance(){
    if(instance == 0){
        instance = new ArduinoUtil();
    }
    return instance;
};

//Public functions
void ArduinoUtil::sencAckConnectWifi(bool success, int status){
    JsonObject& jsonObject = this->jsonBuffer.createObject();
    jsonObject["command"] = "ack_connect_wifi";
    JsonObject& param = jsonObject.createNestedObject("param");
    param["success"] = success;
    param["status"] = status;
    jsonObject.printTo(Serial);
    Serial.println();
};


//Led settings related functions
void ArduinoUtil::sendHello(String ipAddress, int port){
    JsonObject& root = this->jsonBuffer.createObject();
    root["command"] = "hello";

    JsonObject& param = root.createNestedObject("param");
    param["ipAddress"] = ipAddress;
    param["port"] = port;

    root.printTo(Serial);
    Serial.println();
};

void ArduinoUtil::sendChangeColor(String ipAddress, int port, int r, int g, int b, int w){
    JsonObject& root = this->jsonBuffer.createObject();
    root["command"] = "change_color";

    JsonObject& param = root.createNestedObject("param");

    param["ipAddress"] = ipAddress;
    param["port"] = port;
    param["r"] = r;
    param["g"] = g;
    param["b"] = b;
    param["w"] = w;

    root.printTo(Serial);
    Serial.println();
}

//Settings related functions
void ArduinoUtil::sendAckSwitchToAp(String ipAddress, int port){
    JsonObject& root = this->jsonBuffer.createObject();
    root["command"] = "ack_switch_ap";

    JsonObject& param = root.createNestedObject("param");

    param["ipAddress"] = ipAddress;
    param["port"] = port;

    root.printTo(Serial);
    Serial.println();
}
void ArduinoUtil::sendConnect(String ipAddress, int port){
    JsonObject& root = this->jsonBuffer.createObject();
    root["command"] = "connect";
    JsonObject& param = root.createNestedObject("param");
    param["ipAddress"] = ipAddress;
    param["port"] = port;
    root.printTo(Serial);
    Serial.println();
}

void ArduinoUtil::sendChangeSettings(String ipAddress, int port, String ssid, String passwd){
    JsonObject& root = this->jsonBuffer.createObject();
    root["command"] = "change_settings";
    JsonObject& param = root.createNestedObject("param");
    param["ipAddress"] = ipAddress;
    param["port"] = port;
    param["ssid"] = ssid;
    param["passwd"] = passwd;

    root.printTo(Serial);
    Serial.println();
}

void ArduinoUtil::sendSwitchNormal(String ipAddress, int port){
    JsonObject& root = this->jsonBuffer.createObject();
    root["command"] = "switch_normal";
    JsonObject& param = root.createNestedObject("param");
    param["ipAddress"] = ipAddress;
    param["port"] = port;

    root.printTo(Serial);
    Serial.println();
}

//Private functions
ArduinoUtil::ArduinoUtil(){
    //Empty implementation
};
