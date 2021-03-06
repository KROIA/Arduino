//	Autor	Alex Krieg
//	Version	2.4
//	Datum 	04.11.2020

#ifndef TIMER_H
#define TIMER_H

#include "Arduino.h"
#define TMicros 1
#define TMillis 0
class Timer
{
	public:
	Timer(bool Micros = TMillis);
	~Timer();
	
	bool update();
	bool start(unsigned long timeOfDelayIn = 0);
	unsigned long stop();

	void onFinished(void (*p_func)());
	unsigned long runtime();
	
	void autoRestart(bool autoRestart);
	bool isRunning();
	
	private:
	void reset();
	void (*p_fctTimerEnd)(void);
	
	
	
	unsigned long benoetigteZeit;
	unsigned long startZeit;
	unsigned long vergangeneZeit;
	bool doMicros;
	bool _autoRestart;
	
	boolean runState;
};
#endif