#include "ledcube8.h"
byte ledPin[8]        = {2,3,4,5,6,7,8,9};
byte addressPin[4]    = {10,11,12,13};
byte layerPin[4]      = {A0,A1,A2,A3};

  byte a = B00000001;
  byte b = B00000010;
  byte c = B00000100;
  byte d = B00001000;
  byte e = B00010000;
  byte f = B00100000;
  byte g = B01000000;
  byte h = B10000000;
LedCube8 cube(ledPin,addressPin,layerPin);
int t = 1;
int i=1;
void setup()
{
  Serial.begin(9600);
  Serial.println("TEST");
  
  
  cube.init();
 // cube.draw(8,255,255,255,255,255,255,255,255);

}

void loop()
{
while (true)
{
 // for(int i=0; i<9; i++)
  {
cube.draw(i,t,128,64,32,16,8,4,2,1);
cube.draw(i+1,t,64,32,32,16,8,4,4,2);
cube.draw(i+2,t,32,16,16,16,8,8,8,4);
cube.draw(i+3,t,4,8,8,8,24,16,16,32);
cube.draw(i+4,t,2,4,4,8,16,32,32,64);
cube.draw(i+5,t,1,2,4,8,16,32,64,128);
cube.draw(i+6,t,0,1,6,8,16,96,128,0);
cube.draw(i+7,t,0,0,1,14,112,128,0,0);
cube.draw(i+8,t,0,0,128,112,14,1,0,0);
cube.draw(i+8,t,0,128,96,16,8,6,1,0);
  }

}
  /*
          for(int i = 0; i<takt; i++)
{              
cube.draw(1,1,B00001000,
              B00000000,
              B00000000,
              B00000000,
              B10000000,
              B00000000,
              B00000000,
              B00000000);
             


cube.draw(2,1,B00000100,
              B00000000,
              B00000000,
              B00000000,
              B00000000,
              B10000000,
              B00000000,
              B00000000);

cube.draw(3,1,B00010100,
              B00000000,
              B00000000,
              B10000000,
              B00000000,
              B10000000,
              B00000000,
              B00000000);

cube.draw(4,1,B00101000,
              B00000000,
              B10000000,
              B00000000,
              B10000000,
              B00000000,
              B00000000,
              B00000000);
              
cube.draw(5,1,B00100000,
              B00000000,
              B10000000,
              B00000000,
              B00000000,
              B00000000,
              B00000000,
              B00000000);

cube.draw(6,1,B00100000,
              B00000000,
              B10000000,
              B00000000,
              B00000000,
              B00000000,
              B00000000,
              B00000000);
              
cube.draw(7,1,B11100000,
              B10000000,
              B10000000,
              B00000000,
              B00000000,
              B00000000,
              B00000000,
              B00000000);
                
cube.draw(8,1,B10100000,
              B01100000,
              B11100000,
              B00010000,
              B00001000,
              B00000000,
              B00000000,
              B00000000);
}  



 for(int i = 0; i<takt; i++)
{              
cube.draw(1,1,B00001000,
              B00000000,
              B00000000,
              B00000000,
              B10000000,
              B00000000,
              B00000000,
              B00000000);
             


cube.draw(2,1,B00000100,
              B00000000,
              B00000000,
              B00000000,
              B00000000,
              B10000000,
              B00000000,
              B00000000);

cube.draw(3,1,B00010100,
              B00000000,
              B00000000,
              B10000000,
              B00000000,
              B10000000,
              B00000000,
              B00000000);

cube.draw(4,1,B00101000,
              B00000000,
              B10000000,
              B00000000,
              B10000000,
              B00000000,
              B00000000,
              B00000000);
              
cube.draw(5,1,B00100000,
              B00000000,
              B10000000,
              B00000000,
              B00000000,
              B00000000,
              B00000000,
              B00000000);

cube.draw(6,1,B00100000,
              B00000000,
              B10000000,
              B00000000,
              B00000000,
              B00000000,
              B00000000,
              B00000000);
              
cube.draw(7,1,B11100000,
              B10000000,
              B10000000,
              B00000000,
              B00000000,
              B00000000,
              B00000000,
              B00000000);
                
cube.draw(8,1,B10100000,
              B01100000,
              B11100000,
              B00010000,
              B00001100,
              B00000100,
              B00000000,
              B00000000);
}        
 for(int i = 0; i<takt; i++)
{  
  cube.draw(1,1,B00001000,
              B00000000,
              B00000000,
              B00000000,
              B10000000,
              B00000000,
              B00000000,
              B00000000);
             


cube.draw(2,1,B00000100,
              B00000000,
              B00000000,
              B00000000,
              B00000000,
              B10000000,
              B00000000,
              B00000000);

cube.draw(3,1,B00010100,
              B00000000,
              B00000000,
              B10000000,
              B00000000,
              B10000000,
              B00000000,
              B00000000);

cube.draw(4,1,B00101000,
              B00000000,
              B10000000,
              B00000000,
              B10000000,
              B00000000,
              B00000000,
              B00000000);
              
cube.draw(5,1,B00100000,
              B00000000,
              B10000000,
              B00000000,
              B00000000,
              B00000000,
              B00000000,
              B00000000);

cube.draw(6,1,B00100000,
              B00000000,
              B10000000,
              B00000000,
              B00000000,
              B00000000,
              B00000000,
              B00000000);
              
cube.draw(7,1,B11100000,
              B10000000,
              B10000000,
              B00000000,
              B00000000,
              B00000000,
              B00000000,
              B00000000);
              
cube.draw(8,1,B10100000,
              B01100000,
              B11100000,
              B00000000,
              B00010000,
              B00011000,
              B00001100,
              B00001100);
}


    for(int i = 0; i<takt; i++)
{  
  cube.draw(1,1,B00001000,
              B00000000,
              B00000000,
              B00000000,
              B10000000,
              B00000000,
              B00000000,
              B00000000);
             


cube.draw(2,1,B00000100,
              B00000000,
              B00000000,
              B00000000,
              B00000000,
              B10000000,
              B00000000,
              B00000000);

cube.draw(3,1,B00010100,
              B00000000,
              B00000000,
              B10000000,
              B00000000,
              B10000000,
              B00000000,
              B00000000);

cube.draw(4,1,B00101000,
              B00000000,
              B10000000,
              B00000000,
              B10000000,
              B00000000,
              B00000000,
              B00000000);
              
cube.draw(5,1,B00100000,
              B00000000,
              B10000000,
              B00000000,
              B00000000,
              B00000000,
              B00000000,
              B00000000);

cube.draw(6,1,B00100000,
              B00000000,
              B10000000,
              B00000000,
              B00000000,
              B00000000,
              B00000000,
              B00000000);
              
cube.draw(7,1,B11100000,
              B10000000,
              B10000000,
              B00000000,
              B00000000,
              B00000000,
              B00000000,
              B00000000);
              
cube.draw(8,1,B10100000,
              B01100000,
              B11100000,
              B00000000,
              B00000000,
              B00000000,
              B00001100,
              B00011100);
}


    for(int i = 0; i<takt; i++)
{  
  cube.draw(1,1,B00001000,
              B00000000,
              B00000000,
              B00000000,
              B10000000,
              B00000000,
              B00000000,
              B00000000);
             


cube.draw(2,1,B00000100,
              B00000000,
              B00000000,
              B00000000,
              B00000000,
              B10000000,
              B00000000,
              B00000000);

cube.draw(3,1,B00010100,
              B00000000,
              B00000000,
              B10000000,
              B00000000,
              B10000000,
              B00000000,
              B00000000);

cube.draw(4,1,B00101000,
              B00000000,
              B10000000,
              B00000000,
              B10000000,
              B00000000,
              B00000000,
              B00000000);
              
cube.draw(5,1,B00100000,
              B00000000,
              B10000000,
              B00000000,
              B00000000,
              B00000000,
              B00000000,
              B00000000);

cube.draw(6,1,B00100000,
              B00000000,
              B10000000,
              B00000000,
              B00000000,
              B00000000,
              B00000000,
              B00000000);
              
cube.draw(7,1,B11100000,
              B10000000,
              B10000000,
              B00000000,
              B00000000,
              B00000000,
              B00000000,
              B00000000);
              
cube.draw(8,1,B10100000,
              B01100000,
              B11100000,
              B00000000,
              B00000000,
              B00000000,
              B00011000,
              B01111000);
}   
/*for(int i = 0; i<takt/2; i++)
{		
cube.draw(1,1,	B00001111,
                B00001111,
                B00001111,
                B00001111,
                B00001111,
                B00001111,
                B00001111,
                B00001111);

cube.draw(2,1,	B11110000,
                B11110000,
                B11110000,
                B11110000,
                B11110000,
                B11110000,
                B11110000,
                B11110000);
}
for(int i = 0; i<takt/4; i++)
{
cube.draw(1,1,	B00000011,
                B00000011,
                B00000011,
                B00000011,
                B00000011,
                B00000011,
                B00000011,
                B00000011);

cube.draw(2,1,	B00001100,
                B00001100,
                B00001100,
                B00001100,
                B00001100,
                B00001100,
                B00001100,
                B00001100);
				
cube.draw(3,1,	B00110000,
                B00110000,
                B00110000,
                B00110000,
                B00110000,
                B00110000,
                B00110000,
                B00110000);
				
cube.draw(4,1,	B11000000,
                B11000000,
                B11000000,
                B11000000,
                B11000000,
                B11000000,
                B11000000,
                B11000000);
}

for(int i = 0; i<takt/5; i++)
{
cube.draw(1,1,	B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001);

cube.draw(2,1,	B00000010,
                B00000010,
                B00000010,
                B00000010,
                B00000010,
                B00000010,
                B00000010,
                B00000010);
				
cube.draw(3,1,	B00000100,
                B00000100,
                B00000100,
                B00000100,
                B00000100,
                B00000100,
                B00000100,
                B00000100);
				
cube.draw(4,1,	B00001000,
                B00001000,
                B00001000,
                B00001000,
                B00001000,
                B00001000,
                B00001000,
                B00001000);
				
cube.draw(5,1,	B00010000,
                B00010000,
                B00010000,
                B00010000,
                B00010000,
                B00010000,
                B00010000,
                B00010000);
				
cube.draw(6,1,	B00100000,
                B00100000,
                B00100000,
                B00100000,
                B00100000,
                B00100000,
                B00100000,
                B00100000);
				
cube.draw(7,1,	B01000000,
                B01000000,
                B01000000,
                B01000000,
                B01000000,
                B01000000,
                B01000000,
                B01000000);
				
cube.draw(8,1,	B10000000,
                B10000000,
                B10000000,
                B10000000,
                B10000000,
                B10000000,
                B10000000,
                B10000000);
}

for(int i = 0; i<takt/5; i++)
{
cube.draw(1,1,	B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001);

cube.draw(2,1,	B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001);
				
cube.draw(3,1,	B00000010,
                B00000010,
                B00000010,
                B00000010,
                B00000010,
                B00000010,
                B00000010,
                B00000010);
				
cube.draw(4,1,	B00000010,
                B00000010,
                B00000010,
                B00000010,
                B00000010,
                B00000010,
                B00000010,
                B00000010);
				
cube.draw(5,1,	B00000100,
                B00000100,
                B00000100,
                B00000100,
                B00000100,
                B00000100,
                B00000100,
                B00000100);
				
cube.draw(6,1,	B00000100,
                B00000100,
                B00000100,
                B00000100,
                B00000100,
                B00000100,
                B00000100,
                B00000100);
				
cube.draw(7,1,	B00001000,
                B00001000,
                B00001000,
                B00001000,
                B00001000,
                B00001000,
                B00001000,
                B00001000);
				
cube.draw(8,1,	B00001000,
                B00001000,
                B00001000,
                B00001000,
                B00001000,
                B00001000,
                B00001000,
                B00001000);
}

for(int i = 0; i<takt/5; i++)
{
cube.draw(1,1,	B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001);

cube.draw(2,1,	B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001);
				
cube.draw(3,1,	B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001);
				
cube.draw(4,1,	B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001);
				
cube.draw(5,1,	B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001);
				
cube.draw(6,1,	B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001);
				
cube.draw(7,1,	B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001);
				
cube.draw(8,1,	B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001,
                B00000001);
}
  
  
  
  
  


  cube.draw(1,100,255,255,255,255,255,255,255,255);
  cube.draw(2,100,255,255,255,255,255,255,255,255);
  cube.draw(3,100,255,255,255,255,255,255,255,255);
  cube.draw(4,100,255,255,255,255,255,255,255,255);
  cube.draw(5,100,255,255,255,255,255,255,255,255);
  cube.draw(6,100,255,255,255,255,255,255,255,255);
  cube.draw(7,100,255,255,255,255,255,255,255,255);
  cube.draw(8,100,255,255,255,255,255,255,255,255);
  */
 /* cube.draw(1,200,B00000000,
                    B00000000,
                    B00000000,
                    B00000000,
                    B00000000,
                    B00000000,
                    B00000000,
                    B00000000,
*/
}
