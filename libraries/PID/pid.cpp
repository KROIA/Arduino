/*
	Version 00.00.00
	Datum	12.07.2019
	Autor 	Alex Krieg
*/

#include "pid.h"

PID::PID()
{
	this->kp(0.1);
	this->ki(0.01);
	this->kd(0.1);
	this->setup();
}
PID::PID(float kp,float ki,float kd)
{
	this->kp(kp);
	this->ki(ki);
	this->kd(kd);
	this->setup();
}
PID::~PID()
{
	
}
void PID::setup()
{
	this->setSpeed(__SPEED_NORMAL);
	_enable_P_I_D = B00000111;
	this->input(0);
	this->expected(0);
	this->maximum(0);	
	this->minimum(0);
	this->reset();
}

void PID::update()
{
	// reading the elapsed time for the "d" -value
	//unsigned long _elapsedTime;
	_output = 0;
	if(_speedModus == __SPEED_FAST)
	{
		_elapsedTime = micros() - _lastTime; 
		_lastTime = micros();
	}else{
		_elapsedTime = millis() - _lastTime; 
		_lastTime = millis();
	}
	
	if(_elapsedTime == 0){_elapsedTime = 1;}
	
	// calculating the error of the system
	_error = _input - _expected;
	_pid_P = 0;
	_pid_D = 0;
	
	if((_enable_P_I_D & B00000001) != 0)
	{
		_pid_P = _kp * _error;
		_output += _pid_P;
	}
	
	// incrementing the "i" proportion
	if((_enable_P_I_D & B00000010) != 0)
	{
		_pid_I = _pid_I + _ki * _error;
		_output += _pid_I;
	}
	
	// calculate the "p" and "d" proportion and adding them all up including the "i"
	if((_enable_P_I_D & B00000100) != 0)
	{
		float time = (float)_elapsedTime;
		if(_speedModus == __SPEED_FAST)
		{
			time /=1000; 
		}
		_pid_D += _kd*((_error - _lastError)/time);
		_output += _pid_D;
	}
	
	// check for min/max boundry. If there is any, the increment value will be decresed 
	// to prevent an overflow. Output will by set to the boundry value.
	if(_min != 0 && _output < _min)
	{
		_pid_I -= _output - _min;
		_output = _min;
	}else if(_max != 0 && _output > _max)
	{
		_pid_I -= _output - _max;
		_output = _max;
	}
	_lastError = _error;
}
void PID::input(float input)
{
	_input = input;
}
void PID::expected(float expected)
{
	_expected = expected;
}
float PID::output()
{
	return _output;
}
float PID::error()
{
	return _error;
}

void PID::kp(float kp)
{
	_kp = kp;
}
void PID::ki(float ki)
{
	_ki = ki;
}
void PID::kd(float kd)
{
	_kd = kd;
}
void PID::I(float i)
{
	_pid_I = i;
}
float PID::P()
{
	return _pid_P;
}
float PID::I()
{
	return _pid_I;
}
float PID::D()
{
	return _pid_D;
}
void PID::maximum(float max)
{
	// max value can't be smaller than the min value
	if(max < _min)
		max = _min;
	_max = max;
}
void PID::minimum(float min)
{
	// min value can't be larger than the max value
	if(min > _max)
		min = _max;
	_min = min;
}

float PID::kp()
{
	return _kp;
}
float PID::ki()
{
	return _ki;
}
float PID::kd()
{
	return _kd;
}
float PID::maximum()
{
	return _max;
}
float PID::minimum()
{
	return _min;
}
void PID::reset()
{
	_pid_I = 0;
	_lastTime = 0;
	_lastError = 0;
	_output = 0;
}
void PID::setSpeed(bool speed)
{
	_speedModus = speed;
}
void PID::enable_P()
{
	_enable_P_I_D |= B00000001;
}
void PID::enable_I()
{
	_enable_P_I_D |= B00000010;
}
void PID::enable_D()
{
	_enable_P_I_D |= B00000100;
}
void PID::disable_P()
{
	_enable_P_I_D &= B00000110;
}
void PID::disable_I()
{
	_enable_P_I_D &= B00000101;
}
void PID::disable_D()
{
	_enable_P_I_D &= B00000011;
}