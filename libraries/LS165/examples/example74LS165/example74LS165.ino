#include "LS165.h"
LS165 IC(2,3,4,2);  
//2 -> enablePin
//3 -> clockPin
//4 -> serialInPin
//2 -> anzRegister


void setup()
{
  Serial.begin(9600);
  pinMode(7,OUTPUT);
  digitalWrite(7,HIGH);
  digitalWrite(7,LOW);
  IC.read();                    //Lese Register ein
  Serial.print(IC.get(0),BIN);  //Gebe das byte des ersten Registers aus 
  Serial.print(" ");          
  Serial.println(IC.get(1),BIN);//Gebe das byte des zweiten Registers aus 

  Serial.print(rotateByte(IC.get(0)),BIN);  //Gebe das byte des ersten Registers rotiert aus 
  Serial.print(" ");          
  Serial.println(rotateByte(IC.get(1)),BIN);//Gebe das byte des zweiten Registers rotiert aus 
}

void loop()
{
  
}

