// Autor: 									Alex Krieg
// Erstellt:								3.5.16
// Version 									3.0.0 BUILD
// Kompatibel mit den versionen: 			*****
// Funktionen:								*****




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
	void LedCube8::draw(struct CUBEDATALAYER data)
	{
	 byte bufferHelligkeit = helligkeit;
	 if(hackLightStatus == false)
	 {
		helligkeit = helligkeit/8;
	 }
	setPin(data.A,countAddress());
	setPin(data.B,countAddress());
	setPin(data.C,countAddress());
	setPin(data.D,countAddress());
	setPin(data.E,countAddress());
	setPin(data.F,countAddress());
	setPin(data.G,countAddress());
	setPin(data.H,countAddress());
	setLayer(data.Layer,Time,10);
	PORTB = (PORTB & B111100) | ((B00000000 & B11000000) >> 6);  // pins nach dem setztn auf 0 scheriben
	PORTD = (PORTB & B00000011) |(B00000000 << 2);				 //
	
	helligkeit = bufferHelligkeit;
	 
 }
	void LedCube8::drawCube(struct CUBEDATACUBE data)
	{
		for(int i=0; i<Time/8; i++)
		{
			setPin(data.CA1, countAddress());
			setPin(data.CB1, countAddress());
			setPin(data.CC1, countAddress());
			setPin(data.CD1, countAddress());
			setPin(data.CE1, countAddress());
			setPin(data.CF1, countAddress());
			setPin(data.CG1, countAddress());
			setPin(data.CH1, countAddress());
			setLayer(1,1,10);
			
			setPin(data.CA2, countAddress());
			setPin(data.CB2, countAddress());
			setPin(data.CC2, countAddress());
			setPin(data.CD2, countAddress());
			setPin(data.CE2, countAddress());
			setPin(data.CF2, countAddress());
			setPin(data.CG2, countAddress());
			setPin(data.CH2, countAddress());
			setLayer(2,1,10); 
			             
			setPin(data.CA3, countAddress());
			setPin(data.CB3, countAddress());
			setPin(data.CC3, countAddress());
			setPin(data.CD3, countAddress());
			setPin(data.CE3, countAddress());
			setPin(data.CF3, countAddress());
			setPin(data.CG3, countAddress());
			setPin(data.CH3, countAddress());
			setLayer(3,1,10); 
			             
			setPin(data.CA4, countAddress());
			setPin(data.CB4, countAddress());
			setPin(data.CC4, countAddress());
			setPin(data.CD4, countAddress());
			setPin(data.CE4, countAddress());
			setPin(data.CF4, countAddress());
			setPin(data.CG4, countAddress());
			setPin(data.CH4, countAddress());
			setLayer(4,1,10); 
			             
			setPin(data.CA5, countAddress());
			setPin(data.CB5, countAddress());
			setPin(data.CC5, countAddress());
			setPin(data.CD5, countAddress());
			setPin(data.CE5, countAddress());
			setPin(data.CF5, countAddress());
			setPin(data.CG5, countAddress());
			setPin(data.CH5, countAddress());
			setLayer(5,1,10); 
			             
			setPin(data.CA6, countAddress());
			setPin(data.CB6, countAddress());
			setPin(data.CC6, countAddress());
			setPin(data.CD6, countAddress());
			setPin(data.CE6, countAddress());
			setPin(data.CF6, countAddress());
			setPin(data.CG6, countAddress());
			setPin(data.CH6, countAddress());
			setLayer(6,1,10); 
			             
			setPin(data.CA7, countAddress());
			setPin(data.CB7, countAddress());
			setPin(data.CC7, countAddress());
			setPin(data.CD7, countAddress());
			setPin(data.CE7, countAddress());
			setPin(data.CF7, countAddress());
			setPin(data.CG7, countAddress());
			setPin(data.CH7, countAddress());
			setLayer(7,1,10); 
			             
			setPin(data.CA8, countAddress());
			setPin(data.CB8, countAddress());
			setPin(data.CC8, countAddress());
			setPin(data.CD8, countAddress());
			setPin(data.CE8, countAddress());
			setPin(data.CF8, countAddress());
			setPin(data.CG8, countAddress());
			setPin(data.CH8, countAddress());
			setLayer(8,1,10);
		}
	}
	void LedCube8::drawLayer(byte layer)
	{
	  CUBEDATALAYER full {layer,255,255,255,255,255,255,255,255};
	  draw(full);
	  
	  
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
	void LedCube8::shiftLayerRight(int count,bool reload, struct CUBEDATALAYER data)
	{ 
	  draw(data);
	  for(int x = 0; x<count; x++)
	  {
		  if(reload == true)
		  {	  
			  data.A = ((data.A & B00000001 )<<7)| (data.A>>1);
			  data.B = ((data.B & B00000001 )<<7)| (data.B>>1);
			  data.C = ((data.C & B00000001 )<<7)| (data.C>>1);
			  data.D = ((data.D & B00000001 )<<7)| (data.D>>1);
			  data.E = ((data.E & B00000001 )<<7)| (data.E>>1);
			  data.F = ((data.F & B00000001 )<<7)| (data.F>>1);
			  data.G = ((data.G & B00000001 )<<7)| (data.G>>1);
			  data.H = ((data.H & B00000001 )<<7)| (data.H>>1);
		  }
		  else
		  {
			  data.A = data.A >> 1;
			  data.B = data.B >> 1;
			  data.C = data.C >> 1;
			  data.D = data.D >> 1;
			  data.E = data.E >> 1;
			  data.F = data.F >> 1;
			  data.G = data.G >> 1;
			  data.H = data.H >> 1;
		  }
		  draw(data);
	  }
  }
	void LedCube8::shiftLayerLeft(int count,bool reload, struct CUBEDATALAYER data)
	{
	  draw(data);
	  for(int x = 0; x<count; x++)
	  {
		  if(reload == true)
		  {	  
			  data.A = ((data.A&B10000000 )>>7)| (data.A<<1);
			  data.B = ((data.B&B10000000 )>>7)| (data.B<<1);
			  data.C = ((data.C&B10000000 )>>7)| (data.C<<1);
			  data.D = ((data.D&B10000000 )>>7)| (data.D<<1);
			  data.E = ((data.E&B10000000 )>>7)| (data.E<<1);
			  data.F = ((data.F&B10000000 )>>7)| (data.F<<1);
			  data.G = ((data.G&B10000000 )>>7)| (data.G<<1);
			  data.H = ((data.H&B10000000 )>>7)| (data.H<<1);
		  }
		  else
		  {
			  data.A = data.A << 1;
			  data.B = data.B << 1;
			  data.C = data.C << 1;
			  data.D = data.D << 1;
			  data.E = data.E << 1;
			  data.F = data.F << 1;
			  data.G = data.G << 1;
			  data.H = data.H << 1;
		  }
		  draw(data);
	  }
  }
	void LedCube8::shiftLayerRight90(int count,bool reload, struct CUBEDATALAYER data)
	{
	  draw(data);
	  for(int x = 0; x<count; x++)
	  {
		  byte buffer = data.H;
		  if(reload == true)
		  {	  	       
			  data.H = data.G;
			  data.G = data.F;
			  data.F = data.E;
			  data.E = data.D;
			  data.D = data.C;
			  data.C = data.B;
			  data.B = data.A;
			  data.A = buffer;
		  }
		  else
		  {            
			  data.H = data.G;
			  data.G = data.F;
			  data.F = data.E;
			  data.E = data.D;
			  data.D = data.C;
			  data.C = data.B;
			  data.B = data.A;
			  data.A = 0;
		  }
		  draw(data);
	  }
  }
	void LedCube8::shiftLayerLeft90(int count,bool reload, struct CUBEDATALAYER data)
	{
	  draw(data);
	  for(int x = 0; x<count; x++)
	  {
		  byte buffer = data.A;
		  if(reload == true)
		  {	          
			 data.A = data.B;
			 data.B = data.C;
			 data.C = data.D;
			 data.D = data.E;
			 data.E = data.F;
			 data.F = data.G;
			 data.G = data.H;
			 data.H = buffer;
		  }
		  else
		  {            
			  data.A = data.B;
			  data.B = data.C;
			  data.C = data.D;
			  data.D = data.E;
			  data.E = data.F;
			  data.F = data.G;
			  data.G = data.H;
			  data.H = 0;
		  }
		  draw(data);
	  }
  }
	void LedCube8::shiftLayerDown(int count,bool reload, struct CUBEDATALAYER data)
	{
		for(int i=0; i<count;i++)
		{
			draw(data);
			data.Layer--;
			if(data.Layer == 0 && reload == true)
			{
				data.Layer = 8;
			}
			if(data.Layer == 0)
			{
				return;
			}
		}
	}	
	void LedCube8::shiftLayerUp(int count,bool reload, struct CUBEDATALAYER data)
	{
		for(int i=0; i<count;i++)
		{
			draw(data);
			data.Layer++;
			if(data.Layer == 9 && reload == true)
			{
				data.Layer = 1;
			}
			if(data.Layer == 9)
			{
				return;
			}
		}
	} 
  void LedCube8::shiftCubeRight(int count,bool reload, struct CUBEDATACUBE data)
	{
		for(int x = 0; x<count; x++)
		{
			drawCube(data);
			if(reload == true)
			{
			  {
			  data.CA1 = ((data.CA1&B00000001 )<<7)| (data.CA1>>1);	data.CA2 = ((data.CA2&B00000001 )<<7)| (data.CA2>>1);
			  data.CB1 = ((data.CB1&B00000001 )<<7)| (data.CB1>>1);    data.CB2 = ((data.CB2&B00000001 )<<7)| (data.CB2>>1);
			  data.CC1 = ((data.CC1&B00000001 )<<7)| (data.CC1>>1);    data.CC2 = ((data.CC2&B00000001 )<<7)| (data.CC2>>1);
			  data.CD1 = ((data.CD1&B00000001 )<<7)| (data.CD1>>1);    data.CD2 = ((data.CD2&B00000001 )<<7)| (data.CD2>>1);
			  data.CE1 = ((data.CE1&B00000001 )<<7)| (data.CE1>>1);    data.CE2 = ((data.CE2&B00000001 )<<7)| (data.CE2>>1);
			  data.CF1 = ((data.CF1&B00000001 )<<7)| (data.CF1>>1);    data.CF2 = ((data.CF2&B00000001 )<<7)| (data.CF2>>1);
			  data.CG1 = ((data.CG1&B00000001 )<<7)| (data.CG1>>1);    data.CG2 = ((data.CG2&B00000001 )<<7)| (data.CG2>>1);
			  data.CH1 = ((data.CH1&B00000001 )<<7)| (data.CH1>>1);    data.CH2 = ((data.CH2&B00000001 )<<7)| (data.CH2>>1);
			  
			  
			  data.CA3 = ((data.CA3&B00000001 )<<7)| (data.CA3>>1);	data.CA4 = ((data.CA4&B00000001 )<<7)| (data.CA4>>1);
			  data.CB3 = ((data.CB3&B00000001 )<<7)| (data.CB3>>1);    data.CB4 = ((data.CB4&B00000001 )<<7)| (data.CB4>>1);
			  data.CC3 = ((data.CC3&B00000001 )<<7)| (data.CC3>>1);    data.CC4 = ((data.CC4&B00000001 )<<7)| (data.CC4>>1);
			  data.CD3 = ((data.CD3&B00000001 )<<7)| (data.CD3>>1);    data.CD4 = ((data.CD4&B00000001 )<<7)| (data.CD4>>1);
			  data.CE3 = ((data.CE3&B00000001 )<<7)| (data.CE3>>1);    data.CE4 = ((data.CE4&B00000001 )<<7)| (data.CE4>>1);
			  data.CF3 = ((data.CF3&B00000001 )<<7)| (data.CF3>>1);    data.CF4 = ((data.CF4&B00000001 )<<7)| (data.CF4>>1);
			  data.CG3 = ((data.CG3&B00000001 )<<7)| (data.CG3>>1);    data.CG4 = ((data.CG4&B00000001 )<<7)| (data.CG4>>1);
			  data.CH3 = ((data.CH3&B00000001 )<<7)| (data.CH3>>1);    data.CH4 = ((data.CH4&B00000001 )<<7)| (data.CH4>>1);
  
			  
			  data.CA5 = ((data.CA5&B00000001 )<<7)| (data.CA5>>1);	data.CA6 = ((data.CA6&B00000001 )<<7)| (data.CA6>>1);
			  data.CB5 = ((data.CB5&B00000001 )<<7)| (data.CB5>>1);    data.CB6 = ((data.CB6&B00000001 )<<7)| (data.CB6>>1);
			  data.CC5 = ((data.CC5&B00000001 )<<7)| (data.CC5>>1);    data.CC6 = ((data.CC6&B00000001 )<<7)| (data.CC6>>1);
			  data.CD5 = ((data.CD5&B00000001 )<<7)| (data.CD5>>1);    data.CD6 = ((data.CD6&B00000001 )<<7)| (data.CD6>>1);
			  data.CE5 = ((data.CE5&B00000001 )<<7)| (data.CE5>>1);    data.CE6 = ((data.CE6&B00000001 )<<7)| (data.CE6>>1);
			  data.CF5 = ((data.CF5&B00000001 )<<7)| (data.CF5>>1);    data.CF6 = ((data.CF6&B00000001 )<<7)| (data.CF6>>1);
			  data.CG5 = ((data.CG5&B00000001 )<<7)| (data.CG5>>1);    data.CG6 = ((data.CG6&B00000001 )<<7)| (data.CG6>>1);
			  data.CH5 = ((data.CH5&B00000001 )<<7)| (data.CH5>>1);    data.CH6 = ((data.CH6&B00000001 )<<7)| (data.CH6>>1);
			  
			  
			  data.CA7 = ((data.CA7&B00000001 )<<7)| (data.CA7>>1);	data.CA8 = ((data.CA8&B00000001 )<<7)| (data.CA8>>1);
			  data.CB7 = ((data.CB7&B00000001 )<<7)| (data.CB7>>1);    data.CB8 = ((data.CB8&B00000001 )<<7)| (data.CB8>>1);
			  data.CC7 = ((data.CC7&B00000001 )<<7)| (data.CC7>>1);    data.CC8 = ((data.CC8&B00000001 )<<7)| (data.CC8>>1);
			  data.CD7 = ((data.CD7&B00000001 )<<7)| (data.CD7>>1);    data.CD8 = ((data.CD8&B00000001 )<<7)| (data.CD8>>1);
			  data.CE7 = ((data.CE7&B00000001 )<<7)| (data.CE7>>1);    data.CE8 = ((data.CE8&B00000001 )<<7)| (data.CE8>>1);
			  data.CF7 = ((data.CF7&B00000001 )<<7)| (data.CF7>>1);    data.CF8 = ((data.CF8&B00000001 )<<7)| (data.CF8>>1);
			  data.CG7 = ((data.CG7&B00000001 )<<7)| (data.CG7>>1);    data.CG8 = ((data.CG8&B00000001 )<<7)| (data.CG8>>1);
			  data.CH7 = ((data.CH7&B00000001 )<<7)| (data.CH7>>1);    data.CH8 = ((data.CH8&B00000001 )<<7)| (data.CH8>>1); 
			  }
			}
			 else
			{
				 data.CA8 = data.CA8 >> 1;	data.CB8 = data.CB8 >> 1;		data.CC8 = data.CC8 >> 1;		data.CD8 = data.CD8 >> 1;
				 data.CA7 = data.CA7 >> 1;    data.CB7 = data.CB7 >> 1;     data.CC7 = data.CC7 >> 1;     data.CD7 = data.CD7 >> 1;
				 data.CA6 = data.CA6 >> 1;    data.CB6 = data.CB6 >> 1;     data.CC6 = data.CC6 >> 1;     data.CD6 = data.CD6 >> 1;
				 data.CA5 = data.CA5 >> 1;    data.CB5 = data.CB5 >> 1;     data.CC5 = data.CC5 >> 1;     data.CD5 = data.CD5 >> 1;
				 data.CA4 = data.CA4 >> 1;    data.CB4 = data.CB4 >> 1;     data.CC4 = data.CC4 >> 1;     data.CD4 = data.CD4 >> 1;
				 data.CA3 = data.CA3 >> 1;    data.CB3 = data.CB3 >> 1;     data.CC3 = data.CC3 >> 1;     data.CD3 = data.CD3 >> 1;
				 data.CA2 = data.CA2 >> 1;    data.CB2 = data.CB2 >> 1;     data.CC2 = data.CC2 >> 1;     data.CD2 = data.CD2 >> 1;
				 data.CA1 = data.CA1 >> 1;    data.CB1 = data.CB1 >> 1;     data.CC1 = data.CC1 >> 1;     data.CD1 = data.CD1 >> 1;
				 
				 data.CE8 = data.CE8 >> 1;	data.CF8 = data.CF8 >> 1;		data.CG8 = data.CG8 >> 1;		data.CH8 = data.CH8 >> 1;
				 data.CE7 = data.CE7 >> 1;    data.CF7 = data.CF7 >> 1;     data.CG7 = data.CG7 >> 1;     data.CH7 = data.CH7 >> 1;
				 data.CE6 = data.CE6 >> 1;    data.CF6 = data.CF6 >> 1;     data.CG6 = data.CG6 >> 1;     data.CH6 = data.CH6 >> 1;
				 data.CE5 = data.CE5 >> 1;    data.CF5 = data.CF5 >> 1;     data.CG5 = data.CG5 >> 1;     data.CH5 = data.CH5 >> 1;
				 data.CE4 = data.CE4 >> 1;    data.CF4 = data.CF4 >> 1;     data.CG4 = data.CG4 >> 1;     data.CH4 = data.CH4 >> 1;
				 data.CE3 = data.CE3 >> 1;    data.CF3 = data.CF3 >> 1;     data.CG3 = data.CG3 >> 1;     data.CH3 = data.CH3 >> 1;
				 data.CE2 = data.CE2 >> 1;    data.CF2 = data.CF2 >> 1;     data.CG2 = data.CG2 >> 1;     data.CH2 = data.CH2 >> 1;
				 data.CE1 = data.CE1 >> 1;    data.CF1 = data.CF1 >> 1;     data.CG1 = data.CG1 >> 1;     data.CH1 = data.CH1 >> 1;
			 }
				  
			  
			  //drawCube(data);
			}
		}	
	void LedCube8::shiftCubeLeft(int count,bool reload, struct CUBEDATACUBE data)
	{
		for(int x = 0; x<count; x++)
		{
			drawCube(data);
			if(reload == true)
			{
			  {
			  data.CA1 = ((data.CA1&B10000000 )>>7)| (data.CA1<<1);	data.CA2 = ((data.CA2&B10000000 )>>7)| (data.CA2<<1);
			  data.CB1 = ((data.CB1&B10000000 )>>7)| (data.CB1<<1);    data.CB2 = ((data.CB2&B10000000 )>>7)| (data.CB2<<1);
			  data.CC1 = ((data.CC1&B10000000 )>>7)| (data.CC1<<1);    data.CC2 = ((data.CC2&B10000000 )>>7)| (data.CC2<<1);
			  data.CD1 = ((data.CD1&B10000000 )>>7)| (data.CD1<<1);    data.CD2 = ((data.CD2&B10000000 )>>7)| (data.CD2<<1);
			  data.CE1 = ((data.CE1&B10000000 )>>7)| (data.CE1<<1);    data.CE2 = ((data.CE2&B10000000 )>>7)| (data.CE2<<1);
			  data.CF1 = ((data.CF1&B10000000 )>>7)| (data.CF1<<1);    data.CF2 = ((data.CF2&B10000000 )>>7)| (data.CF2<<1);
			  data.CG1 = ((data.CG1&B10000000 )>>7)| (data.CG1<<1);    data.CG2 = ((data.CG2&B10000000 )>>7)| (data.CG2<<1);
			  data.CH1 = ((data.CH1&B10000000 )>>7)| (data.CH1<<1);    data.CH2 = ((data.CH2&B10000000 )>>7)| (data.CH2<<1);
			                                                                                              
			                                                                                              
			  data.CA3 = ((data.CA3&B10000000 )>>7)| (data.CA3<<1);	data.CA4 = ((data.CA4&B10000000 )>>7)| (data.CA4<<1);
			  data.CB3 = ((data.CB3&B10000000 )>>7)| (data.CB3<<1);    data.CB4 = ((data.CB4&B10000000 )>>7)| (data.CB4<<1);
			  data.CC3 = ((data.CC3&B10000000 )>>7)| (data.CC3<<1);    data.CC4 = ((data.CC4&B10000000 )>>7)| (data.CC4<<1);
			  data.CD3 = ((data.CD3&B10000000 )>>7)| (data.CD3<<1);    data.CD4 = ((data.CD4&B10000000 )>>7)| (data.CD4<<1);
			  data.CE3 = ((data.CE3&B10000000 )>>7)| (data.CE3<<1);    data.CE4 = ((data.CE4&B10000000 )>>7)| (data.CE4<<1);
			  data.CF3 = ((data.CF3&B10000000 )>>7)| (data.CF3<<1);    data.CF4 = ((data.CF4&B10000000 )>>7)| (data.CF4<<1);
			  data.CG3 = ((data.CG3&B10000000 )>>7)| (data.CG3<<1);    data.CG4 = ((data.CG4&B10000000 )>>7)| (data.CG4<<1);
			  data.CH3 = ((data.CH3&B10000000 )>>7)| (data.CH3<<1);    data.CH4 = ((data.CH4&B10000000 )>>7)| (data.CH4<<1);
                                                                                                          
			                                                                                              
			  data.CA5 = ((data.CA5&B10000000 )>>7)| (data.CA5<<1);	data.CA6 = ((data.CA6&B10000000 )>>7)| (data.CA6<<1);
			  data.CB5 = ((data.CB5&B10000000 )>>7)| (data.CB5<<1);    data.CB6 = ((data.CB6&B10000000 )>>7)| (data.CB6<<1);
			  data.CC5 = ((data.CC5&B10000000 )>>7)| (data.CC5<<1);    data.CC6 = ((data.CC6&B10000000 )>>7)| (data.CC6<<1);
			  data.CD5 = ((data.CD5&B10000000 )>>7)| (data.CD5<<1);    data.CD6 = ((data.CD6&B10000000 )>>7)| (data.CD6<<1);
			  data.CE5 = ((data.CE5&B10000000 )>>7)| (data.CE5<<1);    data.CE6 = ((data.CE6&B10000000 )>>7)| (data.CE6<<1);
			  data.CF5 = ((data.CF5&B10000000 )>>7)| (data.CF5<<1);    data.CF6 = ((data.CF6&B10000000 )>>7)| (data.CF6<<1);
			  data.CG5 = ((data.CG5&B10000000 )>>7)| (data.CG5<<1);    data.CG6 = ((data.CG6&B10000000 )>>7)| (data.CG6<<1);
			  data.CH5 = ((data.CH5&B10000000 )>>7)| (data.CH5<<1);    data.CH6 = ((data.CH6&B10000000 )>>7)| (data.CH6<<1);
			                                                                                              
			                                                                                              
			  data.CA7 = ((data.CA7&B10000000 )>>7)| (data.CA7<<1);	data.CA8 = ((data.CA8&B10000000 )>>7)| (data.CA8<<1);
			  data.CB7 = ((data.CB7&B10000000 )>>7)| (data.CB7<<1);    data.CB8 = ((data.CB8&B10000000 )>>7)| (data.CB8<<1);
			  data.CC7 = ((data.CC7&B10000000 )>>7)| (data.CC7<<1);    data.CC8 = ((data.CC8&B10000000 )>>7)| (data.CC8<<1);
			  data.CD7 = ((data.CD7&B10000000 )>>7)| (data.CD7<<1);    data.CD8 = ((data.CD8&B10000000 )>>7)| (data.CD8<<1);
			  data.CE7 = ((data.CE7&B10000000 )>>7)| (data.CE7<<1);    data.CE8 = ((data.CE8&B10000000 )>>7)| (data.CE8<<1);
			  data.CF7 = ((data.CF7&B10000000 )>>7)| (data.CF7<<1);    data.CF8 = ((data.CF8&B10000000 )>>7)| (data.CF8<<1);
			  data.CG7 = ((data.CG7&B10000000 )>>7)| (data.CG7<<1);    data.CG8 = ((data.CG8&B10000000 )>>7)| (data.CG8<<1);
			  data.CH7 = ((data.CH7&B10000000 )>>7)| (data.CH7<<1);    data.CH8 = ((data.CH8&B10000000 )>>7)| (data.CH8<<1); 
			  }                                
			}
			 else
			{
				 data.CA8 = data.CA8 << 1;	data.CB8 = data.CB8 << 1;		data.CC8 = data.CC8 << 1;		data.CD8 = data.CD8 << 1;
				 data.CA7 = data.CA7 << 1;    data.CB7 = data.CB7 << 1;     data.CC7 = data.CC7 << 1;     data.CD7 = data.CD7 << 1;
				 data.CA6 = data.CA6 << 1;    data.CB6 = data.CB6 << 1;     data.CC6 = data.CC6 << 1;     data.CD6 = data.CD6 << 1;
				 data.CA5 = data.CA5 << 1;    data.CB5 = data.CB5 << 1;     data.CC5 = data.CC5 << 1;     data.CD5 = data.CD5 << 1;
				 data.CA4 = data.CA4 << 1;    data.CB4 = data.CB4 << 1;     data.CC4 = data.CC4 << 1;     data.CD4 = data.CD4 << 1;
				 data.CA3 = data.CA3 << 1;    data.CB3 = data.CB3 << 1;     data.CC3 = data.CC3 << 1;     data.CD3 = data.CD3 << 1;
				 data.CA2 = data.CA2 << 1;    data.CB2 = data.CB2 << 1;     data.CC2 = data.CC2 << 1;     data.CD2 = data.CD2 << 1;
				 data.CA1 = data.CA1 << 1;    data.CB1 = data.CB1 << 1;     data.CC1 = data.CC1 << 1;     data.CD1 = data.CD1 << 1;
				                                                                                    
				 data.CE8 = data.CE8 << 1;	data.CF8 = data.CF8 << 1;		data.CG8 = data.CG8 << 1;		data.CH8 = data.CH8 << 1;
				 data.CE7 = data.CE7 << 1;    data.CF7 = data.CF7 << 1;     data.CG7 = data.CG7 << 1;     data.CH7 = data.CH7 << 1;
				 data.CE6 = data.CE6 << 1;    data.CF6 = data.CF6 << 1;     data.CG6 = data.CG6 << 1;     data.CH6 = data.CH6 << 1;
				 data.CE5 = data.CE5 << 1;    data.CF5 = data.CF5 << 1;     data.CG5 = data.CG5 << 1;     data.CH5 = data.CH5 << 1;
				 data.CE4 = data.CE4 << 1;    data.CF4 = data.CF4 << 1;     data.CG4 = data.CG4 << 1;     data.CH4 = data.CH4 << 1;
				 data.CE3 = data.CE3 << 1;    data.CF3 = data.CF3 << 1;     data.CG3 = data.CG3 << 1;     data.CH3 = data.CH3 << 1;
				 data.CE2 = data.CE2 << 1;    data.CF2 = data.CF2 << 1;     data.CG2 = data.CG2 << 1;     data.CH2 = data.CH2 << 1;
				 data.CE1 = data.CE1 << 1;    data.CF1 = data.CF1 << 1;     data.CG1 = data.CG1 << 1;     data.CH1 = data.CH1 << 1;
			 }
			 // drawCube(data);
			}
		}			
	void LedCube8::shiftCubeRight90(int count,bool reload, struct CUBEDATACUBE data)
	{
		
		for(int x = 0; x<count; x++)
		{
			drawCube(data);
			byte buffer[8] = {data.CH1,data.CH2,data.CH3,data.CH4,data.CH5,data.CH6,data.CH7,data.CH8};
			if(reload == true)
			{
			  {
				                                                                                                  
				  data.CH1	=		  data.CG1;	data.CH2	=		  data.CG2;	data.CH3	=		  data.CG3;	data.CH4	=		  data.CG4;
				  data.CG1	=		  data.CF1;  data.CG2	=		  data.CF2;  data.CG3	=		  data.CF3;  data.CG4	=		  data.CF4;
				  data.CF1	=		  data.CE1;  data.CF2	=		  data.CE2;  data.CF3	=		  data.CE3;  data.CF4	=		  data.CE4;
				  data.CE1	=		  data.CD1;  data.CE2	=		  data.CD2;  data.CE3	=		  data.CD3;  data.CE4	=		  data.CD4;
				  data.CD1	=		  data.CC1;  data.CD2	=		  data.CC2;  data.CD3	=		  data.CC3;  data.CD4	=		  data.CC4;
				  data.CC1	=		  data.CB1;  data.CC2	=		  data.CB2;  data.CC3	=		  data.CB3;  data.CC4	=		  data.CB4;
				  data.CB1	=		  data.CA1;  data.CB2	=		  data.CA2;  data.CB3	=		  data.CA3;  data.CB4	=		  data.CA4;
				  data.CA1	=		buffer[0];  data.CA2	=		buffer[1]; 	data.CA3	=		buffer[2];  data.CA4	=		buffer[3];
				                                                                                    
				  data.CH5	=		  data.CG5;	data.CH6	=		  data.CG6;	data.CH7	=		  data.CG7;	data.CH8	=		  data.CG8;
				  data.CG5	=		  data.CF5;  data.CG6	=		  data.CF6;  data.CG7	=		  data.CF7;  data.CG8	=		  data.CF8;
				  data.CF5	=		  data.CE5;  data.CF6	=		  data.CE6;  data.CF7	=		  data.CE7;  data.CF8	=		  data.CE8;
				  data.CE5	=		  data.CD5;  data.CE6	=		  data.CD6;  data.CE7	=		  data.CD7;  data.CE8	=		  data.CD8;
				  data.CD5	=		  data.CC5;  data.CD6	=		  data.CC6;  data.CD7	=		  data.CC7;  data.CD8	=		  data.CC8;
				  data.CC5	=		  data.CB5;  data.CC6	=		  data.CB6;  data.CC7	=		  data.CB7;  data.CC8	=		  data.CB8;
				  data.CB5	=		  data.CA5;  data.CB6	=		  data.CA6;  data.CB7	=		  data.CA7;  data.CB8	=		  data.CA8;
				  data.CA5	=		buffer[4];  data.CA6	=		buffer[5];  data.CA7	=		buffer[6];  data.CA8	=		buffer[7];
			  }                                
			}
			 else
			{    
				  data.CH1 = data.CG1;  data.CH2 = data.CG2;  data.CH3 = data.CG3;  data.CH4 =	data.CG4;
				  data.CG1 = data.CF1;  data.CG2 = data.CF2;  data.CG3 = data.CF3;  data.CG4 =	data.CF4;
				  data.CF1 = data.CE1;  data.CF2 = data.CE2;  data.CF3 = data.CE3;  data.CF4 =	data.CE4;
				  data.CE1 = data.CD1;  data.CE2 = data.CD2;  data.CE3 = data.CD3;  data.CE4 =	data.CD4;
				  data.CD1 = data.CC1;  data.CD2 = data.CC2;  data.CD3 = data.CC3;  data.CD4 =	data.CC4;
				  data.CC1 = data.CB1;  data.CC2 = data.CB2;  data.CC3 = data.CB3;  data.CC4 =	data.CB4;
				  data.CB1 = data.CA1;  data.CB2 = data.CA2;  data.CB3 = data.CA3;  data.CB4 =	data.CA4;
				  data.CA1 =	0;    	  data.CA2 =	0;        data.CA3 =	0;    data.CA4 =	0;
				                                                   
				  data.CH5 = data.CG5;  data.CH6 = data.CG6;  data.CH7 = data.CG7;  data.CH8 =	data.CG8;
				  data.CG5 = data.CF5;  data.CG6 = data.CF6;  data.CG7 = data.CF7;  data.CG8 =	data.CF8;
				  data.CF5 = data.CE5;  data.CF6 = data.CE6;  data.CF7 = data.CE7;  data.CF8 =	data.CE8;
				  data.CE5 = data.CD5;  data.CE6 = data.CD6;  data.CE7 = data.CD7;  data.CE8 =	data.CD8;
				  data.CD5 = data.CC5;  data.CD6 = data.CC6;  data.CD7 = data.CC7;  data.CD8 =	data.CC8;
				  data.CC5 = data.CB5;  data.CC6 = data.CB6;  data.CC7 = data.CB7;  data.CC8 =	data.CB8;
				  data.CB5 = data.CA5;  data.CB6 = data.CA6;  data.CB7 = data.CA7;  data.CB8 =	data.CA8;
				  data.CA5 =	0;        data.CA6 =	0;        data.CA7 =	0;        data.CA8 =	0;
			 }
				  
			  
			  //drawCube(data);
			}
		}
	void LedCube8::shiftCubeLeft90(int count,bool reload, struct CUBEDATACUBE data)
	{
		for(int x = 0; x<count; x++)
		{
			drawCube(data);
			byte buffer[8] = {data.CA1,data.CA2,data.CA3,data.CA4,data.CA5,data.CA6,data.CA7,data.CA8};
			if(reload == true)
			{
			  {  
				  data.CA1	=		  data.CB1;	data.CA2	=		  data.CB2;	 data.CA3	=		  data.CB3;	 data.CA4	=		  data.CB4;
				  data.CB1	=		  data.CC1;  data.CB2	=		  data.CC2;  data.CB3	=		  data.CC3;  data.CB4	=		  data.CC4;
				  data.CC1	=		  data.CD1;  data.CC2	=		  data.CD2;  data.CC3	=		  data.CD3;  data.CC4	=		  data.CD4;
				  data.CD1	=		  data.CE1;  data.CD2	=		  data.CE2;  data.CD3	=		  data.CE3;  data.CD4	=		  data.CE4;
				  data.CE1	=		  data.CF1;  data.CE2	=		  data.CF2;  data.CE3	=		  data.CF3;  data.CE4	=		  data.CF4;
				  data.CF1	=		  data.CG1;  data.CF2	=		  data.CG2;  data.CF3	=		  data.CG3;  data.CF4	=		  data.CG4;
				  data.CG1	=		  data.CH1;  data.CG2	=		  data.CH2;  data.CG3	=		  data.CH3;  data.CG4	=		  data.CH4;
				  data.CH1	=		 buffer[0];  data.CH2	=		buffer[1];  data.CH3	=		buffer[2];  data.CH4	=		buffer[3];
				                                                                                     
				  data.CA5	=		  data.CB5;	data.CA6	=		  data.CB6;	data.CA7	=		  data.CB7;	data.CA8	=		  data.CB8;
				  data.CB5	=		  data.CC5;  data.CB6	=		  data.CC6;  data.CB7	=		  data.CC7;  data.CB8	=		  data.CC8;
				  data.CC5	=		  data.CD5;  data.CC6	=		  data.CD6;  data.CC7	=		  data.CD7;  data.CC8	=		  data.CD8;
				  data.CD5	=		  data.CE5;  data.CD6	=		  data.CE6;  data.CD7	=		  data.CE7;  data.CD8	=		  data.CE8;
				  data.CE5	=		  data.CF5;  data.CE6	=		  data.CF6;  data.CE7	=		  data.CF7;  data.CE8	=		  data.CF8;
				  data.CF5	=		  data.CG5;  data.CF6	=		  data.CG6;  data.CF7	=		  data.CG7;  data.CF8	=		  data.CG8;
				  data.CG5	=		  data.CH5;  data.CG6	=		  data.CH6;  data.CG7	=		  data.CH7;  data.CG8	=		  data.CH8;
				  data.CH5	=		 buffer[4];  data.CH6	=		buffer[5];  data.CH7	=		buffer[6];  data.CH8	=		buffer[7];
			  }                                
			}
			 else
			{
				  data.CA1	= data.CB1;	data.CA2	=  data.CB2;	 data.CA3	=  data.CB3;	 data.CA4	=  data.CB4;
				  data.CB1	= data.CC1;  data.CB2	=  data.CC2;  data.CB3	=  data.CC3;  data.CB4	=  data.CC4;
				  data.CC1	= data.CD1;  data.CC2	=  data.CD2;  data.CC3	=  data.CD3;  data.CC4	=  data.CD4;
				  data.CD1	= data.CE1;  data.CD2	=  data.CE2;  data.CD3	=  data.CE3;  data.CD4	=  data.CE4;
				  data.CE1	= data.CF1;  data.CE2	=  data.CF2;  data.CE3	=  data.CF3;  data.CE4	=  data.CF4;
				  data.CF1	= data.CG1;  data.CF2	=  data.CG2;  data.CF3	=  data.CG3;  data.CF4	=  data.CG4;
				  data.CG1	= data.CH1;  data.CG2	=  data.CH2;  data.CG3	=  data.CH3;  data.CG4	=  data.CH4;
				  data.CH1	= 		0;  data.CH2	=		0;   data.CH3	=		0;   data.CH4	=		0;
				                                                               
				  data.CA5	= data.CB5;	data.CA6	=  data.CB6;	 data.CA7	=  data.CB7;	 data.CA8	=  data.CB8;
				  data.CB5	= data.CC5;  data.CB6	=  data.CC6;  data.CB7	=  data.CC7;  data.CB8	=  data.CC8;
				  data.CC5	= data.CD5;  data.CC6	=  data.CD6;  data.CC7	=  data.CD7;  data.CC8	=  data.CD8;
				  data.CD5	= data.CE5;  data.CD6	=  data.CE6;  data.CD7	=  data.CE7;  data.CD8	=  data.CE8;
				  data.CE5	= data.CF5;  data.CE6	=  data.CF6;  data.CE7	=  data.CF7;  data.CE8	=  data.CF8;
				  data.CF5	= data.CG5;  data.CF6	=  data.CG6;  data.CF7	=  data.CG7;  data.CF8	=  data.CG8;
				  data.CG5	= data.CH5;  data.CG6	=  data.CH6;  data.CG7	=  data.CH7;  data.CG8	=  data.CH8;
				  data.CH5	= 		0; 	data.CH6	=		0;   data.CH7	=		0;   data.CH8	=		0;
			 }			  
			  //drawCube(data);
			}
		}			
	void LedCube8::shiftCubeUp(int count,bool reload, struct CUBEDATACUBE data)
	{
			byte buffer[8] = {0,0,0,0,0,0,0,0};
			if (reload == true)
			{
				
				for(int i = 0; i < count; i++)
				{
					drawCube(data);
								
					buffer[0] = data.CA1;
					buffer[1] = data.CB1;
					buffer[2] = data.CC1;
					buffer[3] = data.CD1;
					buffer[4] = data.CE1;
					buffer[5] = data.CF1;
					buffer[6] = data.CG1;
					buffer[7] = data.CH1;
					
					data.CA1 = data.CA8;
					data.CB1 = data.CB8;
					data.CC1 = data.CC8;
					data.CD1 = data.CD8;
					data.CE1 = data.CE8;
					data.CF1 = data.CF8;
					data.CG1 = data.CG8;
					data.CH1 = data.CH8;
					
					data.CA8 = data.CA7;
					data.CB8 = data.CB7;
					data.CC8 = data.CC7;
					data.CD8 = data.CD7;
					data.CE8 = data.CE7;
					data.CF8 = data.CF7;
					data.CG8 = data.CG7;
					data.CH8 = data.CH7;
					
					data.CA7 = data.CA6;
					data.CB7 = data.CB6;
					data.CC7 = data.CC6;
					data.CD7 = data.CD6;
					data.CE7 = data.CE6;
					data.CF7 = data.CF6;
					data.CG7 = data.CG6;
					data.CH7 = data.CH6;
					
					data.CA6 = data.CA5;
					data.CB6 = data.CB5;
					data.CC6 = data.CC5;
					data.CD6 = data.CD5;
					data.CE6 = data.CE5;
					data.CF6 = data.CF5;
					data.CG6 = data.CG5;
					data.CH6 = data.CH5;
					
					data.CA5 = data.CA4;
					data.CB5 = data.CB4;
					data.CC5 = data.CC4;
					data.CD5 = data.CD4;
					data.CE5 = data.CE4;
					data.CF5 = data.CF4;
					data.CG5 = data.CG4;
					data.CH5 = data.CH4;
					
					data.CA4 = data.CA3;
					data.CB4 = data.CB3;
					data.CC4 = data.CC3;
					data.CD4 = data.CD3;
					data.CE4 = data.CE3;
					data.CF4 = data.CF3;
					data.CG4 = data.CG3;
					data.CH4 = data.CH3;
					
					data.CA3 = data.CA2;
					data.CB3 = data.CB2;
					data.CC3 = data.CC2;
					data.CD3 = data.CD2;
					data.CE3 = data.CE2;
					data.CF3 = data.CF2;
					data.CG3 = data.CG2;
					data.CH3 = data.CH2;
					
					data.CA2 = buffer[0];
					data.CB2 = buffer[1];
					data.CC2 = buffer[2];
					data.CD2 = buffer[3];
					data.CE2 = buffer[4];
					data.CF2 = buffer[5];
					data.CG2 = buffer[6];
					data.CH2 = buffer[7];
					
					
				}
			}
			else
			{
				for(int i = 0; i < count; i++)
				{
					drawCube(data);
					
					data.CA1 = data.CA8;
					data.CB1 = data.CB8;
					data.CC1 = data.CC8;
					data.CD1 = data.CD8;
					data.CE1 = data.CE8;
					data.CF1 = data.CF8;
					data.CG1 = data.CG8;
					data.CH1 = data.CH8;
					
					data.CA8 = data.CA7;
					data.CB8 = data.CB7;
					data.CC8 = data.CC7;
					data.CD8 = data.CD7;
					data.CE8 = data.CE7;
					data.CF8 = data.CF7;
					data.CG8 = data.CG7;
					data.CH8 = data.CH7;
					
					data.CA7 = data.CA6;
					data.CB7 = data.CB6;
					data.CC7 = data.CC6;
					data.CD7 = data.CD6;
					data.CE7 = data.CE6;
					data.CF7 = data.CF6;
					data.CG7 = data.CG6;
					data.CH7 = data.CH6;
					
					data.CA6 = data.CA5;
					data.CB6 = data.CB5;
					data.CC6 = data.CC5;
					data.CD6 = data.CD5;
					data.CE6 = data.CE5;
					data.CF6 = data.CF5;
					data.CG6 = data.CG5;
					data.CH6 = data.CH5;
					
					data.CA5 = data.CA4;
					data.CB5 = data.CB4;
					data.CC5 = data.CC4;
					data.CD5 = data.CD4;
					data.CE5 = data.CE4;
					data.CF5 = data.CF4;
					data.CG5 = data.CG4;
					data.CH5 = data.CH4;
					
					data.CA4 = data.CA3;
					data.CB4 = data.CB3;
					data.CC4 = data.CC3;
					data.CD4 = data.CD3;
					data.CE4 = data.CE3;
					data.CF4 = data.CF3;
					data.CG4 = data.CG3;
					data.CH4 = data.CH3;
					
					data.CA3 = data.CA2;
					data.CB3 = data.CB2;
					data.CC3 = data.CC2;
					data.CD3 = data.CD2;
					data.CE3 = data.CE2;
					data.CF3 = data.CF2;
					data.CG3 = data.CG2;
					data.CH3 = data.CH2;
					
					data.CA2 = data.CA1;
					data.CB2 = data.CB1;
					data.CC2 = data.CC1;
					data.CD2 = data.CD1;
					data.CE2 = data.CE1;
					data.CF2 = data.CF1;
					data.CG2 = data.CG1;
					data.CH2 = data.CH1;
					
					data.CA1 = 0;
					data.CB1 = 0;
					data.CC1 = 0;
					data.CD1 = 0;
					data.CE1 = 0;
					data.CF1 = 0;
					data.CG1 = 0;
					data.CH1 = 0;
					
				}
			}	
		}				
	void LedCube8::shiftCubeDown(int count,bool reload, struct CUBEDATACUBE data)							
	{
			if (reload == true)
			{
				
				byte buffer[8] = {0,0,0,0,0,0,0,0};
				for(int i = 0; i < count; i++)
				{
					
					drawCube(data);		
					buffer[0] = data.CA8;
					buffer[1] = data.CB8;
					buffer[2] = data.CC8;
					buffer[3] = data.CD8;
					buffer[4] = data.CE8;
					buffer[5] = data.CF8;
					buffer[6] = data.CG8;
					buffer[7] = data.CH8;
					                
					data.CA8 = data.CA1;
					data.CB8 = data.CB1;
					data.CC8 = data.CC1;
					data.CD8 = data.CD1;
					data.CE8 = data.CE1;
					data.CF8 = data.CF1;
					data.CG8 = data.CG1;
					data.CH8 = data.CH1;
					
					data.CA1 = data.CA2;
					data.CB1 = data.CB2;
					data.CC1 = data.CC2;
					data.CD1 = data.CD2;
					data.CE1 = data.CE2;
					data.CF1 = data.CF2;
					data.CG1 = data.CG2;
					data.CH1 = data.CH2;
					
					data.CA2 = data.CA3;
					data.CB2 = data.CB3;
					data.CC2 = data.CC3;
					data.CD2 = data.CD3;
					data.CE2 = data.CE3;
					data.CF2 = data.CF3;
					data.CG2 = data.CG3;
					data.CH2 = data.CH3;
					
					data.CA3 = data.CA4;
					data.CB3 = data.CB4;
					data.CC3 = data.CC4;
					data.CD3 = data.CD4;
					data.CE3 = data.CE4;
					data.CF3 = data.CF4;
					data.CG3 = data.CG4;
					data.CH3 = data.CH4;
					
					data.CA4 = data.CA5;
					data.CB4 = data.CB5;
					data.CC4 = data.CC5;
					data.CD4 = data.CD5;
					data.CE4 = data.CE5;
					data.CF4 = data.CF5;
					data.CG4 = data.CG5;
					data.CH4 = data.CH5;
					
					data.CA5 = data.CA6;
					data.CB5 = data.CB6;
					data.CC5 = data.CC6;
					data.CD5 = data.CD6;
					data.CE5 = data.CE6;
					data.CF5 = data.CF6;
					data.CG5 = data.CG6;
					data.CH5 = data.CH6;
					
					data.CA6 = data.CA7;
					data.CB6 = data.CB7;
					data.CC6 = data.CC7;
					data.CD6 = data.CD7;
					data.CE6 = data.CE7;
					data.CF6 = data.CF7;
					data.CG6 = data.CG7;
					data.CH6 = data.CH7;
					
					data.CA7 = buffer[0];
					data.CB7 = buffer[1];
					data.CC7 = buffer[2];
					data.CD7 = buffer[3];
					data.CE7 = buffer[4];
					data.CF7 = buffer[5];
					data.CG7 = buffer[6];
					data.CH7 = buffer[7];
					
				}
			}
			else
			{
				for(int i = 0; i < count; i++)
				{
					drawCube(data);
					
					data.CA1 = data.CA2;
					data.CB1 = data.CB2;
					data.CC1 = data.CC2;
					data.CD1 = data.CD2;
					data.CE1 = data.CE2;
					data.CF1 = data.CF2;
					data.CG1 = data.CG2;
					data.CH1 = data.CH2;
					
					data.CA2 = data.CA3;
					data.CB2 = data.CB3;
					data.CC2 = data.CC3;
					data.CD2 = data.CD3;
					data.CE2 = data.CE3;
					data.CF2 = data.CF3;
					data.CG2 = data.CG3;
					data.CH2 = data.CH3;
					
					data.CA3 = data.CA4;
					data.CB3 = data.CB4;
					data.CC3 = data.CC4;
					data.CD3 = data.CD4;
					data.CE3 = data.CE4;
					data.CF3 = data.CF4;
					data.CG3 = data.CG4;
					data.CH3 = data.CH4;
					
					data.CA4 = data.CA5;
					data.CB4 = data.CB5;
					data.CC4 = data.CC5;
					data.CD4 = data.CD5;
					data.CE4 = data.CE5;
					data.CF4 = data.CF5;
					data.CG4 = data.CG5;
					data.CH4 = data.CH5;
					
					data.CA5 = data.CA6;
					data.CB5 = data.CB6;
					data.CC5 = data.CC6;
					data.CD5 = data.CD6;
					data.CE5 = data.CE6;
					data.CF5 = data.CF6;
					data.CG5 = data.CG6;
					data.CH5 = data.CH6;
					
					data.CA6 = data.CA7;
					data.CB6 = data.CB7;
					data.CC6 = data.CC7;
					data.CD6 = data.CD7;
					data.CE6 = data.CE7;
					data.CF6 = data.CF7;
					data.CG6 = data.CG7;
					data.CH6 = data.CH7;
					
					data.CA7 = data.CA8;
					data.CB7 = data.CB8;
					data.CC7 = data.CC8;
					data.CD7 = data.CD8;
					data.CE7 = data.CE8;
					data.CF7 = data.CF8;
					data.CG7 = data.CG8;
					data.CH7 = data.CH8;
					
					data.CA8 = 0;
					data.CB8 = 0;
					data.CC8 = 0;
					data.CD8 = 0;
					data.CE8 = 0;
					data.CF8 = 0;
					data.CG8 = 0;
					data.CH8 = 0;
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
		
		CUBEDATACUBE data {0,0,0,0,0,0,0,0};
		byte randomBit[8] {0,0,0,0,0,0,0,0};
		for(int x = 0; x<count; x++)
		{
			for(int i = 8; i>=1; i--)
			{
				
/*				byte randomBit2 = 0;
				byte randomBit3 = 0;
				byte randomBit4 = 0;
				byte randomBit5 = 0;
				byte randomBit6 = 0;
				byte randomBit7 = 0;
				byte randomBit8 = 0;
*/				
				
				for(int i = 0; i<8; i++)
				{
					for(int e = 0;e<8; e++)
					{
						randomBit[e] = random(amount,105);
						if(randomBit[e] > 100)
						{
							randomBit[e] = 1;
						}
						else
						{
							randomBit[e] = 0;
						}
					}
					
					{
	/*				if(randomBit1 > 100)
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
					}*/
					switch(i)
					{
						case 0:
						{
							data.CA8 = randomBit[0] + (randomBit[1] << 1) + (randomBit[2] << 2) + (randomBit[3] << 3) + (randomBit[4] << 4) + (randomBit[5] << 5) + (randomBit[6] << 6) + (randomBit[7] << 7);
							break;
						}
						case 1:
						{
							data.CB8 = randomBit[0] + (randomBit[1] << 1) + (randomBit[2] << 2) + (randomBit[3] << 3) + (randomBit[4] << 4) + (randomBit[5] << 5) + (randomBit[6] << 6) + (randomBit[7] << 7);
							break;
						}
						case 2:
						{
							data.CC8 = randomBit[0] + (randomBit[1] << 1) + (randomBit[2] << 2) + (randomBit[3] << 3) + (randomBit[4] << 4) + (randomBit[5] << 5) + (randomBit[6] << 6) + (randomBit[7] << 7);
							break;
						}
						case 3:
						{
							data.CD8 = randomBit[0] + (randomBit[1] << 1) + (randomBit[2] << 2) + (randomBit[3] << 3) + (randomBit[4] << 4) + (randomBit[5] << 5) + (randomBit[6] << 6) + (randomBit[7] << 7);
							break;
						}
						case 4:
						{
							data.CE8 = randomBit[0] + (randomBit[1] << 1) + (randomBit[2] << 2) + (randomBit[3] << 3) + (randomBit[4] << 4) + (randomBit[5] << 5) + (randomBit[6] << 6) + (randomBit[7] << 7);
							break;
						}
						case 5:
						{
							data.CF8 = randomBit[0] + (randomBit[1] << 1) + (randomBit[2] << 2) + (randomBit[3] << 3) + (randomBit[4] << 4) + (randomBit[5] << 5) + (randomBit[6] << 6) + (randomBit[7] << 7);
							break;
						}
						case 6:
						{
							data.CG8 = randomBit[0] + (randomBit[1] << 1) + (randomBit[2] << 2) + (randomBit[3] << 3) + (randomBit[4] << 4) + (randomBit[5] << 5) + (randomBit[6] << 6) + (randomBit[7] << 7);
							break;
						}
						case 7:
						{
							data.CH8 = randomBit[0] + (randomBit[1] << 1) + (randomBit[2] << 2) + (randomBit[3] << 3) + (randomBit[4] << 4) + (randomBit[5] << 5) + (randomBit[6] << 6) + (randomBit[7] << 7);
							break;
						}
					}
					/*if(i == 0)
					{
					data.CA8 = randomBit[0] + (randomBit[1] << 1) + (randomBit[2] << 2) + (randomBit[3] << 3) + (randomBit[4] << 4) + (randomBit[5] << 5) + (randomBit[6] << 6) + (randomBit[7] << 7);
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
					}*/
					}
				}	
				//SHIFT DOWN---------------------------------------------------
				drawCube(data);
				{				
				data.CA1 = data.CA2;
				data.CB1 = data.CB2;
				data.CC1 = data.CC2;
				data.CD1 = data.CD2;
				data.CE1 = data.CE2;
				data.CF1 = data.CF2;
				data.CG1 = data.CG2;
				data.CH1 = data.CH2;

				data.CA2 = data.CA3;
				data.CB2 = data.CB3;
				data.CC2 = data.CC3;
				data.CD2 = data.CD3;
				data.CE2 = data.CE3;
				data.CF2 = data.CF3;
				data.CG2 = data.CG3;
				data.CH2 = data.CH3;
	
				data.CA3 = data.CA4;
				data.CB3 = data.CB4;
				data.CC3 = data.CC4;
				data.CD3 = data.CD4;
				data.CE3 = data.CE4;
				data.CF3 = data.CF4;
				data.CG3 = data.CG4;
				data.CH3 = data.CH4;
				
				data.CA4 = data.CA5;
				data.CB4 = data.CB5;
				data.CC4 = data.CC5;
				data.CD4 = data.CD5;
				data.CE4 = data.CE5;
				data.CF4 = data.CF5;
				data.CG4 = data.CG5;
				data.CH4 = data.CH5;
				
				data.CA5 = data.CA6;
				data.CB5 = data.CB6;
				data.CC5 = data.CC6;
				data.CD5 = data.CD6;
				data.CE5 = data.CE6;
				data.CF5 = data.CF6;
				data.CG5 = data.CG6;
				data.CH5 = data.CH6;
				
				data.CA6 = data.CA7;
				data.CB6 = data.CB7;
				data.CC6 = data.CC7;
				data.CD6 = data.CD7;
				data.CE6 = data.CE7;
				data.CF6 = data.CF7;
				data.CG6 = data.CG7;
				data.CH6 = data.CH7;

				data.CA7 = data.CA8;	
				data.CB7 = data.CB8;
				data.CC7 = data.CC8;
				data.CD7 = data.CD8;
				data.CE7 = data.CE8;
				data.CF7 = data.CF8;
				data.CG7 = data.CG8;
				data.CH7 = data.CH8;
				}
			}		
		}
	}
	void LedCube8::writeLayer(char text[],byte lenge,byte layer)
	{
		/*========================================================Wird noch ergänzt===============================
		
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
		}*/
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
    PORTD = (PORTB & B00000011) | (pin << 2);								//Setzt die pins 2-7
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
