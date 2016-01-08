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
		countdown			= 12
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
			int   				light;		//Wert für die helligkeit --> Wenn Wert 256 DisplayLicht = LOW;
			unsigned long  		shootTime;	// in Millisekunden
			unsigned long  		passedTime;	// Bereits abgelaufende Zeit des "shootTime"-Intervalls in Millisekunden
	
			int 				stunden;                 
			int 				minuten;                                                          
			unsigned long 		images;
	
			int 				lastTime;				//In Sekunden		-->		Kann bis zu 24 Stunden --> 86400 Sekunden gehen
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
	};       

#endif
