// Autor: 									Alex Krieg
// Erstellt:								6.12.2015
// Version 									2.2.1
// Kompatibel mit den versionen: 			2.2.0 2.0.0  2.1.0  2.1.1
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
		
	void LedCube8::rain(byte count)
	{
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
				a=random(0,255);
				b=random(0,255);
				c=random(0,255);
				d=random(0,255);
				e=random(0,255);
				f=random(0,255);
				g=random(0,255);
				h=random(0,255);
				
				
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
		
		for(int co = 0; co <lenge; co++)
		{
			for(int count = 65; count <91; count++)
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
					
					//Serial.println(count);
				}
				if(text[co]==95)
				{
					draw(layer,0,0,0,0,0,0,0,0);
					//Serial.println("_");
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