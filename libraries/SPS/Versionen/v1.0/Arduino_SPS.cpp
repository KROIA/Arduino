/*
	Autor	Alex Krieg
	Version 1.0
	Datum 	23.12.2016
*/


#include "Arduino_SPS.h"

SPS::SPS(int anz_module){
	InPL 		= 7;
	InQ  		= 10;
	InCP 		= 9;
	InCE 		= 8;
	
	OutSRCLR  	= 4;
	OutSRCLK 	= 5;
	OutRCLK 	= 3;
	OutOE 		= 2;
	OutSER 		= 6;

	
	module 		= anz_module;
	dataIn 		= new byte[module];
	dataOut 	= new byte[module];
	
	dataExternIn= new int[module];
	dataExternOut= new byte[module];
	
	init();
 
}
SPS::~SPS(){
	
}

void 	SPS::init(){
 pinMode(A0,OUTPUT);
 pinMode(A1,OUTPUT);
 pinMode(A2,OUTPUT);
 pinMode(A3,OUTPUT);
 
 pinMode(InPL,OUTPUT);
 pinMode(InQ,INPUT);
 pinMode(InCP,OUTPUT);
 pinMode(InCE,OUTPUT);
 
 pinMode(OutSRCLR ,OUTPUT);
 pinMode(OutSRCLK,OUTPUT);
 pinMode(OutRCLK,OUTPUT);
 pinMode(OutOE,OUTPUT);
 pinMode(OutSER,OUTPUT);
 

 

 
 digitalWrite(OutSRCLR ,HIGH);
 digitalWrite(OutOE,LOW);
 
 digitalWrite(InPL,HIGH);
 digitalWrite(InCE,HIGH);
 digitalWrite(InCP,LOW);
	
}
void 	SPS::write(){
	reset();
	#ifdef DEBUG
		Serial.print("Output: \t");
		for(int b=0; b<module; b++)
		{
			for(byte i=0; i<8; i++)
			{
				Serial.print((dataOut[b] & (B10000000 >> i))>>(7-i));
			}
			Serial.print(" ");
		}
		Serial.println("");
    #endif
	
	byte ausgabe;
	for(int b = module-1; b>=0; b--)
	{
		for(int i = 0; i<8; i++)
		{
		  ausgabe = dataOut[b] & (B00000001 << i);
		  ausgabe = ausgabe >> i;
		  //Serial.println(ausgabe << 6,BIN);
		  PORTD = (PORTD & B10111111) | (ausgabe << 6);
		  PORTD = (PORTD & B11011111) | B00100000;
		  PORTD = (PORTD & B11011111) | B00000000;
		  
		  //digitalWrite(OutSER,ausgabe);
		 //digitalWrite(OutSRCLK,HIGH);
		// digitalWrite(OutSRCLK,LOW);
		}
	}
	
	PORTD = (PORTD & B11110111) | B00001000;
	PORTD = (PORTD & B11110111) | B00000000;
	//writeT();
  //digitalWrite(OutRCLK,HIGH);
  //digitalWrite(OutRCLK,LOW);
}
void 	SPS::read(){
	byte bufferInput = 0;
	
	for(int i= 0; i<module; i++)
	{
		dataIn[i] = 0;
	}
	PORTD = (PORTD & B01111111);
	PORTD = (PORTD & B01111111) | B10000000;
	
	//digitalWrite(InPL,LOW);      //speichern
	//digitalWrite(InPL,HIGH);
  
	PORTB = (PORTB & B11111110);
	
    //digitalWrite(InCE,LOW);      //auslesen
	
	for(int b=0; b<module; b++)
	{
		for(int i=0; i<8; i++)
		{
			PORTB = (PORTB & B11111101);
			//digitalWrite(InCP,LOW);
			bufferInput = digitalRead(InQ);
			dataIn[b] = (dataIn[b] << 1) + bufferInput;
			PORTB = (PORTB & B11111101) | B00000010;
			//digitalWrite(InCP,HIGH);
			delayMicroseconds(1);
		}
	}
	#ifdef DEBUG
		Serial.print("Input: \t\t");
		for(int b=0; b<module; b++)
		{
			for(byte i=0; i<8; i++)
			{
				Serial.print((dataIn[b] & (B10000000 >> i))>>(7-i));
			}
			Serial.print(" ");
		}
		Serial.println("");
    #endif
}
boolean SPS::getInputPin(byte modul,byte pin){			//(1-x,1-8)
	if((pin<1)||(pin>8) || (modul < 1) || (modul > module))
	{
		//pin = 1;
		#ifdef DEBUG
		Serial.print("ERROR: getInputPin(");
		Serial.print(modul);
		Serial.print(",");
		Serial.print(pin);
		Serial.println("); -Wert nicht gültig");
		#endif
	}
	else
	{
		boolean retValue = false;
		if(((dataIn[modul-1] & (B10000000 >> pin-1))) > 0)
		{
			retValue = true;
		}
		
		return retValue;
	}
	return 0;
}
boolean SPS::getOutputPin(byte modul,byte pin){
	if((pin<1)||(pin>8) || (modul < 1) || (modul > module))
	{
		//pin = 1;
		#ifdef DEBUG
		Serial.print("ERROR: getOutputPin(");
		Serial.print(modul);
		Serial.print(",");
		Serial.print(pin);
		Serial.println("); -Wert nicht gültig");
		#endif
	}
	else
	{
		boolean retValue = false;
		if(((dataOut[modul-1] & (B10000000 >> pin-1))) > 0)
		{
			retValue = true;
		}
		return retValue;
	}
	return 0;
}
void 	SPS::setOutputPin(byte modul,byte pin,boolean DATA){
	if((pin<1)||(pin>8) || (modul < 1) || (modul > module))
	{
		//pin = 1;
		#ifdef DEBUG
		Serial.print("ERROR: setOutputPin(");
		Serial.print(modul);
		Serial.print(",");
		Serial.print(pin);
		Serial.print(",");
		Serial.print(DATA);
		Serial.println("); -Wert nicht gültig");
		#endif
	}
	else
	{
		byte x = 0;
		switch(pin)
		{
			case 1:{x = B01111111;break;}
			case 2:{x = B10111111;break;}
			case 3:{x = B11011111;break;}
			case 4:{x = B11101111;break;}
			case 5:{x = B11110111;break;}
			case 6:{x = B11111011;break;}
			case 7:{x = B11111101;break;}
			case 8:{x = B11111110;break;}
		}
		dataOut[modul-1] = (dataOut[modul-1] & x) | (DATA<<(8-pin));
	}
}
byte* 	SPS::getInput(){
	return dataIn;
}
byte* 	SPS::getOutput(){
	return dataOut;
}
void 	SPS::setOutput(byte outputData[]){
	if(sizeof(outputData)-1 == 8 * module)
	{
		dataOut = outputData;
	}
	else
	{
		#ifdef DEBUG
		Serial.print("ERROR: setOutput(");
		if(sizeof(outputData)-1 < 8 * module)
		{
			Serial.println("ARRAY); -Array zu klein");
		}
		else
		{
			Serial.println("ARRAY); -Array zu gross");
		}
		#endif
	}
}
void 	SPS::setOutputModul(byte modul,byte DATA){
	if(modul >= 1 && modul <= module )
	{
		dataOut[modul-1] = DATA;
	}
	else
	{
		#ifdef DEBUG
		Serial.print("ERROR: setOutputModul(");
		Serial.print(modul);
		Serial.print(",");
		Serial.print(modul);
		if(modul < 1)
		{
			Serial.print("); -Modul zu klein");
		}
		else
		{
			Serial.print("); -Modul zu gross");
		}
		#endif
	}
}
byte 	SPS::rotateByte(byte in){
	byte out = 0;
	
	out = out + ((in & B10000000)>>7);
	out = out + ((in & B01000000)>>5);
	out = out + ((in & B00100000)>>3);
	out = out + ((in & B00010000)>>1);
	out = out + ((in & B00001000)<<1);
	out = out + ((in & B00000100)<<3);
	out = out + ((in & B00000010)<<5);
	out = out + ((in & B00000001)<<7);
	
	out = out >> 4;
	return out;
}
void 	SPS::reset(){
	//digitalWrite(OutSRCLR,LOW);
	//digitalWrite(OutSRCLR,HIGH);
	
	PORTD = (PORTD & B11101111) | B00000000;
	//delayMicroseconds(10);
	PORTD = (PORTD & B11101111) | B00010000;
}