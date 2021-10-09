
#include "webClient.h"

int WebClient::Post(String url, String postBody){
  this->error="";
  this->responseBody="";
  if(!this->http.begin(this->client,url)){
    this->error="Unable to connect";
    return 0;
  }
  this->http.addHeader("Content-Type", "application/json");
  int httpCode = this->http.POST(postBody);
  if(httpCode>0){
    this->responseBody= http.getString();
  }else{
    this->error = this->http.errorToString(httpCode).c_str();
  }
  return httpCode;
}
