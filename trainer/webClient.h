#ifndef WEB_CLIENT_H
#define WEB_CLIENT_H

#include <ESP8266HTTPClient.h>

#include <WiFiClient.h>
class WebClient{
  private:
  WiFiClient client;
  HTTPClient http;
  public:
  int Post(String url, String postBody);
  String error, responseBody;
};
#endif
