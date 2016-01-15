#ifndef LEDCUBE_H
#define LEDCUBE_H

#include "Arduino.h"


class ledCube
{
	public:
			
	ledCube(byte SIZE, byte layerPin[], byte ledPin[]);		
	~ledCube(); 
	void init();
	void draw(int Layer,byte leds[]);
	void takt(int value);
	
	
	
	
	
	
	private:
	
	int Takt;		//Wie fiel Zeit vergeht bis der Befehl beendet ist	
	
	byte size;		//Kantenlänge des Cubes
	byte aLed;		//Anzal Led-Pins die angesteuet werden müssen
	byte *led;		//pointer auf die Led's die angesteuert werden	<<Ist ein Array>>
	byte *layer;	//pinter auf die Layers die angesteuert werden	<<Ist ein Array>>
};
#endif