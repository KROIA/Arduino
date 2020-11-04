/*
Timer runtime call example

*/
#include "Timer.h"

Timer timer; //Make a Timer instance
unsigned int time = 10000; //set time to 10000ms -> 10s

void setup() {
  Serial.begin(9600); //Setup serial port for debug outputs
  Serial.println("end of setup");
  Serial.println("\nType in an integer to change the time of the timer.\nIt automaticly updates it\n");
  delay(2000);
}

void loop() {
  //When you use the timer in an if(), than you don't have to call the .update() function.
  //timer.update(); //check if the Timer is finishd
                   
 
  if(Serial.available() > 0)
  {
      unsigned int newTime = Serial.readStringUntil('\n').toInt();
      Serial.print("Overwrite timers time from: ");
      Serial.print(time);
      Serial.print("ms\tto: ");
      Serial.print(newTime);
      Serial.println("ms");
      time = newTime;
  }
  
  // If timer isn't running, it will be started
  // The "time" can by changed and the timer will update it self
  if(timer.start(time))// check if timer is finished
  {                    // If Yes, stop the timer and return true
    Serial.println("timer finished");
    while(true){}
  }
  displayRuntime();
}
void displayRuntime()
{
  Serial.print("timer's current runtime: ");
  Serial.print(timer.runtime());
  Serial.println("ms");
  
  //Use delay very carefully. A delay can make the timer work imprecisely. The delay is only used to make the console output clear.
  delay(100);
}