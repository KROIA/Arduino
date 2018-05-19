#include "Arduino_SPS.h"
#include "Timer.h"

SPS sps(1);
Timer timer;
//Timer timer2;
int a = 1;
void setup() {
  Serial.begin(9600);
  sps.init();
  timer.init();
  //timer2.init();
  //timer.start(1000,test);
  
}

void loop() {
  sps.read();
  timer.update();
  //timer2.update();
  timer.start(100,test3);
  sps.write();
}

void test3()
{
  if(a<9)
  {
   sps.setOutputPin(1,a,1);
  }
  else
  {
    sps.setOutputPin(1,a-8,0);
  }
 a++;
 if(a>16)
 {
  a = 1; 
 }
}
















void test()
{
    //timer2.start(500,test1);
    sps.setOutputModul(1,B11111111);
}
void test1()
{
    //timer.start(2000,test);
    sps.setOutputModul(1,B00000000);
}
