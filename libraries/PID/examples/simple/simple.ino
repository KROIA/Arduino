/* V00.00.00
 * 12.07.2019
 * 
 * PID for Arduino
 * 
 * This Example shows the simplest application with this PID
 * You can't run this code directly, you have to adjust the Input, expected and output for your project.
 * This code shows only the procedure of this PID.
 */
#include "pid.h"

const byte inputPin = A0;   //Sensor pin
const byte outputPin = 9;   //actuator pin

PID pid(5,0.01,3);
void setup() {
  Serial.begin(9600);
  pinMode(inputPin,INPUT);
  pinMode(outputPin,OUTPUT);

  /*
   * If you don't call this function, the standard would be 0 which means no limits.
   * 
   * The min/max -parameter prevents the PID of incrementing thourds infinite if the actuator can't 
   * adjust the desired value in a small time frame. Or for example you habe a servo which is contolled by
   * an gyroscope and you want to keep the sensor leveled out, but you turn the servo out of the servorange eg. 180deg.
   * The PID would try to increment even more and when you turn the servo back, it would take some time until the PID-value is small enough 
   * to work again as desired.
   */
  pid.maximum(3);    //Set the maximum possible outputvalue to 3 | set to 0 if you don't want to have a limit
  pid.minimum(-3);
}

void loop() {
  float inputValue = (float)map(analogRead(inputPin),0,1023,0,1000)/1000.f;
  float expectedValue = 0.5;

  /*
   * Inputvalue could be the temperature of a heating/cooling -system.
   */
  pid.input(inputValue);          //Set the input value (Sensor)
  /*
   * Expected could be the desired temperature.
   */
  pid.expected(expectedValue);    //Set the expected value which is used to calculate the error

  /*
   * Always call this funcion after setting the parameter above to calculate the new Output.
   */
  pid.update();                   //calculate the new PID values

  /*
   * The output could by the delta temperature of the heating/cooling -system.
   */
  float output = pid.output();
  analogWrite(outputPin,output);
  Serial.println("Input: "+String(inputValue)+" expected: "+String(expectedValue)+" error: "+String(pid.error())+" output: "+String(output));
  

}
