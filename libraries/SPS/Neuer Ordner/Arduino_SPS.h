/*
	Autor	Alex Krieg
	Version 2.0
	Datum 	29.01.2018
*/

#ifndef ARDUINO_SPS_H
#define ARDUINO_SPS_H


#include "Arduino.h"
#include "bitBool.h"
#include "LS165.h"	//Version 1.0
#include "HC595.h"	//Version 1.0

struct IN{
 byte pin;				//Adresse
 bool value; 			//Wert 0-1
};
struct OUT{
 byte pin;				//Adresse
 bool value; 			//Wert 0-1
};
class SPS
{
	public:
	SPS(byte anz_module = 1);
	~SPS();

	void 	write();
	void 	read();
	
	bool 	input(byte modul,byte pin);
	byte* 	input();
	
	void 	output(byte modul,byte pin,bool DATA);
	void 	output(byte outputData[]);
	void 	output(byte modul,byte DATA);
private:
	void 	reset();
	byte 	module;
	
	byte	*dataIn;
	byte 	*dataOut;
	
	byte 	*dataExternIn;		//
	byte 	*dataExternOut;		//von var.h
	
	LS165 	*inputRegister;
	HC595	*outputRegister;
};
#endif