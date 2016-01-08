#include "ledcube8.h"
#include "Arduino.h"
 
 LedCube8::LedCube8(byte flipfloppin[],byte ledaddress[],byte layeraddresspin[])
 {
	 ledpin				= new byte[8];
	 ledAddresspin		= new byte[4];
	 layerpin			= new byte[4];
	 
	 for(int i=0; i<8; i++)
	 { 
		 ledpin[i]			=	flipfloppin[i]; // Das Array hat 8 bits
	 }
	 for(int i=0; i<4; i++)
	 {
		 layerpin[i]		=	layeraddresspin[i];
		 ledAddresspin[i]	=	ledaddress[i];
	 }
	 counter = B00000000;
	 init(); 
 }
 LedCube8::~LedCube8()
 {}
 void LedCube8::init()
 {
	 for(int i=0; i<8; i++)
	 {
		pinMode(ledpin[i],		OUTPUT);
	 }
	 for(int i=0; i<4; i++)
	 {
		pinMode(layerpin[i],		OUTPUT);
		pinMode(ledAddresspin[i],	OUTPUT);
	 }
	 Time 	= 1000;
	 Zahler = 0;
 }
 void LedCube8::draw(byte layer, byte a, byte b, byte c, byte d, byte e, byte f, byte g, byte h)
 {
	setPin(a,countAddress());
	setPin(b,countAddress());
	setPin(c,countAddress());
	setPin(d,countAddress());
	setPin(e,countAddress());
	setPin(f,countAddress());
	setPin(g,countAddress());
	setPin(h,countAddress());
	setLayer(layer,Time);
	PORTB = (PORTB & B111100) | ((B00000000 & B11000000) >> 6);  // pins nach dem setztn auf 0 scheriben
	PORTD = (PORTB & B00000011) |(B00000000 << 2);				 //
	
 }
 void LedCube8::drawCube(byte E8a,byte E8b,byte E8c,byte E8d,byte E8e,byte E8f,byte E8g,byte E8h, 
								  byte E7a,byte E7b,byte E7c,byte E7d,byte E7e,byte E7f,byte E7g,byte E7h,
								  byte E6a,byte E6b,byte E6c,byte E6d,byte E6e,byte E6f,byte E6g,byte E6h,
								  byte E5a,byte E5b,byte E5c,byte E5d,byte E5e,byte E5f,byte E5g,byte E5h,
								  byte E4a,byte E4b,byte E4c,byte E4d,byte E4e,byte E4f,byte E4g,byte E4h,
								  byte E3a,byte E3b,byte E3c,byte E3d,byte E3e,byte E3f,byte E3g,byte E3h,
								  byte E2a,byte E2b,byte E2c,byte E2d,byte E2e,byte E2f,byte E2g,byte E2h,
								  byte E1a,byte E1b,byte E1c,byte E1d,byte E1e,byte E1f,byte E1g,byte E1h)
	{
		for(int i=0; i<Time/8; i++)
		{
			setPin(E1a, countAddress());
			setPin(E1b, countAddress());
			setPin(E1c, countAddress());
			setPin(E1d, countAddress());
			setPin(E1e, countAddress());
			setPin(E1f, countAddress());
			setPin(E1g, countAddress());
			setPin(E1h, countAddress());
			setLayer(1,1);
			
			setPin(E2a, countAddress());
			setPin(E2b, countAddress());
			setPin(E2c, countAddress());
			setPin(E2d, countAddress());
			setPin(E2e, countAddress());
			setPin(E2f, countAddress());
			setPin(E2g, countAddress());
			setPin(E2h, countAddress());
			setLayer(2,1); 
			             
			setPin(E3a, countAddress());
			setPin(E3b, countAddress());
			setPin(E3c, countAddress());
			setPin(E3d, countAddress());
			setPin(E3e, countAddress());
			setPin(E3f, countAddress());
			setPin(E3g, countAddress());
			setPin(E3h, countAddress());
			setLayer(3,1); 
			             
			setPin(E4a, countAddress());
			setPin(E4b, countAddress());
			setPin(E4c, countAddress());
			setPin(E4d, countAddress());
			setPin(E4e, countAddress());
			setPin(E4f, countAddress());
			setPin(E4g, countAddress());
			setPin(E4h, countAddress());
			setLayer(4,1); 
			             
			setPin(E5a, countAddress());
			setPin(E5b, countAddress());
			setPin(E5c, countAddress());
			setPin(E5d, countAddress());
			setPin(E5e, countAddress());
			setPin(E5f, countAddress());
			setPin(E5g, countAddress());
			setPin(E5h, countAddress());
			setLayer(5,1); 
			             
			setPin(E6a, countAddress());
			setPin(E6b, countAddress());
			setPin(E6c, countAddress());
			setPin(E6d, countAddress());
			setPin(E6e, countAddress());
			setPin(E6f, countAddress());
			setPin(E6g, countAddress());
			setPin(E6h, countAddress());
			setLayer(6,1); 
			             
			setPin(E7a, countAddress());
			setPin(E7b, countAddress());
			setPin(E7c, countAddress());
			setPin(E7d, countAddress());
			setPin(E7e, countAddress());
			setPin(E7f, countAddress());
			setPin(E7g, countAddress());
			setPin(E7h, countAddress());
			setLayer(7,1); 
			             
			setPin(E8a, countAddress());
			setPin(E8b, countAddress());
			setPin(E8c, countAddress());
			setPin(E8d, countAddress());
			setPin(E8e, countAddress());
			setPin(E8f, countAddress());
			setPin(E8g, countAddress());
			setPin(E8h, countAddress());
			setLayer(8,1);
		}
	}
  void LedCube8::drawLayer(byte layer)
  {
	  for(int i=0;i<9; i++)
	  {
	  setPin(B00000000,i);
	  }
	  for(byte i=0; i<8; i++)
	  {
	  setPin(B11111111,countAddress());
	  }
	  setLayer(layer,Time);
  }
  void LedCube8::drawWall(byte wall)
  {
	  for(int i=0;i<9; i++)
	  {
	  setPin(B00000000,i);
	  }
	  setPin(B11111111,wall);
	  for(int count= 0; count<Time; count++)
	  {
		  for(int i = 1; i<9; i++)
		  {
			  setLayer(i,1);
		  }
	  }
  }
  void LedCube8::drawWall90(byte wall)
  {
	 for(int i=0;i<9; i++)
	  {
	  setPin(B00000000,i);
	  }
	  for(int i = 0; i<9; i++)
	  {
		setPin(B10000000>>(wall-1),i);
	  }
	  for(int count= 0; count<Time; count++)
	  {
		  for(int i = 1; i<9; i++)
		  {
			  setLayer(i,1);
		  }
	  }
  }
  
  
  
  
	
	
	
	
  void LedCube8::time(int t)
  {
	  Time = t;
  }
  byte LedCube8::countAddress()
 {
	 if(counter >= 8)
	 {
		 counter = B00000000; 
	 }
	 counter = counter + B00000001;
	 return counter;
 }
  void LedCube8::setPin(byte pin, byte address)
 {
	PORTB = (PORTB & B111100) | ((pin & B11000000) >> 6);                 //Setzt die pins 8-9
    PORTD = (PORTB & B00000011) | (pin << 2);								   	//Setzt die pins 2-7
	saveToFlipFlop(address);
 }
 void LedCube8::saveToFlipFlop(byte address)
 {
	PORTB = (PORTB & B000011) | (address << 2);					//Setzt die pins 10-13  														//-----------------------*********
	PORTB = (PORTB & B000011) | (B000000 << 2);	                                                                                      
 }
 void LedCube8::setLayer(byte layer,int T)
 {
		PORTC = (PORTC & B110000) | layer;								//Setzt die pins A0-A3 bzw Die Ebenen
		delay(T);													//-----------------------*********
		PORTC = (PORTC & B110000) | B000000;
 }