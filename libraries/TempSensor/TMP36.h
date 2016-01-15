#ifndef TMP36_CPP
#define TMP36_CPP

#include "Arduino.h"
#include "TMP.h"

class Tmp36 : public Tmp
{
  public:
  Tmp36(int pinNr);
  ~Tmp36();
  float getTemp();
  
  private:

};
#endif
