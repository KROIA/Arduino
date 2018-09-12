/*
	Autor	Alex Krieg
	Version 1.0
	Datum 	23.12.2016
*/


#include "Arduino_SPS.h"

SPS::SPS(byte anz_module){
	module = anz_module;
	
	inputRegister 	= new LS165(7,9,10,module);
	outputRegister 	= new HC595(2,5,6,4,3,module);
	pinMode(8,OUTPUT);
	digitalWrite(8,LOW);
	
	dataIn 			= new byte[module];
	dataOut 		= new byte[module];
	
	dataExternIn	= new byte[module];
	dataExternOut	= new byte[module];
}
SPS::~SPS(){
	
}

void 	SPS::write(){
	/*reset();
	byte ausgabe;
	for(int b = module-1; b>=0; b--)
	{
		for(int i = 0; i<8; i++)
		{
		  ausgabe = dataOut[b] & (B00000001 << i);
		  ausgabe = ausgabe >> i;
		  PORTD = (PORTD & B10111111) | (ausgabe << 6);
		  PORTD = (PORTD & B11011111) | B00100000;
		  PORTD = (PORTD & B11011111) | B00000000;
		}
	}
	PORTD = (PORTD & B11110111) | B00001000;
	PORTD = (PORTD & B11110111) | B00000000;*/
	outputRegister->write();
}
void 	SPS::read(){
	/*byte bufferInput = 0;
	
	for(int i= 0; i<module; i++)
	{
		dataIn[i] = 0;
	}
	PORTD = (PORTD & B01111111);
	PORTD = (PORTD & B01111111) | B10000000;
	PORTB = (PORTB & B11111110);
	for(int b=0; b<module; b++)
	{
		for(int i=0; i<8; i++)
		{
			PORTB = (PORTB & B11111101);
			bufferInput = digitalRead(InQ);
			dataIn[b] = (dataIn[b] << 1) + bufferInput;
			PORTB = (PORTB & B11111101) | B00000010;
			delayMicroseconds(1);
		}
	}*/
	inputRegister->read();
}

bool    SPS::input(byte modul,byte pin){			//(1-x,1-8)
	/*if((pin<1)||(pin>8) || (modul < 1) || (modul > module))
	{
		//pin = 1;
		#ifdef DEBUG
		Serial.print("ERROR: getInputPin(");
		Serial.print(modul);
		Serial.print(",");
		Serial.print(pin);
		Serial.println("); -Wert nicht gueltig");
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
	}*/
	if((inputRegister->get(modul) & (B00000001 << pin)) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
byte* 	SPS::input(){
	return inputRegister->get();
}

void 	SPS::output(byte modul,byte pin,bool DATA){
	/*if((pin<1)||(pin>8) || (modul < 1) || (modul > module))
	{
		#ifdef DEBUG
		Serial.print("ERROR: setOutputPin(");
		Serial.print(modul);
		Serial.print(",");
		Serial.print(pin);
		Serial.print(",");
		Serial.print(DATA);
		Serial.println("); -Wert nicht gueltig");
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
	}*/
	if(DATA == true)
	{
		outputRegister->set(modul,(outputRegister->get(modul) | (B00000001 << pin)));
	}
	else
	{
		outputRegister->set(modul,(outputRegister->get(modul) & ~(B00000001 << pin)));
	}
	
}
void 	SPS::output(byte outputData[]){
	/*if(sizeof(outputData)-1 == 8 * module)
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
	}*/
	outputRegister->set(outputData);
}
void 	SPS::output(byte modul,byte DATA){
	/*if(modul >= 1 && modul <= module )
	{
		dataOut[modul-1] = DATA;
	}
	else
	{
		#ifdef DEBUG
		Serial.print("ERROR: setOutputModul(");
		Serial.print(modul);
		Serial.print(",");
		Serial.print(DATA);
		Serial.print(")");
		if(modul < 1)
		{
			Serial.print(" -Modul zu klein");
		}
		else
		{
			Serial.print(" -Modul zu gross");
		}
		#endif
	}*/
	outputRegister->set(modul,DATA);
}
void 	SPS::reset(){
	outputRegister->reset();
}