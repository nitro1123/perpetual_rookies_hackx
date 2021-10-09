#include "Pins.h"
#include <vector>

using namespace std;

vector<int> pinArray{16, 5, 4, 0, 10};


void initiatePins(){
  for(int i=0;i<pinArray.size();i++){
    pinMode(pinArray[i],INPUT_PULLUP);
  }
}
uint64_t getKeys(){
  uint64_t op=0;
  for(int i=0;i<pinArray.size();i++){
    if(!digitalRead(pinArray[i])){
      op|=1<<i;
    }
  }
  return op;
}
