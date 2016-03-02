
/*Intervalometer
Author 			: Alex Krieg
Version			: 1.3.5		
compatibility 	: Hardware 1.0.0
Date			: 2.3.2016

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


enum modes 
	{ 
		IntervallSetzen		= 0, 
		HelligkeitSetzen	= 1, 
		AufnahmezeitSetzen	= 2, 
		Kontrolle1			= 3, 
		Running1			= 4,
		Abschlussinfo1		= 5,
		Hauptmenue			= 6,
		ToleranzSetzen		= 7,
		TaktSetzen			= 8,
		Kontrolle2			= 9,
		Running2			= 10,
		Abschlussinfo2		= 11,
		countdown			= 12,
		
		PushToShoot			= 13,
		
		
		ZeitAusloeser		= 14,
		ZeitAusloeserSetup	= 1,
		ZeitAusloeserRun	= 2,
		
		HauptmenueAuswahl_1	= 1,
		HauptmenueAuswahl_2	= 2,
		HauptmenueAuswahl_3	= 3,
		HauptmenueAuswahl_4	= 4
	};

	
class Intervalometer
	{
		public:
			Intervalometer(int bOK,int bUp,int bDown,int blUp,int blDown,int bback,boolean logicLevel,int shuter,int display,int light,int LDR);
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
		
			void intro();
			void checkButtons();
			void stopRunning();
			void reset();
			void shoot();
			
			LiquidCrystal_I2C   *p_lcd;
			Led	*p_led;
			
			byte kamera[8] = 
			{
				0b00000,
				0b00000,
				0b00011,
				0b11111,
				0b11001,
				0b11001,
				0b11111,
				0b00000
			};
			
			int 				shuterPin;
			int 				displayPin;
			int 				brightnessPin;
			int 				countDown;
					
			short 				mode;
			short 				MenueMode;
			
			
			
			int   				light;		//Wert für die helligkeit --> Wenn Wert 256 DisplayLicht = LOW;
			unsigned long  		shootTime;	// in Millisekunden
			unsigned long  		passedTime;	// Bereits abgelaufende Zeit des "shootTime"-Intervalls in Millisekunden
	
			int 				stunden;                 
			int 				minuten;                                                          
			unsigned long 		images;
	
			long 				lastTime;				//In Sekunden		-->		Kann bis zu 24 Stunden --> 86400 Sekunden gehen
			int 				lastMode;
			float 				lastIntervall;			//In 10/Sekunden		-->		Kann bis zu 10 Minuten --> 6000 10/Sekunden gehen
			
			unsigned long 		currentMillis; 
			unsigned long 		previousMillis;
			unsigned long 		referenceTime;

			const int 			scrollTimer = 500;		//In Ms
			
			
			
			
			
	//------------------BLITZ-----------------\\
			
			int toleranz;
			int takt;
			int ldrPin;
			
			int ldrValue;
			int lastLdrValue;
			
	//----------------PushToShoot--------------\\
	
			
	
	//----------------ZeitAusloeser------------\\
		
			int ZeitAusloeserMode;	//Untermodus 
			unsigned long timeToShoot;		//Time in ms
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