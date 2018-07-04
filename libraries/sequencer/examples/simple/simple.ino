#include "sequencer.h"

Sequencer sequenc;

void func1();
void func2();
void func3();

void setup()
{
  Serial.begin(9600);
  sequenc.add(func1);
  sequenc.add(func2);
  sequenc.add(func3);
  sequenc.startPos(1);
}
  
void loop()
{
  sequenc.run();
  sequenc.stepUp();
  //Serial.println("step "+String(sequenc.step()));
  delay(1000);
}

void func1()
{
  Serial.println("func1");
}
void func2()
{
  Serial.println("func2");
}
void func3()
{
  Serial.println("func3");
}