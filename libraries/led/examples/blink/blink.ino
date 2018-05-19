#include "Timer.h"
#include "led.h"

Led led(13);

void setup() 
{                
  led.blinkOn(100);
}

void loop() 
{
  led.update();
}