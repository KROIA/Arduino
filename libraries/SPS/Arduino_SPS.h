#ifndef ARDUINO_SPS_H
#define ARDUINO_SPS_H
#include "Arduino.h"
//#define DEBUG

class SPS
{
	public:
	SPS(int anz_module = 1);
	~SPS();
	void write();
	void init();
	void read();
	
	boolean getInputPin(byte modul,byte pin);
	boolean getOutputPin(byte modul,byte pin);
	
	
	byte* getInput();
	byte* getOutput();
	
	void setOutputPin(byte modul,byte pin,boolean DATA);
	void setOutput(byte outputData[]);
	void setOutputModul(byte modul,byte DATA);
		
	
	
	void writeT();
	byte getOutputT();
	void setOutputTModul(byte modul,byte DATA);
	void setOutputTPin(byte modul,byte pin,boolean DATA);
	void setOutputT(byte outputData[]);
	
	
	private:
	byte rotateByte(byte in);
	
	byte module;
	
	byte InPL;
	byte InQ;
	byte InCP;	
	byte InCE;	

	byte OutMR; 	
	byte OutSHCP;
	byte OutSTCP;
	byte OutOE; 	
	byte OutDS; 	

	byte Out1;
	byte Out2;
	byte Out3;
	byte Out4;
	
	byte *dataIn;
	byte *dataOut;
	byte *dataOutT;
};
#endif