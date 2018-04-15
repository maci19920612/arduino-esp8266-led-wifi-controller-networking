#include "utils/WifiUtil.h"


WifiUtil* WifiUtil::instance = 0;

//Static functions
WifiUtil* WifiUtil::getInstance(){
    if(instance == 0){
        instance = new WifiUtil();
    }
    return instance;
};
char* WifiUtil::mapWifiStatus(int status){
    switch(status){
        case WL_CONNECTED: {
            return "Connected";
        }
        case WL_IDLE_STATUS: {
            return "Idle";
        }
        case WL_NO_SSID_AVAIL: {
            return "SSID not available";
        }
        case WL_SCAN_COMPLETED:{
            return "Scan completed";
        }
        case WL_CONNECT_FAILED:{
            return "Connection failure";
        }
        case WL_CONNECTION_LOST:{
            return "Connection lost";
        }
        case WL_DISCONNECTED: {
            return "Disconnected";
        }
        default:{
            return "Unknown";
        }
    }

}

//Public functions
ConnectionResult WifiUtil::connect(const char* ssid, const char* password){
    WiFi.begin(ssid, password);
    while(WiFi.status() == WL_DISCONNECTED){
        log("Connecting to wifi...");
        delay(500);
    };
    ConnectionResult result;
    int wifiStatus = WiFi.status();
    result.success = wifiStatus == WL_CONNECTED;
    result.statusCode = wifiStatus;

    if(wifiStatus == WL_CONNECTED){
        log("Connected, IP: %s", WiFi.localIP().toString().c_str());
    }else{
        log("Wifi connection status: %s(%d)", mapWifiStatus(wifiStatus), wifiStatus);
        return result;
    }
    
    this->udpServer.begin(UDP_PORT);
    log("UDP server started...");
    return result;
};

void WifiUtil::disconnect(){
    this->udpServer.stopAll();
    WiFi.disconnect();
};

bool WifiUtil::receive(){
    int packetSize = this->udpServer.parsePacket();
    bool isReceived = packetSize > 0;
    if(isReceived){
        this->inputPacket.length = packetSize;
        int readedString = this->udpServer.read(this->inputPacket.content, MAX_UDP_PACKET_SIZE - 1);
        this->inputPacket.content[readedString - 1] = '\0';
        this->inputPacket.remoteIp = this->udpServer.remoteIP();
        this->inputPacket.remotePort = this->udpServer.remotePort();

        log("UDP packet received: %s", this->inputPacket.content);
    }
    return isReceived;
};

UdpPacket& WifiUtil::getReceivedPacket(){
    return this->inputPacket;
};

void WifiUtil::send(IPAddress& remoteIp, int& remotePort, JsonObject& object){
    this->udpServer.beginPacket(remoteIp, remotePort);
    object.printTo(this->udpServer);
    this->udpServer.endPacket();
};


//Private functions