#include "ledCube.h"
#include "Arduino.h"

		
	
	ledCube::ledCube(byte SIZE, byte lp[], byte cp[]):
					size(SIZE),aLed(SIZE*SIZE)
	{
		led = new byte[(aLed)];
		layer =new byte[size];
	
		for(int i=0; i<size; i++) 
		
	
	for(int i=0; i< size; i++)
	{
		layer[i]	=	lp[i];
		pinMode(layer[i],OUTPUT);
	}
	for(int i=0; i<=(size*size); i++)
	{
		led[i]	=	cp[i];
		pinMode(led[i],OUTPUT);
	}
	}
	
	
ledCube::~ledCube()
{
	
}
void ledCube::init()
{
	/*Serial.begin(9600);						//DEBUG mode
	digitalWrite(layer[0],HIGH);
	digitalWrite(led[0],HIGH);
	delay(500);
	digitalWrite(layer[0],LOW);
	digitalWrite(led[0],LOW);*/
	Takt   = 500;
	Takt   = Takt/18;
}
void ledCube::draw(int Layer,byte leds[])
{
		digitalWrite(layer[Layer],HIGH);		//Layer Setzen	
		  
		  for(int t=0; t<Takt; t++)						  
		  {
			for(int i=0; i<aLed; i++)			
			{
				digitalWrite(led[i],leds[i]);	//Led Setzen
				delay(2);						//2 millis warten
				digitalWrite(led[i],LOW);		//Led Rücksetzen
			}
		  }
		digitalWrite(layer[Layer],LOW);			//Layer Rücksetzen
}

void ledCube::takt(int value)
{
	Takt = value;
	Takt = Takt/18;							//Takt/18
}