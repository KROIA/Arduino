#include "TMP36.h"

Tmp36 sensor1(A0);

void setup() 
{
 sensor1.init();
 Serial.begin(9600);
}

void loop() 
{
  //Serial.print(sensor1.getVoltage());
  //Serial.println(" V");
  
  Serial.println(sensor1.getTemp());
  //Serial.println(" C");
 
  delay(100);
}
