/*
Autor:	 	Alex Krieg
Datum:		12.06.2018
Version:	1.0.1
*/


#ifndef LED_H
#define LED_H

#include "Arduino.h"
#include "Timer.h"

class Led 
{

 public:

  Led(int pinNr);
  ~Led();
  
  void update();
  
  void on();
  void off();
  void toggle();
  
  void blinkOn(unsigned int interval);
  void blinkOff();
  void blinkToggle(unsigned int interval);
  void blinkInterval(unsigned int interval);
  unsigned int blinkInterval();
  
  bool isOn();
  bool isBlinking();

 private:

  int pin;
  bool ledIsOn;
  bool blinking;
  Timer *blinkTimer;
  unsigned int _blinkInterval;
};

#endif // LED_H
