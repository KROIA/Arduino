/*
Autor:	 	Alex Krieg
Datum:		11.07.2018
Version:	1.0.2
*/

#ifndef BUTTON_H
#define BUTTON_H

#include "Arduino.h"

#define activeLow 3
#define activeHigh 4
#define pullup 2
#define PULLUP 2

class Button
{

 public:

  Button(int pinNr);
  Button(int pinNr, unsigned int logicLevel);
  ~Button();
  void update();

  void OnPressedEdge(void (*p_func)());
  void OnReleasedEdge(void (*p_func)());
  void OnBothButtonEdges(void (*p_func)());
  void IsPressedHigh(void (*p_func)());
  void IsPressedLow(void (*p_func)());
  void getPulseLength(void (*p_func)(unsigned int));

  bool getValue();
  
  int getPin();

 private:

  void setup(int pinNr, unsigned int logicLevel);
  int pin;
  bool activeLogicState;
  bool state;
  bool lastState;
  unsigned int pulseLength;
  unsigned long startTime;
  
  void (*p_fctButtonChanged)(void);
  void (*p_fctButtonPressed)(void);
  void (*p_fctButtonReleased)(void);
  void (*p_fctButtonIsPressedHigh)(void);
  void (*p_fctButtonIsPressedLow)(void);
  void (*p_fctGetPulseLength)(unsigned int);
};

#endif // BUTTON_H