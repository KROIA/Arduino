/*
Timer loop Trigger function call example

*/
#include "Timer.h"

Timer timer; //Make a Timer instance

void setup() {
  Serial.begin(9600); //Setup serial port for debug outputs
  timer.onFinished(timerFinishdFunction); //Set the "void timerFinishdFunction()" as function when timer finishes
  timer.start(1000); //Start the timer with 1000ms 
  Serial.println("end of setup");
}

void loop() {
  timer.update(); //check if the Timer is finishd
                  //If yes, run the timerFinishdFunction() and than stop timer.
  if(timer.isRunning()) //check if timer is running
  {
    Serial.print("Timer's time: ");
    Serial.println(timer.runtime());  // get current runtime of timer
    delay(10);
  }
}

void timerFinishdFunction()//This function is called, when timer is finishd
{
    Serial.println("Timer finishd");
}
