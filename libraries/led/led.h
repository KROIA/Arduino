/*
Autor:	 	© by Alex Krieg
Datum:		19.3.2018
Version:	1.0.0
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
  
  void blinkOn(unsigned int intervall);
  void blinkOff();
  void blinkToggle(unsigned int intervall);
  void blinkIntervall(unsigned int intervall);
  unsigned int blinkIntervall();
  bool isOn();
  bool isBlinking();

 private:

  int pin;
  bool ledIsOn;
  bool blinking;
  Timer *blinkTimer;
  unsigned int _blinkIntervall;
};

#endif // LED_H
