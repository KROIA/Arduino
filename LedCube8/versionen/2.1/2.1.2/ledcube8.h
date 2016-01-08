// Autor: 									Alex Krieg
// Erstellt:								24.11.2015
// Version 									2.1.2
// Kompatibel mit den versionen: 			2.0.0  2.1.0
// Funktionen:								Siehe Versionsverlauf

#ifndef LEDCUBE8_H
#define LEDCUBE8_H
#include "Arduino.h"

class LedCube8
{
	public:
		 LedCube8(byte flipfloppin[],byte ledadress[],byte layeradresspin[]);
		 ~LedCube8();
	void init();
	void draw(byte layer, byte a, byte b, byte c, byte d, byte e, byte f, byte g, byte h);
	void drawCube(byte E8a,byte E8b,byte E8c,byte E8d,byte E8e,byte E8f,byte E8g,byte E8h, 
	                       byte E7a,byte E7b,byte E7c,byte E7d,byte E7e,byte E7f,byte E7g,byte E7h,
	                       byte E6a,byte E6b,byte E6c,byte E6d,byte E6e,byte E6f,byte E6g,byte E6h,
	                       byte E5a,byte E5b,byte E5c,byte E5d,byte E5e,byte E5f,byte E5g,byte E5h,
	                       byte E4a,byte E4b,byte E4c,byte E4d,byte E4e,byte E4f,byte E4g,byte E4h,
	                       byte E3a,byte E3b,byte E3c,byte E3d,byte E3e,byte E3f,byte E3g,byte E3h,
	                       byte E2a,byte E2b,byte E2c,byte E2d,byte E2e,byte E2f,byte E2g,byte E2h,
	                       byte E1a,byte E1b,byte E1c,byte E1d,byte E1e,byte E1f,byte E1g,byte E1h);
	
	void drawLayer(byte layer);
	void drawWall(byte wall);
	void drawWall90(byte wall);
	void shiftLayerR(int count,byte layer,bool reload, byte a, byte b, byte c, byte d, byte e, byte f, byte g, byte h);
	void shiftCubeR(int count,bool reload,byte E8a,byte E8b,byte E8c,byte E8d,byte E8e,byte E8f,byte E8g,byte E8h, 
								byte E7a,byte E7b,byte E7c,byte E7d,byte E7e,byte E7f,byte E7g,byte E7h,
								byte E6a,byte E6b,byte E6c,byte E6d,byte E6e,byte E6f,byte E6g,byte E6h,
								byte E5a,byte E5b,byte E5c,byte E5d,byte E5e,byte E5f,byte E5g,byte E5h,
								byte E4a,byte E4b,byte E4c,byte E4d,byte E4e,byte E4f,byte E4g,byte E4h,
								byte E3a,byte E3b,byte E3c,byte E3d,byte E3e,byte E3f,byte E3g,byte E3h,
								byte E2a,byte E2b,byte E2c,byte E2d,byte E2e,byte E2f,byte E2g,byte E2h,
								byte E1a,byte E1b,byte E1c,byte E1d,byte E1e,byte E1f,byte E1g,byte E1h);
	
	void light(byte L);
	void time(int t);
	
	private:
	
	byte countAddress();				//zählt "counter" um 1 hoch
	void setPin(byte pin, byte address);				//setzt pins bei den pins 2-9
	void saveToFlipFlop(byte address);				//setzt pins in Binär bei 10-13
	void setLayer(byte layer,int T,int multiplikator);					//setzt pins in Binär bei A0-A4
	void setLight();
	
	byte *ledpin;
	byte *ledAddresspin;
	byte *layerpin;
	
	byte led;
	byte ledAddress;
	byte layerAddress;
	
	byte counter;
	byte helligkeit;
	unsigned long Time;
	unsigned long TimeMicro;
	
	
	
	unsigned long startMillis;
	unsigned long referenzMillis;
	unsigned long benotigtMillis;
};
#endif