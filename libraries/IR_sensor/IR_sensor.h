/*
Autor:	 	Alex Krieg
Datum:		13.06.2018
Version:	0.0.0
*/

#ifndef IR_SENSOR_H
#define IR_SENSOR_H

#include "Arduino.h"

class IR_sensor
{
	public:
		IR_sensor(byte IR_ledPin,byte IR_pdPin);
		~IR_sensor();
		void update();
		
		byte ledPin();
		byte pdPin();
		
		void highTriggerValue(unsigned int triggerValue);
		unsigned int highTriggerValue();
		void lowTriggerValue(unsigned int triggerValue);
		unsigned int lowTriggerValue();
		void triggerHysteresis(unsigned int hysteresis);
		unsigned int triggerHysteresis();
		
		unsigned int value();
		
		
		//---------EVENTS-----------------------
		void onLowTrigger(void (*p_func)());
		void onLowTrigger(void (*p_func)(),unsigned int triggerValue);
		void onHighTrigger(void (*p_func)());
		void onHighTrigger(void (*p_func)(),unsigned int triggerValue);
		void onBothTrigger(void (*p_func)());
		//--------------------------------------
	private:
		void readPdValue();
		void checkEvents();
		
	
		byte _ledPin;
		byte _pdPin;
		
		unsigned int pdValue;
		unsigned int lastPdValue;
	
		unsigned int _triggerHysteresis;
		unsigned int _lowTriggerValue;
		void (*p_fctLowTrigger)(void);
		bool lowTriggerCoolDown;
		
		unsigned int _highTriggerValue;
		void (*p_fctHighTrigger)(void);
		bool highTriggerCoolDown;
		
		void (*p_fctBothTrigger)(void);
};
#endif