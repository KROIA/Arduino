#include "button.h"

  Button::Button(int pinNr, boolean logicLevel)
  : pin(pinNr), isActiveLow(logicLevel)
  {
    state = getValue();
    p_fctButtonChanged  		= NULL;
    p_fctButtonPressed  		= NULL;
    p_fctButtonReleased 		= NULL;
	p_fctButtonIsPressedHigh 	= NULL;
	p_fctButtonIsPressedLow 	= NULL;
  }
  
  Button::~Button()
  {
  
  }

  void Button::init()
  {
    pinMode(pin, INPUT);
  }
  
  void Button::initWithInternalPullup()
  {
    pinMode(pin, INPUT_PULLUP);
  }
  
  boolean Button::getValue()
  {
    return digitalRead(pin);
  }

  void Button::checkButton()
  {
    if(getValue() && !isActiveLow)
	{
	  if(p_fctButtonIsPressedHigh != NULL)
      {
		  (*p_fctButtonIsPressedHigh)();
	  }
	}
	
	if(!getValue() && isActiveLow)
	{
	  if(p_fctButtonIsPressedLow != NULL)
      {
		  (*p_fctButtonIsPressedLow)();
	  }
	}
	
    if(state != getValue())
    {
      if(p_fctButtonChanged != NULL)
      {
       (*p_fctButtonChanged)();
      }
      if(getValue() == false)
      {
        if(isActiveLow)
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
        if(isActiveLow)
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
      state = getValue();
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

  

