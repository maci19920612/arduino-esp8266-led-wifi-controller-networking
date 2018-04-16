#ifndef __WIFI_AP_UTIL
#define __WIFI_AP_UTIL

#include <ESP8266WiFi.h>
#include <Arduino.h>

#include "Config.h"
#include "utils/list.h"

class WifiAPUtil{
    public:
        static WifiAPUtil* getInstance();
        void start();
        void stop();
        bool available();
        String read();
        void send(String data); 
    private:
        static WifiAPUtil* instance;
        WifiAPUtil();
        WiFiServer* wifiServer;
        WiFiClient connectedWifiClient;
};
#endif
