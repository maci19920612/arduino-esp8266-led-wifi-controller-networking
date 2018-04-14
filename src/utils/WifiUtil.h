#ifndef __WIFI_UTIL
#define __WIFI_UTIL
//Libs
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>


struct ConnectionResult{
    bool success;
    int statusCode;
};

class WifiUtil{
    public:
        static WifiUtil* getInstance();
        ConnectionResult connect(String ssid, String password);
        void disconnect();
        bool isConnected();
    private:
        static WifiUtil* instance;
        bool connected;
        WiFiUDP* udpServer;
};

WifiUtil* WifiUtil::instance = 0;

//Static functions
WifiUtil* WifiUtil::getInstance(){
    if(instance == 0){
        instance = new WifiUtil();
    }
    return instance;
};

//Public functions

//Private functions
#endif