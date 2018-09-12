/*
	Autor	Alex Krieg
	Version 2.0
	Datum 	29.01.2018
*/


#include "Arduino_SPS.h"

SPS::SPS(byte anz_module){
	module = anz_module;
	
	inputRegister 	= new LS165(7,9,10,module);
	outputRegister 	= new HC595(2,5,6,4,3,module);
	pinMode(8,OUTPUT);
	digitalWrite(8,LOW);
	
	_onInputChange_amount     		= 255;
	_onInputRising_amount	  		= 255;
	_onInputFalling_amount    		= 255;
	_onInputHigh_amount    			= 255;
	_onInputLow_amount    			= 255;
	
	_onInputChange_lastElement     	= 255;
	_onInputRising_lastElement	   	= 255;
	_onInputFalling_lastElement    	= 255;
	_onInputHigh_lastElement    	= 255;
	_onInputLow_lastElement    		= 255;
	
	boolList1 = 0;
	_onError  = NULL;
	
	//_onInputChange = new onInputChangeFunction[module*8];
	previousInputs = new byte[module];
	for(int a=0; a<module; a++)
	{
		previousInputs[a] = 0;
	}
	
	allOff();
}
SPS::~SPS(){
	delete inputRegister;
	delete outputRegister;
	delete _onInputChange;
	delete _onInputRising;
	delete _onInputFalling;
	delete _onInputHigh;
	delete _onInputLow;
	delete previousInputs;
}
void 	SPS::setupEvents(byte event,byte amount)
{
	if(amount == 255)
	{
		amount = 254;
	}
	switch(event)
	{
		case sps_event_onInputChange:
		{
			if(_onInputChange_amount == 255)
			{
				_onInputChange_amount = amount;
				_onInputChange = new onInputChangeFunction[_onInputChange_amount];
				_onInputChange_pin = new unsigned int[_onInputChange_amount];
				for(int a=0; a<_onInputChange_amount; a++)
				{
					_onInputChange[a] = NULL;
					_onInputChange_pin[a] = 0;
				}
			}
			break;
		}
		case sps_event_onInputRising:
		{
			if(_onInputRising_amount == 255)
			{
				_onInputRising_amount = amount;
				_onInputRising = new onInputRisingFunction[_onInputRising_amount];
				_onInputRising_pin = new unsigned int[_onInputRising_amount];
				for(int a=0; a<_onInputRising_amount; a++)
				{
					_onInputRising[a] = NULL;
					_onInputRising_pin[a] = 0;
				}
			}
			break;
		}
		case sps_event_onInputFalling:
		{
			if(_onInputFalling_amount == 255)
			{
				_onInputFalling_amount = amount;
				_onInputFalling = new onInputFallingFunction[_onInputFalling_amount];
				_onInputFalling_pin = new unsigned int[_onInputFalling_amount];
				for(int a=0; a<_onInputFalling_amount; a++)
				{
					_onInputFalling[a] = NULL;
					_onInputFalling_pin[a] = 0;
				}
			}
			break;
		}
		case sps_event_onError:
		{
			//_onError = NULL;
			break;
		}
		case sps_event_onInputHigh:
		{
			if(_onInputHigh_amount == 255)
			{
				_onInputHigh_amount = amount;
				_onInputHigh = new onInputHighFunction[_onInputHigh_amount];
				_onInputHigh_pin = new unsigned int[_onInputHigh_amount];
				for(int a=0; a<_onInputHigh_amount; a++)
				{
					_onInputHigh[a] = NULL;
					_onInputHigh_pin[a] = 0;
				}
			}
			break;
		}
		case sps_event_onInputLow:
		{
			if(_onInputLow_amount == 255)
			{
				_onInputLow_amount = amount;
				_onInputLow = new onInputLowFunction[_onInputLow_amount];
				_onInputLow_pin = new unsigned int[_onInputLow_amount];
				for(int a=0; a<_onInputLow_amount; a++)
				{
					_onInputLow[a] = NULL;
					_onInputLow_pin[a] = 0;
				}
			}
			break;
		}
		default:
		{
			
		}
	}
}
void 	SPS::write(){
	outputRegister->write();
}
void 	SPS::read(){
	for(byte a=0; a<module; a++)
	{
		previousInputs[a] = inputRegister->get(a);
	}
	inputRegister->read();
}
void 	SPS::onInputChange(unsigned int address,void (*p_func)(bool))
{
	if(address < 0 || _onInputChange_amount == 255 || _onInputChange_lastElement == _onInputChange_amount-1)
	{
		error(10);
		return;
	}
	_onInputChange_lastElement++;
	_onInputChange[_onInputChange_lastElement] = p_func;
	_onInputChange_pin[_onInputChange_lastElement] = address;
}
void 	SPS::onInputRising(unsigned int address,void (*p_func)())
{
	if(address < 0 || _onInputRising_amount == 255 || _onInputRising_lastElement == _onInputRising_amount-1)
	{
		error(11);
		return;
	}	
	_onInputRising_lastElement++;
	_onInputRising[_onInputRising_lastElement] = p_func;
	_onInputRising_pin[_onInputRising_lastElement] = address;
}
void 	SPS::onInputFalling(unsigned int address,void (*p_func)())
{
	if(address < 0 || _onInputFalling_amount == 255 || _onInputFalling_lastElement == _onInputFalling_amount-1)
	{
		error(12);
		return;
	}	
	_onInputFalling_lastElement++;
	_onInputFalling[_onInputFalling_lastElement] = p_func;
	_onInputFalling_pin[_onInputFalling_lastElement] = address;
}
void 	SPS::onInputHigh(unsigned int address,void (*p_func)())
{
	if(address < 0 || _onInputHigh_amount == 255 || _onInputHigh_lastElement == _onInputHigh_amount-1)
	{
		error(13);
		return;
	}	
	_onInputHigh_lastElement++;
	_onInputHigh[_onInputHigh_lastElement] = p_func;
	_onInputHigh_pin[_onInputHigh_lastElement] = address;
}
void 	SPS::onInputLow(unsigned int address,void (*p_func)())
{
	if(address < 0 || _onInputLow_amount == 255 || _onInputLow_lastElement == _onInputLow_amount-1)
	{
		error(14);
		return;
	}	
	_onInputLow_lastElement++;
	_onInputLow[_onInputLow_lastElement] = p_func;
	_onInputLow_pin[_onInputLow_lastElement] = address;
}
void 	SPS::onError(void (*p_func)(byte))
{	
	_onError = p_func;
}
bool    SPS::input(byte modul,byte pin){
	if(pin > 7 || modul >= module)
	{
		return false;
	}
	if((inputRegister->get(modul) & (B00000001 << pin)) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
byte    SPS::input(byte modul)
{
	if(modul < 0 || modul >= module)
	{
		return 0;
	}
	return inputRegister->get(modul);
}
bool	SPS::inputAddress(int address)
{
	if(address < 0 || address >= module*8)
	{
		return 0;
	}
	return input(address/8,address%8);
}
byte* 	SPS::input(){
	return inputRegister->get();
}

void 	SPS::output(byte modul,byte pin,bool DATA){
	if(DATA == true)
	{
		//Serial.println("true");
		outputRegister->set(modul,(outputRegister->get(modul) | (B10000000 >> pin)));
	}
	else
	{
		//Serial.println("false");
		outputRegister->set(modul,(outputRegister->get(modul) & ~(B10000000 >> pin)));
	}
}
void 	SPS::output(byte outputData[]){
	outputRegister->set(outputData);
}
void 	SPS::output(byte modul,byte DATA){
	outputRegister->set(modul,DATA);
}
void 	SPS::outputAddress(unsigned int address,bool DATA)
{
	//Serial.println("aaa");
	if(address < 0 || address >= module*8)
	{
		return;
	}
	output(address/8,address%8,DATA);
}
bool 	SPS::getOutput(byte modul,byte pin)
{
	if(pin > 7 || modul >= module)
	{
		return false;
	}
	if((outputRegister->get(modul) & (B10000000 >> pin)) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
byte    SPS::getOutput(byte modul)
{
	if(modul < 0 || modul >= module)
	{
		return 0;
	}
	return outputRegister->get(modul);
}
bool	SPS::getOutputAddress(int address)
{
	if(address < 0 || address >= module*8)
	{
		return 0;
	}
	return getOutput(address/8,address%8);
}
byte* 	SPS::getOutput()
{
	return outputRegister->get();
}



void 	SPS::allOff()
{
	for(byte a=0; a< module; a++)
	{
		modulOff(a);
	}
}
void 	SPS::modulOff(byte modul)
{
	output(modul,0);
}
void 	SPS::allOn()
{
	for(byte a=0; a< module; a++)
	{
		modulOn(a);
	}
}
void 	SPS::modulOn(byte modul)
{
	output(modul,255);
}
void 	SPS::checkEvents()
{
	int counter = 0;
	if(_onInputChange_amount !=255)
	{
		for(byte a=0; a<_onInputChange_amount; a++)
		{
			//Serial.print((inputRegister->get(0) & (B10000000 >> 0)));
			//Serial.print(" ");
			//Serial.println((previousInputs[_onInputChange_pin[a]/8] & (B00000001 << _onInputChange_pin[a]%8)));
			if((inputRegister->get(_onInputChange_pin[a]/8) & (B00000001 << _onInputChange_pin[a]%8)) != (previousInputs[_onInputChange_pin[a]/8] & (B00000001 << _onInputChange_pin[a]%8)))
			{
				//Serial.println("b");
				(*_onInputChange[a])(inputAddress(_onInputChange_pin[a]));
			}
		}
	}
	if(_onInputRising_amount !=255)
	{
		for(byte a=0; a<_onInputRising_amount; a++)
		{
			if((inputRegister->get(_onInputRising_pin[a]/8) & (B00000001 << _onInputRising_pin[a]%8)) != (previousInputs[_onInputRising_pin[a]/8] & (B00000001 << _onInputRising_pin[a]%8)))
			{
				if((inputRegister->get(_onInputRising_pin[a]/8) & (B00000001 << _onInputRising_pin[a]%8)) > 0)
				{
					(*_onInputRising[a])();
				}			
			}
		}
	}
	if(_onInputFalling_amount !=255)
	{
		for(byte a=0; a<_onInputFalling_amount; a++)
		{
			if((inputRegister->get(_onInputFalling_pin[a]/8) & (B00000001 << _onInputFalling_pin[a]%8)) != (previousInputs[_onInputFalling_pin[a]/8] & (B00000001 << _onInputFalling_pin[a]%8)))
			{
				if((inputRegister->get(_onInputFalling_pin[a]/8) & (B00000001 << _onInputFalling_pin[a]%8)) == 0)
				{
					(*_onInputFalling[a])();
				}			
			}
		}
	}
	if(_onInputHigh_amount !=255)
	{
		for(byte a=0; a<_onInputHigh_amount; a++)
		{
			if(inputAddress(_onInputHigh_pin[a]) == true)
			{
				(*_onInputHigh[a])();
			}
		}
	}
	if(_onInputLow_amount !=255)
	{
		for(byte a=0; a<_onInputLow_amount; a++)
		{
			if(inputAddress(_onInputLow_pin[a]) == false)
			{
				(*_onInputLow[a])();
			}
		}
	}
	/*
	for(byte a=0; a<module; a++)
	{
		if(inputRegister->get(a) != previousInputs[a])
		{
			byte now = inputRegister->get(a);
			Serial.println("change__");
			Serial.print(previousInputs[a],BIN);
			Serial.print(" ");
			Serial.println(now,BIN);
			
			for(byte b=0; b<8; b++)
			{
				if((now & (B00000001 << b)) != (previousInputs[a] & (B00000001 << b)))
				{
					Serial.print("found counter: ");
					Serial.println(counter);
					
					if(_onInputChange[counter] != NULL)
					{
						Serial.print("input(counter): ");
						Serial.println(inputAddress(counter));
						(*_onInputChange[counter])(inputAddress(counter));
						
					}
				}
				counter++;
			}
		}
		else
		{
			counter+=8;
		}
	}
	*/
}
void 	SPS::error(byte errorCode)
{
	if(_onError != NULL)
	{
		(*_onError)(errorCode);
	}
}
void 	SPS::reset(){
	outputRegister->reset();
}

//-------------------------------------------------------


bool 	AND(bool a,bool b)
{
	return a && b;
}
bool 	OR(bool a,bool b)
{
	return a || b;
}
bool 	XOR(bool a,bool b)
{
	return a != b;
}