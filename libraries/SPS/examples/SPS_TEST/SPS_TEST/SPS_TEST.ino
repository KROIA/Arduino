#include "Arduino_SPS.h"


//---------
int anzahlModule = 1;
//---------
SPS sps(anzahlModule);

void setup() {
  Serial.begin(9600);
  sps.init();
//  while(true)
  {}
}

void loop()
{
 test1();
 test2();
 test3();
 test4();
}
void test1()
{
  int time = 30;
  for(int a = 1; a<9; a++)
  {
    for(int b = 1; b<(anzahlModule+1); b++)
    {
      for(int i = 1; i<9; i++)
      {
        {
       sps.setOutputPin(b,i,1);
       if(i==1)
       {
       sps.setOutputPin(b,8,0);
       }
       else
       {
         sps.setOutputPin(b,i-1,0);
       }
       }
       sps.write();
       delay(time);
       time++;
       if(time > 1000)
       {
        time = 30;
       }
      }
    }
  }
}
void test2()
{
  for(int i = 0; i<2; i++)
  {
    for(int x = 1; x<anzahlModule+1; x++)
    {
      sps.setOutputModul(x,B11111111);
    }
    sps.write();
    delay(1000);
    for(int x = 1; x<anzahlModule+1; x++)
    {
      sps.setOutputModul(x,B00000000);
    }
    sps.write();
    delay(1000);
  }
}
void test3()
{
 byte  testArray[anzahlModule];
 for(int i = 0; i<anzahlModule; i++)
 {
   testArray[i] = B10101010;
 }
 sps.setOutput(testArray);
 sps.write();
 delay(1000);
  for(int i = 0; i<anzahlModule; i++)
 {
   testArray[i] = B00000000;
 }
 sps.setOutput(testArray);
 sps.write();
 delay(1000);
}
void test4()
{
  for(int i = 0; i<100; i++)
  {
    sps.read();
    sps.setOutput(sps.getInput());
    sps.write();
    delay(10);
  }
}