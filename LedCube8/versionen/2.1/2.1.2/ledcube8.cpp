// Autor: 									Alex Krieg
// Erstellt:								24.11.2015
// Version 									2.1.2
// Kompatibel mit den versionen: 			2.0.0  2.1.0
// Funktionen:								Siehe Versionsverlauf




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
	 TimeMicro = 1000000;
	 helligkeit= 100;
	 
	 startMillis	=0;
	 referenzMillis	=0;
	 benotigtMillis	=0;
 }
 void LedCube8::draw(byte layer, byte a, byte b, byte c, byte d, byte e, byte f, byte g, byte h)
 {
	//helligkeit = helligkeit/8;
	setPin(a,countAddress());
	setPin(b,countAddress());
	setPin(c,countAddress());
	setPin(d,countAddress());
	setPin(e,countAddress());
	setPin(f,countAddress());
	setPin(g,countAddress());
	setPin(h,countAddress());
	setLayer(layer,Time,1000);
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
			setLayer(1,1,10);
			
			setPin(E2a, countAddress());
			setPin(E2b, countAddress());
			setPin(E2c, countAddress());
			setPin(E2d, countAddress());
			setPin(E2e, countAddress());
			setPin(E2f, countAddress());
			setPin(E2g, countAddress());
			setPin(E2h, countAddress());
			setLayer(2,1,10); 
			             
			setPin(E3a, countAddress());
			setPin(E3b, countAddress());
			setPin(E3c, countAddress());
			setPin(E3d, countAddress());
			setPin(E3e, countAddress());
			setPin(E3f, countAddress());
			setPin(E3g, countAddress());
			setPin(E3h, countAddress());
			setLayer(3,1,10); 
			             
			setPin(E4a, countAddress());
			setPin(E4b, countAddress());
			setPin(E4c, countAddress());
			setPin(E4d, countAddress());
			setPin(E4e, countAddress());
			setPin(E4f, countAddress());
			setPin(E4g, countAddress());
			setPin(E4h, countAddress());
			setLayer(4,1,10); 
			             
			setPin(E5a, countAddress());
			setPin(E5b, countAddress());
			setPin(E5c, countAddress());
			setPin(E5d, countAddress());
			setPin(E5e, countAddress());
			setPin(E5f, countAddress());
			setPin(E5g, countAddress());
			setPin(E5h, countAddress());
			setLayer(5,1,10); 
			             
			setPin(E6a, countAddress());
			setPin(E6b, countAddress());
			setPin(E6c, countAddress());
			setPin(E6d, countAddress());
			setPin(E6e, countAddress());
			setPin(E6f, countAddress());
			setPin(E6g, countAddress());
			setPin(E6h, countAddress());
			setLayer(6,1,10); 
			             
			setPin(E7a, countAddress());
			setPin(E7b, countAddress());
			setPin(E7c, countAddress());
			setPin(E7d, countAddress());
			setPin(E7e, countAddress());
			setPin(E7f, countAddress());
			setPin(E7g, countAddress());
			setPin(E7h, countAddress());
			setLayer(7,1,10); 
			             
			setPin(E8a, countAddress());
			setPin(E8b, countAddress());
			setPin(E8c, countAddress());
			setPin(E8d, countAddress());
			setPin(E8e, countAddress());
			setPin(E8f, countAddress());
			setPin(E8g, countAddress());
			setPin(E8h, countAddress());
			setLayer(8,1,10);
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
	  setLayer(layer,Time,10);
  }
  void LedCube8::drawWall(byte wall)
  {
	  for(int i=0;i<9; i++)
	  {
	  setPin(B00000000,i);
	  }
	  setPin(B11111111,wall);
	  for(int count= 0; count<Time*1.25; count++)
	  {
		  for(int i = 1; i<9; i++)
		  {
			  setLayer(i,1,1);
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
	  for(int count= 0; count<Time*1.25; count++)
	  {
		  for(int i = 1; i<9; i++)
		  {
			  setLayer(i,1,1);
		  }
	  }
  }
  
  void LedCube8::shiftLayerR(int count,byte layer,bool reload, byte a, byte b, byte c, byte d, byte e, byte f, byte g, byte h)
  { 
	  for(int x = 0; x<count; x++)
	  {
		  if(reload == true)
		  {	  
			  a = ((a&B00000001 )<<7)| (a>>1);
			  b = ((b&B00000001 )<<7)| (b>>1);
			  c = ((c&B00000001 )<<7)| (c>>1);
			  d = ((d&B00000001 )<<7)| (d>>1);
			  e = ((e&B00000001 )<<7)| (e>>1);
			  f = ((f&B00000001 )<<7)| (f>>1);
			  g = ((g&B00000001 )<<7)| (g>>1);
			  h = ((h&B00000001 )<<7)| (h>>1);
		  }
		  else
		  {
			  a = a >> 1;
			  b = b >> 1;
			  c = c >> 1;
			  d = d >> 1;
			  e = e >> 1;
			  f = f >> 1;
			  g = g >> 1;
			  h = h >> 1;
		  }
		  draw(layer,a,b,c,d,e,f,g,h);
	  }
  }
  
  void LedCube8::shiftCubeR(int count,bool reload,byte E8a,byte E8b,byte E8c,byte E8d,byte E8e,byte E8f,byte E8g,byte E8h, 
										byte E7a,byte E7b,byte E7c,byte E7d,byte E7e,byte E7f,byte E7g,byte E7h,
										byte E6a,byte E6b,byte E6c,byte E6d,byte E6e,byte E6f,byte E6g,byte E6h,
										byte E5a,byte E5b,byte E5c,byte E5d,byte E5e,byte E5f,byte E5g,byte E5h,
										byte E4a,byte E4b,byte E4c,byte E4d,byte E4e,byte E4f,byte E4g,byte E4h,
										byte E3a,byte E3b,byte E3c,byte E3d,byte E3e,byte E3f,byte E3g,byte E3h,
										byte E2a,byte E2b,byte E2c,byte E2d,byte E2e,byte E2f,byte E2g,byte E2h,
										byte E1a,byte E1b,byte E1c,byte E1d,byte E1e,byte E1f,byte E1g,byte E1h)
	{
		for(int x = 0; x<count; x++)
		{
			if(reload == true)
			{
			  {
			  E1a = ((E1a&B00000001 )<<7)| (E1a>>1);	E2a = ((E2a&B00000001 )<<7)| (E2a>>1);
			  E1b = ((E1b&B00000001 )<<7)| (E1b>>1);    E2b = ((E2b&B00000001 )<<7)| (E2b>>1);
			  E1c = ((E1c&B00000001 )<<7)| (E1c>>1);    E2c = ((E2c&B00000001 )<<7)| (E2c>>1);
			  E1d = ((E1d&B00000001 )<<7)| (E1d>>1);    E2d = ((E2d&B00000001 )<<7)| (E2d>>1);
			  E1e = ((E1e&B00000001 )<<7)| (E1e>>1);    E2e = ((E2e&B00000001 )<<7)| (E2e>>1);
			  E1f = ((E1f&B00000001 )<<7)| (E1f>>1);    E2f = ((E2f&B00000001 )<<7)| (E2f>>1);
			  E1g = ((E1g&B00000001 )<<7)| (E1g>>1);    E2g = ((E2g&B00000001 )<<7)| (E2g>>1);
			  E1h = ((E1h&B00000001 )<<7)| (E1h>>1);    E2h = ((E2h&B00000001 )<<7)| (E2h>>1);
			  
			  
			  E3a = ((E3a&B00000001 )<<7)| (E3a>>1);	E4a = ((E4a&B00000001 )<<7)| (E4a>>1);
			  E3b = ((E3b&B00000001 )<<7)| (E3b>>1);    E4b = ((E4b&B00000001 )<<7)| (E4b>>1);
			  E3c = ((E3c&B00000001 )<<7)| (E3c>>1);    E4c = ((E4c&B00000001 )<<7)| (E4c>>1);
			  E3d = ((E3d&B00000001 )<<7)| (E3d>>1);    E4d = ((E4d&B00000001 )<<7)| (E4d>>1);
			  E3e = ((E3e&B00000001 )<<7)| (E3e>>1);    E4e = ((E4e&B00000001 )<<7)| (E4e>>1);
			  E3f = ((E3f&B00000001 )<<7)| (E3f>>1);    E4f = ((E4f&B00000001 )<<7)| (E4f>>1);
			  E3g = ((E3g&B00000001 )<<7)| (E3g>>1);    E4g = ((E4g&B00000001 )<<7)| (E4g>>1);
			  E3h = ((E3h&B00000001 )<<7)| (E3h>>1);    E4h = ((E4h&B00000001 )<<7)| (E4h>>1);
  
			  
			  E5a = ((E5a&B00000001 )<<7)| (E5a>>1);	E6a = ((E6a&B00000001 )<<7)| (E6a>>1);
			  E5b = ((E5b&B00000001 )<<7)| (E5b>>1);    E6b = ((E6b&B00000001 )<<7)| (E6b>>1);
			  E5c = ((E5c&B00000001 )<<7)| (E5c>>1);    E6c = ((E6c&B00000001 )<<7)| (E6c>>1);
			  E5d = ((E5d&B00000001 )<<7)| (E5d>>1);    E6d = ((E6d&B00000001 )<<7)| (E6d>>1);
			  E5e = ((E5e&B00000001 )<<7)| (E5e>>1);    E6e = ((E6e&B00000001 )<<7)| (E6e>>1);
			  E5f = ((E5f&B00000001 )<<7)| (E5f>>1);    E6f = ((E6f&B00000001 )<<7)| (E6f>>1);
			  E5g = ((E5g&B00000001 )<<7)| (E5g>>1);    E6g = ((E6g&B00000001 )<<7)| (E6g>>1);
			  E5h = ((E5h&B00000001 )<<7)| (E5h>>1);    E6h = ((E6h&B00000001 )<<7)| (E6h>>1);
			  
			  
			  E7a = ((E7a&B00000001 )<<7)| (E7a>>1);	E8a = ((E8a&B00000001 )<<7)| (E8a>>1);
			  E7b = ((E7b&B00000001 )<<7)| (E7b>>1);    E8b = ((E8b&B00000001 )<<7)| (E8b>>1);
			  E7c = ((E7c&B00000001 )<<7)| (E7c>>1);    E8c = ((E8c&B00000001 )<<7)| (E8c>>1);
			  E7d = ((E7d&B00000001 )<<7)| (E7d>>1);    E8d = ((E8d&B00000001 )<<7)| (E8d>>1);
			  E7e = ((E7e&B00000001 )<<7)| (E7e>>1);    E8e = ((E8e&B00000001 )<<7)| (E8e>>1);
			  E7f = ((E7f&B00000001 )<<7)| (E7f>>1);    E8f = ((E8f&B00000001 )<<7)| (E8f>>1);
			  E7g = ((E7g&B00000001 )<<7)| (E7g>>1);    E8g = ((E8g&B00000001 )<<7)| (E8g>>1);
			  E7h = ((E7h&B00000001 )<<7)| (E7h>>1);    E8h = ((E8h&B00000001 )<<7)| (E8h>>1); 
			  }
			}
			 else
			{
				 E8a = E8a >> 1;	E8b = E8b >> 1;		E8c = E8c >> 1;		E8d = E8d >> 1;
				 E7a = E7a >> 1;    E7b = E7b >> 1;     E7c = E7c >> 1;     E7d = E7d >> 1;
				 E6a = E6a >> 1;    E6b = E6b >> 1;     E6c = E6c >> 1;     E6d = E6d >> 1;
				 E5a = E5a >> 1;    E5b = E5b >> 1;     E5c = E5c >> 1;     E5d = E5d >> 1;
				 E4a = E4a >> 1;    E4b = E4b >> 1;     E4c = E4c >> 1;     E4d = E4d >> 1;
				 E3a = E3a >> 1;    E3b = E3b >> 1;     E3c = E3c >> 1;     E3d = E3d >> 1;
				 E2a = E2a >> 1;    E2b = E2b >> 1;     E2c = E2c >> 1;     E2d = E2d >> 1;
				 E1a = E1a >> 1;    E1b = E1b >> 1;     E1c = E1c >> 1;     E1d = E1d >> 1;
				 
				 E8e = E8e >> 1;	E8f = E8f >> 1;		E8g = E8g >> 1;		E8h = E8h >> 1;
				 E7e = E7e >> 1;    E7f = E7f >> 1;     E7g = E7g >> 1;     E7h = E7h >> 1;
				 E6e = E6e >> 1;    E6f = E6f >> 1;     E6g = E6g >> 1;     E6h = E6h >> 1;
				 E5e = E5e >> 1;    E5f = E5f >> 1;     E5g = E5g >> 1;     E5h = E5h >> 1;
				 E4e = E4e >> 1;    E4f = E4f >> 1;     E4g = E4g >> 1;     E4h = E4h >> 1;
				 E3e = E3e >> 1;    E3f = E3f >> 1;     E3g = E3g >> 1;     E3h = E3h >> 1;
				 E2e = E2e >> 1;    E2f = E2f >> 1;     E2g = E2g >> 1;     E2h = E2h >> 1;
				 E1e = E1e >> 1;    E1f = E1f >> 1;     E1g = E1g >> 1;     E1h = E1h >> 1;
			 }
				  
			  
			  drawCube(E8a,E8b,E8c,E8d,E8e,E8f,E8g,E8h,
					   E7a,E7b,E7c,E7d,E7e,E7f,E7g,E7h,
					   E6a,E6b,E6c,E6d,E6e,E6f,E6g,E6h,
					   E5a,E5b,E5c,E5d,E5e,E5f,E5g,E5h,
					   E4a,E4b,E4c,E4d,E4e,E4f,E4g,E4h,
					   E3a,E3b,E3c,E3d,E3e,E3f,E3g,E3h,
					   E2a,E2b,E2c,E2d,E2e,E2f,E2g,E2h,
					   E1a,E1b,E1c,E1d,E1e,E1f,E1g,E1h);
			}
		}
		
		
		
		
		
	void LedCube8::light(byte L)
	{
		helligkeit = L;
		if(helligkeit > 100)
		{
			helligkeit = 100;
		}
		if(helligkeit < 1)
		{
			helligkeit = 1;
		}
		//setLight();
	}	
		
	void LedCube8::setLight()
	{
		
	}
		
		
		
		
		
	
	
	
	
	
  void LedCube8::time(int t)
  {
	  Time = t;
	  
	  TimeMicro = t*1000;
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
 void LedCube8::setLayer(byte layer,int T,int multiplikator)
 {
	 int r = 0;
	 while(true)
	 {
		 r=r+1;
		 for(int i = 0; i<multiplikator; i++)				//1ms
		 {
			PORTC = (PORTC & B110000) | layer;
			delayMicroseconds(helligkeit);
			PORTC = (PORTC & B110000) | B000000;
			delayMicroseconds(101 - helligkeit);
		 }	
		 if(r==T)
		 {
			 return;
		 }
	 }	
		/*
		PORTC = (PORTC & B110000) | layer;		//Setzt die pins A0-A3 bzw Die Ebenen
		for(int i = 0; i< multiplikator; i++)
		{
		delayMicroseconds(T);	
		}												//-----------------------*********
		PORTC = (PORTC & B110000) | B000000;*/
 }