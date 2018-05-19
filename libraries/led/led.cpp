/*
Autor:	 	© by Alex Krieg
Datum:		19.3.2018
Version:	1.0.0
*/


#include "led.h"

Led::Led(int pinNr)
{
  pin 		= pinNr;
  ledIsOn 	= false;
  blinking	= false;
  _blinkIntervall = 1000;
  
  
  pinMode(pin, OUTPUT);
  blinkTimer = new Timer();
}

Led::~Led()
{
	delete blinkTimer;
}
void Led::update()
{
	if(blinking)
	{
		if(blinkTimer->start(_blinkIntervall))
		{
			this->toggle();
		}
	}
}
void Led::on()
{
  digitalWrite(pin, HIGH);
  ledIsOn = true;
}

void Led::off()
{
  digitalWrite(pin, LOW);
  ledIsOn = false;
}

void Led::toggle()
{
  ledIsOn ? off() : on();
}
void Led::blinkOn(unsigned int intervall)
{
	blinking = true;
	blinkIntervall(intervall);
}
void Led::blinkOff()
{
	off();
	blinking = false;
	blinkTimer->stop();
}
void Led::blinkToggle(unsigned int intervall)
{
	if(blinking)
	{
		blinkOff();
	}
	else
	{
		blinkOn(intervall);
	}
}
void Led::blinkIntervall(unsigned int intervall)
{
	_blinkIntervall = intervall;
}
unsigned int Led::blinkIntervall()
{
	return _blinkIntervall;
}
bool Led::isOn()
{
  return ledIsOn;
}
bool Led::isBlinking()
{
	return blinking;
}
