/*
	Version 00.00.00
	Datum	12.07.2019
	Autor 	Alex Krieg
*/

#ifndef PID_H
#define PID_H
#include <Arduino.h>

#define __SPEED_NORMAL 0
#define __SPEED_FAST 1


class PID
{
	public:
		PID(); // Presets the pid values
		PID(float kp,float ki,float kd);
		~PID();
		
		void update();
		void input(float input);
		void expected(float expected);
		float output();
		float error();
		
		void kp(float kp);					// cosntant for the proportional factor
		void ki(float ki);					// constant for the increment factor
		void kd(float kd);					// constant for the diferential factor
		
		void maximum(float max);
		void minimum(float min);
		
		float kp();
		float ki();
		float kd();
		
		void I(float _ki);
		
		float P();
		float I();
		float D();
		
		
		float maximum();
		float minimum();
		
		void reset();
		void setSpeed(bool speed);	
		
		void enable_P();
		void enable_I();
		void enable_D();
		
		void disable_P();
		void disable_I();
		void disable_D();
		
		
		unsigned int elapsedTime(){
			return _elapsedTime;
		}
	private:
		void setup();
	
		float _kp;
		float _ki;
		float _kd;
		
		float _pid_P;
		float _pid_I;
		float _pid_D;
		
		
		
		float _input;
		float _expected;
		float _output;
		float _error;
		float _lastError;
		float _max;				// If value is 0 -> no maximum
		float _min;				// If value is 0 -> no minimum
		
		
		
		bool _speedModus;		// Use millis() or micros()
		byte _enable_P_I_D;		// Bit 0 -> P Bit 1 -> I Bit 2 -> D
		
		unsigned long _lastTime;
		unsigned long _elapsedTime;
};
#endif