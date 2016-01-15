#include "ledCube3.h"
#include "Arduino.h"

ledCube_3::ledCube_3(int pinLed1,	   int pinLed2,	   int pinLed3,
				int pinLed4,	   int pinLed5,	   int pinLed6,	   
				int pinLed7,	   int pinLed8,	   int pinLed9,	   
				int pinLayer1,	   int pinLayer2,  int pinLayer3)
	{
		pin[0] = pinLed1;	  layer[0] = pinLayer1;
	    pin[1] = pinLed2;     layer[1] = pinLayer2;
        pin[2] = pinLed3;     layer[2] = pinLayer3;
        pin[3] = pinLed4;		
        pin[4] = pinLed5;		
        pin[5] = pinLed6;
        pin[6] = pinLed7;
        pin[7] = pinLed8;
        pin[8] = pinLed9;
	}
ledCube_3::~ledCube_3()
{
	
}
void ledCube_3::init()
{
	for(int i=0; i<=9; i++)
	{
		pinMode(pin[i],OUTPUT);
	}
	for(int i=0; i<=3; i++)
	{
		pinMode(layer[i],OUTPUT);
	}
	
	takt   = 500;
}
void ledCube_3::draw(byte LED13,byte LED23,byte LED33,byte LED43, byte LED53,byte LED63,byte LED73,byte LED83,byte LED93,
					 byte LED12,byte LED22,byte LED32,byte LED42, byte LED52,byte LED62,byte LED72,byte LED82,byte LED92,
					 byte LED11,byte LED21,byte LED31,byte LED41, byte LED51,byte LED61,byte LED71,byte LED81,byte LED91)
            
{
  for(int i=0; i<takt; i++)
  {
    setLayer(2,LED13, LED23, LED33, LED43, LED53, LED63, LED73, LED83, LED93);
    setLayer(1,LED12, LED22, LED32, LED42, LED52, LED62, LED72, LED82, LED92);
    setLayer(0,LED11, LED21, LED31, LED41, LED51, LED61, LED71, LED81, LED91);
  }
}
void ledCube_3::Takt(int value)
{
	takt = value;
	takt = takt/6;
}
void ledCube_3::setLayer(byte Layer, byte LED1, byte LED2, byte LED3, byte LED4, byte LED5, byte LED6, byte LED7, byte LED8, byte LED9)
{
  digitalWrite(layer[Layer],1);
  digitalWrite(pin[0],LED1);
  digitalWrite(pin[1],LED2);
  digitalWrite(pin[2],LED3);
  digitalWrite(pin[3],LED4);
  digitalWrite(pin[4],LED5);
  digitalWrite(pin[5],LED6);
  digitalWrite(pin[6],LED7);
  digitalWrite(pin[7],LED8);
  digitalWrite(pin[8],LED9);
  
  delay(2); 
  
  
  digitalWrite(pin[0],LOW);
  digitalWrite(pin[1],LOW);
  digitalWrite(pin[2],LOW);
  digitalWrite(pin[3],LOW);
  digitalWrite(pin[4],LOW);
  digitalWrite(pin[5],LOW);
  digitalWrite(pin[6],LOW);
  digitalWrite(pin[7],LOW);
  digitalWrite(pin[8],LOW);
  digitalWrite(layer[Layer],LOW);
	/*
  led1=LED1;
  led2=LED2;
  led3=LED3;
  led4=LED4;
  led5=LED5;
  led6=LED6;
  led7=LED7;
  led8=LED8;
  led9=LED9;
  

  
    dWrite(Layer);

  led1=0;
  led2=0;
  led3=0;
  led4=0;
  led5=0;
  led6=0;
  led7=0;
  led8=0;
  led9=0;
*/
}

void ledCube_3::dWrite(int LAYER)
{
/*
  digitalWrite(layer[LAYER],1);
  digitalWrite(pin[0],led1);
  digitalWrite(pin[1],led2);
  digitalWrite(pin[2],led3);
  digitalWrite(pin[3],led4);
  digitalWrite(pin[4],led5);
  digitalWrite(pin[5],led6);
  digitalWrite(pin[6],led7);
  digitalWrite(pin[7],led8);
  digitalWrite(pin[8],led9);
  
  delay(2); 
  
  digitalWrite(layer[LAYER],LOW);
  digitalWrite(pin[0],LOW);
  digitalWrite(pin[1],LOW);
  digitalWrite(pin[2],LOW);
  digitalWrite(pin[3],LOW);
  digitalWrite(pin[4],LOW);
  digitalWrite(pin[5],LOW);
  digitalWrite(pin[6],LOW);
  digitalWrite(pin[7],LOW);
  digitalWrite(pin[8],LOW);*/
}