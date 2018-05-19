/*
Autor:	 	KRIA
Datum:		16.4.2018
Version:	1.0.2

NOTE:

4294967295 revolutions in a unsigned long means:
	@	1000 	rpm 	-> 8 	years 	to overflow
	@	3000 	rpm 	-> 994 	days 	to overflow
	@	6000 	rpm 	-> 497 	days 	to overflow
	@	12000 	rpm 	-> 248 	days 	to overflow
	@	30000 	rpm 	-> 99 	days 	to overflow


*/
#ifndef A3144_H
#define A3144_H
#include "Arduino.h"
#include "Timer.h"


class 		A3144;
typedef 	A3144 HallSensor;

class A3144
{
	public:
		A3144(byte pin,bool activeHigh = false);
		~A3144();
		void OnChange(void (*p_func)(bool));
		void OnTriggerHigh(void (*p_func)());
		void OnTriggerLow(void (*p_func)());
		void OnHigh(void (*p_func)());
		void ticksPerRevolution(unsigned int ticks);
		
		void update();
		unsigned long counts();
		float rpm();
		bool state();
		void reset();
		
	private:
		byte 			pin;
		bool 			activeHigh;
		unsigned long 	_counts;
		unsigned int 	_rpmCounts;
		float 			_rpm;
		bool 			_state;
		bool 			_lastState;
		unsigned int 	_ticksPerRevolution;
		unsigned int 	_rpmTimeout;
		unsigned int 	_rpmLastTime;
		
		void (*p_fctChanged)(bool);
		void (*p_fctTriggerHigh)(void);
		void (*p_fctTriggerLow)(void);
		void (*p_fctHigh)(void);
		Timer rpmTimer;
		Timer rpmCalculateTimer;
		Timer rpmTimeoutTimer;
};
#endif