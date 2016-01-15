#include "TMP36.h"

 Tmp36::Tmp36(int pinNr): Tmp(pinNr)
{

}
 Tmp36::~Tmp36()
{
  
}

float Tmp36::getTemp()
{   return 104.167 * getVoltage() -54.167;
}
