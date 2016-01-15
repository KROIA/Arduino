#ifndef LDR_H
#define LDR_H

#define AnzahlMesspunkte 4
//#define DEBUG

struct Voltagate2LuxCorrelation {
  float volt;   
  int lux;    // in Lux
};

class LDR
{
  public:
  LDR(int pin);
  ~LDR();
  void init();
  float getVoltage();
  int getLux();
  void calculate(int MesspunktIndex1, float volt);
  
  private:
  float Voltage;
  int   Lux;
  int   Pin;
  Voltagate2LuxCorrelation messpunkte[AnzahlMesspunkte];
  
};
#endif
