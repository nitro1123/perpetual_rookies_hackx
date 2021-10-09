#include "Pins.h"

void setup() {
  Serial.begin(115200);
  initiatePins();
}

uint64_t prevOutput=0;

void loop() {
  uint64_t op=getKeys();
  if(op!=prevOutput){
    Serial.print("Changed to ");
    Serial.println(op);
    prevOutput=op;
  }
}
