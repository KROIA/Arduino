/*
	Autor	Alex Krieg
	Version	0.0.1
	Datum 	4.07.2018
*/


#ifndef SEQUENCER_H
#define SEQUENCER_H

#include "Arduino.h"
#include "vector.h"


typedef void (*seq_p_func)(void);


class Sequencer
{
	public:
		Sequencer();
		~Sequencer();
		void startPos(byte startPos);
		byte startPos();
		void add(seq_p_func p_func);
		void clear();
		void stepUp();
		void stepDown();
		void step(byte step);
		byte step();
		byte run();
		
	private:
		Vector<seq_p_func>  p_func_list;
		byte _step;
		byte _step_startPos;
};
#endif