#include "button.h"
#include "led.h"
#include "Timer.h"

Led led(13);
Button button(4);

void toggleLed();
void setup()
{ 
  button.OnBothButtonEdges(toggleLed);
}

void loop() 
{
  button.update();
}

void toggleLed()
{
  led.toggle();
}
