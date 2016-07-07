
/*Intervalometer
Author 			: Alex Krieg
Version			: 1.3.6	
compatibility 	: Hardware 1.0.0
Date			: 4.3.2016

copyright by BlenderEr Informatics®
All rights reserved
*/



#ifndef INTERVALOMETER_H
#define INTERVALOMETER_H

#include "Arduino.h"
#include "button.h"
#include "led.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

	struct Modus
{
	unsigned int interval;
	unsigned long runTime;
	unsigned long pastTime;
	unsigned short modus;
	int toleranz;
	int takt;
	int ldrValue;
	int lastLdrValue;
};

class Intervalometer
{
	public:
		Intervalometer(int bOK,int bUp,int bDown,int blUp,int blDown,int bback,boolean logicLevel,int shuter,int focus,int display,int light,int LDR);
		~Intervalometer();
		void init();
		void run();
		
		void setLight();
		void handleUpButton();
		void handleDownButton();
		void handleLightUpButton();
		void handleLightDownButton();
		void handleOkButton();	
		void handleBackButton();
	
		Button  *p_buttonLightUp;
		Button  *p_buttonLightDown;   
		Button  *p_buttonUp;               
		Button  *p_buttonDown;             
		Button  *p_buttonOk;
		Button 	*p_buttonBack;
	private:
	

	
	
		LiquidCrystal_I2C   *p_lcd;
		Led	*p_led;
	
	
		void checkButtons();
		void reset();
		
		void shoot();
		void focusOn();
		void focusOff();
		
		void displayOff();
		void displayOn();
		
		
		
		//pins
		int focusPin;
		int ldrPin;	
		int shuterPin;
		int displayPin;
		int brightnessPin;
		 
};     

#endif
/*NEUE FUNKTIONEN HINZUFÜGEN:

Um neue Funktionen hinzufügen muss man

1. den neuen Modus deklarieren
	alle Variabeln deklarieren und um "init()" definieren
2. den neuen Modes definieren zb was soll dargestellt werden?
3. alle Buttons die benötigt werden informieren bzw die jeweilige Funktion der in den Buttons schreiben
4. den neuen Modus in den "checkbutton()" eintragen, das heist man definiert wann welcher Button gecheckt wird
5. Im "back" Button die neue Funktion eintragen
*/