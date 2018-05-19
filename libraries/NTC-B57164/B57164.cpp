/*
	Autor	Alex Krieg
	Version	1.0.0
	Datum 	20.3.2018
*/
#include "B57164.h"


B57164NTC::B57164NTC(byte pin)
{
	_pin 				= pin;
	_rawValue 			= 0;
	_temperature 		= 0;
		
	p_fctHigherThan 	= NULL;
	p_fctLowerThan  	= NULL;
	higherThanTrigger 	= 0;
	lowerThanTrigger 	= 0;
	
	pinMode(_pin,INPUT);
}
B57164NTC::~B57164NTC()
{
	
}
void B57164NTC::update()
{
	read();
	checkEvents();
}
void B57164NTC::read()
{
	_rawValue = analogRead(_pin);
	calculateTemparature();
}
float B57164NTC::temperature()
{
	return _temperature;
}
void B57164NTC::onHigherThan(float temperature,void (*p_func)(float))
{
	if(temperature > minTemperatur && temperature < maxTemperature)
	{
		higherThanTrigger 	= temperature;
		p_fctHigherThan 	= p_func;
	}
}
void B57164NTC::onLowerThan(float temperature,void (*p_func)(float))
{
	if(temperature > minTemperatur && temperature < maxTemperature)
	{
		lowerThanTrigger 	= temperature;
		p_fctLowerThan 		= p_func;
	}
}
		
void B57164NTC::calculateTemparature()
{
	if(_rawValue < rawStart1 && _rawValue > rawStart2){_temperature = (((float)_rawValue-rawStart1 )/ (float)rawStep1) + temperatureOffset;return;}
	if(_rawValue < rawStart2 && _rawValue > rawStart3){_temperature = (((float)_rawValue-rawStart2 )/ (float)rawStep2) + temperatureOffset + tempStep;return;}
	if(_rawValue < rawStart3 && _rawValue > rawStart4){_temperature = (((float)_rawValue-rawStart3 )/ (float)rawStep3) + temperatureOffset + 2*tempStep;return;}
	if(_rawValue < rawStart4 && _rawValue > rawStart5){_temperature = (((float)_rawValue-rawStart4 )/ (float)rawStep4) + temperatureOffset + 3*tempStep;return;}
}
void B57164NTC::checkEvents()
{
	if(p_fctHigherThan != NULL)
	{
		if(_temperature > higherThanTrigger)
		{
			(*p_fctHigherThan)(_temperature);
		}
	}
	if(p_fctLowerThan != NULL)
	{
		if(_temperature < lowerThanTrigger)
		{
			(*p_fctLowerThan)(_temperature);
		}
	}
}