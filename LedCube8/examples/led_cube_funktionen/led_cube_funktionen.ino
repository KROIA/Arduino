#include "ledcube8.h"
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
void setup()
{
  //Serial.begin(9600);
 // Serial.println("TEST");
  cube.init();
  cube.time(100);
  //cube.draw(1,a,b,c,d,e,f,g,h);
}

void loop()
{
 
  cube.rain(1000,30);


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
