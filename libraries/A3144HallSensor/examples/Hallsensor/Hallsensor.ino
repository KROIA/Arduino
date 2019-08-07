#include "Timer.h"
#include "A3144.h"
A3144 hall(A0);
Timer timer;
bool _switch = false;
void setup() {
  Serial.begin(9600);
  hall.OnChange(change);
  hall.OnTriggerHigh(high);
  hall.OnTriggerLow(low);
}

void loop() {
  hall.update();  
  if(timer.start(100))
  {
    Serial.print("rpm: ");
    Serial.println(hall.rpm());
  }
}
void change(bool state)
{
  if(state)
  {
    Serial.println("change: HIGH"); 
  }
  else
  {
    Serial.println("change: LOW"); 
  }
}
void high()
{
  Serial.println("HIGH"); 
}
void low()
{
  Serial.println("LOW"); 
}
