#include "A3144.h"


A3144 hall(A0);          //Make an instance of A3144 on Pin A0

void change(bool state);
void high();
void low();

void setup() {
  Serial.begin(9600);
  hall.OnChange(change);     //Define function which is executed when a change occurs
  hall.OnTriggerHigh(high);  //Define function which is executed when a rising flank occurs
  hall.OnTriggerLow(low);    //Define function which is executed when a sinking flank occurs
}

void loop() {
  hall.update();  				 //Read the sensor
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
