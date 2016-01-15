#ifndef LEDCUBE3_H
#define LEDCUBE3_H

#include "Arduino.h"

class ledCube_3
{
	public:
	ledCube_3(int pinLed1,	   int pinLed2,	   int pinLed3,
			int pinLed4,	   int pinLed5,	   int pinLed6,	   
			int pinLed7,	   int pinLed8,	   int pinLed9,	   
			int pinLayer1,	   int pinLayer2,  int pinLayer3);
	~ledCube_3();
	void init();
	void draw(byte LED13,byte LED23,byte LED33,byte LED43, byte LED53,byte LED63,byte LED73,byte LED83,byte LED93,
			  byte LED12,byte LED22,byte LED32,byte LED42, byte LED52,byte LED62,byte LED72,byte LED82,byte LED92,
			  byte LED11,byte LED21,byte LED31,byte LED41, byte LED51,byte LED61,byte LED71,byte LED81,byte LED91);
	void Takt(int value);
	int takt;
	
	int pin[9];
	int layer[3];
	
	int led1;
	int led2;
	int led3;
	int led4;
	int led5;
	int led6;
	int led7;
	int led8;
	int led9;
	 
	
	
	private:
	
	void setLayer(byte Layer, byte LED1, byte LED2, byte LED3, byte LED4, byte LED5, byte LED6, byte LED7, byte LED8, byte LED9);
	void dWrite(int LAYER);
	int ledLayer;
	
	
};
#endif
