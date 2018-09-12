/*
	Autor	Alex Krieg
	Version 1.0
	Datum 	23.12.2016
*/

#ifndef ARDUINO_SPS_H
#define ARDUINO_SPS_H
#include "Arduino.h"

#define DEBUG
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
	SPS(int anz_module = 1);
	~SPS();

	void 	write();
	void 	init();
	void 	read();
	boolean getInputPin(byte modul,byte pin);
	boolean getOutputPin(byte modul,byte pin);
	byte* 	getInput();
	byte* 	getOutput();
	void 	setOutputPin(byte modul,byte pin,boolean DATA);
	void 	setOutput(byte outputData[]);
	void 	setOutputModul(byte modul,byte DATA);
private:
	void 	reset();
	byte 	rotateByte(byte in);
	byte 	module;
	byte 	InPL;
	byte 	InQ;
	byte 	InCP;	
	byte 	InCE;
	byte 	OutSRCLR;
	byte 	OutSRCLK;
	byte 	OutRCLK; 
	byte 	OutOE; 	
	byte 	OutSER; 	
	
	byte	*dataIn;
	byte 	*dataOut;
	
	int 	*dataExternIn;		//
	byte 	*dataExternOut;		//von var.h
};
#endif