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
	 
	/*setPin(B11111111);
	setPin(B11111111);
	setPin(B11111111);
	setPin(B11111111);
	setPin(B11111111);
	setPin(B11111111);
	setPin(B11111111);
	setPin(B11111111);*/
	//for(int i =0; i<8; i++)
	/* {
		setLayer(5);
		delay(2);
	 }*/
	/*setPin(B00000000);
	setPin(B00000000);
	setPin(B00000000);
	setPin(B00000000);
	setPin(B00000000);
	setPin(B00000000);
	setPin(B00000000);
	setPin(B00000000);*/
	/*for(int i =0; i<8; i++)
	 {
		setLayer(i);
		delay(2);
	 }*/
	 /*
	 PORTB = (PORTB & B111100) | ((B11111111 & B11000000) >> 6);                 //Setzt die pins 8-9
     PORTD = (PORTB & B00000011) | (B11111111 << 2);
	 delay(1);
	 for(int i =0; i<8; i++)
	 {
		setLayer(1);
		delay(2);
	 }
	 PORTB = (PORTB & B111100) | ((B00000000 & B11000000) >> 6);                 //Setzt die pins 8-9
     PORTD = (PORTB & B00000011) | (B00000000 << 2);
	 delay(1);
	 for(int i =0; i<8; i++)
	 {
		setLayer(1);
		delay(2);
	 }*/
 }
 void LedCube8::draw(byte layer,int time, byte a, byte b, byte c, byte d, byte e, byte f, byte g, byte h)
 {
	setPin(a);
	setPin(b);
	setPin(c);
	setPin(d);
	setPin(e);
	setPin(f);
	setPin(g);
	setPin(h);
	setLayer(layer,time);
	PORTB = (PORTB & B111100) | ((B00000000 & B11000000) >> 6);  // pins nach dem setztn auf 0 scheriben
	PORTD = (PORTB & B00000011) |(B00000000 << 2);				 //
	
 }
  
  byte LedCube8::countAddress()
 {

	 if(counter == 8)
	 {
		 counter = B00000000; 
	 }
	 counter = counter + B00000001;
	 //delay(1);
	 return counter;
 }
  void LedCube8::setPin(byte pin)
 {
	PORTB = (PORTB & B111100) | ((pin & B11000000) >> 6);                 //Setzt die pins 8-9
    PORTD = (PORTB & B00000011) | (pin << 2);								   	//Setzt die pins 2-7
	//delay(1);
	saveToFlipFlop();
 }
 void LedCube8::saveToFlipFlop()
 {
	PORTB = (PORTB & B000011) | (countAddress() << 2);					//Setzt die pins 10-13  
	//delay(1);														//-----------------------*********
	PORTB = (PORTB & B000011) | (B000000 << 2);	                                                                                      
 }
 void LedCube8::setLayer(byte layer,int time)
 {
		PORTC = (PORTC & B110000) | layer;								//Setzt die pins A0-A3 bzw Die Ebenen
		delay(time);													//-----------------------*********
		PORTC = (PORTC & B110000) | B000000;
 }