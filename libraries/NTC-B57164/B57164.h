/*
	Autor	Alex Krieg
	Version	1.0.0
	Datum 	20.3.2018
	
	0*C to 120*C
	
	Hardware:
	
	                  B57164
	     1000ohm    NTC   NTC   200ohm
	5V ---####--T---###---###-----###--- 0V
				|
				|  10uF
				|---||------------------ 0V
				|
				|
				|-------- AnalogInput
				
*/
#ifndef B57164_H
#define B57164_H

#include "Arduino.h"

#define minTemperatur 0
#define maxTemperature 120

#define rawStart1 754
#define rawStep1  -8.266
#define rawStart2 506 
#define rawStep2  -5.766
#define rawStart3 333 
#define rawStep3  -2.833
#define rawStart4 248
#define rawStep4  -1.3
#define rawStart5 209
#define tempStep  30
#define temperatureOffset 0

class 		B57164NTC;
typedef 	B57164NTC Temperature;

class B57164NTC
{
	public:
		B57164NTC(byte pin);
		~B57164NTC();
		
		void update();
		void read();
		float temperature();	// *C
		
		void onHigherThan(float temperature,void (*p_func)(float));
		void onLowerThan(float temperature,void (*p_func)(float));
		
	private:
		
		void calculateTemparature();
		void checkEvents();
		
		byte _pin;
		unsigned int _rawValue;
		float _temperature;
		
		void (*p_fctHigherThan)(float);
		float higherThanTrigger;
		void (*p_fctLowerThan)(float);
		float lowerThanTrigger;
};
#endif