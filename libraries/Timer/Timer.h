//	Autor	Alex Krieg
//	Version	2.1
//	Datum 	19.05.2018

#ifndef TIMER_H
#define TIMER_H

#include "Arduino.h"

class Timer
{
	public:
	Timer(bool Micros = 0);
	~Timer();
	
	bool update();
	bool start(unsigned long timeOfDelayIn = 0);
	void stop();

	void on_timeout(void (*p_func)());
	unsigned int runtime();
	
	private:
	void reset();
	void (*p_fctTimerEnd)(void);
	
	
	
	unsigned int benoetigteZeit;
	unsigned long startZeit;
	unsigned long vergangeneZeit;
	bool doMicros;
	//bool doStopWatch;
	
	boolean runState;
};
#endif