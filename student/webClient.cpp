#include "webClient.h"

int WebClient::Get(String url){
  this->error="";
  this->responseBody="";
  if(!this->http.begin(this->client,url)){
    this->error="Unable to connect";
    return 0;
  }
  int httpCode = this->http.GET();
  if(httpCode>0){
    this->responseBody= http.getString();
  }else{
    this->error = this->http.errorToString(httpCode).c_str();
  }
  return httpCode;
}
