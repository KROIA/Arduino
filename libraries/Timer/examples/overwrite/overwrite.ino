/*
Timer overwrite time example

*/
#include "Timer.h"

Timer timer(TMicros); //Make a Timer instance as an micros Timer

// time can go from 0 to 4'294'967'295 (unsigned long)
unsigned long time = 1000000; //set time to 1000000us -> 1000ms

void setup() {
  Serial.begin(9600); //Setup serial port for debug outputs
  Serial.println("end of setup");
}

void loop() {
  //When you use the timer in an if(), than you don't have to call the .update() function.
  //timer.update(); //check if the Timer is finishd
                  
  
  // If timer isn't running, it will be started
  // The "time" can by changed and the timer will update it self
  if(timer.start(time))// check if timer is finished
  {                    // If Yes, stop the timer and return true
    Serial.println("timer finished");
  }
}
