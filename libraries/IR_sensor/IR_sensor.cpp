/*
Autor:	 	Alex Krieg
Datum:		13.06.2018
Version:	0.0.0
*/
#include "IR_sensor.h"


IR_sensor::IR_sensor(byte IR_ledPin,byte IR_pdPin)
{
	p_fctLowTrigger  	= NULL;
	p_fctHighTrigger 	= NULL;
	p_fctBothTrigger 	= NULL;
	
	highTriggerCoolDown = false;
	lowTriggerCoolDown = false;

	this->triggerHysteresis(30);
	this->lowTriggerValue(1000);
	this->highTriggerValue(800);
	
	_ledPin				= IR_ledPin;
	_pdPin				= IR_pdPin;
	
	pinMode(_ledPin,OUTPUT);
	pinMode(_pdPin,INPUT);
	
	pdValue     = 1023;
	lastPdValue = pdValue;
}
IR_sensor::~IR_sensor()
{
	
}
void IR_sensor::update()
{
	lastPdValue = pdValue;
	this->readPdValue();
	this->checkEvents();
}
byte IR_sensor::ledPin()
{
	return _ledPin;
}
byte IR_sensor::pdPin()
{
	return _pdPin;
}
void IR_sensor::highTriggerValue(unsigned int triggerValue){
	_highTriggerValue = triggerValue;
}
unsigned int IR_sensor::highTriggerValue(){
	return _highTriggerValue;
}
void IR_sensor::lowTriggerValue(unsigned int triggerValue){
	_lowTriggerValue = triggerValue;
}
unsigned int IR_sensor::lowTriggerValue(){
	return _lowTriggerValue;
}
void IR_sensor::triggerHysteresis(unsigned int hysteresis)
{
	_triggerHysteresis = hysteresis;
}
unsigned int IR_sensor::triggerHysteresis()
{
	return _triggerHysteresis;
}
unsigned int IR_sensor::value(){
	return pdValue;
}
void IR_sensor::readPdValue(){
	digitalWrite(_ledPin,HIGH);
	pdValue 	= (lastPdValue+analogRead(_pdPin))/2;
	digitalWrite(_ledPin,LOW);
}
void IR_sensor::checkEvents()
{
	if(!highTriggerCoolDown)
	{
		if(pdValue < _highTriggerValue && lastPdValue >= _highTriggerValue)
		{
			highTriggerCoolDown = true;
			if(p_fctHighTrigger != NULL){
			(*p_fctHighTrigger)();}
		
			if(p_fctBothTrigger != NULL){
			(*p_fctBothTrigger)();}
		}
	}
	else if(pdValue >= (_highTriggerValue+_triggerHysteresis))
	{
		highTriggerCoolDown = false;
	}
	if(!lowTriggerCoolDown)
	{
		if(pdValue > _lowTriggerValue && lastPdValue <= _lowTriggerValue)
		{
			lowTriggerCoolDown = true;
			if(p_fctLowTrigger != NULL){
			(*p_fctLowTrigger)();}
		
			if(p_fctBothTrigger != NULL){
			(*p_fctBothTrigger)();}
		}
	}
	else if(pdValue <= (_lowTriggerValue-_triggerHysteresis))
	{
		lowTriggerCoolDown = false;
	}
	
}
void IR_sensor::onLowTrigger(void (*p_func)()){
	p_fctLowTrigger = p_func;
}
void IR_sensor::onLowTrigger(void (*p_func)(),unsigned int triggerValue){
	this->onLowTrigger(p_func);
	this->lowTriggerValue(triggerValue);
}
void IR_sensor::onHighTrigger(void (*p_func)()){
	p_fctHighTrigger = p_func;
}
void IR_sensor::onHighTrigger(void (*p_func)(),unsigned int triggerValue){
	this->onHighTrigger(p_func);
	this->highTriggerValue(triggerValue);
}
void IR_sensor::onBothTrigger(void (*p_func)()){
	p_fctBothTrigger = p_func;
}