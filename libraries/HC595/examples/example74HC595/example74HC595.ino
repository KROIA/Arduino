#include "HC595.h"
//Version 1.0

HC595 ICOut(9,11,8,12,10,1); // enable,clock,serialOut,reset,save ,amount
                             // IC:13 ,IC:11,IC:14    ,IC10 ,IC:12
void setup()
{
  Serial.begin(9600);
  ICOut.write(0,B01001110);
}
void loop()
{
  
}