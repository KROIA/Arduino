#include "Timer.h"
#include "led.h"

Led led(13);

void setup() 
{                
  
}

void loop() 
{
  led.on();
  delay(1000);
  led.off();
  delay(1000);
  led.toggle();
  delay(500);
  led.toggle();
  delay(500);
}