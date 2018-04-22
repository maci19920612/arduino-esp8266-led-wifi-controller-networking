#include "utils/WifiAPUtil.h"

WifiAPUtil* WifiAPUtil::instance = 0;

//Static functions
WifiAPUtil* WifiAPUtil::getInstance(){
    if(instance == 0){
        instance = new WifiAPUtil();
    }
    return instance;
};
//Public functions
void WifiAPUtil::start(){
    WiFi.softAP(WIFI_AP_SSID,WIFI_AP_PASSWD);
    this->wifiServer->begin();
};

void WifiAPUtil::stop(){
    WiFi.softAPdisconnect();
    this->wifiServer->stop();
}
bool WifiAPUtil::available(){
    if(this->wifiServer->hasClient()){
        Serial.println("AP: Has client");
        WiFiClient availableClient = this->wifiServer->available();
        Serial.print("Available client: ");
        Serial.println((bool)availableClient);
        Serial.print("Equals to current client: ");
        Serial.println(this->connectedWifiClient == availableClient);
        Serial.print("Currenct client is connected: ");
        Serial.println(this->connectedWifiClient.connected());

        if(!this->connectedWifiClient.connected()){
            this->connectedWifiClient = availableClient;
        }
    }

    return this->connectedWifiClient.connected() && this->connectedWifiClient.available();
};
String WifiAPUtil::read(){
    if(this->connectedWifiClient.available()){
        return this->connectedWifiClient.readStringUntil('\n');
    }
    return "\n";
};
void WifiAPUtil::send(String data){
    if(this->connectedWifiClient.connected()){
        this->connectedWifiClient.write((data + "\n").c_str());
    }
}
//Private functions
WifiAPUtil::WifiAPUtil(){
    this->wifiServer = new WiFiServer(TCP_SERVER_PORT);
};