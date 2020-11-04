//	Autor	Alex Krieg
//	Version	2.3
//	Datum 	19.06.2018

#include "Timer.h"

//-------------Public------------------
Timer::Timer(bool Micros)
{
	p_fctTimerEnd = nullptr;
	doMicros = Micros;
	_autoRestart = false;
	this->reset();
}
Timer::~Timer()
{
	
}
void Timer::reset()
{
	runState		= false;
	if(!_autoRestart)
	{
		benoetigteZeit	= 0;
	}
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
	if(_autoRestart)
	{
		this->start(benoetigteZeit);
	}
}
bool Timer::update()
{
	if(runState)
	{
		
		if(doMicros)
		{
			vergangeneZeit	= micros();
		}
		else
		{
			vergangeneZeit	= millis();
		}
		if(((vergangeneZeit - startZeit) >= benoetigteZeit) && benoetigteZeit != 0)
		{
			if(p_fctTimerEnd != nullptr)
			{
				this->stop();
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
	if(this->update())
	{
		this->stop();
		return true;
	}
	return false;
}
unsigned long  Timer::stop()
{
	unsigned long runtime = this->runtime();
	this->reset();
	return runtime;
}
void Timer::onFinished(void (*p_func)())
{
	p_fctTimerEnd 	= p_func;
}
unsigned long Timer::runtime()
{
	return vergangeneZeit - startZeit;
}
void Timer::autoRestart(bool autoRestart)
{
	_autoRestart = autoRestart;
}
bool Timer::isRunning()
{
	return runState;
}