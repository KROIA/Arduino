#include "IR_sensor.h"

IR_sensor sensor(3,A0);
void lowTriggerFunction();
void highTriggerFunction();
void setup()
{
  Serial.begin(9600);
  sensor.onLowTrigger(lowTriggerFunction);
  sensor.onHighTrigger(highTriggerFunction);
  Serial.println(sensor.triggerHysteresis());
}

void loop()
{
  sensor.update();    
}

void lowTriggerFunction()
{
  Serial.print("TRIGGER LOW: ");
  Serial.println(sensor.value());
}
void highTriggerFunction()
{
  Serial.print("TRIGGER HIGH: ");
  Serial.println(sensor.value());
}