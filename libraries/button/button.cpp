/*
Autor:	 	Alex Krieg
Datum:		24.05.2018
Version:	1.0.0
*/
#include "button.h"

Button::Button(int pinNr, boolean logicLevel)
{
  pin 						= pinNr;
  activeLogicState			= logicLevel;
  
  p_fctButtonChanged  		= NULL;
  p_fctButtonPressed  		= NULL;
  p_fctButtonReleased 		= NULL;
  p_fctButtonIsPressedHigh 	= NULL;
  p_fctButtonIsPressedLow 	= NULL;
  lastState 				= false;

  pinMode(pin, INPUT);
  this->update();
}

Button::~Button()
{

}

boolean Button::getValue()
{
  return digitalRead(pin);
}

void Button::update()
{
  state = getValue();
  if(state && activeLogicState)
  {
    if(p_fctButtonIsPressedHigh != NULL)
  	{
  	  (*p_fctButtonIsPressedHigh)();
    }
  }
  
  if(!state && !activeLogicState)
  {
    if(p_fctButtonIsPressedLow != NULL)
  	{
  	  (*p_fctButtonIsPressedLow)();
    }
  }

  if(lastState != state)
  {
    if(p_fctButtonChanged != NULL)
    {
     (*p_fctButtonChanged)();
    }
    if(state == false)
    {
      if(!activeLogicState)
      {
        if(p_fctButtonPressed != NULL)
        {
          (*p_fctButtonPressed)();
        }
      }
      else
      {
        if(p_fctButtonReleased != NULL)
        {
          (*p_fctButtonReleased)();
        }
      }
    }
    else
    {
      if(!activeLogicState)
      {
        if(p_fctButtonReleased != NULL)
        { 
          (*p_fctButtonReleased)();
        }
      }
      else
      {
        if(p_fctButtonPressed != NULL)
        { 
          (*p_fctButtonPressed)();
        }
      }
    }
    lastState = state;
  }
}

int Button::getPin()
{
  return pin;
}

void Button::OnPressedEdge(void (*p_func)())
{
  p_fctButtonPressed = p_func;
}

void Button::OnReleasedEdge(void (*p_func)())
{
  p_fctButtonReleased = p_func;
}

void Button::OnBothButtonEdges(void (*p_func)())
{
  p_fctButtonChanged = p_func;
}

void Button::IsPressedHigh(void (*p_func)())
{
  p_fctButtonIsPressedHigh = p_func;
}

void Button::IsPressedLow(void (*p_func)())
{
  p_fctButtonIsPressedLow = p_func;
}



