#ifndef __ARDUINO_UTIL
#define __ARDUINO_UTIL

#include <ArduinoJson.h>
#include <Arduino.h>

class ArduinoUtil{
    public:
        static ArduinoUtil* getInstance();
        //Non network related messages
        void sencAckConnectWifi(bool success, int status);

        //Led settings related functions
        void sendHello(String ipAddress, int port);
        void sendChangeColor(String ipAddress, int port, int r, int g, int b, int w);

        //Settings related functions
        void sendAckSwitchToAp();
        void sendConnect();
        void sendChangeSettings(String ssid, String passwd);
        void sendSwitchNormal();

    private:
        static ArduinoUtil* instance;
        DynamicJsonBuffer jsonBuffer;
        ArduinoUtil();
};
#endif