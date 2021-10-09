

#include "piano.h"


void setup() {
  beginPiano();
  // put your setup code here, to run once:

}

void loop() {
  for(unsigned long i=0;i<37;i++){
    printKeys(1<<i);
    delay(100);
    printKeys(1<<i);
    delay(100);
    printKeys(1<<i);
    delay(100);
  }
}
