#ifndef BUTTON_H
#define BUTTON_H

#include "Arduino.h"

#define activeLow true
#define activeHigh false

class Button
{

 public:

  Button(int pinNr, boolean logicLevel);
  ~Button();
  void init();
  void initWithInternalPullup();

  void OnPressedEdge(void (*p_func)());
  void OnReleasedEdge(void (*p_func)());
  void OnBothButtonEdges(void (*p_func)());
  void IsPressedHigh(void (*p_func)());
  void IsPressedLow(void (*p_func)());

  virtual boolean getValue();
  void checkButton();
  int getPin();

 private:

  int pin;
  boolean isActiveLow;
  boolean state;
  void (*p_fctButtonChanged)(void);
  void (*p_fctButtonPressed)(void);
  void (*p_fctButtonReleased)(void);
  void (*p_fctButtonIsPressedHigh)(void);
  void (*p_fctButtonIsPressedLow)(void);

};

#endif // BUTTON_H