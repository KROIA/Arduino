/*
Timer cyclical function call example

*/
#include "Timer.h"

Timer timer; //Make a Timer instance

void setup() {
  Serial.begin(9600); //Setup serial port for debug outputs
  timer.onFinished(timerFinishdFunction); //Set the "void timerFinishdFunction()" as function when timer finishes
  timer.autoRestart(true); //If this is set to true, the timer will automatically restart after it was finished
  timer.start(1000);  //Start the timer with 1000ms 
  Serial.println("end of setup");
}

void loop() {
  timer.update(); //Updates the timer and checks if the Timer is finishd
                  //If yes, run the timerFinishdFunction() and than stop timer.
  if(timer.isRunning()) //check if timer is running
  {
    Serial.print("Timer's time: ");
    Serial.println(timer.runtime());  // get current runtime of timer

    //Use delay very carefully. A delay can make the timer work imprecisely. The delay is only used to make the console output clear.
    delay(200);
  }
}

void timerFinishdFunction()//This function is called, when timer is finishd
{
    Serial.println("Timer finishd");
}