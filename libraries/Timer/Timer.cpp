//	Autor	Alex Krieg
//	Version	2.1
//	Datum 	19.05.2018

#include "Timer.h"

//-------------Public------------------
Timer::Timer(bool Micros)
{
	p_fctTimerEnd = NULL;
	doMicros = Micros;
	this->reset();
}
Timer::~Timer()
{
	
}
void Timer::reset()
{
	runState		= false;
	benoetigteZeit	= 0;
	startZeit		= 0;
	if(doMicros)
	{
		vergangeneZeit	= micros();
	}
	else
	{
		vergangeneZeit	= millis();
	}
	startZeit 		= vergangeneZeit;
}
bool Timer::update()
{
	
	if(runState == true)
	{
		
		if(doMicros)
		{
			vergangeneZeit	= micros();
		}
		else
		{
			vergangeneZeit	= millis();
		}
		if(((vergangeneZeit - startZeit) > benoetigteZeit) && benoetigteZeit != 0)
		{
			this->reset();
			if(p_fctTimerEnd != NULL)
			{
				(*p_fctTimerEnd)();
			}
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}
bool Timer::start(unsigned long timeOfDelayIn)
{
	if(!runState)
	{
		runState 		= true;
		if(doMicros)
		{
			startZeit	= micros();
		}
		else
		{
			startZeit	= millis();
		}
		
	}
	benoetigteZeit 	= timeOfDelayIn;
	return this->update();
}
void Timer::stop()
{
	this->reset();
}
void Timer::on_timeout(void (*p_func)())
{
	p_fctTimerEnd 	= p_func;
}
unsigned int Timer::runtime()
{
	return vergangeneZeit - startZeit;
}