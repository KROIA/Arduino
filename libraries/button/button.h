/*
Autor:	 	Alex Krieg
Datum:		24.05.2018
Version:	1.0.0
*/

#ifndef BUTTON_H
#define BUTTON_H

#include "Arduino.h"

#define activeLow false
#define activeHigh true

class Button
{

 public:

  Button(int pinNr, boolean logicLevel = activeHigh);
  ~Button();
  void update();

  void OnPressedEdge(void (*p_func)());
  void OnReleasedEdge(void (*p_func)());
  void OnBothButtonEdges(void (*p_func)());
  void IsPressedHigh(void (*p_func)());
  void IsPressedLow(void (*p_func)());

  bool getValue();
  
  int getPin();

 private:

  int pin;
  bool activeLogicState;
  bool state;
  bool lastState;
  void (*p_fctButtonChanged)(void);
  void (*p_fctButtonPressed)(void);
  void (*p_fctButtonReleased)(void);
  void (*p_fctButtonIsPressedHigh)(void);
  void (*p_fctButtonIsPressedLow)(void);

};

#endif // BUTTON_H