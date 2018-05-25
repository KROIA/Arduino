/*
Autor:	 	KRIA
Datum:		25.5.2018
Version:	1.0.3
*/
#include "A3144.h"

A3144::A3144(byte pin,bool activeHigh){
	this->pin 			= pin;
	this->activeHigh 	= activeHigh;
	
	//_rpm				= 0.0;
	_ticksPerRevolution = 1;
	pinMode(pin,INPUT);
	p_fctChanged 		= NULL;
	p_fctTriggerHigh 	= NULL;
	p_fctTriggerLow 	= NULL;
	p_fctHigh		 	= NULL;
	this->reset();
	
}
A3144::~A3144(){
	delete &p_fctChanged;
	delete &p_fctTriggerHigh;
	delete &p_fctTriggerLow;
	delete &p_fctHigh;
}
void A3144::OnChange(void (*p_func)(bool)){
	p_fctChanged = p_func;
}
void A3144::OnTriggerHigh(void (*p_func)()){
	p_fctTriggerHigh = p_func;
}
void A3144::OnTriggerLow(void (*p_func)()){
	p_fctTriggerLow = p_func;
}
void A3144::ticksPerRevolution(unsigned int ticks)
{
	if(ticks != 0)
	{
		_ticksPerRevolution = ticks;
	}
}
void A3144::update(){
	_lastState 	= _state;
	_state 		= digitalRead(pin);
	
	if(_lastState != _state)
	{
		
		if(p_fctChanged != NULL)
		{
			if(activeHigh)
			{
				(*p_fctChanged)(_state);
			}
			else
			{
				(*p_fctChanged)(!_state);
			}
		}
		if(!(_state ^ activeHigh))
		{
			if(p_fctTriggerHigh != NULL)
			{
				(*p_fctTriggerHigh)();
			}
			_counts++;
			_rpmCounts++;
			rpmTimer.stop();
			rpmTimer.start(0);
			//_rpmLastTime = m
			
			rpmTimeoutTimer.stop();
			rpmTimeoutTimer.start(_rpmTimeout);
			if(_rpmLastTime != 0)
			{
				_rpm = 60000/(((float)millis() - (float)_rpmLastTime)*_ticksPerRevolution);
			}
			_rpmLastTime = millis();
		}
		else
		{
			if(p_fctTriggerLow != NULL)
			{
				(*p_fctTriggerLow)();
			}
		}
		/*if(_counts != 0)
		{
			_rpm = (float)_counts*(float)60000/((float)millis()*(float)_ticksPerRevolution);
		}*/
		
	}
	if(p_fctHigh != NULL)
	{
		if(_state ^ activeHigh)
		{
			(*p_fctHigh)();
		}		
	}
	rpmTimeoutTimer.update();
	if(rpmTimeoutTimer.runtime() >= _rpmTimeout)
	{
		_rpm = 0;
	}
}
unsigned long A3144::counts(){
	return _counts;
}
float A3144::rpm(){
	return _rpm;
}
bool A3144::state(){
	return !(_state ^ activeHigh);
}
void A3144::reset(){
	
	_state	 			= !activeHigh;
	_lastState 			= !activeHigh;
	_rpm				= 0.0;
	_rpmCounts			= 0;
	_counts				= 0;
	
	_rpmLastTime 		= 0;
	_rpmTimeout			= 10000;
}