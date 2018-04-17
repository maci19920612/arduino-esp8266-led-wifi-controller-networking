#ifndef __WIFI_UTIL
#define __WIFI_UTIL
//Libs
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoJson.h>

//Utils
#include "utils/Logger.h"

//Configs
#include "Config.h"


struct ConnectionResult{
    bool success;
    int statusCode;
};
struct UdpPacket{
    char content[MAX_UDP_PACKET_SIZE];
    int length;
    IPAddress remoteIp;
    int remotePort; 
};

class WifiUtil{
    public:
        static WifiUtil* getInstance();
        static const char* mapWifiStatus(int wifiStatus);
        ConnectionResult connect(const char* ssid, const char* password);
        void disconnect();
        bool isConnected();
        
        bool receive();
        UdpPacket& getReceivedPacket();
        void send(IPAddress& target, int& remotePort, JsonObject& object);
    private:
        static WifiUtil* instance;
        bool connected;
        WiFiUDP udpServer;
        UdpPacket inputPacket;
};

#endif