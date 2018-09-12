#include "Arduino_SPS.h"


//---------
int anzahlModule = 2;
//---------
SPS sps(anzahlModule);
void setup() {
  Serial.begin(9600);
  

   //sps.onError(error);

  sps.setupEvents(sps_event_onInputChange,1);
  sps.setupEvents(sps_event_onInputRising,1);
  sps.setupEvents(sps_event_onInputFalling,1);

 
  
  sps.onInputChange(0,change0);
  sps.onInputRising(1,rising);
  sps.onInputRising(2,rising);
  sps.onInputFalling(2,falling);
 // sps.init();
//  while(true)
  {}
}
void error(byte error)
{
  Serial.print("ERROR: ");
  Serial.println(error);
}
void change0(bool value)
{
  Serial.print("change: ");
  Serial.println(value);
}
void rising()
{
  Serial.println("rising");
}
void falling()
{
  Serial.println("falling");
}
void loop()
{
   
  sps.read();
  sps.checkEvents();
  /*
 test0();
 test1();
 test2();
 test3();
 test4();*/
 sps.write();
}
void test0()
{
  sps.read();
  sps.output(sps.input());
  

 // delay(10);
  sps.write();
/*
  for(int a = 0; a<8; a++)
  {
    sps.output(0,a,1);
    sps.write();
    delay(100);
    
  }
  for(int a = 0; a<8; a++)
  {
    sps.output(1,a,1);
    sps.write();
    delay(100);
    
  }
  */
}
void test1()
{
  int time = 30;
  for(int a = 0; a<8; a++)
  {
    for(int b = 0; b<anzahlModule; b++)
    {
      for(int i = 0; i<8; i++)
      {
        {
       sps.output(b,i,1);
       if(i==0)
       {
        for(int c=0; c<anzahlModule; c++)
        {
         sps.output(c,7,0);
        }
       }
       else
       {
         sps.output(b,i-1,0);
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
      sps.output(x,B11111111);
    }
    sps.write();
    delay(1000);
    for(int x = 1; x<anzahlModule+1; x++)
    {
      sps.output(x,B00000000);
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
 sps.output(testArray);
 sps.write();
 delay(1000);
  for(int i = 0; i<anzahlModule; i++)
 {
   testArray[i] = B00000000;
 }
 sps.output(testArray);
 sps.write();
 delay(1000);
}
void test4()
{
  for(int i = 0; i<100; i++)
  {
    sps.read();
    sps.output(sps.input());
    sps.write();
    delay(10);
  }
}