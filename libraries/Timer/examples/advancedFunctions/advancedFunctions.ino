/*
Timer advanced function call example

*/
#include "Timer.h"

Timer timer_1; //Make a Timer instance
Timer timer_2; //Make a Timer instance

void timer_1_FinishdFunction();
void timer_2_FinishdFunction();

void setup() {
	//Setup serial port for debug outputs
	Serial.begin(9600); 
	
	//Set the function which will be called when the timer finishes
	timer_1.onFinished(timer_1_FinishdFunction); 
	timer_2.onFinished(timer_2_FinishdFunction); 
	
	//If this is set to true, the timer will automatically restart after it was finished
	timer_1.autoRestart(true); 
	timer_2.autoRestart(true); 
	
	//Start the timer with 1000ms
	timer_1.start(1000); 
	timer_2.start(3000);  
	
	Serial.println("end of setup");
}

void loop() {
	//check if the Timer is finishd
	//If yes, run the timer_x_FinishdFunction() and than restart the timer_x.
	timer_1.update(); 
	timer_2.update(); 
}

//This function is called, when timer_1 is finishd
void timer_1_FinishdFunction()
{
    Serial.println("Timer 1 finishd");
}

//This function is called, when timer_2 is finishd
void timer_2_FinishdFunction()
{
    Serial.println("Timer 2 finishd");
}
