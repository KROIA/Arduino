#include "LDR.H"
#include <Arduino.h>

 LDR::LDR(int pin)
{
  Pin = pin;
  
  messpunkte[0].volt = 0;
  messpunkte[0].lux = 0;
  
  messpunkte[1].volt = 0.245;
  messpunkte[1].lux = 53;
  
  messpunkte[2].volt = 0.635;
  messpunkte[2].lux = 200;
  
  messpunkte[3].volt = 0.830;
  messpunkte[3].lux = 500;
}

 LDR::~LDR()
{
  
}

void LDR::init()
{
  pinMode(Pin,INPUT); 
}

float LDR::getVoltage()
{
  Voltage = analogRead(Pin)*5/1024.0;
  return Voltage;
}

int LDR::getLux()
{
  // Spannungswert aktualisieren
  getVoltage();
  
  for(int i=0;i<(AnzahlMesspunkte-1);i++)
  {
    calculate(i,Voltage);
  }
 
  return Lux;
}

void LDR::calculate(int MesspunktIndex1, float volt)
{ 
    int a;
    int b;
  
  if((messpunkte[MesspunktIndex1].volt < volt) && (volt < messpunkte[MesspunktIndex1+1].volt))
  {
    a = (messpunkte[MesspunktIndex1+1].lux  - messpunkte[MesspunktIndex1].lux)/
        (messpunkte[MesspunktIndex1+1].volt - messpunkte[MesspunktIndex1].volt);
    
    b = messpunkte[MesspunktIndex1+1].lux - (a * messpunkte[MesspunktIndex1+1].volt);
#ifdef DEBUG
     Serial.println(a);
     Serial.println(b);
#endif
    Lux = (a * volt) + b;
  }
}
