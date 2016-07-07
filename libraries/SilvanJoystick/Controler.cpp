#include "Controler.h"
#include <Arduino.h>

 Controler::Controler()
{
	AButton = new Button(2, activeLow);	
	BButton = new Button(3, activeLow);	
	CButton = new Button(4, activeLow);	
	DButton = new Button(5, activeLow);	
	EButton = new Button(6, activeLow);	
	FButton = new Button(7, activeLow);	

	joystick = new Joystick(A0,A1,8,activeLow);
	
	
	
	
	
}
 Controler::~Controler()
{}
void Controler::init()
{
	AButton->init();
	BButton->init();
	CButton->init();
	DButton->init();
	EButton->init();
	FButton->init();
	joystick->init();
}
void Controler::check()
{
	AButton->checkButton();
	BButton->checkButton();
	CButton->checkButton();
	DButton->checkButton();
	EButton->checkButton();
	FButton->checkButton();
	
	joystick->check();
}