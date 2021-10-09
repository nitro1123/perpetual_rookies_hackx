int pinArray[]={16, 5, 4, 0, 10};

#define pins 5

void setup() {
  Serial.begin(115200);
  Serial.println("Size of pinArray is :");
  for(int i=0;i<pins;i++){
    pinMode(pinArray[i],INPUT_PULLUP);
  }
  Serial.println("Starting loop");
}

int prevOutput=0;

void loop() {
  int op=0;
  for(int i=0;i<pins;i++){
    if(!digitalRead(pinArray[i]))
    {
      op|=1<<i;
    }
  }
  if(op!=prevOutput){
    Serial.print("Changed to ");
    Serial.println(op);
    prevOutput=op;
  }
}
