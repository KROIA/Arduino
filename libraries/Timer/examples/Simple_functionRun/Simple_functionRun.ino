/*
Timer loop Trigger function call example

*/
#include "Timer.h"

Timer timer; //Make a Timer instance

void setup() {
  Serial.begin(9600); //Setup serial port for debug outputs
  timer.onFinished(timerFinishdFunction); //Set the "void timerFinishdFunction()" as function when timer finishes
  timer.start(1000); //Start the timer with 1000ms 
  timer.autoRestart(true);  //Restart timer automaticly after timer finished
  Serial.println("end of setup");
}

void loop() {
  timer.update(); //check if the Timer is finishd
                  //If yes, run the timerFinishdFunction() and than stop timer.

}

void timerFinishdFunction()//This function is called, when timer is finishd
{
    Serial.println("Timer finishd");
}
