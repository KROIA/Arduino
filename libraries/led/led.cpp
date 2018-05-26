/*
Autor:	    Alex Krieg
Datum:		19.3.2018
Version:	1.0.0
*/


#include "led.h"

Led::Led(int pinNr)
{
  pin 		= pinNr;
  ledIsOn 	= false;
  blinking	= false;
  _blinkinterval = 1000;
  
  
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
		if(blinkTimer->start(_blinkinterval))
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
void Led::blinkOn(unsigned int interval)
{
	blinking = true;
	blinkInterval(interval);
}
void Led::blinkOff()
{
	off();
	blinking = false;
	blinkTimer->stop();
}
void Led::blinkToggle(unsigned int interval)
{
	if(blinking)
	{
		blinkOff();
	}
	else
	{
		blinkOn(interval);
	}
}
void Led::blinkInterval(unsigned int interval)
{
	_blinkinterval = interval;
}
unsigned int Led::blinkInterval()
{
	return _blinkinterval;
}
bool Led::isOn()
{
  return ledIsOn;
}
bool Led::isBlinking()
{
	return blinking;
}
