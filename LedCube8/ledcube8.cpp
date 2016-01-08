// Autor: 									Alex Krieg
// Erstellt:								6.12.2015
// Version 									2.3.0
// Kompatibel mit den versionen: 			2.2.1
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
	 hackLightStatus = false;
	 startMillis	=0;
	 referenzMillis	=0;
	 benotigtMillis	=0;
 }
 void LedCube8::draw(byte layer, byte a, byte b, byte c, byte d, byte e, byte f, byte g, byte h)
 {
	 byte bufferHelligkeit = helligkeit;
	 if(hackLightStatus == false)
	 {
		helligkeit = helligkeit/8;
	 }
	setPin(a,countAddress());
	setPin(b,countAddress());
	setPin(c,countAddress());
	setPin(d,countAddress());
	setPin(e,countAddress());
	setPin(f,countAddress());
	setPin(g,countAddress());
	setPin(h,countAddress());
	setLayer(layer,Time,10);
	PORTB = (PORTB & B111100) | ((B00000000 & B11000000) >> 6);  // pins nach dem setztn auf 0 scheriben
	PORTD = (PORTB & B00000011) |(B00000000 << 2);				 //
	
	helligkeit = bufferHelligkeit;
	 
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
	  draw(layer,255,255,255,255,255,255,255,255);
	  
	  
	  /*for(int i=0;i<9; i++)
	  {
	  setPin(B00000000,i);
	  }
	  for(byte i=0; i<8; i++)
	  {
	  setPin(B11111111,countAddress());
	  }
	  setLayer(layer,Time,10);*/
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
	  draw(layer,a,b,c,d,e,f,g,h);
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
  
  void LedCube8::shiftLayerL(int count,byte layer,bool reload, byte a, byte b, byte c, byte d, byte e, byte f, byte g, byte h)
  {
	  draw(layer,a,b,c,d,e,f,g,h);
	  for(int x = 0; x<count; x++)
	  {
		  if(reload == true)
		  {	  
			  a = ((a&B10000000 )>>7)| (a<<1);
			  b = ((b&B10000000 )>>7)| (b<<1);
			  c = ((c&B10000000 )>>7)| (c<<1);
			  d = ((d&B10000000 )>>7)| (d<<1);
			  e = ((e&B10000000 )>>7)| (e<<1);
			  f = ((f&B10000000 )>>7)| (f<<1);
			  g = ((g&B10000000 )>>7)| (g<<1);
			  h = ((h&B10000000 )>>7)| (h<<1);
		  }
		  else
		  {
			  a = a << 1;
			  b = b << 1;
			  c = c << 1;
			  d = d << 1;
			  e = e << 1;
			  f = f << 1;
			  g = g << 1;
			  h = h << 1;
		  }
		  draw(layer,a,b,c,d,e,f,g,h);
	  }
  }
  
  void LedCube8::shiftLayerR90(int count,byte layer,bool reload, byte a, byte b, byte c, byte d, byte e, byte f, byte g, byte h)
  {
	  draw(layer,a,b,c,d,e,f,g,h);
	  for(int x = 0; x<count; x++)
	  {
		  byte buffer = h;
		  if(reload == true)
		  {	  	    
			  h = g;
			  g = f;
			  f = e;
			  e = d;
			  d = c;
			  c = b;
			  b = a;
			  a = buffer;
		  }
		  else
		  {
			  h = g;
			  g = f;
			  f = e;
			  e = d;
			  d = c;
			  c = b;
			  b = a;
			  a = 0;
		  }
		  draw(layer,a,b,c,d,e,f,g,h);
	  }
  }
  
  void LedCube8::shiftLayerL90(int count,byte layer,bool reload, byte a, byte b, byte c, byte d, byte e, byte f, byte g, byte h)
  {
	  draw(layer,a,b,c,d,e,f,g,h);
	  for(int x = 0; x<count; x++)
	  {
		  byte buffer = a;
		  if(reload == true)
		  {	  
			  a = b;
			  b = c;
			  c = d;
			  d = e;
			  e = f;
			  f = g;
			  g = h;
			  h = buffer;
		  }
		  else
		  {
			  a = b;
			  b = c;
			  c = d;
			  d = e;
			  e = f;
			  f = g;
			  g = h;
			  h = 0;
		  }
		  draw(layer,a,b,c,d,e,f,g,h);
	  }
  }
	void LedCube8::shiftLayerDown(int count,byte layer,bool reload, byte a, byte b, byte c, byte d, byte e, byte f, byte g, byte h)
	{
		for(int i=0; i<count;i++)
		{
			draw(layer,a,b,c,d,e,f,g,h);
			layer--;
			if(layer == 0 && reload == true)
			{
				layer = 8;
			}
			if(layer == 0)
			{
				return;
			}
		}
	}
	
	void LedCube8::shiftLayerUp(int count,byte layer,bool reload, byte a, byte b, byte c, byte d, byte e, byte f, byte g, byte h)
	{
		for(int i=0; i<count;i++)
		{
			draw(layer,a,b,c,d,e,f,g,h);
			layer++;
			if(layer == 9 && reload == true)
			{
				layer = 1;
			}
			if(layer == 9)
			{
				return;
			}
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
		
	void LedCube8::shiftCubeL(int count,bool reload,byte E8a,byte E8b,byte E8c,byte E8d,byte E8e,byte E8f,byte E8g,byte E8h, 
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
			  E1a = ((E1a&B10000000 )>>7)| (E1a<<1);	E2a = ((E2a&B10000000 )>>7)| (E2a<<1);
			  E1b = ((E1b&B10000000 )>>7)| (E1b<<1);    E2b = ((E2b&B10000000 )>>7)| (E2b<<1);
			  E1c = ((E1c&B10000000 )>>7)| (E1c<<1);    E2c = ((E2c&B10000000 )>>7)| (E2c<<1);
			  E1d = ((E1d&B10000000 )>>7)| (E1d<<1);    E2d = ((E2d&B10000000 )>>7)| (E2d<<1);
			  E1e = ((E1e&B10000000 )>>7)| (E1e<<1);    E2e = ((E2e&B10000000 )>>7)| (E2e<<1);
			  E1f = ((E1f&B10000000 )>>7)| (E1f<<1);    E2f = ((E2f&B10000000 )>>7)| (E2f<<1);
			  E1g = ((E1g&B10000000 )>>7)| (E1g<<1);    E2g = ((E2g&B10000000 )>>7)| (E2g<<1);
			  E1h = ((E1h&B10000000 )>>7)| (E1h<<1);    E2h = ((E2h&B10000000 )>>7)| (E2h<<1);
			                                                        
			                                                        
			  E3a = ((E3a&B10000000 )>>7)| (E3a<<1);	E4a = ((E4a&B10000000 )>>7)| (E4a<<1);
			  E3b = ((E3b&B10000000 )>>7)| (E3b<<1);    E4b = ((E4b&B10000000 )>>7)| (E4b<<1);
			  E3c = ((E3c&B10000000 )>>7)| (E3c<<1);    E4c = ((E4c&B10000000 )>>7)| (E4c<<1);
			  E3d = ((E3d&B10000000 )>>7)| (E3d<<1);    E4d = ((E4d&B10000000 )>>7)| (E4d<<1);
			  E3e = ((E3e&B10000000 )>>7)| (E3e<<1);    E4e = ((E4e&B10000000 )>>7)| (E4e<<1);
			  E3f = ((E3f&B10000000 )>>7)| (E3f<<1);    E4f = ((E4f&B10000000 )>>7)| (E4f<<1);
			  E3g = ((E3g&B10000000 )>>7)| (E3g<<1);    E4g = ((E4g&B10000000 )>>7)| (E4g<<1);
			  E3h = ((E3h&B10000000 )>>7)| (E3h<<1);    E4h = ((E4h&B10000000 )>>7)| (E4h<<1);
            
			
			  E5a = ((E5a&B10000000 )>>7)| (E5a<<1);	E6a = ((E6a&B10000000 )>>7)| (E6a<<1);
			  E5b = ((E5b&B10000000 )>>7)| (E5b<<1);    E6b = ((E6b&B10000000 )>>7)| (E6b<<1);
			  E5c = ((E5c&B10000000 )>>7)| (E5c<<1);    E6c = ((E6c&B10000000 )>>7)| (E6c<<1);
			  E5d = ((E5d&B10000000 )>>7)| (E5d<<1);    E6d = ((E6d&B10000000 )>>7)| (E6d<<1);
			  E5e = ((E5e&B10000000 )>>7)| (E5e<<1);    E6e = ((E6e&B10000000 )>>7)| (E6e<<1);
			  E5f = ((E5f&B10000000 )>>7)| (E5f<<1);    E6f = ((E6f&B10000000 )>>7)| (E6f<<1);
			  E5g = ((E5g&B10000000 )>>7)| (E5g<<1);    E6g = ((E6g&B10000000 )>>7)| (E6g<<1);
			  E5h = ((E5h&B10000000 )>>7)| (E5h<<1);    E6h = ((E6h&B10000000 )>>7)| (E6h<<1);
			  
			  
			  E7a = ((E7a&B10000000 )>>7)| (E7a<<1);	E8a = ((E8a&B10000000 )>>7)| (E8a<<1);
			  E7b = ((E7b&B10000000 )>>7)| (E7b<<1);    E8b = ((E8b&B10000000 )>>7)| (E8b<<1);
			  E7c = ((E7c&B10000000 )>>7)| (E7c<<1);    E8c = ((E8c&B10000000 )>>7)| (E8c<<1);
			  E7d = ((E7d&B10000000 )>>7)| (E7d<<1);    E8d = ((E8d&B10000000 )>>7)| (E8d<<1);
			  E7e = ((E7e&B10000000 )>>7)| (E7e<<1);    E8e = ((E8e&B10000000 )>>7)| (E8e<<1);
			  E7f = ((E7f&B10000000 )>>7)| (E7f<<1);    E8f = ((E8f&B10000000 )>>7)| (E8f<<1);
			  E7g = ((E7g&B10000000 )>>7)| (E7g<<1);    E8g = ((E8g&B10000000 )>>7)| (E8g<<1);
			  E7h = ((E7h&B10000000 )>>7)| (E7h<<1);    E8h = ((E8h&B10000000 )>>7)| (E8h<<1); 
			  }                                
			}
			 else
			{
				 E8a = E8a << 1;	E8b = E8b << 1;		E8c = E8c << 1;		E8d = E8d << 1;
				 E7a = E7a << 1;    E7b = E7b << 1;     E7c = E7c << 1;     E7d = E7d << 1;
				 E6a = E6a << 1;    E6b = E6b << 1;     E6c = E6c << 1;     E6d = E6d << 1;
				 E5a = E5a << 1;    E5b = E5b << 1;     E5c = E5c << 1;     E5d = E5d << 1;
				 E4a = E4a << 1;    E4b = E4b << 1;     E4c = E4c << 1;     E4d = E4d << 1;
				 E3a = E3a << 1;    E3b = E3b << 1;     E3c = E3c << 1;     E3d = E3d << 1;
				 E2a = E2a << 1;    E2b = E2b << 1;     E2c = E2c << 1;     E2d = E2d << 1;
				 E1a = E1a << 1;    E1b = E1b << 1;     E1c = E1c << 1;     E1d = E1d << 1;
				       
				 E8e = E8e << 1;	E8f = E8f << 1;		E8g = E8g << 1;		E8h = E8h << 1;
				 E7e = E7e << 1;    E7f = E7f << 1;     E7g = E7g << 1;     E7h = E7h << 1;
				 E6e = E6e << 1;    E6f = E6f << 1;     E6g = E6g << 1;     E6h = E6h << 1;
				 E5e = E5e << 1;    E5f = E5f << 1;     E5g = E5g << 1;     E5h = E5h << 1;
				 E4e = E4e << 1;    E4f = E4f << 1;     E4g = E4g << 1;     E4h = E4h << 1;
				 E3e = E3e << 1;    E3f = E3f << 1;     E3g = E3g << 1;     E3h = E3h << 1;
				 E2e = E2e << 1;    E2f = E2f << 1;     E2g = E2g << 1;     E2h = E2h << 1;
				 E1e = E1e << 1;    E1f = E1f << 1;     E1g = E1g << 1;     E1h = E1h << 1;
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
		
	void LedCube8::shiftCubeR90(int count,bool reload,byte E8a,byte E8b,byte E8c,byte E8d,byte E8e,byte E8f,byte E8g,byte E8h, 
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
			byte buffer[8] = {E1h,E2h,E3h,E4h,E5h,E6h,E7h,E8h};
			if(reload == true)
			{
			  {
				  
				  E1h	=		  E1g;	E2h	=		  E2g;	E3h	=		  E3g;	E4h	=		  E4g;
				  E1g	=		  E1f;  E2g	=		  E2f;  E3g	=		  E3f;  E4g	=		  E4f;
				  E1f	=		  E1e;  E2f	=		  E2e;  E3f	=		  E3e;  E4f	=		  E4e;
				  E1e	=		  E1d;  E2e	=		  E2d;  E3e	=		  E3d;  E4e	=		  E4d;
				  E1d	=		  E1c;  E2d	=		  E2c;  E3d	=		  E3c;  E4d	=		  E4c;
				  E1c	=		  E1b;  E2c	=		  E2b;  E3c	=		  E3b;  E4c	=		  E4b;
				  E1b	=		  E1a;  E2b	=		  E2a;  E3b	=		  E3a;  E4b	=		  E4a;
				  E1a	=	buffer[0];  E2a	=	buffer[1];  E3a	=	buffer[2];  E4a	=	buffer[3];
				  
				  E5h	=		  E5g;	E6h	=		  E6g;	E7h	=		  E7g;	E8h	=		  E8g;
				  E5g	=		  E5f;  E6g	=		  E6f;  E7g	=		  E7f;  E8g	=		  E8f;
				  E5f	=		  E5e;  E6f	=		  E6e;  E7f	=		  E7e;  E8f	=		  E8e;
				  E5e	=		  E5d;  E6e	=		  E6d;  E7e	=		  E7d;  E8e	=		  E8d;
				  E5d	=		  E5c;  E6d	=		  E6c;  E7d	=		  E7c;  E8d	=		  E8c;
				  E5c	=		  E5b;  E6c	=		  E6b;  E7c	=		  E7b;  E8c	=		  E8b;
				  E5b	=		  E5a;  E6b	=		  E6a;  E7b	=		  E7a;  E8b	=		  E8a;
				  E5a	=	buffer[4];  E6a	=	buffer[5];  E7a	=	buffer[6];  E8a	=	buffer[7];
			  }                                
			}
			 else
			{
				  E1h = E1g;  E2h = E2g;  E3h = E3g;  E4h =	E4g;
				  E1g = E1f;  E2g = E2f;  E3g = E3f;  E4g =	E4f;
				  E1f = E1e;  E2f = E2e;  E3f = E3e;  E4f =	E4e;
				  E1e = E1d;  E2e = E2d;  E3e = E3d;  E4e =	E4d;
				  E1d = E1c;  E2d = E2c;  E3d = E3c;  E4d =	E4c;
				  E1c = E1b;  E2c = E2b;  E3c = E3b;  E4c =	E4b;
				  E1b = E1a;  E2b = E2a;  E3b = E3a;  E4b =	E4a;
				  E1a =	0;   E2a =	0;    E3a =	0;    E4a =	0;
				                                          
				  E5h = E5g;  E6h = E6g;  E7h = E7g;  E8h =	E8g;
				  E5g = E5f;  E6g = E6f;  E7g = E7f;  E8g =	E8f;
				  E5f = E5e;  E6f = E6e;  E7f = E7e;  E8f =	E8e;
				  E5e = E5d;  E6e = E6d;  E7e = E7d;  E8e =	E8d;
				  E5d = E5c;  E6d = E6c;  E7d = E7c;  E8d =	E8c;
				  E5c = E5b;  E6c = E6b;  E7c = E7b;  E8c =	E8b;
				  E5b = E5a;  E6b = E6a;  E7b = E7a;  E8b =	E8a;
				  E5a =	0;   E6a =	0;    E7a =	0;    E8a =	0;
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


void LedCube8::shiftCubeL90(int count,bool reload,byte E8a,byte E8b,byte E8c,byte E8d,byte E8e,byte E8f,byte E8g,byte E8h, 
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
			byte buffer[8] = {E1a,E2a,E3a,E4a,E5a,E6a,E7a,E8a};
			if(reload == true)
			{
			  {
				  
				  E1a	=		  E1b;	E2a	=		  E2b;	E3a	=		  E3b;	E4a	=		  E4b;
				  E1b	=		  E1c;  E2b	=		  E2c;  E3b	=		  E3c;  E4b	=		  E4c;
				  E1c	=		  E1d;  E2c	=		  E2d;  E3c	=		  E3d;  E4c	=		  E4d;
				  E1d	=		  E1e;  E2d	=		  E2e;  E3d	=		  E3e;  E4d	=		  E4e;
				  E1e	=		  E1f;  E2e	=		  E2f;  E3e	=		  E3f;  E4e	=		  E4f;
				  E1f	=		  E1g;  E2f	=		  E2g;  E3f	=		  E3g;  E4f	=		  E4g;
				  E1g	=		  E1h;  E2g	=		  E2h;  E3g	=		  E3h;  E4g	=		  E4h;
				  E1h	=	buffer[0];  E2h	=	buffer[1];  E3h	=	buffer[2];  E4h	=	buffer[3];
				  
				  E5a	=		  E5b;	E6a	=		  E6b;	E7a	=		  E7b;	E8a	=		  E8b;
				  E5b	=		  E5c;  E6b	=		  E6c;  E7b	=		  E7c;  E8b	=		  E8c;
				  E5c	=		  E5d;  E6c	=		  E6d;  E7c	=		  E7d;  E8c	=		  E8d;
				  E5d	=		  E5e;  E6d	=		  E6e;  E7d	=		  E7e;  E8d	=		  E8e;
				  E5e	=		  E5f;  E6e	=		  E6f;  E7e	=		  E7f;  E8e	=		  E8f;
				  E5f	=		  E5g;  E6f	=		  E6g;  E7f	=		  E7g;  E8f	=		  E8g;
				  E5g	=		  E5h;  E6g	=		  E6h;  E7g	=		  E7h;  E8g	=		  E8h;
				  E5h	=	buffer[4];  E6h	=	buffer[5];  E7h	=	buffer[6];  E8h	=	buffer[7];
			  }                                
			}
			 else
			{
				  E1a	= E1b;	E2a	= E2b;	E3a	= E3b;	E4a	= E4b;
				  E1b	= E1c;  E2b	= E2c;  E3b	= E3c;  E4b	= E4c;
				  E1c	= E1d;  E2c	= E2d;  E3c	= E3d;  E4c	= E4d;
				  E1d	= E1e;  E2d	= E2e;  E3d	= E3e;  E4d	= E4e;
				  E1e	= E1f;  E2e	= E2f;  E3e	= E3f;  E4e	= E4f;
				  E1f	= E1g;  E2f	= E2g;  E3f	= E3g;  E4f	= E4g;
				  E1g	= E1h;  E2g	= E2h;  E3g	= E3h;  E4g	= E4h;
				  E1h	=	0;  E2h	=	0;  E3h	=	0;  E4h	=	0;
				  
				  E5a	= E5b;	E6a	= E6b;	E7a	= E7b;	E8a	= E8b;
				  E5b	= E5c;  E6b	= E6c;  E7b	= E7c;  E8b	= E8c;
				  E5c	= E5d;  E6c	= E6d;  E7c	= E7d;  E8c	= E8d;
				  E5d	= E5e;  E6d	= E6e;  E7d	= E7e;  E8d	= E8e;
				  E5e	= E5f;  E6e	= E6f;  E7e	= E7f;  E8e	= E8f;
				  E5f	= E5g;  E6f	= E6g;  E7f	= E7g;  E8f	= E8g;
				  E5g	= E5h;  E6g	= E6h;  E7g	= E7h;  E8g	= E8h;
				  E5h	=	0;  E6h	=	0;  E7h	=	0;  E8h	=	0;
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
	
	void LedCube8::shiftCubeUp(int count,bool reload,byte E8a,byte E8b,byte E8c,byte E8d,byte E8e,byte E8f,byte E8g,byte E8h, 
								byte E7a,byte E7b,byte E7c,byte E7d,byte E7e,byte E7f,byte E7g,byte E7h,
								byte E6a,byte E6b,byte E6c,byte E6d,byte E6e,byte E6f,byte E6g,byte E6h,
								byte E5a,byte E5b,byte E5c,byte E5d,byte E5e,byte E5f,byte E5g,byte E5h,
								byte E4a,byte E4b,byte E4c,byte E4d,byte E4e,byte E4f,byte E4g,byte E4h,
								byte E3a,byte E3b,byte E3c,byte E3d,byte E3e,byte E3f,byte E3g,byte E3h,
								byte E2a,byte E2b,byte E2c,byte E2d,byte E2e,byte E2f,byte E2g,byte E2h,
								byte E1a,byte E1b,byte E1c,byte E1d,byte E1e,byte E1f,byte E1g,byte E1h)

		{
			  byte buffer1;
			  byte buffer2;
			  byte buffer3;
			  byte buffer4;
			  byte buffer5;
			  byte buffer6;
			  byte buffer7;
			  byte buffer8;
			
			if (reload == true)
			{
				for(int i = 0; i < count; i++)
				{
					
					
					
					drawCube(E8a,E8b,E8c,E8d,E8e,E8f,E8g,E8h,
							 E7a,E7b,E7c,E7d,E7e,E7f,E7g,E7h,
							 E6a,E6b,E6c,E6d,E6e,E6f,E6g,E6h,
							 E5a,E5b,E5c,E5d,E5e,E5f,E5g,E5h,
							 E4a,E4b,E4c,E4d,E4e,E4f,E4g,E4h,
							 E3a,E3b,E3c,E3d,E3e,E3f,E3g,E3h,
							 E2a,E2b,E2c,E2d,E2e,E2f,E2g,E2h,
							 E1a,E1b,E1c,E1d,E1e,E1f,E1g,E1h);
								
					buffer1 = E1a;
					buffer2 = E1b;
					buffer3 = E1c;
					buffer4 = E1d;
					buffer5 = E1e;
					buffer6 = E1f;
					buffer7 = E1g;
					buffer8 = E1h;
					
					E1a = E8a;
					E1b = E8b;
					E1c = E8c;
					E1d = E8d;
					E1e = E8e;
					E1f = E8f;
					E1g = E8g;
					E1h = E8h;
					
					E8a = E7a;
					E8b = E7b;
					E8c = E7c;
					E8d = E7d;
					E8e = E7e;
					E8f = E7f;
					E8g = E7g;
					E8h = E7h;
					
					E7a = E6a;
					E7b = E6b;
					E7c = E6c;
					E7d = E6d;
					E7e = E6e;
					E7f = E6f;
					E7g = E6g;
					E7h = E6h;
					
					E6a = E5a;
					E6b = E5b;
					E6c = E5c;
					E6d = E5d;
					E6e = E5e;
					E6f = E5f;
					E6g = E5g;
					E6h = E5h;
					
					E5a = E4a;
					E5b = E4b;
					E5c = E4c;
					E5d = E4d;
					E5e = E4e;
					E5f = E4f;
					E5g = E4g;
					E5h = E4h;
					
					E4a = E3a;
					E4b = E3b;
					E4c = E3c;
					E4d = E3d;
					E4e = E3e;
					E4f = E3f;
					E4g = E3g;
					E4h = E3h;
					
					E3a = E2a;
					E3b = E2b;
					E3c = E2c;
					E3d = E2d;
					E3e = E2e;
					E3f = E2f;
					E3g = E2g;
					E3h = E2h;
					
					E2a = buffer1;
					E2b = buffer2;
					E2c = buffer3;
					E2d = buffer4;
					E2e = buffer5;
					E2f = buffer6;
					E2g = buffer7;
					E2h = buffer8;
					
					
				}
			}
			else
			{
				for(int i = 0; i < count; i++)
				{
					
				}
			}	
		}				
	void LedCube8::shiftCubeDown(int count,bool reload,byte E8a,byte E8b,byte E8c,byte E8d,byte E8e,byte E8f,byte E8g,byte E8h, 
								byte E7a,byte E7b,byte E7c,byte E7d,byte E7e,byte E7f,byte E7g,byte E7h,
								byte E6a,byte E6b,byte E6c,byte E6d,byte E6e,byte E6f,byte E6g,byte E6h,
								byte E5a,byte E5b,byte E5c,byte E5d,byte E5e,byte E5f,byte E5g,byte E5h,
								byte E4a,byte E4b,byte E4c,byte E4d,byte E4e,byte E4f,byte E4g,byte E4h,
								byte E3a,byte E3b,byte E3c,byte E3d,byte E3e,byte E3f,byte E3g,byte E3h,
								byte E2a,byte E2b,byte E2c,byte E2d,byte E2e,byte E2f,byte E2g,byte E2h,
								byte E1a,byte E1b,byte E1c,byte E1d,byte E1e,byte E1f,byte E1g,byte E1h)							
		{
			if (reload == true)
			{
				byte buffer1;
				byte buffer2;
				byte buffer3;
				byte buffer4;
				byte buffer5;
				byte buffer6;
				byte buffer7;
				byte buffer8;
				
				
				
				for(int i = 0; i < count; i++)
				{
					drawCube(E8a,E8b,E8c,E8d,E8e,E8f,E8g,E8h,
							 E7a,E7b,E7c,E7d,E7e,E7f,E7g,E7h,
							 E6a,E6b,E6c,E6d,E6e,E6f,E6g,E6h,
							 E5a,E5b,E5c,E5d,E5e,E5f,E5g,E5h,
							 E4a,E4b,E4c,E4d,E4e,E4f,E4g,E4h,
							 E3a,E3b,E3c,E3d,E3e,E3f,E3g,E3h,
							 E2a,E2b,E2c,E2d,E2e,E2f,E2g,E2h,
							 E1a,E1b,E1c,E1d,E1e,E1f,E1g,E1h);
								
					buffer1 = E8a;
					buffer2 = E8b;
					buffer3 = E8c;
					buffer4 = E8d;
					buffer5 = E8e;
					buffer6 = E8f;
					buffer7 = E8g;
					buffer8 = E8h;
					
					E8a = E1a;
					E8b = E1b;
					E8c = E1c;
					E8d = E1d;
					E8e = E1e;
					E8f = E1f;
					E8g = E1g;
					E8h = E1h;
					
					E1a = E2a;
					E1b = E2b;
					E1c = E2c;
					E1d = E2d;
					E1e = E2e;
					E1f = E2f;
					E1g = E2g;
					E1h = E2h;
					
					E2a = E3a;
					E2b = E3b;
					E2c = E3c;
					E2d = E3d;
					E2e = E3e;
					E2f = E3f;
					E2g = E3g;
					E2h = E3h;
					
					E3a = E4a;
					E3b = E4b;
					E3c = E4c;
					E3d = E4d;
					E3e = E4e;
					E3f = E4f;
					E3g = E4g;
					E3h = E4h;
					
					E4a = E5a;
					E4b = E5b;
					E4c = E5c;
					E4d = E5d;
					E4e = E5e;
					E4f = E5f;
					E4g = E5g;
					E4h = E5h;
					
					E5a = E6a;
					E5b = E6b;
					E5c = E6c;
					E5d = E6d;
					E5e = E6e;
					E5f = E6f;
					E5g = E6g;
					E5h = E6h;
					
					E6a = E7a;
					E6b = E7b;
					E6c = E7c;
					E6d = E7d;
					E6e = E7e;
					E6f = E7f;
					E6g = E7g;
					E6h = E7h;
					
					E7a = buffer1;
					E7b = buffer2;
					E7c = buffer3;
					E7d = buffer4;
					E7e = buffer5;
					E7f = buffer6;
					E7g = buffer7;
					E7h = buffer8;
				}
			}
			else
			{
				for(int i = 0; i < count; i++)
				{
					E1a = E2a;
					E1b = E2b;
					E1c = E2c;
					E1d = E2d;
					E1e = E2e;
					E1f = E2f;
					E1g = E2g;
					E1h = E2h;
					
					E2a = E3a;
					E2b = E3b;
					E2c = E3c;
					E2d = E3d;
					E2e = E3e;
					E2f = E3f;
					E2g = E3g;
					E2h = E3h;
					
					E3a = E4a;
					E3b = E4b;
					E3c = E4c;
					E3d = E4d;
					E3e = E4e;
					E3f = E4f;
					E3g = E4g;
					E3h = E4h;
					
					E4a = E5a;
					E4b = E5b;
					E4c = E5c;
					E4d = E5d;
					E4e = E5e;
					E4f = E5f;
					E4g = E5g;
					E4h = E5h;
					
					E5a = E6a;
					E5b = E6b;
					E5c = E6c;
					E5d = E6d;
					E5e = E6e;
					E5f = E6f;
					E5g = E6g;
					E5h = E6h;
					
					E6a = E7a;
					E6b = E7b;
					E6c = E7c;
					E6d = E7d;
					E6e = E7e;
					E6f = E7f;
					E6g = E7g;
					E6h = E7h;
					
					E7a = E8a;
					E7b = E8b;
					E7c = E8c;
					E7d = E8d;
					E7e = E8e;
					E7f = E8f;
					E7g = E8g;
					E7h = E8h;
					
					E8a = 0;
					E8b = 0;
					E8c = 0;
					E8d = 0;
					E8e = 0;
					E8f = 0;
					E8g = 0;
					E8h = 0;
				}
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
	}	
		
	void LedCube8::rain(byte count,byte amount)
	{
		if(amount > 100)
		{
			amount = 100;
		}
		if(amount < 1)
		{
			amount = 1;
		}
		
		byte a	= 0;
		byte b	= 0;
		byte c	= 0;
		byte d	= 0;
		byte e	= 0;
		byte f	= 0;
		byte g	= 0;
		byte h	= 0;
		
		
		byte ab = 0;	byte ac = 0;	byte ad = 0;	byte ae = 0;	byte af = 0;	byte ag = 0;	byte ah = 0;
		byte bb = 0;    byte bc = 0;    byte bd = 0;    byte be = 0;    byte bf = 0;    byte bg = 0;    byte bh = 0;
		byte cb = 0;    byte cc = 0;    byte cd = 0;    byte ce = 0;    byte cf = 0;    byte cg = 0;    byte ch = 0;
		byte db = 0;    byte dc = 0;    byte dd = 0;    byte de = 0;    byte df = 0;    byte dg = 0;    byte dh = 0;
		byte eb = 0;    byte ec = 0;    byte ed = 0;    byte ee = 0;    byte ef = 0;    byte eg = 0;    byte eh = 0;
		byte fb = 0;    byte fc = 0;    byte fd = 0;    byte fe = 0;    byte ff = 0;    byte fg = 0;    byte fh = 0;
		byte gb = 0;    byte gc = 0;    byte gd = 0;    byte ge = 0;    byte gf = 0;    byte gg = 0;    byte gh = 0;
		byte hb = 0;    byte hc = 0;    byte hd = 0;    byte he = 0;    byte hf = 0;    byte hg = 0;    byte hh = 0;
		
		
		for(int x = 0; x<count; x++)
		{
			for(int i = 8; i>=1; i--)
			{
				byte randomBit1 = 0;
				byte randomBit2 = 0;
				byte randomBit3 = 0;
				byte randomBit4 = 0;
				byte randomBit5 = 0;
				byte randomBit6 = 0;
				byte randomBit7 = 0;
				byte randomBit8 = 0;
				
				
				for(int i = 0; i<8; i++)
				{
					
					randomBit1 = random(amount,105);
					randomBit2 = random(amount,105);
					randomBit3 = random(amount,105);
					randomBit4 = random(amount,105);
					randomBit5 = random(amount,105);
					randomBit6 = random(amount,105);
					randomBit7 = random(amount,105);
					randomBit8 = random(amount,105);
					
					{
					if(randomBit1 > 100)
					{
						randomBit1 = 1;
					}
					else
					{
						randomBit1 = 0;
					}
					if(randomBit2 > 100)
					{
						randomBit2 = 1;
					}
					else
					{
						randomBit2 = 0;
					}				
					if(randomBit3 > 100)
					{
						randomBit3 = 1;
					}
					else
					{
						randomBit3 = 0;
					}				
					if(randomBit4 > 100)
					{
						randomBit4 = 1;
					}
					else
					{
						randomBit4 = 0;
					}				
					if(randomBit5 > 100)
					{
						randomBit5 = 1;
					}
					else
					{
						randomBit5 = 0;
					}				
					if(randomBit6 > 100)
					{
						randomBit6 = 1;
					}
					else
					{
						randomBit6 = 0;
					}				
					if(randomBit7 > 100)
					{
						randomBit7 = 1;
					}
					else
					{
						randomBit7 = 0;
					}				
					if(randomBit8 > 100)
					{
						randomBit8 = 1;
					}
					else
					{
						randomBit8 = 0;
					}
					if(i == 0)
					{
					a = randomBit1 + (randomBit2 << 1) + (randomBit3 << 2) + (randomBit4 << 3) + (randomBit5 << 4) + (randomBit6 << 5) + (randomBit7 << 6) + (randomBit8 << 7);
					}
					if(i == 1)
					{
					b = randomBit1 + (randomBit2 << 1) + (randomBit3 << 2) + (randomBit4 << 3) + (randomBit5 << 4) + (randomBit6 << 5) + (randomBit7 << 6) + (randomBit8 << 7);
					}
					if(i == 2)
					{
					c = randomBit1 + (randomBit2 << 1) + (randomBit3 << 2) + (randomBit4 << 3) + (randomBit5 << 4) + (randomBit6 << 5) + (randomBit7 << 6) + (randomBit8 << 7);
					}
					if(i == 3)
					{
					d = randomBit1 + (randomBit2 << 1) + (randomBit3 << 2) + (randomBit4 << 3) + (randomBit5 << 4) + (randomBit6 << 5) + (randomBit7 << 6) + (randomBit8 << 7);
					}
					if(i == 4)
					{
					e = randomBit1 + (randomBit2 << 1) + (randomBit3 << 2) + (randomBit4 << 3) + (randomBit5 << 4) + (randomBit6 << 5) + (randomBit7 << 6) + (randomBit8 << 7);
					}
					if(i == 5)
					{
					f = randomBit1 + (randomBit2 << 1) + (randomBit3 << 2) + (randomBit4 << 3) + (randomBit5 << 4) + (randomBit6 << 5) + (randomBit7 << 6) + (randomBit8 << 7);
					}
					if(i == 6)
					{
					g = randomBit1 + (randomBit2 << 1) + (randomBit3 << 2) + (randomBit4 << 3) + (randomBit5 << 4) + (randomBit6 << 5) + (randomBit7 << 6) + (randomBit8 << 7);
					}
					if(i == 7)
					{
					h = randomBit1 + (randomBit2 << 1) + (randomBit3 << 2) + (randomBit4 << 3) + (randomBit5 << 4) + (randomBit6 << 5) + (randomBit7 << 6) + (randomBit8 << 7);
					}
					}
				}	
				
				drawCube(a,b,c,d,e,f,g,h,
						ab,bb,cb,db,eb,fb,gb,hb,
						ac,bc,cc,dc,ec,fc,gc,hc,
						ad,bd,cd,dd,ed,fd,gd,hd,
						ae,be,ce,de,ee,fe,ge,he,
						af,bf,cf,df,ef,ff,gf,hf,
						ag,bg,cg,dg,eg,fg,gg,hg,
						ah,bh,ch,dh,eh,fh,gh,hh);
				{				
				ah = ag;
				bh = bg;
				ch = cg;
				dh = dg;
				eh = eg;
				fh = fg;
				gh = gg;
				hh = hg;

				ag = af;
				bg = bf;
				cg = cf;
				dg = df;
				eg = ef;
				fg = ff;
				gg = gf;
				hg = hf;
	
				af = ae;
				bf = be;
				cf = ce;
				df = de;
				ef = ee;
				ff = fe;
				gf = ge;
				hf = he;
				
				ae = ad;
				be = bd;
				ce = cd;
				de = dd;
				ee = ed;
				fe = fd;
				ge = gd;
				he = hd;
				
				ad = ac;
				bd = bc;
				cd = cc;
				dd = dc;
				ed = ec;
				fd = fc;
				gd = gc;
				hd = hc;
				
				ac = ab;
				bc = bb;
				cc = cb;
				dc = db;
				ec = eb;
				fc = fb;
				gc = gb;
				hc = hb;

				ab = a;	
				bb = b;
				cb = c;
				db = d;
				eb = e;
				fb = f;
				gb = g;
				hb = h;
				}
			}		
		}
	}
	void LedCube8::writeLayer(char text[],byte lenge,byte layer)
	{
		
		
		byte A[8] = {24,24,36,36,60,102,66,66};
		byte B[8] = {120,68,68,120,68,68,68,120};
		byte C[8] = {28,32,64,64,64,64,32,28};
		byte D[8] = {112,72,68,68,68,68,72,112};
		byte E[8] = {124,64,64,120,64,64,64,124};
		byte F[8] = {124,64,64,120,64,64,64,64};
		byte G[8] = {28,34,64,64,78,66,34,28};
		byte H[8] = {66,66,66,126,66,66,66,66};
		byte I[8] = {60,24,24,24,24,24,24,60};
		byte J[8] = {60,4,4,4,4,36,36,24};
		byte K[8] = {66,68,72,112,72,68,66,66};
		byte L[8] = {32,32,32,32,32,32,32,60};
		byte M[8] = {66,102,90,90,66,66,66,66};
		byte N[8] = {66,98,82,82,74,74,70,66};
		byte O[8] = {24,36,66,66,66,66,36,24};
		byte P[8] = {120,68,68,68,120,64,64,64};
		byte Q[8] = {24,36,66,66,66,74,36,26};
		byte R[8] = {120,68,68,68,120,68,68,68};
		byte S[8] = {60,64,64,60,2,2,2,60};
		byte T[8] = {126,126,24,24,24,24,24,24};
		byte U[8] = {66,66,66,66,66,66,36,24};
		byte V[8] = {66,66,66,66,36,36,24,24};
		byte W[8] = {66,66,66,66,90,90,102,66};
		byte X[8] = {66,36,36,24,24,36,36,66};
		byte Y[8] = {66,102,60,24,24,24,24,24};
		byte Z[8] = {126,66,4,8,16,32,66,126};
		
		byte a[8] = {0,52,76,68,68,76,52,0};
		byte b[8] = {0,32,32,56,36,36,56,0};
		byte c[8] = {0,0,0,24,32,32,24,0};
		byte d[8] = {4,4,4,28,36,36,28,0};
		byte e[8] = {0,0,24,36,60,32,24,0};
		byte f[8] = {8,20,16,56,16,16,16,0};
		byte g[8] = {0,0,28,36,36,28,4,28};
		byte h[8] = {0,32,32,32,56,36,36,0};
		byte i[8] = {0,16,0,0,16,16,16,0};
		byte j[8] = {0,8,0,8,8,8,40,24};
		byte k[8] = {0,32,32,40,48,40,36,0};
		byte l[8] = {0,16,16,16,16,20,24,0};
		byte m[8] = {0,0,0,0,32,60,42,42};
		byte n[8] = {0,0,0,0,16,28,20,20};
		byte o[8] = {0,0,0,24,36,36,24,0};
		byte p[8] = {0,0,56,36,36,56,32,32};
		byte q[8] = {0,0,28,36,36,28,4,4};
		byte r[8] = {0,0,32,56,36,32,32,0};
		byte s[8] = {0,0,24,32,16,8,48,0};
		byte t[8] = {0,16,56,16,16,16,16,0};
		byte u[8] = {0,0,0,36,36,36,28,0};
		byte v[8] = {0,0,0,0,20,20,8,0};
		byte w[8] = {0,0,0,0,42,42,20,0};
		byte x[8] = {0,0,0,0,20,8,20,0};
		byte y[8] = {0,0,0,0,20,8,16,32};
		byte z[8] = {0,0,0,60,8,16,60,0};
		
		byte nul	[8] = {60,98,82,82,74,74,70,60};
		byte eins	[8] = {8,24,40,8,8,8,8,28};
		byte zwei	[8] = {60,66,66,4,8,16,34,126};
		byte drei	[8] = {56,4,4,56,4,4,4,56};
		byte vier	[8] = {4,12,20,36,126,4,4,4};
		byte fuenf	[8] = {126,64,64,124,2,2,66,60};
		byte sechs	[8] = {60,66,64,124,66,66,66,60};
		byte siben	[8] = {62,66,4,8,16,32,64,0};
		byte acht	[8] = {60,66,66,60,66,66,66,60};
		byte neun	[8] = {60,66,66,66,62,2,66,60};
		
		byte ausruffezeichen  [8] = {24,24,24,24,24,0,24,24};
	//	byte gaensefuesse     [8] = {18,36,36,0,0,0,0,0};
		byte hastag           [8] = {0,18,127,36,36,254,72,0};
		byte prozent          [8] = {0,98,100,8,16,38,70,0};
		byte und              [8] = {48,72,48,48,74,68,58,0};
		byte halbGaense       [8] = {8,8,8,0,0,0,0,0};
		byte klammerAuf       [8] = {12,16,32,32,32,32,16,12};
		byte klammerZu        [8] = {24,4,2,2,2,2,4,24};
		byte plus             [8] = {0,24,24,126,126,24,24,0};
		byte komma            [8] = {0,0,0,0,0,12,24,48};
		byte minus            [8] = {0,0,0,126,126,0,0,0};
		byte punkt            [8] = {0,0,0,0,0,24,24,0};
		byte schregstrich     [8] = {0,12,12,24,24,48,48,0};
		byte doppelpunkt      [8] = {0,24,24,0,0,24,24,0};
		byte simikolon        [8] = {0,24,24,0,0,24,56,32};
		byte kleinerAls       [8] = {0,6,24,96,96,24,6,0};
		byte gleich           [8] = {0,126,126,0,0,126,126,0};
		byte groesserAls      [8] = {0,96,24,6,6,24,96,0};
		byte fragezeichen     [8] = {28,34,34,4,8,8,0,8};
		byte at               [8] = {56,68,156,164,164,156,65,62};
		byte EKlammerAuf      [8] = {56,32,32,32,32,32,32,56};
	//	byte backSlash        [8] = {0,96,112,56,28,14,6,0};
		byte EKlammerZu       [8] = {28,4,4,4,4,4,4,28};
		byte dach             [8] = {16,40,68,0,0,0,0,0};
		byte apostrof         [8] = {8,4,0,0,0,0,0,0};
		byte geschwKlammerAuf [8] = {28,32,16,96,16,32,32,28};
		byte senkrechtStrich  [8] = {24,24,24,24,24,24,24,24};
		byte geschwKlammerZu  [8] = {56,4,8,6,8,4,4,56};
		byte welle            [8] = {0,0,0,50,76,0,0,0};
		 
		
		
		for(int co = 0; co <lenge; co++)
		{
			for(int count = 1; count <255; count++)
			{
				if(text[co]==count)
				{
				if(count ==65){draw(layer,A[0],A[1],A[2],A[3],A[4],A[5],A[6],A[7]);}	
				if(count ==66){draw(layer,B[0],B[1],B[2],B[3],B[4],B[5],B[6],B[7]);}	
				if(count ==67){draw(layer,C[0],C[1],C[2],C[3],C[4],C[5],C[6],C[7]);}	
				if(count ==68){draw(layer,D[0],D[1],D[2],D[3],D[4],D[5],D[6],D[7]);}	
				if(count ==69){draw(layer,E[0],E[1],E[2],E[3],E[4],E[5],E[6],E[7]);}	
				if(count ==70){draw(layer,F[0],F[1],F[2],F[3],F[4],F[5],F[6],F[7]);}	
				if(count ==71){draw(layer,G[0],G[1],G[2],G[3],G[4],G[5],G[6],G[7]);}	
				if(count ==72){draw(layer,H[0],H[1],H[2],H[3],H[4],H[5],H[6],H[7]);}	
				if(count ==73){draw(layer,I[0],I[1],I[2],I[3],I[4],I[5],I[6],I[7]);}	
				if(count ==74){draw(layer,J[0],J[1],J[2],J[3],J[4],J[5],J[6],J[7]);}	
				if(count ==75){draw(layer,K[0],K[1],K[2],K[3],K[4],K[5],K[6],K[7]);}	
				if(count ==76){draw(layer,L[0],L[1],L[2],L[3],L[4],L[5],L[6],L[7]);}	
				if(count ==77){draw(layer,M[0],M[1],M[2],M[3],M[4],M[5],M[6],M[7]);}	
				if(count ==78){draw(layer,N[0],N[1],N[2],N[3],N[4],N[5],N[6],N[7]);}	
				if(count ==79){draw(layer,O[0],O[1],O[2],O[3],O[4],O[5],O[6],O[7]);}	
				if(count ==80){draw(layer,P[0],P[1],P[2],P[3],P[4],P[5],P[6],P[7]);}	
				if(count ==81){draw(layer,Q[0],Q[1],Q[2],Q[3],Q[4],Q[5],Q[6],Q[7]);}	
				if(count ==82){draw(layer,R[0],R[1],R[2],R[3],R[4],R[5],R[6],R[7]);}	
				if(count ==83){draw(layer,S[0],S[1],S[2],S[3],S[4],S[5],S[6],S[7]);}	
				if(count ==84){draw(layer,T[0],T[1],T[2],T[3],T[4],T[5],T[6],T[7]);}	
				if(count ==85){draw(layer,U[0],U[1],U[2],U[3],U[4],U[5],U[6],U[7]);}	
				if(count ==86){draw(layer,V[0],V[1],V[2],V[3],V[4],V[5],V[6],V[7]);}	
				if(count ==87){draw(layer,W[0],W[1],W[2],W[3],W[4],W[5],W[6],W[7]);}	
				if(count ==88){draw(layer,X[0],X[1],X[2],X[3],X[4],X[5],X[6],X[7]);}	
				if(count ==89){draw(layer,Y[0],Y[1],Y[2],Y[3],Y[4],Y[5],Y[6],Y[7]);}	
				if(count ==90){draw(layer,Z[0],Z[1],Z[2],Z[3],Z[4],Z[5],Z[6],Z[7]);}	
					
				if(count ==97){draw(layer,a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7]);}	
				if(count ==98){draw(layer,b[0],b[1],b[2],b[3],b[4],b[5],b[6],b[7]);}	
				if(count ==99){draw(layer,c[0],c[1],c[2],c[3],c[4],c[5],c[6],c[7]);}	
				if(count ==100){draw(layer,d[0],d[1],d[2],d[3],d[4],d[5],d[6],d[7]);}	
				if(count ==101){draw(layer,e[0],e[1],e[2],e[3],e[4],e[5],e[6],e[7]);}	
				if(count ==102){draw(layer,f[0],f[1],f[2],f[3],f[4],f[5],f[6],f[7]);}	
				if(count ==103){draw(layer,g[0],g[1],g[2],g[3],g[4],g[5],g[6],g[7]);}	
				if(count ==104){draw(layer,h[0],h[1],h[2],h[3],h[4],h[5],h[6],h[7]);}	
				if(count ==105){draw(layer,i[0],i[1],i[2],i[3],i[4],i[5],i[6],i[7]);}	
				if(count ==106){draw(layer,j[0],j[1],j[2],j[3],j[4],j[5],j[6],j[7]);}	
				if(count ==107){draw(layer,k[0],k[1],k[2],k[3],k[4],k[5],k[6],k[7]);}	
				if(count ==108){draw(layer,l[0],l[1],l[2],l[3],l[4],l[5],l[6],l[7]);}	
				if(count ==109){draw(layer,m[0],m[1],m[2],m[3],m[4],m[5],m[6],m[7]);}	
				if(count ==110){draw(layer,n[0],n[1],n[2],n[3],n[4],n[5],n[6],n[7]);}	
				if(count ==111){draw(layer,o[0],o[1],o[2],o[3],o[4],o[5],o[6],o[7]);}	
				if(count ==112){draw(layer,p[0],p[1],p[2],p[3],p[4],p[5],p[6],p[7]);}	
				if(count ==113){draw(layer,q[0],q[1],q[2],q[3],q[4],q[5],q[6],q[7]);}	
				if(count ==114){draw(layer,r[0],r[1],r[2],r[3],r[4],r[5],r[6],r[7]);}	
				if(count ==115){draw(layer,s[0],s[1],s[2],s[3],s[4],s[5],s[6],s[7]);}	
				if(count ==116){draw(layer,t[0],t[1],t[2],t[3],t[4],t[5],t[6],t[7]);}	
				if(count ==117){draw(layer,u[0],u[1],u[2],u[3],u[4],u[5],u[6],u[7]);}	
				if(count ==118){draw(layer,v[0],v[1],v[2],v[3],v[4],v[5],v[6],v[7]);}	
				if(count ==119){draw(layer,w[0],w[1],w[2],w[3],w[4],w[5],w[6],w[7]);}	
				if(count ==120){draw(layer,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7]);}	
				if(count ==121){draw(layer,y[0],y[1],y[2],y[3],y[4],y[5],y[6],y[7]);}	
				if(count ==122){draw(layer,z[0],z[1],z[2],z[3],z[4],z[5],z[6],z[7]);}
                             
				if(count ==48){draw(layer,nul	[0],nul	 [1],nul  [2],nul  [3],nul	[4],nul	 [5],nul  [6],nul  [7]);}	
				if(count ==49){draw(layer,eins	[0],eins [1],eins [2],eins [3],eins [4],eins [5],eins [6],eins [7]);}	
				if(count ==50){draw(layer,zwei	[0],zwei [1],zwei [2],zwei [3],zwei [4],zwei [5],zwei [6],zwei [7]);}	
				if(count ==51){draw(layer,drei	[0],drei [1],drei [2],drei [3],drei [4],drei [5],drei [6],drei [7]);}	
				if(count ==52){draw(layer,vier	[0],vier [1],vier [2],vier [3],vier [4],vier [5],vier [6],vier [7]);}	
				if(count ==53){draw(layer,fuenf	[0],fuenf [1],fuenf [2],fuenf [3],fuenf [4],fuenf [5],fuenf [6],fuenf [7]);}	
				if(count ==54){draw(layer,sechs [0],sechs[1],sechs[2],sechs[3],sechs[4],sechs[5],sechs[6],sechs[7]);}	
				if(count ==55){draw(layer,siben [0],siben[1],siben[2],siben[3],siben[4],siben[5],siben[6],siben[7]);}	
				if(count ==56){draw(layer,acht	[0],acht [1],acht [2],acht [3],acht [4],acht [5],acht [6],acht [7]);}	
				if(count ==57){draw(layer,neun	[0],neun [1],neun [2],neun [3],neun [4],neun [5],neun [6],neun [7]);}
				
				if(count ==33){draw(layer,ausruffezeichen  [0],ausruffezeichen  [1],ausruffezeichen  [2],ausruffezeichen  [3],ausruffezeichen  [4],ausruffezeichen  [5],ausruffezeichen  [6],ausruffezeichen  [7]);}	
			//	if(count ==34){draw(layer,gaensefuesse     [0],gaensefuesse     [1],gaensefuesse     [2],gaensefuesse     [3],gaensefuesse     [4],gaensefuesse     [5],gaensefuesse     [6],gaensefuesse     [7]);}	
				if(count ==35){draw(layer,hastag           [0],hastag           [1],hastag           [2],hastag           [3],hastag           [4],hastag           [5],hastag           [6],hastag           [7]);}	
				if(count ==37){draw(layer,prozent          [0],prozent          [1],prozent          [2],prozent          [3],prozent          [4],prozent          [5],prozent          [6],prozent          [7]);}	
				if(count ==38){draw(layer,und              [0],und              [1],und              [2],und              [3],und              [4],und              [5],und              [6],und              [7]);}	
				if(count ==39){draw(layer,halbGaense       [0],halbGaense       [1],halbGaense       [2],halbGaense       [3],halbGaense       [4],halbGaense       [5],halbGaense       [6],halbGaense       [7]);}	
				if(count ==40){draw(layer,klammerAuf       [0],klammerAuf       [1],klammerAuf       [2],klammerAuf       [3],klammerAuf       [4],klammerAuf       [5],klammerAuf       [6],klammerAuf       [7]);}	
				if(count ==41){draw(layer,klammerZu        [0],klammerZu        [1],klammerZu        [2],klammerZu        [3],klammerZu        [4],klammerZu        [5],klammerZu        [6],klammerZu        [7]);}	
				if(count ==43){draw(layer,plus             [0],plus             [1],plus             [2],plus             [3],plus             [4],plus             [5],plus             [6],plus             [7]);}	
				if(count ==34){draw(layer,komma            [0],komma            [1],komma            [2],komma            [3],komma            [4],komma            [5],komma            [6],komma            [7]);}	
				if(count ==45){draw(layer,minus            [0],minus            [1],minus            [2],minus            [3],minus            [4],minus            [5],minus            [6],minus            [7]);}	
				if(count ==46){draw(layer,punkt            [0],punkt            [1],punkt            [2],punkt            [3],punkt            [4],punkt            [5],punkt            [6],punkt            [7]);}	
				if(count ==47){draw(layer,schregstrich     [0],schregstrich     [1],schregstrich     [2],schregstrich     [3],schregstrich     [4],schregstrich     [5],schregstrich     [6],schregstrich     [7]);}	
				if(count ==58){draw(layer,doppelpunkt      [0],doppelpunkt      [1],doppelpunkt      [2],doppelpunkt      [3],doppelpunkt      [4],doppelpunkt      [5],doppelpunkt      [6],doppelpunkt      [7]);}	
				if(count ==59){draw(layer,simikolon        [0],simikolon        [1],simikolon        [2],simikolon        [3],simikolon        [4],simikolon        [5],simikolon        [6],simikolon        [7]);}	
				if(count ==60){draw(layer,kleinerAls       [0],kleinerAls       [1],kleinerAls       [2],kleinerAls       [3],kleinerAls       [4],kleinerAls       [5],kleinerAls       [6],kleinerAls       [7]);}	
				if(count ==64){draw(layer,gleich           [0],gleich           [1],gleich           [2],gleich           [3],gleich           [4],gleich           [5],gleich           [6],gleich           [7]);}	
				if(count ==62){draw(layer,groesserAls      [0],groesserAls      [1],groesserAls      [2],groesserAls      [3],groesserAls      [4],groesserAls      [5],groesserAls      [6],groesserAls      [7]);}	
				if(count ==63){draw(layer,fragezeichen     [0],fragezeichen     [1],fragezeichen     [2],fragezeichen     [3],fragezeichen     [4],fragezeichen     [5],fragezeichen     [6],fragezeichen     [7]);}	
				if(count ==64){draw(layer,at               [0],at               [1],at               [2],at               [3],at               [4],at               [5],at               [6],at               [7]);}	
				if(count ==91){draw(layer,EKlammerAuf      [0],EKlammerAuf      [1],EKlammerAuf      [2],EKlammerAuf      [3],EKlammerAuf      [4],EKlammerAuf      [5],EKlammerAuf      [6],EKlammerAuf      [7]);}	
			//	if(count ==92){draw(layer,backSlash        [0],backSlash        [1],backSlash        [2],backSlash        [3],backSlash        [4],backSlash        [5],backSlash        [6],backSlash        [7]);}	
				if(count ==93){draw(layer,EKlammerZu       [0],EKlammerZu       [1],EKlammerZu       [2],EKlammerZu       [3],EKlammerZu       [4],EKlammerZu       [5],EKlammerZu       [6],EKlammerZu       [7]);}
				if(count ==94){draw(layer,dach             [0],dach             [1],dach             [2],dach             [3],dach             [4],dach             [5],dach             [6],dach             [7]);}	
				if(count ==96){draw(layer,apostrof         [0],apostrof         [1],apostrof         [2],apostrof         [3],apostrof         [4],apostrof         [5],apostrof         [6],apostrof         [7]);}	
				if(count ==123){draw(layer,geschwKlammerAuf[0],geschwKlammerAuf [1],geschwKlammerAuf [2],geschwKlammerAuf [3],geschwKlammerAuf [4],geschwKlammerAuf [5],geschwKlammerAuf [6],geschwKlammerAuf [7]);}	
				if(count ==124){draw(layer,senkrechtStrich [0],senkrechtStrich  [1],senkrechtStrich  [2],senkrechtStrich  [3],senkrechtStrich  [4],senkrechtStrich  [5],senkrechtStrich  [6],senkrechtStrich  [7]);}	
				if(count ==125){draw(layer,geschwKlammerZu [0],geschwKlammerZu  [1],geschwKlammerZu  [2],geschwKlammerZu  [3],geschwKlammerZu  [4],geschwKlammerZu  [5],geschwKlammerZu  [6],geschwKlammerZu  [7]);}
				if(count ==126){draw(layer,welle           [0],welle            [1],welle            [2],welle            [3],welle            [4],welle            [5],welle            [6],welle            [7]);}

				}
				if(text[co]==95)
				{
					draw(layer,0,0,0,0,0,0,0,0);
					
					co++;
				}
			}	
		}
	}		
		
	
	
	
	
	
  void LedCube8::time(int t)
  {
	  Time = t;
	  
	  TimeMicro = t*1000;
  }
  void LedCube8::hackLight(bool status)
  {
	  hackLightStatus = status;
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
 }