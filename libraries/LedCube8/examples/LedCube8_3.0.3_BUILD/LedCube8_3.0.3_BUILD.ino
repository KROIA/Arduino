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
int time =150;
int Rand = 1;
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
  
  cube.time(70);
  cube.rain(10,10); 
  cube.time(100);
  
  animation8();
  animation1(test);
  animation1(kreuz);
  animation1(kreuz1);
  animation2();
  animation3();
  animation4();
  animation5();
  animation6();
  animation7();
  while(true)
  {
    
    
  
    Rand = random(1,12);
    cube.time(100);
    cube.light(100);
    //Serial.println(Rand);
    
    switch(Rand)
    {
     case 1:
      {
        cube.time(70);
        cube.rain(10,10);
       break;
      } 
      case 2:
      {
        animation1(test);
       break;
      } 
      case 3:
      {
         animation1(kreuz);
       break;
      } 
      case 4:
      {
         animation1(kreuz1);
       break;
      } 
      case 5:
      {
        animation2();
       break;
      } 
      case 6:
      {
        animation3();
       break;
      } 
      case 7:
      {
        animation4();
       break;
      } 
      case 8:
      {
        animation5();
       break;
      } 
      case 9:
      {
        animation6();
       break;
      } 
      case 10:
      {
         animation7();
       break;
      } 
      case 11:
      {
       animation8(); 
      break;
      }
      default:
      {
       break; 
      }
    }
    }
   // rotate3 = cube.getRotate(1,rotate3);
   //cube.drawCube(test);

   
   //
  // animation1(test);
  //animation1(kreuz);
  //animation1(kreuz1);
   //animation2();
  // animation3();
  // animation4();
  // animation5();
  //animation6();
  //animation7();
   
   //cube.shiftCubeLeft( shift , true,test);
   
  // delay(1000);

}
void animation8()
{
  for(int y = 0; y<4; y++)
  {
    for(int x = 0; x<4; x++)
    {
    cube.time(50);
    cube.light(10);
    
    CUBEDATACUBE temp = {
      0,0,0,0,0,0,0,128,
      0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0
      };
    CUBEDATACUBE temp2;
    
    for(int i = 0; i<7; i++)
    {
     temp2 = cube.getRotateUp(x,temp);
     cube.drawCube(temp2);
     temp = cube.getShiftCubeLeft(1,false,temp);
     temp = cube.getShiftCubeRight90(1,false,temp);
     temp = cube.getShiftCubeDown(1,false,temp); 
    }
    
   
    int light = 10;
    for(int i = 0; i<8; i++)
    {
      
      cube.light(light);
      light = light + 10;
     temp = cube.getShiftCubeRight(7-i,false,rotate3);
     temp = cube.getShiftCubeLeft90(7-i,false,temp);
     temp = cube.getShiftCubeUp(7-i,false,temp);
     
     temp = cube.getShiftCubeLeft(7-i,false,temp);
     temp = cube.getShiftCubeRight90(7-i,false,temp);
     temp = cube.getShiftCubeDown(7-i,false,temp);
     temp2 = cube.getRotateUp(x,temp);
    
     cube.drawCube(temp2);
    }
    }
  }
}
void animation7()
{
  CUBEDATACUBE temp;
  int light = 100;
  for(int b = 0; b<8; b++)
  {
    for(int i = 0; i<8; i++)
    {
      temp = cube.add(cube.getShiftCubeUp(i,false,spirale),cube.getRotateUp(1,cube.getShiftCubeDown((7-i),false,spirale)));
      if(i!=0)
      {
        light = light - 13;
        cube.light(light);
      cube.drawCube(temp);
      
      }
    }
    for(int i = 0; i<8; i++)
    {
      temp = cube.add(cube.getRotateUp(1,cube.getShiftCubeUp(i,false,spirale)),cube.getShiftCubeDown((7-i),false,spirale));
       if(i!=0)
      {
        light = light + 13;
        cube.light(light);
      cube.drawCube(temp);
      }
    }
  }
}
void animation6()
{
  int light = 100;
  cube.time(100);
CUBEDATACUBE welle1 = {
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
24,48,96,192,129,3,6,12,
36,72,144,33,66,132,9,18,
66,132,9,18,36,72,144,33,
129,3,6,12,24,48,96,192,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0
};
CUBEDATACUBE welle2 = {
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,255,255,0,0,0,
0,0,255,0,0,255,0,0,
0,255,0,0,0,0,255,0,
255,0,0,0,0,0,0,255,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0
};
//------------------------------------------
CUBEDATACUBE welle3_1 = {
0,0,0,0,0,0,255,255,
0,0,0,0,0,255,0,0,
0,0,0,0,255,0,0,0,
0,0,0,255,0,0,0,0,
0,0,0,255,0,0,0,0,
0,0,255,0,0,0,0,0,
0,255,0,0,0,0,0,0,
255,0,0,0,0,0,0,0
};
CUBEDATACUBE welle3_2 = {
255,0,0,0,0,0,0,0,
0,255,0,0,0,0,0,0,
0,0,255,0,0,0,0,0,
0,0,0,255,0,0,0,0,
0,0,0,255,0,0,0,0,
0,0,0,0,255,0,0,0,
0,0,0,0,0,255,0,0,
0,0,0,0,0,0,255,255
};
CUBEDATACUBE temp;
//------------------------------------------







for(int b = 0; b<8; b++)
{
  for(int i = 0; i<8; i++)
  {
    temp = cube.add(cube.getShiftCubeLeft(i,false,welle3_1),cube.getShiftCubeRight(8-i,false,welle3_2));
    cube.drawCube(temp);
  }
   for(int i = 0; i<8; i++)
  {
    temp = cube.add(cube.getShiftCubeLeft(i,false,welle3_2),cube.getShiftCubeRight(8-i,false,welle3_1));
    cube.drawCube(temp);
  }
}



for(int b = 0; b<4; b++)
{
  for(int i = 0; i<8; i++)
  {
     light = light - 10;
        cube.light(light);
  cube.drawCube(cube.getShiftCubeLeft(i,true,welle2));
  }
  for(int i = 0; i<8; i++)
  {
     light = light + 10;
        cube.light(light);
  cube.drawCube(cube.getShiftCubeLeft(i,true,welle2));
  }
}
for(int b = 0; b<4; b++)
{
  for(int i = 0; i<8; i++)
  {
     light = light - 10;
        cube.light(light);
  cube.drawCube(cube.getShiftCubeLeft(i,true,welle1));
  }
   for(int i = 0; i<8; i++)
  {
     light = light + 10;
        cube.light(light);
  cube.drawCube(cube.getShiftCubeLeft(i,true,welle1));
  }
}

}
void animation5()
{
  cube.time(50);
  cube.light(100);
  CUBEDATACUBE temp;
  
  
  for(int i = 1; i<=3; i++)
  {
    for(int y = 0; y <= 6; y++)
    {
    cube.drawCube(Wand[y]);
    }
    for(int y = 6; y >= 0; y--)
    {
    cube.drawCube(cube.getRotateUp(2,Wand[y]));
    }
    for(int y = 0; y <= 6; y++)
    {
    cube.drawCube(cube.getRotate(2,Wand[y]));
    }
     for(int y = 0; y <= 6; y++)
    {
    cube.drawCube(cube.getRotate(1,Wand[y]));
    }
  }
  
   for(int i = 1; i<=3; i++)
  {
    for(int y = 0; y <= 6; y++)
    {
    cube.drawCube(cube.getRotate90(1,Wand[y]));
    }
    for(int y = 6; y >= 0; y--)
    {
    cube.drawCube(cube.getRotate90(1,cube.getRotateUp(2,Wand[y])));
    }
    for(int y = 0; y <= 6; y++)
    {
    cube.drawCube(cube.getRotate90(1,cube.getRotate(2,Wand[y])));
    }
     for(int y = 0; y <= 6; y++)
    {
    cube.drawCube(cube.getRotate90(1,cube.getRotate(1,Wand[y])));
    }
  }
   for(int y = 0; y <= 6; y++)
    {
    cube.drawCube(cube.getRotate90(1,Wand[y]));
    }
     for(int i = 1; i<=3; i++)
  {
    for(int y = 0; y <= 6; y++)
    {
    cube.drawCube(cube.getRotateUp(3,Wand[y]));
    }
    for(int y = 6; y >= 0; y--)
    {
    cube.drawCube(cube.getRotateUp(3,cube.getRotateUp(2,Wand[y])));
    }
    for(int y = 0; y <= 6; y++)
    {
    cube.drawCube(cube.getRotateUp(3,cube.getRotate(2,Wand[y])));
    }
     for(int y = 0; y <= 6; y++)
    {
    cube.drawCube(cube.getRotateUp(3,cube.getRotate(1,Wand[y])));
    }
  }
  
 // Wand1
}
void animation4()
{
   cube.time(50);
   CUBEDATACUBE temp = rotate3;

     cube.time(200);
    for(int a=0; a<2; a++)
    {
    
     for(int i=0; i<8; i++)
    {
    temp = cube.getRotateUp(1,temp);
    cube.drawCube(temp);
    }
    //rotate3 = cube.getRotate(1,rotate3);
     for(int i=0; i<8; i++)
    {
    temp = cube.getRotate90(1,temp);
    cube.drawCube(temp);
    }
     for(int i=0; i<8; i++)
    {
    temp = cube.getRotate(1,temp);
    cube.drawCube(temp);
    }
    }
}
void animation3()
{
   
/*cube.time(60);
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
      }*/
  cube.time(200);
  
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
  cube.time(50);
  CUBEDATACUBE temp;
  for(int i = 0; i<10; i++)
  {
  for(int a = 1; a<9; a++)
  {
  //for(int i = 0; i<10; i++)
  {
  //cube.drawWall(1);
  //cube.drawWall90(1);
  //cube.drawLayer(a);
  temp = cube.add(cube.add(cube.getWall(1),cube.getWall90(1)),cube.getLayer(a));
  cube.drawCube(temp);
  }
  }
  for(int a = 1; a<9; a++)
  {
  //for(int i = 0; i<10; i++)
  {
 // cube.drawWall(1);
 // cube.drawWall90(a);
 // cube.drawLayer(8);
  temp = cube.add(cube.add(cube.getWall(1),cube.getWall90(a)),cube.getLayer(8));
  cube.drawCube(temp);
  }
  }
  for(int a = 1; a<9; a++)
  {
  //for(int i = 0; i<10; i++)
  {
 // cube.drawWall(a);
 // cube.drawWall90(8);
 // cube.drawLayer(8);
  temp = cube.add(cube.add(cube.getWall(a),cube.getWall90(8)),cube.getLayer(8));
  cube.drawCube(temp);
  }
  }
  
  //--------------------
  for(int a = 8; a>0; a--)
  {
  //for(int i = 0; i<10; i++)
  {
 // cube.drawWall(8);
 // cube.drawWall90(8);
  //cube.drawLayer(a);
  temp = cube.add(cube.add(cube.getWall(8),cube.getWall90(8)),cube.getLayer(a));
  cube.drawCube(temp);
  }
  }
  for(int a = 8; a>0; a--)
  {
  //for(int i = 0; i<10; i++)
  {
//  cube.drawWall(8);
 // cube.drawWall90(a);
 // cube.drawLayer(1);
  temp = cube.add(cube.add(cube.getWall(8),cube.getWall90(a)),cube.getLayer(1));
  cube.drawCube(temp);
  }
  }
 for(int a = 8; a>0; a--)
  {
// for(int i = 0; i<10; i++)
  {
 // cube.drawWall(a);
//  cube.drawWall90(1);
//  cube.drawLayer(1);
  temp = cube.add(cube.add(cube.getWall(a),cube.getWall90(1)),cube.getLayer(1));
  cube.drawCube(temp);
  }
  }
  }
}
void animation1(CUBEDATACUBE test)
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
