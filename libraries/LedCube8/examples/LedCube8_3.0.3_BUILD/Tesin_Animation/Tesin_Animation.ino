#include "ledcube8.h"
#include "data.h"


CUBEDATACUBE temp[3];


LedCube8 cube;

int shift = 8;
int takt = 100;
int time = 100;
int count  = 1;
boolean change = false;
void setup() {
   cube.time(100);
   temp[0] = spirale;
   temp[1] = spirale;
}

void loop() {
  
  animation1();
  animation2();
  animation3();
  animation4();
  
  spiraleAnimation();
  welleAnimation();
  cube.light(5);
  cube.rain(16,50);
  cube.light(100);
  
  kreuzAnimation();
}
void spiraleAnimation()
{
 int V = 150;
 for(int x = 0; x<10; x++)
   {
    for(int i =1; i!=8; i++)
    {  
      cube.drawCube(temp[0]);
      temp[0] = cube.getShiftCubeUp(i,false,spirale);
      temp[1] = cube.getShiftCubeDown(7-i,false,cube.getRotateUp(1,spirale));
      temp[0] = cube.add(temp[0],temp[1]);
      V--;
      cube.time(V);
    }
     for(int i =1; i!=8; i++)
    {
      cube.drawCube(temp[0]);
      temp[0] = cube.getShiftCubeUp(i,false,cube.getRotateUp(1,spirale));
      temp[1] = cube.getShiftCubeDown(7-i,false,spirale);
      temp[0] = cube.add(temp[0],temp[1]);
      V--;
      cube.time(V);
    }
  }
}
void welleAnimation()
{
  cube.time(100);
   for(int x = 0; x<10; x++)
  {
    temp[0] = welle;
    cube.drawCube(temp[0]);
    for(int i = 1; i!=8; i++)
    {
      temp[0] = cube.getShiftCubeRight(i ,true , welle);
      cube.drawCube(temp[0]);
    }
  }
}
void kreuzAnimation()
{
  temp[0] = kreuz;
  temp[1] = kreuz1;
  
  cube.time(100);
  cube.drawCube(temp[0]);
  for(int a = 1; a!=3; a++)
  {
  for(int i = 1; i!=9; i++)
  {
    temp[0] = cube.getShiftCubeLeft(1,true,temp[0]);
    cube.drawCube(temp[0]);
    }
  for(int i = 1; i!=9; i++)
    {
    temp[0] = cube.getShiftCubeLeft90(1,true,temp[0]);
    cube.drawCube(temp[0]);
    }
  for(int i = 1; i!=9; i++)
    {
    temp[0] = cube.getShiftCubeUp(1,true,temp[0]);
    cube.drawCube(temp[0]);
    }
  for(int i = 1; i!=9; i++)
    {
    temp[0] = cube.getShiftCubeRight(1,true,temp[0]);
   
    cube.drawCube(temp[0]);
    }
  for(int i = 1; i!=9; i++)
    {
    temp[0] = cube.getShiftCubeRight90(1,true,temp[0]);
    cube.drawCube(temp[0]);
    }
  for(int i = 1; i!=9; i++)
    {
    temp[0] = cube.getShiftCubeDown(1,true,temp[0]);
    cube.drawCube(temp[0]);
    }
  }
  
  cube.time(200);
  cube.drawCube(temp[0]);
  cube.drawCube(temp[1]);
  cube.drawCube(temp[0]);
  cube.drawCube(temp[1]);
  cube.drawCube(temp[0]);
  cube.drawCube(temp[1]);
  cube.drawCube(temp[0]);
  cube.drawCube(temp[1]);
  temp[0] = temp[1];
  cube.time(100);
  cube.drawCube(temp[0]);
 for(int a = 1; a!=3; a++)
  {
  for(int i = 1; i!=9; i++)
  {
    temp[0] = cube.getShiftCubeLeft(1,true,temp[0]);
    cube.drawCube(temp[0]);
    }
  for(int i = 1; i!=9; i++)
    {
    temp[0] = cube.getShiftCubeLeft90(1,true,temp[0]);
    cube.drawCube(temp[0]);
    }
  for(int i = 1; i!=9; i++)
    {
    temp[0] = cube.getShiftCubeUp(1,true,temp[0]);
    cube.drawCube(temp[0]);
    }
  for(int i = 1; i!=9; i++)
    {
    temp[0] = cube.getShiftCubeRight(1,true,temp[0]);
    cube.drawCube(temp[0]);
    }
  for(int i = 1; i!=9; i++)
    {
    temp[0] = cube.getShiftCubeRight90(1,true,temp[0]);
    cube.drawCube(temp[0]);
    }
  for(int i = 1; i!=9; i++)
    {
    temp[0] = cube.getShiftCubeDown(1,true,temp[0]);
    cube.drawCube(temp[0]);
    }
  }
}
void animation4()
{
  cube.time(300);
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
cube.time(50);
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
  temp[0] = cube.getWall(1);
  temp[1] = cube.getWall90(1);
  temp[2] = cube.getLayer(1);
  
  cube.time(50);
  for(int a = 1; a<9; a++)
  {
  //for(int i = 0; i<10; i++)
  {
    
   /*
  cube.drawWall(1);
  cube.drawWall90(1);
  cube.drawLayer(a);*/
  temp[0] = cube.getWall(1);
  temp[1] = cube.getWall90(1);
  temp[2] = cube.getLayer(a);
  
  cube.drawCube(cube.add(cube.add(temp[0],temp[1]),temp[2]));
  }
  }
  for(int a = 1; a<9; a++)
  {
  //for(int i = 0; i<10; i++)
  {
    /*
  cube.drawWall(1);
  cube.drawWall90(a);
  cube.drawLayer(8);*/
  temp[0] = cube.getWall(1);
  temp[1] = cube.getWall90(a);
  temp[2] = cube.getLayer(8);
  
  cube.drawCube(cube.add(cube.add(temp[0],temp[1]),temp[2]));
  }
  }
  for(int a = 1; a<9; a++)
  {
  //for(int i = 0; i<10; i++)
  {
    /*
  cube.drawWall(a);
  cube.drawWall90(8);
  cube.drawLayer(8);*/
  temp[0] = cube.getWall(a);
  temp[1] = cube.getWall90(8);
  temp[2] = cube.getLayer(8);
  
  cube.drawCube(cube.add(cube.add(temp[0],temp[1]),temp[2]));
  }
  }
  
  //--------------------
  for(int a = 8; a>0; a--)
  {
  //for(int i = 0; i<10; i++)
  {
    /*
  cube.drawWall(8);
  cube.drawWall90(8);
  cube.drawLayer(a);*/
  temp[0] = cube.getWall(8);
  temp[1] = cube.getWall90(8);
  temp[2] = cube.getLayer(a);
  
  cube.drawCube(cube.add(cube.add(temp[0],temp[1]),temp[2]));
  }
  }
  for(int a = 8; a>0; a--)
  {
 // for(int i = 0; i<10; i++)
  {
    /*
  cube.drawWall(8);
  cube.drawWall90(a);
  cube.drawLayer(1);*/
  temp[0] = cube.getWall(8);
  temp[1] = cube.getWall90(a);
  temp[2] = cube.getLayer(1);
  
  cube.drawCube(cube.add(cube.add(temp[0],temp[1]),temp[2]));
  }
  }
 for(int a = 8; a>0; a--)
  {
  //for(int i = 0; i<10; i++)
  {
    /*
  cube.drawWall(a);
  cube.drawWall90(1);
  cube.drawLayer(1);*/
  temp[0] = cube.getWall(a);
  temp[1] = cube.getWall90(1);
  temp[2] = cube.getLayer(1);
  
  cube.drawCube(cube.add(cube.add(temp[0],temp[1]),temp[2]));
  }
  }
  time = 300;
}
void animation1()
{
  //time = 100;
  //cube.time(100);
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
