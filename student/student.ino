
#include "wifi.h"
#include "webClient.h"
#include "piano.h"
#include <Arduino_JSON.h>


#define WIFI_SSID "Nitro_net"
#define WIFI_PASSWORD "bolt9959"

#define GET_KEYS_URL "http://192.168.2.5:1923/keys"

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
  
  JSONVar myObject = JSON.parse(wClient.responseBody.c_str());
  if(!myObject.hasOwnProperty("keys")){
    Serial.print("The response was ");
    Serial.print(wClient.responseBody);
    Serial.println(" Did not receive keys value");
    return;
  }
  long Keys = (long)myObject["keys"];
  printKeys(Keys);
}
