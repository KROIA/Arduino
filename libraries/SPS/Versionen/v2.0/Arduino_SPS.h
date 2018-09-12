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

/*struct IN{
 byte pin;				//Adresse
 bool value; 			//Wert 0-1
};
struct OUT{
 byte pin;				//Adresse
 bool value; 			//Wert 0-1
};*/
typedef void (*onInputChangeFunction)(bool);
typedef void (*onInputRisingFunction)();
typedef void (*onInputFallingFunction)();
typedef void (*onErrorFunction)(byte);
typedef void (*onInputHighFunction)();
typedef void (*onInputLowFunction)();


bool 	AND(bool a,bool b);
bool 	OR(bool a,bool b);
bool 	XOR(bool a,bool b);

#define sps_event_onInputChange	1
#define sps_event_onInputRising 2
#define sps_event_onInputFalling 3
#define sps_event_onError 4
#define sps_event_onInputHigh 5
#define sps_event_onInputLow 6


class SPS
{
	public:
	SPS(byte anz_module);
	~SPS();
	
	void 	setupEvents(byte event,byte amount);
	
	void 	write();
	void 	read();
	
	void 	onInputChange	(unsigned int address,void (*p_func)(bool));
	void 	onInputRising	(unsigned int address,void (*p_func)());
	void 	onInputFalling	(unsigned int address,void (*p_func)());
	void 	onInputHigh		(unsigned int address,void (*p_func)());
	void 	onInputLow		(unsigned int address,void (*p_func)());
	void 	onError			(void (*p_func)(byte));
	
	bool 	input(byte modul,byte pin);
	byte    input(byte modul);
	bool	inputAddress(int address);
	byte* 	input();
	
	void 	output(byte modul,byte pin,bool DATA);
	void 	output(byte outputData[]);
	void 	output(byte modul,byte DATA);
	void 	outputAddress(unsigned int address,bool DATA);
	
	bool 	getOutput(byte modul,byte pin);
	byte    getOutput(byte modul);
	bool	getOutputAddress(int address);
	byte* 	getOutput();
	
	void 	allOff();
	void 	modulOff(byte modul);
	void 	allOn();
	void 	modulOn(byte modul);
	void 	checkEvents();
	
	
	
private:
	void 	error(byte errorCode);
	void 	reset();
	
	byte 	module;
	
	LS165 	*inputRegister;
	HC595	*outputRegister;
	
	byte 	*previousInputs;
	onInputChangeFunction 	*_onInputChange;
	onInputRisingFunction 	*_onInputRising;
	onInputFallingFunction 	*_onInputFalling;
	onInputHighFunction 	*_onInputHigh;
	onInputLowFunction 		*_onInputLow;
	onErrorFunction 		_onError;
	
	byte _onInputChange_amount;
	byte _onInputRising_amount;
	byte _onInputFalling_amount;
	byte _onInputHigh_amount;
	byte _onInputLow_amount;
	
	byte _onInputChange_lastElement;
	byte _onInputRising_lastElement;
	byte _onInputFalling_lastElement;
	byte _onInputHigh_lastElement;
	byte _onInputLow_lastElement;
	
	unsigned int *_onInputChange_pin;
	unsigned int *_onInputRising_pin;
	unsigned int *_onInputFalling_pin;
	unsigned int *_onInputHigh_pin;
	unsigned int *_onInputLow_pin;
	
	byte boolList1;
	
};
#endif

/*
Error Codes:
10 	->	onInputChange() 
11 	->	onInputRising() 
12	->	onInputFalling() 
13	->	onInputHigh()
14 	->	onInputLow();
*/