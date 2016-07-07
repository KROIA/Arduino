#include "Intervalometer.h"

 Intervalometer::Intervalometer(int bOK,int bUp,int bDown,int blUp,int blDown,int bback,boolean logicLevel,int shuter,int focus,int display,int light,int LDR)
{
	p_lcd 					= new LiquidCrystal_I2C(0x20,16,2);
	p_buttonLightUp  		= new Button(blUp,		logicLevel);
	p_buttonLightDown		= new Button(blDown,	logicLevel);
	p_buttonUp            	= new Button(bUp,		logicLevel);
	p_buttonDown          	= new Button(bDown, 	logicLevel);
	p_buttonOk            	= new Button(bOK,		logicLevel);
	p_buttonBack			= new Button(bback,		logicLevel);
	p_led	 				= new Led(13);
	
	focusPin				= focus;
	ldrPin					= LDR;
	shuterPin				= shuter;
	displayPin				= display;
	brightnessPin			= light;
}
Intervalometer::~Intervalometer()
{
			
}
void Intervalometer::init()
{
	p_led->init();
}
void Intervalometer::run()
{
	
}
    
void Intervalometer::setLight()
{
	
}
void Intervalometer::handleUpButton()
{
	
}
void Intervalometer::handleDownButton()
{
	
}
void Intervalometer::handleLightUpButton()
{
	
}
void Intervalometer::handleLightDownButton()
{
	
}
void Intervalometer::handleOkButton()
{
	
}
void Intervalometer::handleBackButton()
{
	
}
//private --------------

void Intervalometer::checkButtons()
{
	
}
void Intervalometer::reset()
{
	
}

void Intervalometer::shoot()
{
	
}
void Intervalometer::focusOn()
{
	
}
void Intervalometer::focusOff()
{
	
}

void Intervalometer::displayOff()
{
	
}
void Intervalometer::displayOn()
{
	
}