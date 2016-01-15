#include "LDR.h"

LDR Sensor(A0);
void setup() 
{
  Sensor.init();
  Serial.begin(9600);
}

void loop() 
{
//  Serial.print(Sensor.getVoltage());
//  Serial.print(" V    ");
  
  Serial.println(Sensor.getLux());
//  Serial.println(" LUX");
  delay(100);
}