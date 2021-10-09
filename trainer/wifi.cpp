
#include "wifi.h"

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

ESP8266WiFiMulti WiFiMulti;

void beingWiFi(const char *ssid, const char *password){
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(ssid, password);
}


bool wifiConnected(){
  return WiFiMulti.run() == WL_CONNECTED;
}
