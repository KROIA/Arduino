#ifndef CONTROLER.H
#define CONTROLER.H

#include <Arduino.h>
#include "button.h"
#include "Joystick.h"






class Controler
{
	public:
	Controler();
	~Controler();
	
	Button* AButton;
	Button* BButton;
	Button* CButton;
	Button* DButton;
	Button* EButton;
	Button* FButton;
	
	Joystick* joystick;
	
	
	void init();
	void check();
	private:
	
	
};
#endif