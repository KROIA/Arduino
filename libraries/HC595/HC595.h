/*
	Autor:		Alex Krieg
	Version:	1.0
	Datum:		29.01.2018
	
	Für 74HC595N
	
	Qb		--|--U--|--	   VCC 5V
	Qc		--|     |--	   Qa
	Qd		--|     |--	   Serial
	Qe		--|     |--	   !enable
	Qf		--|     |--	   save
	Qg		--|     |--	   clock
	Qh		--|     |--	   reset
	GND	0V	--|-----|--	   SerialOut
*/
#ifndef HC595_H
#define HC595_H

#include "Arduino.h"


class HC595
{
	public:
	HC595(byte enable,byte clk,byte serOut,byte reset,byte save,byte amount);
	~HC595();
	void write();
	void write(const byte &modul,const byte &data);
	void write(const byte *data);
	byte get(const byte &modul);
	byte* get();
    void set(const byte &modul,const byte &data);
	void set(const byte *data);
	void enable();
	void disable();
	void reset();
	void shift(byte count);
	
	
	private:
	void shiftOut();
	void save();
	void clockToggle();
	byte _amount;
	
	byte _enablePin;
	byte _savePin;
	byte _resetPin;
	byte _clockPin;
	byte _serialOutPin;
	
	volatile uint8_t *enablePortPin;
	volatile uint8_t *savePortPin;
	volatile uint8_t *resetPortPin;
	volatile uint8_t *clockPortPin;
	volatile uint8_t *serialOutPortPin;
	
	uint8_t enableBit;
	uint8_t saveBit;
	uint8_t resetBit;
	uint8_t clockBit;
	uint8_t serialOutBit;
	
	byte *data;
};
#endif