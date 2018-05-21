/*
Timer endless timer example

*/
#include "Timer.h"

Timer timer; //Make a Timer instance

unsigned int time = 0; //set time to 0ms -> timer will never stop
unsigned int counter = 0;

void setup() {
  Serial.begin(9600); //Setup serial port for debug outputs
  Serial.println("end of setup");
  timer.start(time); // Start the timer with 0ms time
}

void loop() {
  timer.update(); //check if the Timer is finishd
  
  Serial.print("current runtime of timer: ");
  Serial.print(timer.runtime()/1000);
  Serial.println("s");
  delay(500);
  counter++;
  if(counter > 10)
  {
    counter = 0;
    //timer will run endless untill timer.stop() is called
    Serial.print("end time: ");
    Serial.println(timer.stop());  // Stop the timer and get the runtime
    timer.start(time);             // Start the timer again
  }
  
}
