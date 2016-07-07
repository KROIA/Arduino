#include "ledcube8.h"
#include "button.h"
#include <Wire.h>

//Button but1(22,activeHigh);
//Button but2(23,activeHigh);
//GAME
byte A = B00010000;
byte B = 0;
byte C = 0;
byte D = 0;
byte E = 0;
byte F = 0;
byte G = 0;
byte H = 0;

byte aa = B01010000;
byte bb;
int sR = 1;
byte Resultat;

 byte layer;
 byte layer2;









byte ledPin[8]        = {2,3,4,5,6,7,8,9};
byte addressPin[4]    = {10,11,12,13};
byte layerPin[4]      = {A0,A1,A2,A3};

  byte a = B10000001;
  byte b = B01000010;
  byte c = B00100100;
  byte d = B00011000;
  byte e = B00011000;
  byte f = B00100100;
  byte g = B01000010;
  byte h = B10000001;
LedCube8 cube(ledPin,addressPin,layerPin);
int takt = 100;




CUBEDATA cubeData[8]{A,B,C,D,E,F,G,H};

POS pos {1,5,1};



void setup()
{
   Wire.begin(1);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent);
//  but1.init();
//  but2.init();
//  but1.OnPressedEdge(button1);
//  but2.OnPressedEdge(button2);
    Serial.begin(9600);
  //Serial.begin(9600);
 // Serial.println("TEST");
  cube.init();
  cube.time(100);
  //cube.draw(1,a,b,c,d,e,f,g,h);
  
  /*
  cube.draw(8,cubeData.A,cubeData.B,cubeData.C,cubeData.D,cubeData.E,cubeData.F,cubeData.G,cubeData.H);
  cubeData = cube.shiftR(pos,1,cubeData);
  Serial.print(cubeData.A);
  Serial.print(" <-- Reultat ");
  Serial.println("");
   cube.draw(8,cubeData.A,cubeData.B,cubeData.C,cubeData.D,cubeData.E,cubeData.F,cubeData.G,cubeData.H);
  pos.Y = 4;
  cubeData = cube.shiftR(pos,1,cubeData);
  Serial.print(cubeData.A);
  Serial.print(" <-- Reultat ");
  
  
  cube.draw(8,cubeData.A,cubeData.B,cubeData.C,cubeData.D,cubeData.E,cubeData.F,cubeData.G,cubeData.H);
  */
  
  
}
void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // loop through all but the last
  //for(int i = 1; i<9; i++)
  int i = Wire.read();
  
    cubeData[i].A =  Wire.read(); // receive byte as a character
    cubeData[i].B =  Wire.read();
    cubeData[i].C =  Wire.read();
    cubeData[i].D =  Wire.read();
    cubeData[i].E =  Wire.read();
    cubeData[i].F =  Wire.read();
    cubeData[i].G =  Wire.read();
    cubeData[i].H =  Wire.read();   
    
  }
  
  
}
void loop()
{

  
  while(true)
  {
   /*if(layer != layer2)
   {
     // cube.draw(layer,0,0,0,0,0,0,0,0);
   }*/
    cube.drawCube(cubeData[0].A,cubeData[0].B,cubeData[0].C,cubeData[0].D,cubeData[0].E,cubeData[0].F,cubeData[0].G,cubeData[0].H,
                  cubeData[1].A,cubeData[1].B,cubeData[1].C,cubeData[1].D,cubeData[1].E,cubeData[1].F,cubeData[1].G,cubeData[1].H,
                  cubeData[2].A,cubeData[2].B,cubeData[2].C,cubeData[2].D,cubeData[2].E,cubeData[2].F,cubeData[2].G,cubeData[2].H,
                  cubeData[3].A,cubeData[3].B,cubeData[3].C,cubeData[3].D,cubeData[3].E,cubeData[3].F,cubeData[3].G,cubeData[3].H,
                  cubeData[4].A,cubeData[4].B,cubeData[4].C,cubeData[4].D,cubeData[4].E,cubeData[4].F,cubeData[4].G,cubeData[4].H,
                  cubeData[5].A,cubeData[5].B,cubeData[5].C,cubeData[5].D,cubeData[5].E,cubeData[5].F,cubeData[5].G,cubeData[5].H,
                  cubeData[6].A,cubeData[6].B,cubeData[6].C,cubeData[6].D,cubeData[6].E,cubeData[6].F,cubeData[6].G,cubeData[6].H,
                  cubeData[7].A,cubeData[7].B,cubeData[7].C,cubeData[7].D,cubeData[7].E,cubeData[7].F,cubeData[7].G,cubeData[7].H);
   // layer2 = layer;
  }
  cube.rain(1,30);


  cube.time(3000);
  
  cube.drawCube(
0,2,0,8,0,0,0,0,
2,7,10,28,8,0,0,0,
2,7,10,28,8,0,0,0,
0,2,0,8,0,0,0,0,
0,2,0,8,0,0,0,0,
7,3,24,56,0,0,0,0,
248,252,231,199,63,7,3,3,
0,0,0,0,192,248,252,252);
    //cube.shiftLayerR(80,8,true,a,b,c,d,e,f,g,h);
    //cube.shiftLayerR(1,7,true,a,b,c,d,e,f,g,h);
   cube.time(60);
  for(int x=0; x<5; x++)
    {
      for(int i=1; i<9; i++)
        {
         cube.drawLayer(i);
        }
      for(int i=8; i>1; i--)
        {
         cube.drawLayer(i);
        }
      }
  cube.time(150);
  cube.drawLayer(1);
  cube.drawWall(1);
  cube.drawLayer(8);
  cube.drawWall(8);
  
  cube.drawLayer(1);
  cube.drawWall(1);
  cube.drawLayer(8);
  cube.drawWall(8);
  
  cube.drawLayer(1);
  cube.drawWall90(1);
  cube.drawLayer(8);
  cube.drawWall90(8);
  
  cube.drawLayer(1);
  cube.drawWall90(1);
  cube.drawLayer(8);
  cube.drawWall90(8);
  
  cube.time(100);
 cube.shiftCubeR(80,true,a,b,c,d,e,f,g,h,
                         a,b,c,d,e,f,g,h,
                         a,b,c,d,e,f,g,h,
                         a,b,c,d,e,f,g,h,
                         a,b,c,d,e,f,g,h,
                         a,b,c,d,e,f,g,h,
                         a,b,c,d,e,f,g,h,
                         a,b,c,d,e,f,g,h);
   cube.time(2000);                     
  cube.drawCube(
  0,0,0,24,24,0,0,0,
  0,0,0,24,24,0,0,0,
  0,0,0,60,60,90,129,0,
  0,0,0,60,60,24,0,0,
  0,0,0,60,60,24,0,0,
  0,0,0,0,36,0,0,0,
  0,0,0,0,36,0,0,0,
  0,0,0,0,36,36,0,0);
    
    cube.time(150);
  cube.shiftCubeR(80,true,
  0,0,0,24,24,0,0,0,
  0,0,0,24,24,0,0,0,
  0,0,0,60,60,90,129,0,
  0,0,0,60,60,24,0,0,
  0,0,0,60,60,24,0,0,
  0,0,0,0,36,0,0,0,
  0,0,0,0,36,0,0,0,
  0,0,0,0,36,36,0,0); 
 
 cube.shiftCubeR(8,false,
  0,0,0,24,24,0,0,0,
  0,0,0,24,24,0,0,0,
  0,0,0,60,60,90,129,0,
  0,0,0,60,60,24,0,0,
  0,0,0,60,60,24,0,0,
  0,0,0,0,36,0,0,0,
  0,0,0,0,36,0,0,0,
  0,0,0,0,36,36,0,0); 
//----------------------------------------
cube.time(2000);

cube.drawCube(   
0,0,0,2,2,2,0,0,
0,0,0,3,99,3,0,0,
0,0,0,0,66,0,0,0,
0,0,0,0,126,0,0,0,
0,0,0,124,124,124,0,0,
0,0,0,68,0,68,0,0,
0,0,0,68,0,68,0,0,
0,0,0,102,0,102,0,0);

cube.time(150);           
cube.shiftCubeR(80,true,
0,0,0,2,2,2,0,0,
0,0,0,3,99,3,0,0,
0,0,0,0,66,0,0,0,
0,0,0,0,126,0,0,0,
0,0,0,124,124,124,0,0,
0,0,0,68,0,68,0,0,
0,0,0,68,0,68,0,0,
0,0,0,102,0,102,0,0);

cube.shiftCubeR(8,false,
0,0,0,2,2,2,0,0,
0,0,0,3,99,3,0,0,
0,0,0,0,66,0,0,0,
0,0,0,0,126,0,0,0,
0,0,0,124,124,124,0,0,
0,0,0,68,0,68,0,0,
0,0,0,68,0,68,0,0,
0,0,0,102,0,102,0,0);




  cube.time(1);
  for(int y=1; y<5; y++)
      {
        for(int i=1; i<9; i++)
          {
       for(int x=0; x<20; x++)
          { 
          
           
           cube.drawWall(i);
           //cube.drawLayer(i);
           cube.drawWall90(i);
          }
        }
        
        for(int i=7; i>1; i--)
          {
       for(int x=0; x<20; x++)
          { 
          
           
           cube.drawWall(i);
           //cube.drawLayer(i);
           cube.drawWall90(i);
          }
        }
      }
      
      
      
      //---------------------------------------------------------
      
      
       for(int y=1; y<5; y++)
      {
        for(int i=1; i<9; i++)
          {
       for(int x=0; x<20; x++)
          { 
          
           
           cube.drawWall(i);
           cube.drawLayer(i);
           //cube.drawWall90(i);
          }
        }
        
        for(int i=7; i>1; i--)
          {
       for(int x=0; x<20; x++)
          { 
          
           
           cube.drawWall(i);
           cube.drawLayer(i);
           //cube.drawWall90(i);
          }
        }
      }
      
      
      //-------------------------------------
      
      
       for(int y=1; y<5; y++)
      {
        for(int i=1; i<9; i++)
          {
       for(int x=0; x<20; x++)
          { 
          
           
           //cube.drawWall(i);
           cube.drawLayer(i);
           cube.drawWall90(i);
          }
        }
        
        for(int i=7; i>1; i--)
          {
       for(int x=0; x<20; x++)
          { 
          
           
           //cube.drawWall(i);
           cube.drawLayer(i);
           cube.drawWall90(i);
          }
        }
      }
      
      //------------------------------------------
      
       for(int y=1; y<5; y++)
      {
        for(int i=1; i<9; i++)
          {
       for(int x=0; x<20; x++)
          { 
          
           
           cube.drawWall(i);
           cube.drawLayer(i);
           cube.drawWall90(i);
          }
        }
        
        for(int i=7; i>1; i--)
          {
       for(int x=0; x<15; x++)
          { 
          
           
           cube.drawWall(i);
           cube.drawLayer(i);
           cube.drawWall90(i);
          }
        }
      }
      
      //------------------------------------------------***********************************************
      cube.time(100);
      
      
      cube.shiftCubeR(80,true,

24,0,0,0,0,0,0,129,
36,0,0,0,0,0,0,66,
66,0,0,0,0,0,0,36,
129,0,0,0,0,0,0,24,
129,0,0,0,0,0,0,24,
66,0,0,0,0,0,0,36,
36,0,0,0,0,0,0,66,
24,0,0,0,0,0,0,129);
      
      cube.time(1);
for( int y=0; y<10; y++)
   {
    for(int x=1; x<9; x++)
        {
         for(int i=0; i<20;i++)
            {
		cube.drawLayer(x);
		cube.drawLayer(9-x);
	    }
        }
    }
cube.time(100);

 cube.shiftCubeR(80,true,

129,129,129,129,24,24,24,24,
66,66,66,66,36,36,36,36,
36,36,36,36,66,66,66,66,
24,24,24,24,129,129,129,129,
24,24,24,24,129,129,129,129,
36,36,36,36,66,66,66,66,
66,66,66,66,36,36,36,36,
129,129,129,129,24,24,24,24);      
      
      
bool Switch = false;

for(byte i = 0; i< 10; i++)
{
if(Switch == false)
{
kugel1();
kugel2();
kugel3();
kugel4();
kugel5();
kugel6();
kugel7();
kugel8();
kugel9();
Switch = true;
}
else
{
kugel9();
kugel8();
kugel7();
kugel6();
kugel5();
kugel4();
kugel3();
kugel2();
kugel1();
Switch = false;
}
}
Switch = false;



//-----------------------



for(byte i = 0; i< 10; i++)
{
if(Switch == false)
{
wurfel1();
wurfel2();
wurfel3();
wurfel4();
Switch = true;
}
else
{
wurfel4();
wurfel3();
wurfel2();
wurfel1();
Switch = false;
}
}
}


//------------------Funktionen----------------//


//---------------------Kugel------------------//
void kugel1()
{
cube.drawCube(
129,0,0,0,0,0,0,129,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
129,0,0,0,0,0,0,129);
}
void kugel2()
{
cube.drawCube(
66,129,0,0,0,0,129,66,
129,0,0,0,0,0,0,129,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
129,0,0,0,0,0,0,129,
66,129,0,0,0,0,129,66);
}
void kugel3()
{
cube.drawCube( 
36,66,129,0,0,129,66,36,
66,129,0,0,0,0,129,66,
129,0,0,0,0,0,0,129,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
129,0,0,0,0,0,0,129,
66,129,0,0,0,0,129,66,
36,66,129,0,0,129,66,36);
}
void kugel4()
{
cube.drawCube( 
24,36,66,129,129,66,36,24,
36,66,129,0,0,129,66,36,
66,129,0,0,0,0,129,66,
129,0,0,0,0,0,0,129,
129,0,0,0,0,0,0,129,
66,129,0,0,0,0,129,66,
36,66,129,0,0,129,66,36,
24,36,66,129,129,66,36,24);
}
void kugel5()
{
cube.drawCube( 
0,24,36,66,66,36,24,0,
24,36,66,129,129,66,36,24,
36,66,129,0,0,129,66,36,
66,129,0,0,0,0,129,66,
66,129,0,0,0,0,129,66,
36,66,129,0,0,129,66,36,
24,36,66,129,129,66,36,24,
0,24,36,66,66,36,24,0);
}
void kugel6()
{
cube.drawCube(
0,0,24,36,36,24,0,0,
0,24,36,66,66,36,24,0,
24,36,66,129,129,66,36,24,
36,66,129,0,0,129,66,36,
36,66,129,0,0,129,66,36,
24,36,66,129,129,66,36,24,
0,24,36,66,66,36,24,0,
0,0,24,36,36,24,0,0);
}
void kugel7()
{
cube.drawCube( 
0,0,0,24,24,0,0,0,
0,0,24,36,36,24,0,0,
0,24,36,66,66,36,24,0,
24,36,66,129,129,66,36,24,
24,36,66,129,129,66,36,24,
0,24,36,66,66,36,24,0,
0,0,24,36,36,24,0,0,
0,0,0,24,24,0,0,0); 
}
void kugel8()
{
 cube.drawCube(
0,0,0,0,0,0,0,0,
0,0,0,24,24,0,0,0,
0,0,24,36,36,24,0,0,
0,24,36,66,66,36,24,0,
0,24,36,66,66,36,24,0,
0,0,24,36,36,24,0,0,
0,0,0,24,24,0,0,0,
0,0,0,0,0,0,0,0);
}
void kugel9()
{
cube.drawCube(
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,24,24,0,0,0,
0,0,24,36,36,24,0,0,
0,0,24,36,36,24,0,0,
0,0,0,24,24,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0);
}


//--------------------Würfel------------------
void wurfel1()
{
cube.drawCube(                   //cube full
 255,129,129,129,129,129,129,255,
 129,0,0,0,0,0,0,129,
 129,0,0,0,0,0,0,129,
 129,0,0,0,0,0,0,129,
 129,0,0,0,0,0,0,129,
 129,0,0,0,0,0,0,129,
 129,0,0,0,0,0,0,129,
 255,129,129,129,129,129,129,255);
 }
 void wurfel2()
{
cube.drawCube(
0,0,0,0,0,0,0,0,
0,126,66,66,66,66,126,0,
0,66,0,0,0,0,66,0,
0,66,0,0,0,0,66,0, 
0,66,0,0,0,0,66,0, 
0,66,0,0,0,0,66,0, 
0,126,66,66,66,66,126,0,
0,0,0,0,0,0,0,0); 
 }
 void wurfel3()
{
cube.drawCube(
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,60,36,36,60,0,0,
0,0,36,0,0,36,0,0,
0,0,36,0,0,36,0,0,
0,0,60,36,36,60,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0);
 }
 void wurfel4()
{
cube.drawCube( 
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,24,24,0,0,0,
0,0,0,24,24,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0);
}

//------------------
void button1()
{
  if(pos.Y >1)
//  cubeData = cube.shiftR(pos,1,cubeData);
  
  pos.Y--;
  if(pos.Y == 0)
  pos.Y = 1;
 // Serial.print(cubeData.A,BIN);
  Serial.print("  ");
  Serial.println(pos.Y);

}
void button2()
{
  if(pos.Y < 8)
 // cubeData = cube.shiftL(pos,1,cubeData);
  
  pos.Y++;
  if(pos.Y == 9)
  pos.Y = 8;
 // Serial.print(cubeData.A,BIN);
    Serial.print("  ");
  Serial.println(pos.Y);

  
}