#include "Intervalometer.h"
#include "button.h"
#include "led.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

Intervalometer intervalometer(5,2,3,7,6,4,activeHigh,9,11,8,10,A0);

void setup() 
{
  intervalometer.init();
  intervalometer.p_buttonLightUp->     IsPressedHigh(lightUp);
  intervalometer.p_buttonLightDown->   IsPressedHigh(lightDown);
  intervalometer.p_buttonUp->               IsPressedHigh(UP);
  intervalometer.p_buttonDown->             IsPressedHigh(DOWN);
  intervalometer.p_buttonOk->               OnPressedEdge(OK);
  intervalometer.p_buttonBack->             OnPressedEdge(BACK);
}

void loop() 
{

  intervalometer.run();

}


void UP()
{
intervalometer.handleUpButton();
}
void DOWN()
{
intervalometer.handleDownButton();
}
void lightUp()
{
intervalometer.handleLightUpButton();
}
void lightDown()
{
intervalometer.handleLightDownButton();
}
void OK()
{
intervalometer.handleOkButton();
}
void BACK()
{
  intervalometer.handleBackButton();
}
