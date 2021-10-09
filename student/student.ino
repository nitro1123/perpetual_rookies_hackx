
#include "wifi.h"
#include "webClient.h"
#include "piano.h"
#define ARDUINOJSON_USE_LONG_LONG 1
#include <ArduinoJson.h>


#define WIFI_SSID "Nitro_net"
#define WIFI_PASSWORD "bolt9959"

#define GET_KEYS_URL "http://143.244.136.63/trainers/110/keys"

unsigned long nextUpdateTime = millis();

void setup() {
  Serial.begin(115200);
  beingWiFi(WIFI_SSID, WIFI_PASSWORD);
  beginPiano();
  // put your setup code here, to run once:

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
  WebClient wClient;
  int code=wClient.Get(GET_KEYS_URL);
  if( code!=200){
    Serial.print("HTTP error with code ");
    Serial.print(code);
    Serial.print(" the error is : ");
    Serial.println(wClient.error);
    return;
  }
  DynamicJsonDocument doc(1024);
  deserializeJson(doc, wClient.responseBody);
  
  JsonObject myObject= doc.as<JsonObject>();
  String keyString = myObject["keys"].as<String>();
  if(keyString == ""){
    Serial.println("Did not receive key data in response");
  }
  uint64_t Keys=0;
  for(int i=0;i<keyString.length();i++){
    Keys*=10;
    Keys+=(keyString[i]-'0');
  }
  printKeys(Keys);
}
