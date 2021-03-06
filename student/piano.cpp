
#include "piano.h"
#include <MD_MAX72xx.h>
#include <SPI.h>
#include <vector>
using namespace std;

#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
#define CLK_PIN   D5  // or SCK
#define DATA_PIN  D7  // or MOSI
#define CS_PIN    D4  // or SS
#define MAX_DEVICES 12

vector<int> keyData(37, 0);

int keyLocations[37][2] = {
  {4,5},
  {7,7},
  {8,9},
  {11,11},
  {13,14},
  {16,16},
  {17,18},
  {20,21},
  {23,23},
  {25,26},
  {28,28},
  {30,31},
  {32,33},
  {35,35},
  {36,37},
  {39,39},
  {41,42},
  {44,44},
  {46,47},
  {48,49},
  {51,51},
  {53,54},
  {56,56},
  {57,58},
  {60,61},
  {63,63},
  {64,65},
  {67,67},
  {69,70},
  {72,72},
  {74,75},
  {76,77},
  {79,79},
  {81,82},
  {84,84},
  {86,87},
  {88,91}
};

MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);



void printKeys(uint64_t keysData){
  mx.control(MD_MAX72XX::UPDATE, MD_MAX72XX::OFF);
  for(uint64_t i=0;i<37;i++){
    keyData[i]>>=1;
    uint64_t mask = 1;
    mask<<=i;
    if(keysData&mask){
      keyData[i]|=0x80;
    }
    for(int j=keyLocations[i][0];j<=keyLocations[i][1];j++){
      int r_col=(j&0xFFF8)|(7-(j&0x07));
      mx.setColumn(r_col,keyData[i]);
    }
  }
  mx.control(MD_MAX72XX::UPDATE, MD_MAX72XX::ON);
}

void beginPiano(){
  mx.begin();
}
