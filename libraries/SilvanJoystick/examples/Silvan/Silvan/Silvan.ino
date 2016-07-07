#include "button.h"
#include "Joystick.h"
#include "Controler.h"
#include "led.h"

Controler controler;
Led L1(22);
Led L2(23);
Led L3(24);
Led L4(25);
Led L5(26);
Led L6(27);

Led L7(28);
Led L8(29);
Led L9(30);
int analog1 = 0;
int analog2 = 0;

void setup() {
  Serial.begin(9600);
L1.init();
L2.init();
L3.init();
L4.init();
L5.init();
L6.init();
L7.init();
L8.init();
L9.init();
pinMode(A2,OUTPUT);
pinMode(A3,OUTPUT);
  controler.init();
  controler.AButton->OnPressedEdge(Abut);
  controler.BButton->OnPressedEdge(Bbut);
  controler.CButton->OnPressedEdge(Cbut);
  controler.DButton->OnPressedEdge(Dbut);
  controler.EButton->OnPressedEdge(Ebut);
  controler.FButton->OnPressedEdge(Fbut);
  
  
       
//  controler.joystick->attachFunctionOnStateChangeToUP(upDetection);
//  controler.joystick->attachFunctionOnStateChangeToDOWN(downDetection);
//  controler.joystick->attachFunctionOnStateChangeToRIGHT(rightDetection);
  controler.joystick->attachFunctionOnStateChangeToMIDDLE(middleDetection);
//  controler.joystick->attachFunctionOnStateChangeToLEFT(leftDetection);
  
  controler.joystick->button->OnPressedEdge(StickbuttonGetPressed);
  
  controler.joystick->setYThreshold(90);
  controler.joystick->setXThreshold(90);
}

void loop() {
  controler.check();
  upDetection();
  downDetection();
  rightDetection();
  leftDetection();
}
void Abut()
{
  L1.toggle();
}
void Bbut()
{
   L2.toggle();
}
void Cbut()
{
   L3.toggle();
}
void Dbut()
{
   L4.toggle();
}
void Ebut()
{
   L5.toggle();
}
void Fbut()
{
   L6.toggle();
}

void upDetection()
{
  analog1 = controler.joystick->getXValue();
  analogWrite(A2,analog1);
}
void downDetection()
{
  analog1 = controler.joystick->getXValue();
  analogWrite(A2,analog1);
}
void rightDetection()
{
  analog2 = controler.joystick->getYValue();
  analogWrite(A3,analog2);
  Serial.print(analog2);
  Serial.print(" ");
  Serial.println(analog1);
}
void leftDetection()
{
  analog2 = controler.joystick->getYValue();
  analogWrite(A3,analog2);
}
void middleDetection()
{
  L9.toggle();
}
void StickbuttonGetPressed()
{
  L8.toggle();
  Serial.println("P");
}
