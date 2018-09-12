/*
	Autor:		Alex Krieg
	Version:	1.0
	Datum:		29.01.2018
	
	Für 74LS165AN
*/
#include "LS165.h"


LS165::LS165(byte enable,byte clk,byte serIn,byte amount)
{
	_enablePin	= enable;
	_clockPin	= clk;
	_serialInPin= serIn;
	_amount		= amount;
	boolList1	= 0;
	
	inputData 	= new byte[amount];
	
	pinMode(_enablePin	,OUTPUT);
	pinMode(_clockPin	,OUTPUT);
	pinMode(_serialInPin,INPUT);
	
	
	uint8_t portEnable 	= 	digitalPinToPort(_enablePin);
	uint8_t portClock	= 	digitalPinToPort(_clockPin);
	enablePortPin		=	portOutputRegister(portEnable);
	clockPortPin		=	portOutputRegister(portClock);
	
	enableBit 			= digitalPinToBitMask(_enablePin);
	clockBit 			= digitalPinToBitMask(_clockPin);
	for(byte a=0; a<_amount; a++)
	{
		inputData[a] = 0;
	}
	disable();
	digitalWrite(_clockPin	,LOW);	
}
LS165::~LS165()
{
	delete inputData;
	delete enablePortPin;
	delete clockPortPin;
}
void LS165::read()
{
	if(BB_READ(boolList1,BB_0)==false)
	{
		enable();
		disable();
	}
	else
	{
		disable();
	}
	for(byte a=0; a<_amount; a++)
	{
		byte inputBuffer = 0;
		for(byte b=0; b<8; b++)
		{
			inputBuffer |= digitalRead(_serialInPin) << b;
			//inputBuffer |= ((PING & B00100000)>>5)<<b;
			
			//digitalWrite(_clockPin,HIGH);
			//digitalWrite(_clockPin,LOW);
			
			
			*clockPortPin |= clockBit;
			*clockPortPin &= ~clockBit;
			//PORTE = (PORTE & B11011111) | B00100000;
			//PORTE = PORTE & B11011111;
		}
		inputData[a] = inputBuffer;
	}
}
void LS165::enable()
{
	//digitalWrite(_enablePin,LOW);
	//PORTE = PORTE & B11101111;
	*enablePortPin &= ~enableBit;
	BB_TRUE(boolList1,BB_0);
}
void LS165::disable()
{
	//PORTE = (PORTE & B11101111) | B00010000;
	//digitalWrite(_enablePin,HIGH);
	*enablePortPin |= enableBit;
	BB_FALSE(boolList1,BB_0);
}
byte LS165::get(byte modul)
{
	if(modul >= _amount || modul < 0)
	{
		modul = 0;
	}
	return inputData[modul];
}
byte* LS165::get()
{
	return inputData;
}
byte rotateByte(byte data)
{
	
	byte ret = 0;
	for(byte a=0; a<8; a++)
	{
		if((data & (B00000001<<a)) > 0)
		{
			ret |= B10000000>>a;
		}
	}
	return ret;
}
