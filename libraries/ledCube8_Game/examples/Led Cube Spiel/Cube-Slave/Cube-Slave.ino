#include <Wire.h>
#include "ledcube8.h"
LedCube8 cube;
CUBEDATACUBE Data = {
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0
};
  
void setup() {

  Wire.begin(1);
  Wire.onReceive(reciveEvent);
  cube.time(8);
}

void loop()
{
  cube.drawCube(Data);
}
void reciveEvent(int howMany)
{
  while (1 < Wire.available())
  {
   // Serial.println("1");
    //int Layer = Wire.read();
    
    /*switch(Layer)
    {
     case 1:
      {
    Data.CA8 = Wire.read();
    Data.CB8 = Wire.read();
    Data.CC8 = Wire.read();
    Data.CD8 = Wire.read();
    Data.CE8 = Wire.read();
    Data.CF8 = Wire.read();
    Data.CG8 = Wire.read();
    Data.CH8 = Wire.read();
      break;
      } 
      case 2:
      {
       Data.CA7 = Wire.read();
    Data.CB7 = Wire.read();
    Data.CC7 = Wire.read();
    Data.CD7 = Wire.read();
    Data.CE7 = Wire.read();
    Data.CF7 = Wire.read();
    Data.CG7 = Wire.read();
    Data.CH7 = Wire.read();
      break;
      } 
      case 3:
      {
       Data.CA6 = Wire.read();
    Data.CB6 = Wire.read();
    Data.CC6 = Wire.read();
    Data.CD6 = Wire.read();
    Data.CE6 = Wire.read();
    Data.CF6 = Wire.read();
    Data.CG6 = Wire.read();
    Data.CH6 = Wire.read();
      break;
      } 
      case 4:
      {
       Data.CA5 = Wire.read();
    Data.CB5 = Wire.read();
    Data.CC5 = Wire.read();
    Data.CD5 = Wire.read();
    Data.CE5 = Wire.read();
    Data.CF5 = Wire.read();
    Data.CG5 = Wire.read();
    Data.CH5 = Wire.read();
      break;
      } 
      case 5:
      {
       Data.CA4 = Wire.read();
    Data.CB4 = Wire.read();
    Data.CC4 = Wire.read();
    Data.CD4 = Wire.read();
    Data.CE4 = Wire.read();
    Data.CF4 = Wire.read();
    Data.CG4 = Wire.read();
    Data.CH4 = Wire.read();
      break;
      } 
      case 6:
      {
       Data.CA3 = Wire.read();
    Data.CB3 = Wire.read();
    Data.CC3 = Wire.read();
    Data.CD3 = Wire.read();
    Data.CE3 = Wire.read();
    Data.CF3 = Wire.read();
    Data.CG3 = Wire.read();
    Data.CH3 = Wire.read();
      break;
      } 
      case 7:
      {
       Data.CA2 = Wire.read();
    Data.CB2 = Wire.read();
    Data.CC2 = Wire.read();
    Data.CD2 = Wire.read();
    Data.CE2 = Wire.read();
    Data.CF2 = Wire.read();
    Data.CG2 = Wire.read();
    Data.CH2 = Wire.read();
      break;
      } 
      case 8:
      {
        Data.CA1 = Wire.read();
    Data.CB1 = Wire.read();
    Data.CC1 = Wire.read();
    Data.CD1 = Wire.read();
    Data.CE1 = Wire.read();
    Data.CF1 = Wire.read();
    Data.CG1 = Wire.read();
    Data.CH1 = Wire.read();
      break;
      } 
    }*/
  //  Serial.println("2");
    
    
    
    
    
    int reference = Wire.read();
    switch(reference)
    {
      case 1:
      {
    Data.CA1 = Wire.read();
    Data.CB1 = Wire.read();
    Data.CC1 = Wire.read();
    Data.CD1 = Wire.read();
    Data.CE1 = Wire.read();
    Data.CF1 = Wire.read();
    Data.CG1 = Wire.read();
    Data.CH1 = Wire.read();
    
    Data.CA2 = Wire.read();
    Data.CB2 = Wire.read();
    Data.CC2 = Wire.read();
    Data.CD2 = Wire.read();
    Data.CE2 = Wire.read();
    Data.CF2 = Wire.read();
    Data.CG2 = Wire.read();
    Data.CH2 = Wire.read();
    break;
    }
    case 2:
      {
    Data.CA3 = Wire.read();
    Data.CB3 = Wire.read();
    Data.CC3 = Wire.read();
    Data.CD3 = Wire.read();
    Data.CE3 = Wire.read();
    Data.CF3 = Wire.read();
    Data.CG3 = Wire.read();
    Data.CH3 = Wire.read();
    
    Data.CA4 = Wire.read();
    Data.CB4 = Wire.read();
    Data.CC4 = Wire.read();
    Data.CD4 = Wire.read();
    Data.CE4 = Wire.read();
    Data.CF4 = Wire.read();
    Data.CG4 = Wire.read();
    Data.CH4 = Wire.read();
    break;
    }
    case 3:
      {
    Data.CA5 = Wire.read();
    Data.CB5 = Wire.read();
    Data.CC5 = Wire.read();
    Data.CD5 = Wire.read();
    Data.CE5 = Wire.read();
    Data.CF5 = Wire.read();
    Data.CG5 = Wire.read();
    Data.CH5 = Wire.read();
    
    Data.CA6 = Wire.read();
    Data.CB6 = Wire.read();
    Data.CC6 = Wire.read();
    Data.CD6 = Wire.read();
    Data.CE6 = Wire.read();
    Data.CF6 = Wire.read();
    Data.CG6 = Wire.read();
    Data.CH6 = Wire.read();
    break;
    }
    case 4:
      {
    Data.CA7 = Wire.read();
    Data.CB7 = Wire.read();
    Data.CC7 = Wire.read();
    Data.CD7 = Wire.read();
    Data.CE7 = Wire.read();
    Data.CF7 = Wire.read();
    Data.CG7 = Wire.read();
    Data.CH7 = Wire.read();
    
    Data.CA8 = Wire.read();
    Data.CB8 = Wire.read();
    Data.CC8 = Wire.read();
    Data.CD8 = Wire.read();
    Data.CE8 = Wire.read();
    Data.CF8 = Wire.read();
    Data.CG8 = Wire.read();
    Data.CH8 = Wire.read();
    break;
    }
    }
  }
}
