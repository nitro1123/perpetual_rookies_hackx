#include "Pins.h"
#include "wifi.h"
#include "webClient.h"
#include <ArduinoJson.h>


#define WIFI_SSID "Nitro_net"
#define WIFI_PASSWORD "bolt9959"

#define POST_KEYS_URL "http://192.168.2.5:1923/keys"


unsigned long nextUpdateTime = millis();

void setup() {
  Serial.begin(115200);
  beingWiFi(WIFI_SSID, WIFI_PASSWORD);
  initiatePins();
}

void loop() {
  if(!wifiConnected()){
    Serial.println("WiFi not connected");
    delay(5000);
    return;
  }
  if(nextUpdateTime>millis()){
    return;
  }
  nextUpdateTime=millis()+100;
  uint64_t op=getKeys();
  
  WebClient wClient;
  int code=wClient.Post(POST_KEYS_URL, "{\"keys\":"+String(op)+"}");
  if( code!=200){
    Serial.print("HTTP error with code ");
    Serial.print(code);
    Serial.print(" the error is : ");
    Serial.println(wClient.error);
    return;
  }
}
