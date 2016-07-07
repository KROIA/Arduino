//==========================================LED CUBE TETRIS=================== 
// Autor: 									Alex Krieg
// Erstellt:								20.5.16
// Version 									1.0.0
// Kompatibel mit den versionen: 			ledCube9.h : 3.0.3 BUILD ARduino Mega(2560)
// Funktionen:								*****






#include "ledCube8_Tetris.h"

ledCube8_Tetris::ledCube8_Tetris(byte pins[])
{
		
		 cube 	= new LedCube8;
		 
		 p_lcd 	= new LiquidCrystal_I2C(0x20,16,2);
		
		// p_lcd-> 					init();
		 but1 = new Button(pins[0],activeHigh);
		 but2 = new Button(pins[1],activeHigh);
		 but3 = new Button(pins[2],activeHigh);
		 but4 = new Button(pins[3],activeHigh);
		 
		 but5 = new Button(pins[4],activeHigh);
		 but6 = new Button(pins[5],activeHigh);
		 but7 = new Button(pins[6],activeHigh);
		 but8 = new Button(pins[7],activeHigh);
		 

		but1->init();
		but2->init();
		but3->init();
		but4->init();
		but5->init();
		but6->init();
		but7->init();
		but8->init();

		
		Wire.begin();
		cube->time(10);
		
		
		
}
ledCube8_Tetris::~ledCube8_Tetris()
{
	delete cube;
	delete p_lcd;
}



void ledCube8_Tetris::init()
{	
		 p_lcd-> init();
		p_lcd->clear();
		/*p_lcd->          				setCursor  (0, 1);
		p_lcd->                         print      ("Player 2: ");*/
		cubeData = {
		0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0		
		};
		cubeTerain = {
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0
		};
		objects[0]  ={
			
		0,0,0,0,0,0,0,0,	
		0,0,0,0,0,0,0,0,	
		0,0,0,0,8,0,0,0,	
		0,0,0,0,8,0,0,0,	
		0,0,0,0,8,0,0,0,	
		0,0,0,0,8,0,0,0,	
		0,0,0,0,0,0,0,0,	
		0,0,0,0,0,0,0,0
		};
		objects[1]  ={
			
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,8,0,0,0,
			0,0,0,0,8,0,0,0,
			0,0,0,8,8,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0
		};
		objects[2]  ={
			
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,8,0,0,0,0,
			0,0,0,8,0,0,0,0,
			0,0,0,8,8,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0
		};
		objects[3]  ={
			
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,8,8,0,0,0,
			0,0,0,8,8,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0
		};
		objects[4]  ={
			
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,8,8,0,0,
			0,0,0,8,8,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0
		};
		objects[5]  ={
			
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,8,8,8,0,0,
			0,0,0,0,8,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0
		};
		objects[6]  ={
			
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,8,8,0,0,0,
			0,0,0,0,8,8,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0
		};
		
		
		startTime 				= 0;
		time					= 0;
		shiftTime 				= 3000;
		
		activeObjectA 			= random(0,7);
		score					= 0;
		rotationXAmount			= 0;
		rotationYAmount         = 0;
		rotationZAmount         = 0;
		shiftDownAmount 		= 0;
		shiftLeftAmount 		= 3;
		shiftYAmount			= 3;
		
		playerIsDeath			= false;
		
		activeObject1	= objects[activeObjectA];
		activeObject2	= cubeData;
		activeObject3 	= cubeData;
		cubeTerain		= cubeData;
		activeObjectOnlyRotate = activeObject1;

}

void ledCube8_Tetris::run()
{
	startTime = millis();
	init();
	while(true)
	{
		
		
		time = millis();
		
		but1->checkButton();
		but2->checkButton();
		but3->checkButton();
		but4->checkButton();
		but5->checkButton();
		but6->checkButton();
		but7->checkButton();
		but8->checkButton();
		
		
		if((time -startTime) > shiftTime)
		{
			activeObjectA = random(0,7);

			startTime = time;
 
			if(playerIsDeath == false)
			{
				shiftDownAmount++;
			}
			
			if(checkForCollision(1,0)  && playerIsDeath == false)
			{
				
				shiftDownAmount = 0;
				cubeTerain 		= cube->add(cubeTerain,activeObject3);
				activeObject1 	= objects[activeObjectA];
				
	
				
				 if(	 
					 cubeTerain.CA8 && activeObject3.CA8  >= 1 ||
					 cubeTerain.CB8 && activeObject3.CB8  >= 1 ||
					 cubeTerain.CC8 && activeObject3.CC8  >= 1 ||
					 cubeTerain.CD8 && activeObject3.CD8  >= 1 ||
					 cubeTerain.CE8 && activeObject3.CE8  >= 1 ||
					 cubeTerain.CF8 && activeObject3.CF8  >= 1 ||
					 cubeTerain.CG8 && activeObject3.CG8  >= 1 ||
					 cubeTerain.CH8 && activeObject3.CH8  >= 1 
				 )
				 {
					 playerIsDeath = true;
				 }
				if( playerIsDeath == false)
				 {
					 shiftDownAmount 	= 0;
					 shiftLeftAmount	= 3;
					 shiftYAmount		= 3;
					 rotationXAmount	= 0;
					 rotationYAmount    = 0;
					 rotationZAmount    = 0;
					 activeObject1 		= objects[activeObjectA];
					 activeObjectOnlyRotate = activeObject1;
					 
					 score++;
					 checkForDelete();
				 }
			}
			
			
			calculate();
			send();
			
			/*p_lcd->clear();
			p_lcd->                         setCursor  (0, 0);
			
		p_lcd->                         print      ("Player 1: ");
	
		p_lcd->                         print      (scoreP1);
		
		p_lcd->                         setCursor  (0, 1);
		
		p_lcd->                         print      ("Player 2: ");
	
		p_lcd->                         print      (scoreP2);
		send();*/
			
			
		}
		//checkForDelete();
		if(playerIsDeath == true)
		{
			Serial.println("******************************");
			Serial.print("Score: ");
			Serial.println(score);
			
			p_lcd->		clear();
			p_lcd-> 	setCursor  (0, 0);
			p_lcd->     print      ("Score: ");
			p_lcd->     print      (score);
			p_lcd->     setCursor  (0, 1);
			stop();
			return;
		}
		send();
	}
}
void ledCube8_Tetris::stop()
{
	while(true)
	{
		delay(2000);
		init();
		return;
	}
}
void ledCube8_Tetris::calculate()
{
	/*Serial.print("X: ");
	Serial.println(rotationXAmount);
	Serial.print("Y: ");
	Serial.println(rotationYAmount);
	Serial.print("Z: ");
	Serial.println(rotationZAmount);
	Serial.print("");*/
	//=====================ROTATE====================================
/*	activeObject2 = cube->getRotate(rotationXAmount,activeObject1);
	activeObject2 = cube->getRotate90(rotationYAmount,activeObject2);
	activeObject2 = cube->getRotateUp(rotationZAmount,activeObject2);*/
	//=====================ROTATE====================================
	//=====================UP/DOWN===================================
	if(shiftDownAmount < 3)
	{
		activeObject3 = cube->getShiftCubeUp(3-shiftDownAmount,false,activeObjectOnlyRotate);
	}
	else
	{
		activeObject3 = cube->getShiftCubeDown(shiftDownAmount-3,false,activeObjectOnlyRotate);
	}
	//=====================UP/DOWN===================================
	//=====================LEFT/RIGHT================================
	if(shiftLeftAmount < 3)
	{
		activeObject3 = cube->getShiftCubeRight(3-shiftLeftAmount,false,activeObject3);
	}
	else
	{
		activeObject3 = cube->getShiftCubeLeft(shiftLeftAmount-3,false,activeObject3);
	}
	//=====================LEFT/RIGHT================================
	//=====================Y+/Y-=====================================
	if(shiftYAmount < 3)
	{
		activeObject3 = cube->getShiftCubeRight90(3-shiftYAmount,false,activeObject3);
	}
	else
	{
		activeObject3 = cube->getShiftCubeLeft90(shiftYAmount-3,false,activeObject3);
	}
	//=====================Y+/Y-=====================================
	//=====================COMPARE===================================
	cubeData = cube->add(cubeTerain,activeObject3);
	//=====================COMPARE===================================
}

bool ledCube8_Tetris::checkForCollision(int mode,int rotateMode)
{


	CUBEDATACUBE vergleich				 = activeObject3; 
	CUBEDATACUBE vergleichTerain         = cubeTerain;
	
	


	
	if((vergleich.CA1  != 0 ||
		vergleich.CB1  != 0 ||
		vergleich.CC1  != 0 ||
		vergleich.CD1  != 0 ||
		vergleich.CE1  != 0 ||
		vergleich.CF1  != 0 ||
		vergleich.CG1  != 0 ||
		vergleich.CH1  != 0 )
		&& (mode == 1))
	{
		return true;
	}
	
	for(int i=0;i<2;i++)
	{
			
		vergleich	 	 = activeObject3;
  

		
		//vergleich	 	= activeObject3p1;
		
		//Serial.println(mode);
		switch(mode)
		{
			case 1:
			{
				
				vergleich = cube->getShiftCubeDown(1,true,vergleich);
				
				
				break;
			}
			case 2:
			{
				if(i==0)
				{
				vergleich = cube->getShiftCubeLeft(1,true,activeObject3);
				}
				if(i==1)
				{
					
					vergleichTerain = {
					255,0,0,0,0,0,0,0,	
					255,0,0,0,0,0,0,0,	
					255,0,0,0,0,0,0,0,	
					255,0,0,0,0,0,0,0,	
					255,0,0,0,0,0,0,0,	
					255,0,0,0,0,0,0,0,	
					255,0,0,0,0,0,0,0,	
					255,0,0,0,0,0,0,0
					};
					//vergleichTerain = vergleichTerain;
					//vergleich = cube->getShiftCubeRight(1,false,vergleich);
				}
				break;
			}
			case 3:
			{
				if(i==0)
				{
				vergleich = cube->getShiftCubeRight(1,true,activeObject3);
				}
				if(i==1)
				{
					
					vergleichTerain = {
					0,0,0,0,0,0,0,255,
					0,0,0,0,0,0,0,255,
					0,0,0,0,0,0,0,255,
					0,0,0,0,0,0,0,255,
					0,0,0,0,0,0,0,255,
					0,0,0,0,0,0,0,255,
					0,0,0,0,0,0,0,255,
					0,0,0,0,0,0,0,255
					};
					//vergleichTerain = vergleichTerain;
					//vergleich = cube->getShiftCubeLeft(1,false,vergleich);
				}
				break;
			}
			case 4:
			{
				//Serial.println("Case 4");
				
					//Serial.println("Palyer 1");
					if(i==0)
					{
						//=====================ROTATE====================================
						if(rotateMode == 1)
						{
							vergleich = cube->getRotate(1,activeObjectOnlyRotate);
							
						}	
						if(rotateMode == 2)
						{
							
							vergleich = cube->getRotate90(1,activeObjectOnlyRotate);
							
						}
						if(rotateMode == 3)
						{
							
							vergleich = cube->getRotateUp(1,activeObjectOnlyRotate);
						}
	/*Serial.print("X: ");
	Serial.println(rotationXAmount);
	Serial.print("Y: ");
	Serial.println(rotationYAmount);
	Serial.print("Z: ");
	Serial.println(rotationZAmount);
	Serial.print("");*/
	//=====================ROTATE====================================
	//=====================UP/DOWN===================================
	if(shiftDownAmount < 3)
	{
		vergleich = cube->getShiftCubeUp(3-shiftDownAmount,false,vergleich);
	}
	else
	{
		vergleich = cube->getShiftCubeDown(shiftDownAmount-3,false,vergleich);
	}
	//=====================UP/DOWN===================================
	//=====================LEFT/RIGHT================================
	if(shiftLeftAmount < 3)
	{
		vergleich = cube->getShiftCubeRight(3-shiftLeftAmount,false,vergleich);
	}
	else
	{
		vergleich = cube->getShiftCubeLeft(shiftLeftAmount-3,false,vergleich);
	}
	//=====================LEFT/RIGHT================================
	//=====================Y+/Y-=====================================
	if(shiftYAmount < 3)
	{
		vergleich = cube->getShiftCubeRight90(3-shiftYAmount,false,vergleich);
	}
	else
	{
		vergleich = cube->getShiftCubeLeft90(shiftYAmount-3,false,vergleich);
	}
	//=====================Y+/Y-=====================================
					}
					
				/*	if(i==1)
						{
							
						//=====================ROTATE====================================
						if(rotateMode == 1)
						{
							vergleich = cube->getRotate(1,activeObjectOnlyRotate);
							
						}	
						if(rotateMode == 2)
						{
							
							vergleich = cube->getRotate90(1,activeObjectOnlyRotate);
							
						}
						if(rotateMode == 3)
						{
							
							vergleich = cube->getRotateUp(1,activeObjectOnlyRotate);
						}
	//=====================ROTATE====================================
	Serial.print("X: ");
	Serial.println(shiftLeftAmount);
	Serial.print("Y: ");
	Serial.println(shiftYAmount);
	
	Serial.print("");
	//=====================UP/DOWN===================================
	if(shiftDownAmount < 3)
	{
		vergleich = cube->getShiftCubeUp(3-shiftDownAmount,false,vergleich);
	}
	else
	{
		vergleich = cube->getShiftCubeDown(shiftDownAmount-3,false,vergleich);
	}
	//=====================UP/DOWN===================================
	//=====================LEFT/RIGHT================================
	if(shiftLeftAmount < 2)
	{
		vergleich = cube->getShiftCubeRight(2-shiftLeftAmount,false,vergleich);
	}
	else
	{
		vergleich = cube->getShiftCubeLeft(shiftLeftAmount-4,false,vergleich);
	}
	//=====================LEFT/RIGHT================================
	//=====================Y+/Y-=====================================
	if(shiftYAmount < 2)
	{
		vergleich = cube->getShiftCubeRight90(2-shiftYAmount,false,vergleich);
	}
	else
	{
		vergleich = cube->getShiftCubeLeft90(shiftYAmount-4,false,vergleich);
	}
	//=====================Y+/Y-=====================================	
						}*/
							
					/*
							vergleich = cube->getRotate(1,activeObject2p1);
						if(shiftDownAmountP1 < 3)
						{
							vergleich = cube->getShiftCubeUp(3-shiftDownAmountP1,false,vergleich);
						}
						else
						{
							vergleich = cube->getShiftCubeDown(shiftDownAmountP1-3,false,vergleich);
						}
						//Serial.println(shiftLeftAmountP1);
						if(shiftLeftAmountP1 < 2)
						{
							vergleich = cube->getShiftCubeRight(2-shiftLeftAmountP1,false,vergleich);
						}
						else
						{
							vergleich = cube->getShiftCubeLeft(shiftLeftAmountP1-4,false,vergleich);
						}
					*/
					
				
				
			//	if(i==1)
				{
					/*if(rotateMode == 1)
					{
					vergleichTerain = {
					255,0,0,0,0,0,0,255,
					255,0,0,0,0,0,0,255,
					255,0,0,0,0,0,0,255,
					255,0,0,0,0,0,0,255,
					255,0,0,0,0,0,0,255,
					255,0,0,0,0,0,0,255,
					255,0,0,0,0,0,0,255,
					255,0,0,0,0,0,0,255
					};
					}
					if(rotateMode == 2)
					{
						vergleichTerain = {
					129,129,129,129,129,129,129,
					129,129,129,129,129,129,129,
					129,129,129,129,129,129,129,
					129,129,129,129,129,129,129,
					129,129,129,129,129,129,129,
					129,129,129,129,129,129,129,
					129,129,129,129,129,129,129,
					129,129,129,129,129,129,129
					};
					}*/
					//if(rotateMode == 3)
					{
						/*vergleichTerain = {
					255,129,129,129,129,129,255,
					255,129,129,129,129,129,255,
					255,129,129,129,129,129,255,
					255,129,129,129,129,129,255,
					255,129,129,129,129,129,255,
					255,129,129,129,129,129,255,
					255,129,129,129,129,129,255,
					255,129,129,129,129,129,255
					};*/
				/*	vergleichTerain = {
					0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0
					};*/
					}
				}
					//vergleich = cube->getShiftCubeLeft(1,false,vergleich);
				
			break;
			
			}
			case 5:		//Y+
			{
				if(i==0)
				{
				vergleich = cube->getShiftCubeLeft90(1,true,activeObject3);
				}
				if(i==1)
				{
					
					vergleichTerain = {
					128,128,128,128,128,128,128,128,
					128,128,128,128,128,128,128,128,
					128,128,128,128,128,128,128,128,
					128,128,128,128,128,128,128,128,
					128,128,128,128,128,128,128,128,
					128,128,128,128,128,128,128,128,
					128,128,128,128,128,128,128,128,
					128,128,128,128,128,128,128,128
					};
					//vergleichTerain = vergleichTerain;
					//vergleich = cube->getShiftCubeLeft(1,false,vergleich);
				}
				break;
			}
			case 6:		//Y-
			{
				if(i==0)
				{
				vergleich = cube->getShiftCubeRight90(1,true,activeObject3);
				}
				if(i==1)
				{
					
					vergleichTerain = {
					1,1,1,1,1,1,1,1,
					1,1,1,1,1,1,1,1,
					1,1,1,1,1,1,1,1,
					1,1,1,1,1,1,1,1,
					1,1,1,1,1,1,1,1,
					1,1,1,1,1,1,1,1,
					1,1,1,1,1,1,1,1,
					1,1,1,1,1,1,1,1
					};
					//vergleichTerain = vergleichTerain;
					//vergleich = cube->getShiftCubeLeft(1,false,vergleich);
				}
				break;
			}
		}
		 
		
		/*Serial.print("Terain: ");
		Serial.println(vergleichTerain.CA1);
		Serial.print("Objekt: ");
		Serial.println(vergleich.CA1);
		Serial.print("Beides: ");
		Serial.println(vergleichTerain.CA1 & vergleich.CA1);
		Serial.println("");*/
		
		if(
		 (vergleichTerain.CA1 & vergleich.CA1)  != 0 ||
		 (vergleichTerain.CB1 & vergleich.CB1)  != 0 ||
		 (vergleichTerain.CC1 & vergleich.CC1)  != 0 ||
		 (vergleichTerain.CD1 & vergleich.CD1)  != 0 ||
		 (vergleichTerain.CE1 & vergleich.CE1)  != 0 ||
		 (vergleichTerain.CF1 & vergleich.CF1)  != 0 ||
		 (vergleichTerain.CG1 & vergleich.CG1)  != 0 ||
		 (vergleichTerain.CH1 & vergleich.CH1)  != 0 ||
	
		 (vergleichTerain.CA2 & vergleich.CA2)  != 0 ||
		 (vergleichTerain.CB2 & vergleich.CB2)  != 0 ||
		 (vergleichTerain.CC2 & vergleich.CC2)  != 0 ||
		 (vergleichTerain.CD2 & vergleich.CD2)  != 0 ||
		 (vergleichTerain.CE2 & vergleich.CE2)  != 0 ||
		 (vergleichTerain.CF2 & vergleich.CF2)  != 0 ||
		 (vergleichTerain.CG2 & vergleich.CG2)  != 0 ||
		 (vergleichTerain.CH2 & vergleich.CH2)  != 0 ||

		 (vergleichTerain.CA3 & vergleich.CA3)  != 0 ||
		 (vergleichTerain.CB3 & vergleich.CB3)  != 0 ||
		 (vergleichTerain.CC3 & vergleich.CC3)  != 0 ||
		 (vergleichTerain.CD3 & vergleich.CD3)  != 0 ||
		 (vergleichTerain.CE3 & vergleich.CE3)  != 0 ||
		 (vergleichTerain.CF3 & vergleich.CF3)  != 0 ||
		 (vergleichTerain.CG3 & vergleich.CG3)  != 0 ||
		 (vergleichTerain.CH3 & vergleich.CH3)  != 0 ||
		
		 (vergleichTerain.CA4 & vergleich.CA4)  != 0 ||
		 (vergleichTerain.CB4 & vergleich.CB4)  != 0 ||
		 (vergleichTerain.CC4 & vergleich.CC4)  != 0 ||
		 (vergleichTerain.CD4 & vergleich.CD4)  != 0 ||
		 (vergleichTerain.CE4 & vergleich.CE4)  != 0 ||
		 (vergleichTerain.CF4 & vergleich.CF4)  != 0 ||
		 (vergleichTerain.CG4 & vergleich.CG4)  != 0 ||
		 (vergleichTerain.CH4 & vergleich.CH4)  != 0 ||
	
		 (vergleichTerain.CA5 & vergleich.CA5)  != 0 ||
		 (vergleichTerain.CB5 & vergleich.CB5)  != 0 ||
		 (vergleichTerain.CC5 & vergleich.CC5)  != 0 ||
		 (vergleichTerain.CD5 & vergleich.CD5)  != 0 ||
		 (vergleichTerain.CE5 & vergleich.CE5)  != 0 ||
		 (vergleichTerain.CF5 & vergleich.CF5)  != 0 ||
		 (vergleichTerain.CG5 & vergleich.CG5)  != 0 ||
		 (vergleichTerain.CH5 & vergleich.CH5)  != 0 ||
	
		 (vergleichTerain.CA6 & vergleich.CA6)  != 0 ||
		 (vergleichTerain.CB6 & vergleich.CB6)  != 0 ||
		 (vergleichTerain.CC6 & vergleich.CC6)  != 0 ||
		 (vergleichTerain.CD6 & vergleich.CD6)  != 0 ||
		 (vergleichTerain.CE6 & vergleich.CE6)  != 0 ||
		 (vergleichTerain.CF6 & vergleich.CF6)  != 0 ||
		 (vergleichTerain.CG6 & vergleich.CG6)  != 0 ||
		 (vergleichTerain.CH6 & vergleich.CH6)  != 0 ||
	
		 (vergleichTerain.CA7 & vergleich.CA7)  != 0 ||
		 (vergleichTerain.CB7 & vergleich.CB7)  != 0 ||
		 (vergleichTerain.CC7 & vergleich.CC7)  != 0 ||
		 (vergleichTerain.CD7 & vergleich.CD7)  != 0 ||
		 (vergleichTerain.CE7 & vergleich.CE7)  != 0 ||
		 (vergleichTerain.CF7 & vergleich.CF7)  != 0 ||
		 (vergleichTerain.CG7 & vergleich.CG7)  != 0 ||
		 (vergleichTerain.CH7 & vergleich.CH7)  != 0 ||
		 
		 (vergleichTerain.CA8 & vergleich.CA8)  != 0 ||
		 (vergleichTerain.CB8 & vergleich.CB8)  != 0 ||
		 (vergleichTerain.CC8 & vergleich.CC8)  != 0 ||
		 (vergleichTerain.CD8 & vergleich.CD8)  != 0 ||
		 (vergleichTerain.CE8 & vergleich.CE8)  != 0 ||
		 (vergleichTerain.CF8 & vergleich.CF8)  != 0 ||
		 (vergleichTerain.CG8 & vergleich.CG8)  != 0 ||
		 (vergleichTerain.CH8 & vergleich.CH8)  != 0   
		 )
		 {
			/* if(shiftDownAmountP1 ==1 )
			 {
				 stop();
			 }*/
			 //activeObject3p1 = cube->getShiftCubeUp(1,true,activeObject3p1);
			 //cubeTerainp1 = cube->add(activeObject3p1,cubeTerainp1);
			// shiftDownAmountP1 = 0;
			 //activeObject = objects[1];
			 //shiftLeftAmountP1 = 3;
			 return true;
		 }
		 else
		 {
			// return false;
		 }
	}
	return false;
	 /*if(
	 cubeTerainp1.CA1 == 1 &&
	 cubeTerainp1.CB1 == 1 &&
	 cubeTerainp1.CC1 == 1 &&
	 cubeTerainp1.CD1 == 1 &&
	 cubeTerainp1.CE1 == 1 &&
	 cubeTerainp1.CF1 == 1 &&
	 cubeTerainp1.CG1 == 1 &&
	 cubeTerainp1.CH1 == 1  
	 )
	 {
		 cubeTerainp1 = cube->getShiftCubeDown(1,false,cubeTerainp1);
	 }*/
}                                                
void ledCube8_Tetris::checkForDelete()
{
	CUBEDATACUBE TERAIN;
	CUBEDATACUBE cubeDataCopy;
	CUBEDATACUBE SUBTRACTOR = cube->getCube();

		TERAIN = cubeTerain;
		cubeDataCopy = cubeTerain;
	
	if(
	 cubeDataCopy.CA1 == 255 &&
	 cubeDataCopy.CB1 == 255 &&
	 cubeDataCopy.CC1 == 255 &&
	 cubeDataCopy.CD1 == 255 &&
	 cubeDataCopy.CE1 == 255 &&
	 cubeDataCopy.CF1 == 255 &&
	 cubeDataCopy.CG1 == 255 &&
	 cubeDataCopy.CH1 == 255  
	 )
	 {
		 TERAIN = cube->getShiftCubeDown(1,false,TERAIN);
	 }
	 if(
	 cubeDataCopy.CA2 == 255 &&
	 cubeDataCopy.CB2 == 255 &&
	 cubeDataCopy.CC2 == 255 &&
	 cubeDataCopy.CD2 == 255 &&
	 cubeDataCopy.CE2 == 255 &&
	 cubeDataCopy.CF2 == 255 &&
	 cubeDataCopy.CG2 == 255 &&
	 cubeDataCopy.CH2 == 255  
	 )
	 {		
	    SUBTRACTOR = cube->getShiftCubeDown(6,false,SUBTRACTOR);
		TERAIN = cube->subtract(TERAIN,SUBTRACTOR);
		TERAIN = cube->getShiftCubeDown(1,false,TERAIN);
		
		TERAIN.CA1 = cubeDataCopy.CA1;
		TERAIN.CB1 = cubeDataCopy.CB1;
		TERAIN.CC1 = cubeDataCopy.CC1;
		TERAIN.CD1 = cubeDataCopy.CD1;
		TERAIN.CE1 = cubeDataCopy.CE1;
		TERAIN.CF1 = cubeDataCopy.CF1;
		TERAIN.CG1 = cubeDataCopy.CG1;
		TERAIN.CH1 = cubeDataCopy.CH1;
		
	 }
	 if(
	 cubeDataCopy.CA3 == 255 &&
	 cubeDataCopy.CB3 == 255 &&
	 cubeDataCopy.CC3 == 255 &&
	 cubeDataCopy.CD3 == 255 &&
	 cubeDataCopy.CE3 == 255 &&
	 cubeDataCopy.CF3 == 255 &&
	 cubeDataCopy.CG3 == 255 &&
	 cubeDataCopy.CH3 == 255  
	 )
	 {		
	    SUBTRACTOR = cube->getShiftCubeDown(5,false,SUBTRACTOR);
		TERAIN = cube->subtract(TERAIN,SUBTRACTOR);
		TERAIN = cube->getShiftCubeDown(1,false,TERAIN);
		TERAIN.CA1 = cubeDataCopy.CA1;
		TERAIN.CB1 = cubeDataCopy.CB1;
		TERAIN.CC1 = cubeDataCopy.CC1;
		TERAIN.CD1 = cubeDataCopy.CD1;
		TERAIN.CE1 = cubeDataCopy.CE1;
		TERAIN.CF1 = cubeDataCopy.CF1;
		TERAIN.CG1 = cubeDataCopy.CG1;
		TERAIN.CH1 = cubeDataCopy.CH1;
		
		TERAIN.CA2 = cubeDataCopy.CA2;
		TERAIN.CB2 = cubeDataCopy.CB2;
		TERAIN.CC2 = cubeDataCopy.CC2;
		TERAIN.CD2 = cubeDataCopy.CD2;
		TERAIN.CE2 = cubeDataCopy.CE2;
		TERAIN.CF2 = cubeDataCopy.CF2;
		TERAIN.CG2 = cubeDataCopy.CG2;
		TERAIN.CH2 = cubeDataCopy.CH2;
	 }
	 if(
	 cubeDataCopy.CA4 == 255 &&
	 cubeDataCopy.CB4 == 255 &&
	 cubeDataCopy.CC4 == 255 &&
	 cubeDataCopy.CD4 == 255 &&
	 cubeDataCopy.CE4 == 255 &&
	 cubeDataCopy.CF4 == 255 &&
	 cubeDataCopy.CG4 == 255 &&
	 cubeDataCopy.CH4 == 255  
	 )
	 {		
	    SUBTRACTOR = cube->getShiftCubeDown(4,false,SUBTRACTOR);
		TERAIN = cube->subtract(TERAIN,SUBTRACTOR);
		TERAIN = cube->getShiftCubeDown(1,false,TERAIN);
		TERAIN.CA1 = cubeDataCopy.CA1;
		TERAIN.CB1 = cubeDataCopy.CB1;
		TERAIN.CC1 = cubeDataCopy.CC1;
		TERAIN.CD1 = cubeDataCopy.CD1;
		TERAIN.CE1 = cubeDataCopy.CE1;
		TERAIN.CF1 = cubeDataCopy.CF1;
		TERAIN.CG1 = cubeDataCopy.CG1;
		TERAIN.CH1 = cubeDataCopy.CH1;
		
		TERAIN.CA2 = cubeDataCopy.CA2;
		TERAIN.CB2 = cubeDataCopy.CB2;
		TERAIN.CC2 = cubeDataCopy.CC2;
		TERAIN.CD2 = cubeDataCopy.CD2;
		TERAIN.CE2 = cubeDataCopy.CE2;
		TERAIN.CF2 = cubeDataCopy.CF2;
		TERAIN.CG2 = cubeDataCopy.CG2;
		TERAIN.CH2 = cubeDataCopy.CH2;
		
		TERAIN.CA3 = cubeDataCopy.CA3;
		TERAIN.CB3 = cubeDataCopy.CB3;
		TERAIN.CC3 = cubeDataCopy.CC3;
		TERAIN.CD3 = cubeDataCopy.CD3;
		TERAIN.CE3 = cubeDataCopy.CE3;
		TERAIN.CF3 = cubeDataCopy.CF3;
		TERAIN.CG3 = cubeDataCopy.CG3;
		TERAIN.CH3 = cubeDataCopy.CH3;
		
	 }
	if(
	 cubeDataCopy.CA5 == 255 &&
	 cubeDataCopy.CB5 == 255 &&
	 cubeDataCopy.CC5 == 255 &&
	 cubeDataCopy.CD5 == 255 &&
	 cubeDataCopy.CE5 == 255 &&
	 cubeDataCopy.CF5 == 255 &&
	 cubeDataCopy.CG5 == 255 &&
	 cubeDataCopy.CH5 == 255  
	 )
	 {		
	    SUBTRACTOR = cube->getShiftCubeDown(3,false,SUBTRACTOR);
		TERAIN = cube->subtract(TERAIN,SUBTRACTOR);
		TERAIN = cube->getShiftCubeDown(1,false,TERAIN);
		TERAIN.CA1 = cubeDataCopy.CA1;
		TERAIN.CB1 = cubeDataCopy.CB1;
		TERAIN.CC1 = cubeDataCopy.CC1;
		TERAIN.CD1 = cubeDataCopy.CD1;
		TERAIN.CE1 = cubeDataCopy.CE1;
		TERAIN.CF1 = cubeDataCopy.CF1;
		TERAIN.CG1 = cubeDataCopy.CG1;
		TERAIN.CH1 = cubeDataCopy.CH1;
		
		TERAIN.CA2 = cubeDataCopy.CA2;
		TERAIN.CB2 = cubeDataCopy.CB2;
		TERAIN.CC2 = cubeDataCopy.CC2;
		TERAIN.CD2 = cubeDataCopy.CD2;
		TERAIN.CE2 = cubeDataCopy.CE2;
		TERAIN.CF2 = cubeDataCopy.CF2;
		TERAIN.CG2 = cubeDataCopy.CG2;
		TERAIN.CH2 = cubeDataCopy.CH2;
		
		TERAIN.CA3 = cubeDataCopy.CA3;
		TERAIN.CB3 = cubeDataCopy.CB3;
		TERAIN.CC3 = cubeDataCopy.CC3;
		TERAIN.CD3 = cubeDataCopy.CD3;
		TERAIN.CE3 = cubeDataCopy.CE3;
		TERAIN.CF3 = cubeDataCopy.CF3;
		TERAIN.CG3 = cubeDataCopy.CG3;
		TERAIN.CH3 = cubeDataCopy.CH3;
		
		TERAIN.CA4 = cubeDataCopy.CA4;
		TERAIN.CB4 = cubeDataCopy.CB4;
		TERAIN.CC4 = cubeDataCopy.CC4;
		TERAIN.CD4 = cubeDataCopy.CD4;
		TERAIN.CE4 = cubeDataCopy.CE4;
		TERAIN.CF4 = cubeDataCopy.CF4;
		TERAIN.CG4 = cubeDataCopy.CG4;
		TERAIN.CH4 = cubeDataCopy.CH4;
	 }
	if(
	 cubeDataCopy.CA6 == 255 &&
	 cubeDataCopy.CB6 == 255 &&
	 cubeDataCopy.CC6 == 255 &&
	 cubeDataCopy.CD6 == 255 &&
	 cubeDataCopy.CE6 == 255 &&
	 cubeDataCopy.CF6 == 255 &&
	 cubeDataCopy.CG6 == 255 &&
	 cubeDataCopy.CH6 == 255  
	 )
	 {		
	    SUBTRACTOR = cube->getShiftCubeDown(2,false,SUBTRACTOR);
		TERAIN = cube->subtract(TERAIN,SUBTRACTOR);
		TERAIN = cube->getShiftCubeDown(1,false,TERAIN);
		TERAIN.CA1 = cubeDataCopy.CA1;
		TERAIN.CB1 = cubeDataCopy.CB1;
		TERAIN.CC1 = cubeDataCopy.CC1;
		TERAIN.CD1 = cubeDataCopy.CD1;
		TERAIN.CE1 = cubeDataCopy.CE1;
		TERAIN.CF1 = cubeDataCopy.CF1;
		TERAIN.CG1 = cubeDataCopy.CG1;
		TERAIN.CH1 = cubeDataCopy.CH1;
		
		TERAIN.CA2 = cubeDataCopy.CA2;
		TERAIN.CB2 = cubeDataCopy.CB2;
		TERAIN.CC2 = cubeDataCopy.CC2;
		TERAIN.CD2 = cubeDataCopy.CD2;
		TERAIN.CE2 = cubeDataCopy.CE2;
		TERAIN.CF2 = cubeDataCopy.CF2;
		TERAIN.CG2 = cubeDataCopy.CG2;
		TERAIN.CH2 = cubeDataCopy.CH2;
		
		TERAIN.CA3 = cubeDataCopy.CA3;
		TERAIN.CB3 = cubeDataCopy.CB3;
		TERAIN.CC3 = cubeDataCopy.CC3;
		TERAIN.CD3 = cubeDataCopy.CD3;
		TERAIN.CE3 = cubeDataCopy.CE3;
		TERAIN.CF3 = cubeDataCopy.CF3;
		TERAIN.CG3 = cubeDataCopy.CG3;
		TERAIN.CH3 = cubeDataCopy.CH3;
		
		TERAIN.CA4 = cubeDataCopy.CA4;
		TERAIN.CB4 = cubeDataCopy.CB4;
		TERAIN.CC4 = cubeDataCopy.CC4;
		TERAIN.CD4 = cubeDataCopy.CD4;
		TERAIN.CE4 = cubeDataCopy.CE4;
		TERAIN.CF4 = cubeDataCopy.CF4;
		TERAIN.CG4 = cubeDataCopy.CG4;
		TERAIN.CH4 = cubeDataCopy.CH4;
		
		TERAIN.CA5 = cubeDataCopy.CA5;
		TERAIN.CB5 = cubeDataCopy.CB5;
		TERAIN.CC5 = cubeDataCopy.CC5;
		TERAIN.CD5 = cubeDataCopy.CD5;
		TERAIN.CE5 = cubeDataCopy.CE5;
		TERAIN.CF5 = cubeDataCopy.CF5;
		TERAIN.CG5 = cubeDataCopy.CG5;
		TERAIN.CH5 = cubeDataCopy.CH5;
	 }
	if(
	 cubeDataCopy.CA7 == 255 &&
	 cubeDataCopy.CB7 == 255 &&
	 cubeDataCopy.CC7 == 255 &&
	 cubeDataCopy.CD7 == 255 &&
	 cubeDataCopy.CE7 == 255 &&
	 cubeDataCopy.CF7 == 255 &&
	 cubeDataCopy.CG7 == 255 &&
	 cubeDataCopy.CH7 == 255  
	 )
	 {		
	    SUBTRACTOR = cube->getShiftCubeDown(1,false,SUBTRACTOR);
		TERAIN = cube->subtract(TERAIN,SUBTRACTOR);
		TERAIN = cube->getShiftCubeDown(1,false,TERAIN);
		TERAIN.CA1 = cubeDataCopy.CA1;
		TERAIN.CB1 = cubeDataCopy.CB1;
		TERAIN.CC1 = cubeDataCopy.CC1;
		TERAIN.CD1 = cubeDataCopy.CD1;
		TERAIN.CE1 = cubeDataCopy.CE1;
		TERAIN.CF1 = cubeDataCopy.CF1;
		TERAIN.CG1 = cubeDataCopy.CG1;
		TERAIN.CH1 = cubeDataCopy.CH1;
		
		TERAIN.CA2 = cubeDataCopy.CA2;
		TERAIN.CB2 = cubeDataCopy.CB2;
		TERAIN.CC2 = cubeDataCopy.CC2;
		TERAIN.CD2 = cubeDataCopy.CD2;
		TERAIN.CE2 = cubeDataCopy.CE2;
		TERAIN.CF2 = cubeDataCopy.CF2;
		TERAIN.CG2 = cubeDataCopy.CG2;
		TERAIN.CH2 = cubeDataCopy.CH2;
		
		TERAIN.CA3 = cubeDataCopy.CA3;
		TERAIN.CB3 = cubeDataCopy.CB3;
		TERAIN.CC3 = cubeDataCopy.CC3;
		TERAIN.CD3 = cubeDataCopy.CD3;
		TERAIN.CE3 = cubeDataCopy.CE3;
		TERAIN.CF3 = cubeDataCopy.CF3;
		TERAIN.CG3 = cubeDataCopy.CG3;
		TERAIN.CH3 = cubeDataCopy.CH3;
		
		TERAIN.CA4 = cubeDataCopy.CA4;
		TERAIN.CB4 = cubeDataCopy.CB4;
		TERAIN.CC4 = cubeDataCopy.CC4;
		TERAIN.CD4 = cubeDataCopy.CD4;
		TERAIN.CE4 = cubeDataCopy.CE4;
		TERAIN.CF4 = cubeDataCopy.CF4;
		TERAIN.CG4 = cubeDataCopy.CG4;
		TERAIN.CH4 = cubeDataCopy.CH4;
		
		TERAIN.CA5 = cubeDataCopy.CA5;
		TERAIN.CB5 = cubeDataCopy.CB5;
		TERAIN.CC5 = cubeDataCopy.CC5;
		TERAIN.CD5 = cubeDataCopy.CD5;
		TERAIN.CE5 = cubeDataCopy.CE5;
		TERAIN.CF5 = cubeDataCopy.CF5;
		TERAIN.CG5 = cubeDataCopy.CG5;
		TERAIN.CH5 = cubeDataCopy.CH5;
		
		TERAIN.CA6 = cubeDataCopy.CA6;
		TERAIN.CB6 = cubeDataCopy.CB6;
		TERAIN.CC6 = cubeDataCopy.CC6;
		TERAIN.CD6 = cubeDataCopy.CD6;
		TERAIN.CE6 = cubeDataCopy.CE6;
		TERAIN.CF6 = cubeDataCopy.CF6;
		TERAIN.CG6 = cubeDataCopy.CG6;
		TERAIN.CH6 = cubeDataCopy.CH6;
	 }
	if(
	 cubeDataCopy.CA8 == 255 &&
	 cubeDataCopy.CB8 == 255 &&
	 cubeDataCopy.CC8 == 255 &&
	 cubeDataCopy.CD8 == 255 &&
	 cubeDataCopy.CE8 == 255 &&
	 cubeDataCopy.CF8 == 255 &&
	 cubeDataCopy.CG8 == 255 &&
	 cubeDataCopy.CH8 == 255  
	 )
	 {		
	  //  SUBTRACTOR = cube->getShiftCubeDown(1,false,SUBTRACTOR);
		TERAIN = cube->subtract(TERAIN,SUBTRACTOR);
		TERAIN = cube->getShiftCubeDown(1,false,TERAIN);
		TERAIN.CA1 = cubeDataCopy.CA1;
		TERAIN.CB1 = cubeDataCopy.CB1;
		TERAIN.CC1 = cubeDataCopy.CC1;
		TERAIN.CD1 = cubeDataCopy.CD1;
		TERAIN.CE1 = cubeDataCopy.CE1;
		TERAIN.CF1 = cubeDataCopy.CF1;
		TERAIN.CG1 = cubeDataCopy.CG1;
		TERAIN.CH1 = cubeDataCopy.CH1;
		
		TERAIN.CA2 = cubeDataCopy.CA2;
		TERAIN.CB2 = cubeDataCopy.CB2;
		TERAIN.CC2 = cubeDataCopy.CC2;
		TERAIN.CD2 = cubeDataCopy.CD2;
		TERAIN.CE2 = cubeDataCopy.CE2;
		TERAIN.CF2 = cubeDataCopy.CF2;
		TERAIN.CG2 = cubeDataCopy.CG2;
		TERAIN.CH2 = cubeDataCopy.CH2;
		
		TERAIN.CA3 = cubeDataCopy.CA3;
		TERAIN.CB3 = cubeDataCopy.CB3;
		TERAIN.CC3 = cubeDataCopy.CC3;
		TERAIN.CD3 = cubeDataCopy.CD3;
		TERAIN.CE3 = cubeDataCopy.CE3;
		TERAIN.CF3 = cubeDataCopy.CF3;
		TERAIN.CG3 = cubeDataCopy.CG3;
		TERAIN.CH3 = cubeDataCopy.CH3;
		
		TERAIN.CA4 = cubeDataCopy.CA4;
		TERAIN.CB4 = cubeDataCopy.CB4;
		TERAIN.CC4 = cubeDataCopy.CC4;
		TERAIN.CD4 = cubeDataCopy.CD4;
		TERAIN.CE4 = cubeDataCopy.CE4;
		TERAIN.CF4 = cubeDataCopy.CF4;
		TERAIN.CG4 = cubeDataCopy.CG4;
		TERAIN.CH4 = cubeDataCopy.CH4;
		
		TERAIN.CA5 = cubeDataCopy.CA5;
		TERAIN.CB5 = cubeDataCopy.CB5;
		TERAIN.CC5 = cubeDataCopy.CC5;
		TERAIN.CD5 = cubeDataCopy.CD5;
		TERAIN.CE5 = cubeDataCopy.CE5;
		TERAIN.CF5 = cubeDataCopy.CF5;
		TERAIN.CG5 = cubeDataCopy.CG5;
		TERAIN.CH5 = cubeDataCopy.CH5;
		
		TERAIN.CA6 = cubeDataCopy.CA6;
		TERAIN.CB6 = cubeDataCopy.CB6;
		TERAIN.CC6 = cubeDataCopy.CC6;
		TERAIN.CD6 = cubeDataCopy.CD6;
		TERAIN.CE6 = cubeDataCopy.CE6;
		TERAIN.CF6 = cubeDataCopy.CF6;
		TERAIN.CG6 = cubeDataCopy.CG6;
		TERAIN.CH6 = cubeDataCopy.CH6;
		
		TERAIN.CA7 = cubeDataCopy.CA7;
		TERAIN.CB7 = cubeDataCopy.CB7;
		TERAIN.CC7 = cubeDataCopy.CC7;
		TERAIN.CD7 = cubeDataCopy.CD7;
		TERAIN.CE7 = cubeDataCopy.CE7;
		TERAIN.CF7 = cubeDataCopy.CF7;
		TERAIN.CG7 = cubeDataCopy.CG7;
		TERAIN.CH7 = cubeDataCopy.CH7;
	 }


	 
		cubeTerain = TERAIN;
	

	
}

//===========================SEND===========================================
void ledCube8_Tetris::send()
{
	
	
	
	cube->drawCube(cubeData);
	/*int reference = 1;
	Wire.beginTransmission(1); // transmit to device #1
	
	
	Wire.write(reference);
	Wire.write(cubeData.CA1);        
	Wire.write(cubeData.CB1);
	Wire.write(cubeData.CC1);
	Wire.write(cubeData.CD1);
	Wire.write(cubeData.CE1);
	Wire.write(cubeData.CF1);
	Wire.write(cubeData.CG1);
	Wire.write(cubeData.CH1);
	           
	Wire.write(cubeData.CA2);        
	Wire.write(cubeData.CB2);
	Wire.write(cubeData.CC2);
	Wire.write(cubeData.CD2);
	Wire.write(cubeData.CE2);
	Wire.write(cubeData.CF2);
	Wire.write(cubeData.CG2);
	Wire.write(cubeData.CH2);
	Wire.endTransmission(); 
	reference++;
	Wire.beginTransmission(1);	 
	Wire.write(reference);
	Wire.write(cubeData.CA3);        
	Wire.write(cubeData.CB3);
	Wire.write(cubeData.CC3);
	Wire.write(cubeData.CD3);
	Wire.write(cubeData.CE3);
	Wire.write(cubeData.CF3);
	Wire.write(cubeData.CG3);
	Wire.write(cubeData.CH3);
	           
	Wire.write(cubeData.CA4);        
	Wire.write(cubeData.CB4);
	Wire.write(cubeData.CC4);
	Wire.write(cubeData.CD4);
	Wire.write(cubeData.CE4);
	Wire.write(cubeData.CF4);
	Wire.write(cubeData.CG4);
	Wire.write(cubeData.CH4);
	Wire.endTransmission(); 
	reference++;
	Wire.beginTransmission(1);	
	Wire.write(reference);	
	Wire.write(cubeData.CA5);        
	Wire.write(cubeData.CB5);
	Wire.write(cubeData.CC5);
	Wire.write(cubeData.CD5);
	Wire.write(cubeData.CE5);
	Wire.write(cubeData.CF5);
	Wire.write(cubeData.CG5);
	Wire.write(cubeData.CH5);
	           
	Wire.write(cubeData.CA6);        
	Wire.write(cubeData.CB6);
	Wire.write(cubeData.CC6);
	Wire.write(cubeData.CD6);
	Wire.write(cubeData.CE6);
	Wire.write(cubeData.CF6);
	Wire.write(cubeData.CG6);
	Wire.write(cubeData.CH6);
	Wire.endTransmission(); 
	reference++;
	Wire.beginTransmission(1);
	Wire.write(reference);	
	Wire.write(cubeData.CA7);        
	Wire.write(cubeData.CB7);
	Wire.write(cubeData.CC7);
	Wire.write(cubeData.CD7);
	Wire.write(cubeData.CE7);
	Wire.write(cubeData.CF7);
	Wire.write(cubeData.CG7);
	Wire.write(cubeData.CH7);
	           
	Wire.write(cubeData.CA8);        
	Wire.write(cubeData.CB8);
	Wire.write(cubeData.CC8);
	Wire.write(cubeData.CD8);
	Wire.write(cubeData.CE8);
	Wire.write(cubeData.CF8);
	Wire.write(cubeData.CG8);
	Wire.write(cubeData.CH8);
	Wire.endTransmission();*/    // stop transmitting
}
//===========================BUTTONS========================================
//===========================Player1========================================
void ledCube8_Tetris::button1()
{
	if(playerIsDeath == false)
	{
	while(checkForCollision(1,0) == false)
	{
		shiftDownAmount++;
		calculate();
	}
	}
}
void ledCube8_Tetris::button2()
{
	if(playerIsDeath == false)
	{
	if(checkForCollision(2,0))
	{
		
	}
	else
	{
		 shiftLeftAmount++;
		 calculate();
	}
	}
	
}
void ledCube8_Tetris::button3()
{   
//activeObject3p1 = cube->getShiftCubeLeft(1,true,activeObject3p1);
	/*if(checkForCollision())
	 {
		 //activeObject3p1 = cube->getShiftCubeRight(1,true,activeObject3p1);
		// cubeTerainp1 = cube->add(activeObject3p1,cubeTerainp1);
		 //shiftDownAmountP1 = 0;
		 //activeObject = objects[1];
		 //shiftLeftAmountP1 = 3;
	 }
	 else*/
	 if(playerIsDeath == false)
	{
	 if(checkForCollision(3,0))
	{
		
	}
	else
	{
		 shiftLeftAmount--;
		 calculate();
	}
	}
}
void ledCube8_Tetris::button4()
{
	/*activeObject3p1 = cube->getShiftCubeRight(1,true,activeObject3p1);
	if(checkForCollision())
	 {
		 activeObject3p1 = cube->getShiftCubeLeft(1,true,activeObject3p1);
		// cubeTerainp1 = cube->add(activeObject3p1,cubeTerainp1);
		 //shiftDownAmountP1 = 0;
		 //activeObject = objects[1];
		 //shiftLeftAmountP1 = 3;
	 }
	 else*/
	 if(playerIsDeath == false)
	{ 
	 
	 if(checkForCollision(4,1))
	 {
		 
	 }
	 else
	 {
		 rotationXAmount++;
		  if(rotationXAmount > 3)
			 {
				rotationXAmount = 0;
			 }
			 activeObjectOnlyRotate = cube->getRotate(1,activeObjectOnlyRotate);
		 calculate();
	 }
	}
	
	 
}



void ledCube8_Tetris::button5()
{
	if(playerIsDeath == false)
	{
		
	if(checkForCollision(5,0))
	{
		
			Serial.println("ERROR");
	}
else{
		shiftYAmount++;

			//Serial.println(shiftYAmount);
			calculate();
}
	}
}
void ledCube8_Tetris::button6()
{
	if(playerIsDeath == false)
	{
	if(checkForCollision(6,0))
	{
		Serial.println("ERROR");
	}
	else
	{
		 shiftYAmount--;
	//	 Serial.println(shiftLeftAmountP2);
		 
			//Serial.println(shiftYAmount);
			calculate();
	}

	}
}
void ledCube8_Tetris::button7()
{
	 if(playerIsDeath == false)
	{ 
	 
	 if(checkForCollision(4,2))
	 {
		 
	 }
	 else
	 {
		 rotationYAmount++;
		  if(rotationYAmount > 3)
			 {
				rotationYAmount = 0;
			 }
			 activeObjectOnlyRotate = cube->getRotate90(1,activeObjectOnlyRotate);
		 calculate();
	 }
	}
}
void ledCube8_Tetris::button8()
{
	if(playerIsDeath == false)
	{ 
	 
	 if(checkForCollision(4,3))
	 {
		 
	 }
	 else
	 {
		 rotationZAmount++;
		  if(rotationZAmount > 3)
			 {
				rotationZAmount = 0;
			 }
			 activeObjectOnlyRotate = cube->getRotateUp(1,activeObjectOnlyRotate);
			// Serial.println(rotationAmountP2);
		 calculate();
	 }
	}
}
/*void ledCube8_Tetris::button5Player2()
{

	
}
void ledCube8_Tetris::button6Player2()
{
	
}*/