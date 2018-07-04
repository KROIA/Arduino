/*
	Autor	Alex Krieg
	Version	0.0.1
	Datum 	4.07.2018
*/


#include "sequencer.h"

Sequencer::Sequencer()
{
	_step 			= 0;
	_step_startPos 	= 0;
}
Sequencer::~Sequencer()
{
	this->clear();
}
void Sequencer::startPos(byte startPos)
{
	_step_startPos = startPos;
	if(_step_startPos >= p_func_list.size()){_step_startPos = p_func_list.size()-1;}
}
byte Sequencer::startPos()
{
	return _step_startPos;
}
void Sequencer::add(seq_p_func p_func)
{
	if(p_func != NULL)
	{
		p_func_list.push_back(p_func);
	}
}	
void Sequencer::step(byte step)
{
	_step = step;
	if(_step >= p_func_list.size()){_step = p_func_list.size()-1;}
}
void Sequencer::clear()
{
	p_func_list.clear();
}
void Sequencer::stepUp()
{
	_step++;
	if(p_func_list.size() <= _step){_step = _step_startPos;}
}
void Sequencer::stepDown()
{
	if(p_func_list.size() <= _step_startPos)
	{
		_step = p_func_list.size()-1;
	}
	else
	{
		_step--;
	}
}
byte Sequencer::step()
{
	return _step;
}
byte Sequencer::run()
{
	if(p_func_list[_step] != NULL)
	{
		(*p_func_list[_step])();
	}
}