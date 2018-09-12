/*
	Autor:		Alex Krieg
	Version:	1.0
	Datum:		29.01.2018
*/
#include "HC595.h"



HC595::HC595(byte enable,byte clk,byte serOut,byte reset,byte save,byte amount)
{
	_enablePin 		= enable;
	_savePin 		= save;
	_resetPin		= reset;
	_clockPin		= clk;
	_serialOutPin	= serOut;
	_amount			= amount;
	
	
	pinMode(_enablePin		,OUTPUT);
	pinMode(_savePin 		,OUTPUT);
	pinMode(_resetPin		,OUTPUT);
	pinMode(_clockPin		,OUTPUT);
	pinMode(_serialOutPin	,OUTPUT);
	
	
	
	
	
	
	
	enablePortPin		=	portOutputRegister(digitalPinToPort(_enablePin));
	savePortPin			=	portOutputRegister(digitalPinToPort(_savePin));
	resetPortPin		=	portOutputRegister(digitalPinToPort(_resetPin));
	clockPortPin		=	portOutputRegister(digitalPinToPort(_clockPin));
	serialOutPortPin	=	portOutputRegister(digitalPinToPort(_serialOutPin));
	
	enableBit 			= digitalPinToBitMask(_enablePin);
	saveBit 			= digitalPinToBitMask(_savePin);
	resetBit 			= digitalPinToBitMask(_resetPin);
	clockBit 			= digitalPinToBitMask(_clockPin);
	serialOutBit		= digitalPinToBitMask(_serialOutPin);
	
	data				= new byte[_amount];
	for(byte a=0; a<_amount; a++)
	{
		data[a] = 0;
	}
	
	this->disable();
	this->reset();
	this->save();
}
HC595::~HC595()
{
	delete data;
	delete enablePortPin;
	delete savePortPin;
	delete resetPortPin;
	delete clockPortPin;
	delete serialOutPortPin;
}
void HC595::write()
{
	shiftOut();
}
void HC595::write(byte modul, byte data)
{
	set(modul,data);
	shiftOut();
}
void HC595::write(byte *data)
{
	set(data);
	shiftOut();
}
byte HC595::get(byte modul)
{
	if(modul >= _amount || modul < 0)
	{
		modul = 0;
	}
	return data[modul];
}
byte *HC595::get()
{
	return data;
}
void HC595::set(byte modul,byte data)
{
	if(modul >= _amount || modul < 0)
	{
		modul = 0;
	}
	this->data[modul] = data;
}
void HC595::set(byte *data)
{
	if(sizeof(data) == _amount)
	{
		for(byte a=0; a<_amount; a++)
		{
			set(a,data[a]);
		}
	}
}
void HC595::enable()
{
	*enablePortPin &= ~enableBit;
}
void HC595::disable()
{
	*enablePortPin |= enableBit;
}
void HC595::reset()
{
	*resetPortPin &= ~resetBit;
	save();
	*resetPortPin |= resetBit;
	enable();
}
void HC595::shift(byte count)
{
	for(byte a=0; a<count; a++)
	{
		clockToggle();
	}
	save();
	enable();
}
void HC595::shiftOut()
{
	//disable();
	//Serial.print("amount: ");
	//Serial.println(_amount);
	for(byte a=_amount; a>0; a--)
	{
		//Serial.println(a);
		for(byte b=0; b<8; b++)
		{
			if((data[a-1] & (B00000001 << b)) > 0)
			{
				*serialOutPortPin |= serialOutBit;
			}
			else
			{
				*serialOutPortPin &= ~serialOutBit;
			}
			clockToggle();
		}
	}
	*serialOutPortPin &= ~serialOutBit;
	save();
	enable();
}
void HC595::save()
{
	*savePortPin |= saveBit;
	*savePortPin &= ~saveBit;
}
void HC595::clockToggle()
{
	*clockPortPin |= clockBit;
	*clockPortPin &= ~clockBit;
}