#include "Joystick.h"
#include "button.h"
#define DEBUG

Joystick joystick(A0,A1,4,activeLow);

void setup() 
{
  Serial.begin(9600);
  while(!Serial);
  joystick.init();
  joystick.attachFunctionOnStateChangeToUP(upDetection);
  joystick.attachFunctionOnStateChangeToDOWN(downDetection);
  joystick.attachFunctionOnStateChangeToRIGHT(rightDetection);
  joystick.attachFunctionOnStateChangeToMIDDLE(middleDetection);
  joystick.attachFunctionOnStateChangeToLEFT(leftDetection);
  
  joystick.button->attachFunctionOnButtonPressedEdge(buttonGetPressed);
  joystick.button->attachFunctionOnButtonReleasedEdge(buttonGetReleased);

  joystick.setYThreshold(90);
  joystick.setXThreshold(90);
  
  #ifdef DEBUG
  Serial.println("    setup done...    ");
  #endif
}

void loop() 
{
  joystick.check();
  delay(30);
}


void upDetection()
{
  #ifdef DEBUG
  Serial.println("upDetection");
  #endif
}
void downDetection()
{
  #ifdef DEBUG
  Serial.println("downDetection");
  #endif
}
void leftDetection()
{
  #ifdef DEBUG
  Serial.println("leftDetection");
  #endif
}
void rightDetection()
{
  #ifdef DEBUG
  Serial.println("rightDetection");
  #endif
}
void middleDetection()
{
  #ifdef DEBUG
  Serial.println("middleDetection");
  #endif
}


void buttonGetPressed()
{
  #ifdef DEBUG
  Serial.println("buttonGetPressed");
  #endif
}
void buttonGetReleased()
{
  #ifdef DEBUG
  Serial.println("buttonGetReleased");
  #endif
}
