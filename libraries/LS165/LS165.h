/*
	Autor:		Alex Krieg
	Version:	1.0
	Datum:		29.01.2018
	
	Für 74LS165AN
	
	enable	--|--U--|--		VCC 5V
	clock	--|		|--		pullDownRes
	E		--|		|--		D
	F		--|		|--		C
	G		--|		|--		B
	H		--|		|--		A
	open	--|		|--		SER
	GND	0V	--|-----|--		serIn
*/
#ifndef LS165_H
#define LS165_H

#include "Arduino.h"
#include "bitBool.h"
byte rotateByte(byte data);

class LS165
{
	public:
	LS165(byte enable,byte clk,byte serIn,byte amount);
	~LS165();
	
	
	void read();
	void enable();
	void disable();
	
	byte get(byte modul);
	byte* get();
	
	
	
	private:
	byte _amount;
	byte _enablePin;
	byte _clockPin;
	byte _serialInPin;
	byte *inputData;
	
	byte boolList1;
	
	
	volatile uint8_t *enablePortPin;
	volatile uint8_t *clockPortPin;
	
	uint8_t enableBit;
	uint8_t clockBit;
};
#endif


/* boolLost1:
0:	enable



*/