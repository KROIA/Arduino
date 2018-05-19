#include "Arduino_SPS.h"

SPS::SPS(int anz_module)
{
	InPL 		= 7;
	InQ  		= 10;
	InCP 		= 9;
	InCE 		= 8;
	
	OutMR 		= 4;
	OutSHCP 	= 5;
	OutSTCP 	= 3;
	OutOE 		= 2;
	OutDS 		= 6;
	
	Out1 		= A0;
	Out2 		= A1;
	Out3 		= A2;
	Out4 		= A3;
	
	module 		= anz_module;
	dataIn 		= new byte[module];
	dataOut 	= new byte[module];
	dataOutT 	= new byte[1];
	
	init();
 
}
SPS::~SPS()
{
	
}
void SPS::init()
{
 pinMode(A0,OUTPUT);
 pinMode(A1,OUTPUT);
 pinMode(A2,OUTPUT);
 pinMode(A3,OUTPUT);
 
 pinMode(InPL,OUTPUT);
 pinMode(InQ,INPUT);
 pinMode(InCP,OUTPUT);
 pinMode(InCE,OUTPUT);
 
 pinMode(OutMR,OUTPUT);
 pinMode(OutSHCP,OUTPUT);
 pinMode(OutSTCP,OUTPUT);
 pinMode(OutOE,OUTPUT);
 pinMode(OutDS,OUTPUT);
 
 pinMode(Out1,OUTPUT);
 pinMode(Out2,OUTPUT);
 pinMode(Out3,OUTPUT);
 pinMode(Out4,OUTPUT);
 
 delayMicroseconds(1);
 digitalWrite(Out1,HIGH);
 delayMicroseconds(1);
 digitalWrite(Out1,LOW);
 digitalWrite(Out2,HIGH);
 delayMicroseconds(1);
 digitalWrite(Out2,LOW);
 digitalWrite(Out3,HIGH);
 delayMicroseconds(1);
 digitalWrite(Out3,LOW);
 digitalWrite(Out4,HIGH);
 delayMicroseconds(1);
 digitalWrite(Out4,LOW);
 
 digitalWrite(OutMR,HIGH);
 digitalWrite(OutOE,LOW);
 
 digitalWrite(InPL,HIGH);
 digitalWrite(InCE,HIGH);
 digitalWrite(InCP,LOW);
	
}
void SPS::write()
{
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
	byte sizeOfArray = module;
	byte ausgabe;
	for(int b = sizeOfArray; b>=0; b--)
	{
		for(int i = 0; i<8; i++)
		{
		  ausgabe = dataOut[b] & (B00000001 << i);
		  ausgabe = ausgabe >> i;
		  //Serial.println(ausgabe << 6,BIN);
		  PORTD = (PORTD & B10111111) | (ausgabe << 6);
		  PORTD = (PORTD & B11011111) | B00100000;
		  PORTD = (PORTD & B11011111) | B00000000;
		  
		  //digitalWrite(OutDS,ausgabe);
		 //digitalWrite(OutSHCP,HIGH);
		// digitalWrite(OutSHCP,LOW);
		}
	}
	
	PORTD = (PORTD & B11110111) | B00001000;
	PORTD = (PORTD & B11110111) | B00000000;
	writeT();
  //digitalWrite(OutSTCP,HIGH);
  //digitalWrite(OutSTCP,LOW);
}
void SPS::read()
{
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
boolean SPS::getInputPin(byte modul,byte pin)			//(1-x,1-8)
{
	if((pin<1)||(pin>8))
	{
		pin = 1;
	}
	boolean retValue = false;
	if(((dataIn[modul-1] & (B10000000 >> pin-1))) > 0)
	{
		retValue = true;
	}
	
	return retValue;
}
boolean SPS::getOutputPin(byte modul,byte pin)
{
	if((pin<1)||(pin>8))
	{
		pin = 1;
	}
	boolean retValue = false;
	if(((dataOut[modul-1] & (B10000000 >> pin-1))) > 0)
	{
		retValue = true;
	}
	
	return retValue;
}
void SPS::setOutputPin(byte modul,byte pin,boolean DATA)
{
	if((pin<1)||(pin>8))
	{
		pin = 1;
	}
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
	#ifdef DEBUG
	Serial.println(dataOut[modul-1]);
	#endif
}
byte* SPS::getInput()
{
	return dataIn;
}
byte* SPS::getOutput()
{
	return dataOut;
}
void SPS::setOutput(byte outputData[])
{
	dataOut = outputData;
}
void SPS::setOutputModul(byte modul,byte DATA)
{
	dataOut[modul-1] = DATA;
}
void SPS::writeT(){
	
	PORTC = (PORTC & B11110000) | dataOutT[0];
}
byte SPS::getOutputT(){
	//BAUSTELLE
	return rotateByte(dataOutT[0]);
}
void SPS::setOutputTModul(byte modul,byte DATA){
	/*BAUSTELLE*/
	modul = 1;
	dataOutT[modul-1] = rotateByte(DATA);
}
void SPS::setOutputTPin(byte modul,byte pin,boolean DATA){
	
	//BAUSTELLE
	modul = 1;
	//BAUSTELLE
	
	modul--;
	if(DATA == true)
	{
		switch(pin)
		{
			case 1:
			{			
				dataOutT[modul]   =  (dataOutT[modul] & B00001111) | (B00000001);
				break;
			}
			case 2:
			{
				dataOutT[modul]   =  (dataOutT[modul] & B00001111) | (B00000010);
				break;                                                    
			}                                                             
			case 3:                                                       
			{                                                             
				dataOutT[modul]   =  (dataOutT[modul] & B00001111) | (B00000100);
				break;                                                    
			}                                                             
			case 4:                                                       
			{                                                             
				dataOutT[modul]   =  (dataOutT[modul] & B00001111) | (B00001000);
				break;
			}
			
		}
	}
	else
	{
		switch(pin)
		{
			case 1:
			{			
				dataOutT[modul]   =  dataOutT[modul] & B00001110;
				break;                                   
			}                                            
			case 2:                                      
			{                                            
				dataOutT[modul]   =  dataOutT[modul] & B00001101;
				break;                                            
			}                                                     
			case 3:                                               
			{                                                     
				dataOutT[modul]   =  dataOutT[modul] & B00001011;
				break;                                            
			}                                                     
			case 4:                                               
			{                                                     
				dataOutT[modul]   =  dataOutT[modul] & B00000111;
				break;
			}
			
		}
	}
	//dataOutT[modul] = rotateByte(dataOutT[modul]);
}
void SPS::setOutputT(byte outputData[]){
	boolean error = false;
	for(int i = 0; i<module; i++)
	{
		if(outputData[i] > B00001111)
		{
			error = true; 
			//ERROR
		}
	}
	if(!error)
	{
		//BAUSTELLE
		dataOutT[0] = rotateByte(outputData[0]);
	}
}
byte SPS::rotateByte(byte in)
{
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