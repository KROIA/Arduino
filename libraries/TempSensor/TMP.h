#ifndef TMP_CPP
#define TMP_CPP

#include "Arduino.h"

class Tmp
{
  public:
  Tmp(int pinNr);
  ~Tmp();
  void init();
  float getVoltage();
  virtual float getTemp() = 0;
  
  private:
  int pin;
  float voltage;
};
#endif
