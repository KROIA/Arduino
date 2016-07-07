#include "ledcube8.h"
byte ledPin[8]        = {2,3,4,5,6,7,8,9};
byte addressPin[4]    = {10,11,12,13};
byte layerPin[4]      = {A0,A1,A2,A3};

  byte a = B00000001;
  byte b = B00000010;
  byte c = B00000100;
  byte d = B00001000;
  byte e = B00010000;
  byte f = B00100000;
  byte g = B01000000;
  byte h = B10000000;
LedCube8 cube(ledPin,addressPin,layerPin);
int takt = 100;
int time =10;
void setup()
{
  Serial.begin(9600);
  Serial.println("TEST");
  
  
  cube.init();
cube.time(1000);

}
CUBEDATACUBE test{0,0,0,0,0,0,0,0,
0,0,0,24,24,0,0,0,
0,0,24,36,36,24,0,0,
0,24,36,66,66,36,24,0,
0,24,36,66,66,36,24,0,
0,0,24,36,36,24,0,0,
0,0,0,24,24,0,0,0,
0,0,0,0,0,0,0,0};
void loop()
{
   //cube.drawCube(test);
   //cube.rain(10,10);
   cube.shiftCubeDown( 7 , true,test);

}
