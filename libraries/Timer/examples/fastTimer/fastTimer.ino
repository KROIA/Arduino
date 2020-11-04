/*
Timer fast timer example
*/
#include "Timer.h"

//Create a timer instance that uses micros instead of millis
Timer timer(TMicros); 

unsigned long startTime1;
unsigned long startTime2;

void setup() {
  delay(1000);
  //Setup serial port for debug outputs
  Serial.begin(9600); 
  
  //Set the "void timerFinishdFunction()" as function when timer finishes
  timer.onFinished(timerFinishdFunction); 
  
  
  //Start the timer with 500us 
  //startTime1 and 2 will be used to check the timers time.
  //Two measurements are carried out because the arduino is very slow and 
  //therefore the fast timer also shows a great deal of tolerance. 
  //A Teensy is recommended for precise use of the fast timer.
  startTime1 = micros();
  timer.start(500); 
  startTime2 = micros(); 
}

void loop() {
  timer.update(); //check if the Timer is finishd
                  //If yes, run the timerFinishdFunction() and than stop timer.
}

void timerFinishdFunction()//This function is called, when timer is finishd
{
  unsigned long endTime = micros();
  Serial.print("Timer finishd, Timeduration between: ");
  Serial.print(endTime - startTime2);
  Serial.print(" and ");
  Serial.print(endTime - startTime1);
  Serial.println("us");
}
