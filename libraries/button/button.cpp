/*
Autor:	 	Alex Krieg
Datum:		11.07.2018
Version:	1.0.2
*/
#include "button.h"

Button::Button(int pinNr)
{
  this->setup(pinNr,activeHigh);
}
Button::Button(int pinNr, unsigned int logicLevel)
{
  this->setup(pinNr,logicLevel);
}
void Button::setup(int pinNr, unsigned int logicLevel)
{
  pin 						= pinNr;
  if(logicLevel  	 == activeLow)
  {activeLogicState			= false;}
  else if(logicLevel == activeHigh)
  {activeLogicState			= true;}
  else if(logicLevel == INPUT_PULLUP)
  {activeLogicState			= false;}

  lastState 			   != activeLogicState;
  p_fctButtonChanged  		= NULL;
  p_fctButtonPressed  		= NULL;
  p_fctButtonReleased 		= NULL;
  p_fctButtonIsPressedHigh 	= NULL;
  p_fctButtonIsPressedLow 	= NULL;
  p_fctGetPulseLength		= NULL;
  
  pulseLength 				= 0;
  startTime					= 0;
  
  if(logicLevel == INPUT_PULLUP)
	pinMode(pin, INPUT_PULLUP);
  else
	pinMode(pin, INPUT);
  this->update();
}

Button::~Button()
{

}

bool Button::getValue()
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
		startTime = micros();
        if(p_fctButtonPressed != NULL)
        {
          (*p_fctButtonPressed)();
        }
      }
      else
      {
		pulseLength = micros() - startTime;
        if(p_fctButtonReleased != NULL)
        {
          (*p_fctButtonReleased)();
        }
		if(p_fctGetPulseLength != NULL)
        {
          (*p_fctGetPulseLength)(pulseLength);
        }
      }
    }
    else
    {
      if(!activeLogicState)
      {
		pulseLength = micros() - startTime;
        if(p_fctButtonReleased != NULL)
        { 
          (*p_fctButtonReleased)();
        }
		if(p_fctGetPulseLength != NULL)
        {
          (*p_fctGetPulseLength)(pulseLength);
        }
      }
      else
      {
		startTime = micros();
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

void Button::getPulseLength(void (*p_func)(unsigned int))
{
	p_fctGetPulseLength = p_func;
}

