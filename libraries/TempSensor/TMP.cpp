#include "TMP.h"


 Tmp::Tmp(int pinNr)
{
  pin=pinNr;
}
 Tmp::~Tmp()
{
  
}
void Tmp::init()
{
  pinMode(pin, INPUT); 
}
float Tmp::getVoltage()
{
  // analogRead returns an int between 0 and 1023
  voltage = analogRead(pin) * 5 / 1024.0;
  return voltage;
  
}
/*float Tmp::getTemp()
{
   getVoltage();
   //return 104.167 * voltage -54.167;
   return a * voltage + b;
}*/
