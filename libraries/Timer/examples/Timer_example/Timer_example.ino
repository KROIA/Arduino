#include "Timer.h"

Timer timer;
Timer timer2;
Timer timer3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  timer.on_timeout(timeout);
  timer2.on_timeout(timeout2);
  timer.start(5000);
}
int counter = 0;
void loop() {
  // put your main code here, to run repeatedly:
  timer.update();
  timer2.update();
  delay(100);
  Serial.print(timer.runtime());
  Serial.print("\t");
  Serial.println(timer2.runtime());
  if(timer3.start(1000))
  {
   Serial.println("timer3"); 
  }
}
void timeout()
{
 Serial.println("TIMEOUT"); 
 timer2.start(2500);
}
void timeout2()
{
 Serial.println("TIMEOUT2"); 
 timer.start(1500);
 counter++;
 if(counter == 3)
 {
   delay(100);
   Serial.print("STOP");
   timer.stop();
 }
}