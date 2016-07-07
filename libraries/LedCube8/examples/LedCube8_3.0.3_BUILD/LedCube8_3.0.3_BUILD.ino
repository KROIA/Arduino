#include "ledcube8.h"
#include "data.h"
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
LedCube8 cube;
int takt = 100;
int time =300;
void setup()
{
  Serial.begin(9600);
  Serial.println("TEST");
  
  
  cube.init();
cube.time(time);

}
int shift = 8;
CUBEDATACUBE test{0,0,0,24,24,0,0,0,
0,0,0,24,24,0,0,0,
0,0,24,36,36,24,0,0,
0,24,36,66,66,36,24,0,
0,24,36,66,66,36,24,0,
0,0,24,36,36,24,0,0,
0,0,0,24,24,0,0,0,
0,0,0,24,24,0,0,0};

CUBEDATACUBE rotate{
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
60,60,60,60,60,60,60,0,
66,66,66,66,66,66,66,0,
89,89,89,89,89,89,89,0,
89,89,89,89,89,89,89,0,
49,49,49,49,49,49,49,0,
2 ,2 ,2 ,2 ,2 ,2 ,2 ,0 ,
4 ,4 ,4 ,4 ,4 ,4 ,4 ,0 

};
  CUBEDATACUBE rotate2{
128,128,128,128,128,128,128,128,
64 ,64 ,64 ,64 ,64 ,64 ,64 ,64 ,
160,160,160,160,160,160,160,160,
112,112,112,112,112,112,112,112,
14 ,14 ,14 ,14 ,14 ,14 ,14 ,14 ,
50 ,50 ,50 ,50 ,50 ,50 ,50 ,50 ,
20 ,20 ,20 ,20 ,20 ,20 ,20 ,20 ,
1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  

};
   CUBEDATACUBE rotate3{
1,0,0,0,0,0,0,0,
65,0,0,0,0,0,65,0,
33,0,0,0,0,33,0,0,
17,0,0,0,17,0,0,0,
9,0,0,9,0,0,0,0,
5,0,5,0,0,0,0,0,
3,3,0,0,0,0,0,0,
255,3,5,9,17,33,65,1	



}; 
  
  
  
int count = 1;
boolean change = false;

void loop()
{
  while(true)
  {
    
   // rotate3 = cube.getRotate(1,rotate3);
   //cube.drawCube(test);
   //cube.rain(10,10);
   //animation1();
   //animation2();
   //animation3();
   animation4();
   }
   //cube.shiftCubeLeft( shift , true,test);
   
  // delay(1000);

}
void animation4()
{
  for(int a=0; a<8; a++)
    {
  for(int i=0; i<8; i++)
    {
    Wand3 = cube.getRotateUp(1,Wand3);
    cube.drawCube(Wand3);
    }
    //rotate3 = cube.getRotate(1,rotate3);
     for(int i=0; i<8; i++)
    {
    Wand3 = cube.getRotate90(1,Wand3);
    cube.drawCube(Wand3);
    }
     for(int i=0; i<8; i++)
    {
    Wand3 = cube.getRotate(1,Wand3);
    cube.drawCube(Wand3);
    }
   } 
    
    for(int a=0; a<8; a++)
    {
    
     for(int i=0; i<8; i++)
    {
    rotate3 = cube.getRotateUp(1,rotate3);
    cube.drawCube(rotate3);
    }
    //rotate3 = cube.getRotate(1,rotate3);
     for(int i=0; i<8; i++)
    {
    rotate3 = cube.getRotate90(1,rotate3);
    cube.drawCube(rotate3);
    }
     for(int i=0; i<8; i++)
    {
    rotate3 = cube.getRotate(1,rotate3);
    cube.drawCube(rotate3);
    }
    }
}
void animation3()
{
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

}
void animation2()
{
  cube.time(1);
  for(int a = 1; a<9; a++)
  {
  for(int i = 0; i<10; i++)
  {
  cube.drawWall(1);
  cube.drawWall90(1);
  cube.drawLayer(a);
  }
  }
  for(int a = 1; a<9; a++)
  {
  for(int i = 0; i<10; i++)
  {
  cube.drawWall(1);
  cube.drawWall90(a);
  cube.drawLayer(8);
  }
  }
  for(int a = 1; a<9; a++)
  {
  for(int i = 0; i<10; i++)
  {
  cube.drawWall(a);
  cube.drawWall90(8);
  cube.drawLayer(8);
  }
  }
  
  //--------------------
  for(int a = 8; a>0; a--)
  {
  for(int i = 0; i<10; i++)
  {
  cube.drawWall(8);
  cube.drawWall90(8);
  cube.drawLayer(a);
  }
  }
  for(int a = 8; a>0; a--)
  {
  for(int i = 0; i<10; i++)
  {
  cube.drawWall(8);
  cube.drawWall90(a);
  cube.drawLayer(1);
  }
  }
 for(int a = 8; a>0; a--)
  {
  for(int i = 0; i<10; i++)
  {
  cube.drawWall(a);
  cube.drawWall90(1);
  cube.drawLayer(1);
  }
  }
}
void animation1()
{
  countUpDown();   
   cube.shiftCubeDown( shift , true,test);
   countUpDown();
   cube.shiftCubeRight(shift , true,test);
   countUpDown();
   cube.shiftCubeLeft90( shift , true,test);
   countUpDown();
   cube.shiftCubeUp( shift, true,test);
   countUpDown();
   cube.shiftCubeLeft( shift, true,test);
   countUpDown();
   cube.shiftCubeRight90( shift , true,test);
   countUpDown();
   cube.shiftCubeRight(shift , true,test);
}
void countUpDown()
{
  if(count > 90)
   {
     change = true;
   }
   if(count < 1)
   {
     change = false;
   }
   if(change == true)
   {
     count = count - 5;
   }
   else
   {
     count = count + 5; 
   }
    cube.time(time-count);
    cube.light(time-count);
}