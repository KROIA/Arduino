#ifndef LEDCUBE8_H
#define LEDCUBE8_H
#include "Arduino.h"

class LedCube8
{
	public:
		 LedCube8(byte flipfloppin[],byte ledadress[],byte layeradresspin[]);
		 ~LedCube8();
	void init();
	void draw(byte layer,int time, byte a, byte b, byte c, byte d, byte e, byte f, byte g, byte h);
	
	
	private:
	
	byte countAddress();				//zählt "counter" um 1 hoch
	void setPin(byte pin);				//setzt pins bei den pins 2-9
	void saveToFlipFlop();				//setzt pins in Binär bei 10-13
	void setLayer(byte layer,int time);					//setzt pins in Binär bei A0-A4
	
	byte *ledpin;
	byte *ledAddresspin;
	byte *layerpin;
	
	byte led;
	byte ledAddress;
	byte layerAddress;
	
	byte counter;
};
#endif