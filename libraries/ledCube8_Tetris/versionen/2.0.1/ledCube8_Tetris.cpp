//==========================================LED CUBE TETRIS=================== 
// Autor: 									Alex Krieg
// Erstellt:								19.5.16
// Version 									2.0.1
// Kompatibel mit den versionen: 			ledCube9.h : 3.0.3 BUILD ARduino Mega(2560)
// Funktionen:								*****






#include "ledCube8_Tetris.h"

ledCube8_Tetris::ledCube8_Tetris(byte pins[])
{
	
		 cube = new LedCube8;
		 but1P = new Button(pins[0],activeHigh);
		 but2P = new Button(pins[1],activeHigh);
		 but3P = new Button(pins[2],activeHigh);
		 but4P = new Button(pins[3],activeHigh);
		 

		but1P->init();
		but2P->init();
		but3P->init();
		but4P->init();
		
		Wire.begin();
		cube->time(1);
		
		
		
}
ledCube8_Tetris::~ledCube8_Tetris()
{
	delete cube;
}



void ledCube8_Tetris::init()
{	
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
		0,0,0,0,1,0,0,0,	
		0,0,0,0,1,0,0,0,	
		0,0,0,0,1,0,0,0,	
		0,0,0,0,1,0,0,0,	
		0,0,0,0,0,0,0,0,	
		0,0,0,0,0,0,0,0
		};
		objects[1]  ={
			
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,1,0,0,0,
			0,0,0,0,1,0,0,0,
			0,0,0,1,1,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0
		};
		objects[2]  ={
			
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,1,0,0,0,0,
			0,0,0,1,0,0,0,0,
			0,0,0,1,1,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0
		};
		objects[3]  ={
			
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,1,1,0,0,0,
			0,0,0,1,1,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0
		};
		objects[4]  ={
			
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,1,1,0,0,
			0,0,0,1,1,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0
		};
		objects[5]  ={
			
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,1,1,1,0,0,
			0,0,0,0,1,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0
		};
		objects[6]  ={
			
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,1,1,0,0,0,
			0,0,0,0,1,1,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0
		};
		
		
		startTime 				= 0;
		time					= 0;
		shiftTime 				= 1000;
		activeObjectA 			= random(0,7);
		score					= 0;
		rotationAmount			= 0;
		shiftDownAmount 		= 0;
		shiftLeftAmount 		= 3;
		
		activeObject1	= objects[activeObjectA];
		activeObject2	= cubeData;
		activeObject3 	= cubeData;
}

void ledCube8_Tetris::run()
{
	startTime = millis();
	init();
	while(true)
	{
		time = millis();
		
		but1P->checkButton();
		but2P->checkButton();
		but3P->checkButton();
		but4P->checkButton();
		
		if((time -startTime) > shiftTime)
		{
			//Serial.println(score);
			activeObjectA = random(0,7);
			//Serial.println(activeObjectA);
			/*Serial.println(shiftDownAmount);
			Serial.println(shiftLeftAmount);
			Serial.println(rotationAmount);*/
			//Serial.println("");
			startTime = time;
			//if(shiftDownAmount < 6)
			{
				shiftDownAmount++;
			}
			/*else
			{
				shiftDownAmount = 0;
				cubeTerain 		= cube->add(cubeTerain,activeObject3);
				activeObject1 	= objects[activeObjectA];
			}*/
			//calculate();
			if(checkForCollision(1))
			{
				/*shiftDownAmount--;
				calculate();*/
				
				shiftDownAmount = 0;
				cubeTerain 		= cube->add(cubeTerain,activeObject3);
				activeObject1 	= objects[activeObjectA];
				
				
				
				
				 if(	 
					 cubeTerain.CA8 && activeObject3.CA8  == 1 ||
					 cubeTerain.CB8 && activeObject3.CB8  == 1 ||
					 cubeTerain.CC8 && activeObject3.CC8  == 1 ||
					 cubeTerain.CD8 && activeObject3.CD8  == 1 ||
					 cubeTerain.CE8 && activeObject3.CE8  == 1 ||
					 cubeTerain.CF8 && activeObject3.CF8  == 1 ||
					 cubeTerain.CG8 && activeObject3.CG8  == 1 ||
					 cubeTerain.CH8 && activeObject3.CH8  == 1 
				 )
				 {
					 Serial.println("--------------------------");
					 Serial.print("Score: ");
					 Serial.println(score);
					 Serial.println("--------------------------");
					 init();
					 send();
					 stop();
				 }
				// activeObject3	= cube->getShiftCubeUp(1,true,activeObject3);
				// cubeTerain 			= cube->add(activeObject3,cubeTerain);
				 shiftDownAmount 		= 0;
				 shiftLeftAmount 		= 3;
				 rotationAmount			= 0;
				 activeObject1 			= objects[activeObjectA];
				 
				 score++;
				 checkForDelete();
			}
			calculate();
			
		}
		//checkForDelete();
		
		send();
		
		
	}
}
void ledCube8_Tetris::stop()
{
	while(true)
	{
		delay(2000);
		return;
	}
}
void ledCube8_Tetris::calculate()
{
	activeObject2 = cube->getRotate(rotationAmount,activeObject1);
	if(shiftDownAmount < 3)
	{
		activeObject3 = cube->getShiftCubeUp(3-shiftDownAmount,false,activeObject2);
	}
	else
	{
		activeObject3 = cube->getShiftCubeDown(shiftDownAmount-3,false,activeObject2);
	}
	if(shiftLeftAmount < 3)
	{
		activeObject3 = cube->getShiftCubeRight(3-shiftLeftAmount,false,activeObject3);
	}
	else
	{
		activeObject3 = cube->getShiftCubeLeft(shiftLeftAmount-3,false,activeObject3);
	}
	cubeData = cube->add(cubeTerain , activeObject3);
	//cubeData = activeObject1;
}

bool ledCube8_Tetris::checkForCollision(int mode)
{


	CUBEDATACUBE vergleich	 = activeObject3;
	CUBEDATACUBE vergleichTerain = cubeTerain;
	
	
	if((vergleich.CA1  == 1 ||
		vergleich.CB1  == 1 ||
		vergleich.CC1  == 1 ||
		vergleich.CD1  == 1 ||
		vergleich.CE1  == 1 ||
		vergleich.CF1  == 1 ||
		vergleich.CG1  == 1 ||
		vergleich.CH1  == 1 )
		&& (mode == 1))
	{
		return true;
	}
	
	for(int i=0;i<2;i++)
	{
		vergleich	 	= activeObject3;
		
		//Serial.println(i);
		switch(mode)
		{
			case 1:
			{
				if(i==0)
				{
				vergleich = cube->getShiftCubeDown(1,true,activeObject3);
				}
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
				
				
				
			1,0,0,0,0,0,0,0,	
			1,0,0,0,0,0,0,0,	
			1,0,0,0,0,0,0,0,	
			1,0,0,0,0,0,0,0,	
			1,0,0,0,0,0,0,0,	
			1,0,0,0,0,0,0,0,	
			1,0,0,0,0,0,0,0,	
			1,0,0,0,0,0,0,0
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
				
				
				
			0,0,0,0,0,0,0,1,
			0,0,0,0,0,0,0,1,
			0,0,0,0,0,0,0,1,
			0,0,0,0,0,0,0,1,
			0,0,0,0,0,0,0,1,
			0,0,0,0,0,0,0,1,
			0,0,0,0,0,0,0,1,
			0,0,0,0,0,0,0,1
			};
					//vergleichTerain = vergleichTerain;
					//vergleich = cube->getShiftCubeLeft(1,false,vergleich);
				}
				break;
			}
			case 4:
			{
				if(i==0)
				{
				vergleich = cube->getRotate(1,activeObject1);
				if(shiftDownAmount < 3)
				{
					vergleich = cube->getShiftCubeUp(3-shiftDownAmount,false,vergleich);
				}
				else
				{
					vergleich = cube->getShiftCubeDown(shiftDownAmount-3,false,vergleich);
				}
				if(shiftLeftAmount < 3)
				{
					vergleich = cube->getShiftCubeRight(3-shiftLeftAmount,false,vergleich);
				}
				else
				{
					vergleich = cube->getShiftCubeLeft(shiftLeftAmount-3,false,vergleich);
				}
				}
				if(i==1)
				{
					vergleich = cube->getRotate(1,activeObject1);
				if(shiftDownAmount < 3)
				{
					vergleich = cube->getShiftCubeUp(3-shiftDownAmount,false,vergleich);
				}
				else
				{
					vergleich = cube->getShiftCubeDown(shiftDownAmount-3,false,vergleich);
				}
				if(shiftLeftAmount < 3)
				{
					vergleich = cube->getShiftCubeRight(2-shiftLeftAmount,false,vergleich);
				}
				else
				{
					vergleich = cube->getShiftCubeLeft(shiftLeftAmount-4,false,vergleich);
				}
				
					vergleichTerain = {
				
				
				
			1,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,1
			};
					//vergleich = cube->getShiftCubeLeft(1,false,vergleich);
				}
			break;
			}
		}
		 
		
		
		
		
		if(
		 vergleichTerain.CA1 && vergleich.CA1  >= 1 ||
		 vergleichTerain.CB1 && vergleich.CB1  >= 1 ||
		 vergleichTerain.CC1 && vergleich.CC1  >= 1 ||
		 vergleichTerain.CD1 && vergleich.CD1  >= 1 ||
		 vergleichTerain.CE1 && vergleich.CE1  >= 1 ||
		 vergleichTerain.CF1 && vergleich.CF1  >= 1 ||
		 vergleichTerain.CG1 && vergleich.CG1  >= 1 ||
		 vergleichTerain.CH1 && vergleich.CH1  >= 1 ||
		 
		 vergleichTerain.CA2 && vergleich.CA2  >= 1 ||
		 vergleichTerain.CB2 && vergleich.CB2  >= 1 ||
		 vergleichTerain.CC2 && vergleich.CC2  >= 1 ||
		 vergleichTerain.CD2 && vergleich.CD2  >= 1 ||
		 vergleichTerain.CE2 && vergleich.CE2  >= 1 ||
		 vergleichTerain.CF2 && vergleich.CF2  >= 1 ||
		 vergleichTerain.CG2 && vergleich.CG2  >= 1 ||
		 vergleichTerain.CH2 && vergleich.CH2  >= 1 ||
		 
		 vergleichTerain.CA3 && vergleich.CA3  >= 1 ||
		 vergleichTerain.CB3 && vergleich.CB3  >= 1 ||
		 vergleichTerain.CC3 && vergleich.CC3  >= 1 ||
		 vergleichTerain.CD3 && vergleich.CD3  >= 1 ||
		 vergleichTerain.CE3 && vergleich.CE3  >= 1 ||
		 vergleichTerain.CF3 && vergleich.CF3  >= 1 ||
		 vergleichTerain.CG3 && vergleich.CG3  >= 1 ||
		 vergleichTerain.CH3 && vergleich.CH3  >= 1 ||
		 
		 vergleichTerain.CA4 && vergleich.CA4  >= 1 ||
		 vergleichTerain.CB4 && vergleich.CB4  >= 1 ||
		 vergleichTerain.CC4 && vergleich.CC4  >= 1 ||
		 vergleichTerain.CD4 && vergleich.CD4  >= 1 ||
		 vergleichTerain.CE4 && vergleich.CE4  >= 1 ||
		 vergleichTerain.CF4 && vergleich.CF4  >= 1 ||
		 vergleichTerain.CG4 && vergleich.CG4  >= 1 ||
		 vergleichTerain.CH4 && vergleich.CH4  >= 1 ||
		 
		 vergleichTerain.CA5 && vergleich.CA5  >= 1 ||
		 vergleichTerain.CB5 && vergleich.CB5  >= 1 ||
		 vergleichTerain.CC5 && vergleich.CC5  >= 1 ||
		 vergleichTerain.CD5 && vergleich.CD5  >= 1 ||
		 vergleichTerain.CE5 && vergleich.CE5  >= 1 ||
		 vergleichTerain.CF5 && vergleich.CF5  >= 1 ||
		 vergleichTerain.CG5 && vergleich.CG5  >= 1 ||
		 vergleichTerain.CH5 && vergleich.CH5  >= 1 ||
		 
		 vergleichTerain.CA6 && vergleich.CA6  >= 1 ||
		 vergleichTerain.CB6 && vergleich.CB6  >= 1 ||
		 vergleichTerain.CC6 && vergleich.CC6  >= 1 ||
		 vergleichTerain.CD6 && vergleich.CD6  >= 1 ||
		 vergleichTerain.CE6 && vergleich.CE6  >= 1 ||
		 vergleichTerain.CF6 && vergleich.CF6  >= 1 ||
		 vergleichTerain.CG6 && vergleich.CG6  >= 1 ||
		 vergleichTerain.CH6 && vergleich.CH6  >= 1 ||
		 
		 vergleichTerain.CA7 && vergleich.CA7  >= 1 ||
		 vergleichTerain.CB7 && vergleich.CB7  >= 1 ||
		 vergleichTerain.CC7 && vergleich.CC7  >= 1 ||
		 vergleichTerain.CD7 && vergleich.CD7  >= 1 ||
		 vergleichTerain.CE7 && vergleich.CE7  >= 1 ||
		 vergleichTerain.CF7 && vergleich.CF7  >= 1 ||
		 vergleichTerain.CG7 && vergleich.CG7  >= 1 ||
		 vergleichTerain.CH7 && vergleich.CH7  >= 1 ||
		 
		 vergleichTerain.CA8 && vergleich.CA8  >= 1 ||
		 vergleichTerain.CB8 && vergleich.CB8  >= 1 ||
		 vergleichTerain.CC8 && vergleich.CC8  >= 1 ||
		 vergleichTerain.CD8 && vergleich.CD8  >= 1 ||
		 vergleichTerain.CE8 && vergleich.CE8  >= 1 ||
		 vergleichTerain.CF8 && vergleich.CF8  >= 1 ||
		 vergleichTerain.CG8 && vergleich.CG8  >= 1 ||
		 vergleichTerain.CH8 && vergleich.CH8  >= 1   
		 )
		 {
			/* if(shiftDownAmount ==1 )
			 {
				 stop();
			 }*/
			 //activeObject3 = cube->getShiftCubeUp(1,true,activeObject3);
			 //cubeTerain = cube->add(activeObject3,cubeTerain);
			// shiftDownAmount = 0;
			 //activeObject = objects[1];
			 //shiftLeftAmount = 3;
			 return true;
		 }
		 else
		 {
			// return false;
		 }
	}
	return false;
	 /*if(
	 cubeTerain.CA1 == 1 &&
	 cubeTerain.CB1 == 1 &&
	 cubeTerain.CC1 == 1 &&
	 cubeTerain.CD1 == 1 &&
	 cubeTerain.CE1 == 1 &&
	 cubeTerain.CF1 == 1 &&
	 cubeTerain.CG1 == 1 &&
	 cubeTerain.CH1 == 1  
	 )
	 {
		 cubeTerain = cube->getShiftCubeDown(1,false,cubeTerain);
	 }*/
}                                                
void ledCube8_Tetris::checkForDelete()
{
	CUBEDATACUBE TERAIN = cubeTerain;
	CUBEDATACUBE SUBTRACTOR = {
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1
	};
	if(
	 cubeTerain.CA1 == 1 &&
	 cubeTerain.CB1 == 1 &&
	 cubeTerain.CC1 == 1 &&
	 cubeTerain.CD1 == 1 &&
	 cubeTerain.CE1 == 1 &&
	 cubeTerain.CF1 == 1 &&
	 cubeTerain.CG1 == 1 &&
	 cubeTerain.CH1 == 1  
	 )
	 {
		 TERAIN = cube->getShiftCubeDown(1,false,TERAIN);
	 }
	 if(
	 cubeTerain.CA2 == 1 &&
	 cubeTerain.CB2 == 1 &&
	 cubeTerain.CC2 == 1 &&
	 cubeTerain.CD2 == 1 &&
	 cubeTerain.CE2 == 1 &&
	 cubeTerain.CF2 == 1 &&
	 cubeTerain.CG2 == 1 &&
	 cubeTerain.CH2 == 1  
	 )
	 {		
	    SUBTRACTOR = cube->getShiftCubeDown(6,false,SUBTRACTOR);
		TERAIN = cube->subtract(TERAIN,SUBTRACTOR);
		TERAIN = cube->getShiftCubeDown(1,false,TERAIN);
		TERAIN.CA1 = cubeTerain.CA1;
		TERAIN.CB1 = cubeTerain.CB1;
		TERAIN.CC1 = cubeTerain.CC1;
		TERAIN.CD1 = cubeTerain.CD1;
		TERAIN.CE1 = cubeTerain.CE1;
		TERAIN.CF1 = cubeTerain.CF1;
		TERAIN.CG1 = cubeTerain.CG1;
		TERAIN.CH1 = cubeTerain.CH1;
	 }
	 if(
	 cubeTerain.CA3 == 1 &&
	 cubeTerain.CB3 == 1 &&
	 cubeTerain.CC3 == 1 &&
	 cubeTerain.CD3 == 1 &&
	 cubeTerain.CE3 == 1 &&
	 cubeTerain.CF3 == 1 &&
	 cubeTerain.CG3 == 1 &&
	 cubeTerain.CH3 == 1  
	 )
	 {		
	    SUBTRACTOR = cube->getShiftCubeDown(5,false,SUBTRACTOR);
		TERAIN = cube->subtract(TERAIN,SUBTRACTOR);
		TERAIN = cube->getShiftCubeDown(1,false,TERAIN);
		TERAIN.CA1 = cubeTerain.CA1;
		TERAIN.CB1 = cubeTerain.CB1;
		TERAIN.CC1 = cubeTerain.CC1;
		TERAIN.CD1 = cubeTerain.CD1;
		TERAIN.CE1 = cubeTerain.CE1;
		TERAIN.CF1 = cubeTerain.CF1;
		TERAIN.CG1 = cubeTerain.CG1;
		TERAIN.CH1 = cubeTerain.CH1;
		
		TERAIN.CA2 = cubeTerain.CA2;
		TERAIN.CB2 = cubeTerain.CB2;
		TERAIN.CC2 = cubeTerain.CC2;
		TERAIN.CD2 = cubeTerain.CD2;
		TERAIN.CE2 = cubeTerain.CE2;
		TERAIN.CF2 = cubeTerain.CF2;
		TERAIN.CG2 = cubeTerain.CG2;
		TERAIN.CH2 = cubeTerain.CH2;
	 }
	 if(
	 cubeTerain.CA4 == 1 &&
	 cubeTerain.CB4 == 1 &&
	 cubeTerain.CC4 == 1 &&
	 cubeTerain.CD4 == 1 &&
	 cubeTerain.CE4 == 1 &&
	 cubeTerain.CF4 == 1 &&
	 cubeTerain.CG4 == 1 &&
	 cubeTerain.CH4 == 1  
	 )
	 {		
	    SUBTRACTOR = cube->getShiftCubeDown(4,false,SUBTRACTOR);
		TERAIN = cube->subtract(TERAIN,SUBTRACTOR);
		TERAIN = cube->getShiftCubeDown(1,false,TERAIN);
		TERAIN.CA1 = cubeTerain.CA1;
		TERAIN.CB1 = cubeTerain.CB1;
		TERAIN.CC1 = cubeTerain.CC1;
		TERAIN.CD1 = cubeTerain.CD1;
		TERAIN.CE1 = cubeTerain.CE1;
		TERAIN.CF1 = cubeTerain.CF1;
		TERAIN.CG1 = cubeTerain.CG1;
		TERAIN.CH1 = cubeTerain.CH1;
		
		TERAIN.CA2 = cubeTerain.CA2;
		TERAIN.CB2 = cubeTerain.CB2;
		TERAIN.CC2 = cubeTerain.CC2;
		TERAIN.CD2 = cubeTerain.CD2;
		TERAIN.CE2 = cubeTerain.CE2;
		TERAIN.CF2 = cubeTerain.CF2;
		TERAIN.CG2 = cubeTerain.CG2;
		TERAIN.CH2 = cubeTerain.CH2;
		
		TERAIN.CA3 = cubeTerain.CA3;
		TERAIN.CB3 = cubeTerain.CB3;
		TERAIN.CC3 = cubeTerain.CC3;
		TERAIN.CD3 = cubeTerain.CD3;
		TERAIN.CE3 = cubeTerain.CE3;
		TERAIN.CF3 = cubeTerain.CF3;
		TERAIN.CG3 = cubeTerain.CG3;
		TERAIN.CH3 = cubeTerain.CH3;
		
	 }
	if(
	 cubeTerain.CA5 == 1 &&
	 cubeTerain.CB5 == 1 &&
	 cubeTerain.CC5 == 1 &&
	 cubeTerain.CD5 == 1 &&
	 cubeTerain.CE5 == 1 &&
	 cubeTerain.CF5 == 1 &&
	 cubeTerain.CG5 == 1 &&
	 cubeTerain.CH5 == 1  
	 )
	 {		
	    SUBTRACTOR = cube->getShiftCubeDown(3,false,SUBTRACTOR);
		TERAIN = cube->subtract(TERAIN,SUBTRACTOR);
		TERAIN = cube->getShiftCubeDown(1,false,TERAIN);
		TERAIN.CA1 = cubeTerain.CA1;
		TERAIN.CB1 = cubeTerain.CB1;
		TERAIN.CC1 = cubeTerain.CC1;
		TERAIN.CD1 = cubeTerain.CD1;
		TERAIN.CE1 = cubeTerain.CE1;
		TERAIN.CF1 = cubeTerain.CF1;
		TERAIN.CG1 = cubeTerain.CG1;
		TERAIN.CH1 = cubeTerain.CH1;
		
		TERAIN.CA2 = cubeTerain.CA2;
		TERAIN.CB2 = cubeTerain.CB2;
		TERAIN.CC2 = cubeTerain.CC2;
		TERAIN.CD2 = cubeTerain.CD2;
		TERAIN.CE2 = cubeTerain.CE2;
		TERAIN.CF2 = cubeTerain.CF2;
		TERAIN.CG2 = cubeTerain.CG2;
		TERAIN.CH2 = cubeTerain.CH2;
		
		TERAIN.CA3 = cubeTerain.CA3;
		TERAIN.CB3 = cubeTerain.CB3;
		TERAIN.CC3 = cubeTerain.CC3;
		TERAIN.CD3 = cubeTerain.CD3;
		TERAIN.CE3 = cubeTerain.CE3;
		TERAIN.CF3 = cubeTerain.CF3;
		TERAIN.CG3 = cubeTerain.CG3;
		TERAIN.CH3 = cubeTerain.CH3;
		
		TERAIN.CA4 = cubeTerain.CA4;
		TERAIN.CB4 = cubeTerain.CB4;
		TERAIN.CC4 = cubeTerain.CC4;
		TERAIN.CD4 = cubeTerain.CD4;
		TERAIN.CE4 = cubeTerain.CE4;
		TERAIN.CF4 = cubeTerain.CF4;
		TERAIN.CG4 = cubeTerain.CG4;
		TERAIN.CH4 = cubeTerain.CH4;
	 }
	if(
	 cubeTerain.CA6 == 1 &&
	 cubeTerain.CB6 == 1 &&
	 cubeTerain.CC6 == 1 &&
	 cubeTerain.CD6 == 1 &&
	 cubeTerain.CE6 == 1 &&
	 cubeTerain.CF6 == 1 &&
	 cubeTerain.CG6 == 1 &&
	 cubeTerain.CH6 == 1  
	 )
	 {		
	    SUBTRACTOR = cube->getShiftCubeDown(2,false,SUBTRACTOR);
		TERAIN = cube->subtract(TERAIN,SUBTRACTOR);
		TERAIN = cube->getShiftCubeDown(1,false,TERAIN);
		TERAIN.CA1 = cubeTerain.CA1;
		TERAIN.CB1 = cubeTerain.CB1;
		TERAIN.CC1 = cubeTerain.CC1;
		TERAIN.CD1 = cubeTerain.CD1;
		TERAIN.CE1 = cubeTerain.CE1;
		TERAIN.CF1 = cubeTerain.CF1;
		TERAIN.CG1 = cubeTerain.CG1;
		TERAIN.CH1 = cubeTerain.CH1;
		
		TERAIN.CA2 = cubeTerain.CA2;
		TERAIN.CB2 = cubeTerain.CB2;
		TERAIN.CC2 = cubeTerain.CC2;
		TERAIN.CD2 = cubeTerain.CD2;
		TERAIN.CE2 = cubeTerain.CE2;
		TERAIN.CF2 = cubeTerain.CF2;
		TERAIN.CG2 = cubeTerain.CG2;
		TERAIN.CH2 = cubeTerain.CH2;
		
		TERAIN.CA3 = cubeTerain.CA3;
		TERAIN.CB3 = cubeTerain.CB3;
		TERAIN.CC3 = cubeTerain.CC3;
		TERAIN.CD3 = cubeTerain.CD3;
		TERAIN.CE3 = cubeTerain.CE3;
		TERAIN.CF3 = cubeTerain.CF3;
		TERAIN.CG3 = cubeTerain.CG3;
		TERAIN.CH3 = cubeTerain.CH3;
		
		TERAIN.CA4 = cubeTerain.CA4;
		TERAIN.CB4 = cubeTerain.CB4;
		TERAIN.CC4 = cubeTerain.CC4;
		TERAIN.CD4 = cubeTerain.CD4;
		TERAIN.CE4 = cubeTerain.CE4;
		TERAIN.CF4 = cubeTerain.CF4;
		TERAIN.CG4 = cubeTerain.CG4;
		TERAIN.CH4 = cubeTerain.CH4;
		
		TERAIN.CA5 = cubeTerain.CA5;
		TERAIN.CB5 = cubeTerain.CB5;
		TERAIN.CC5 = cubeTerain.CC5;
		TERAIN.CD5 = cubeTerain.CD5;
		TERAIN.CE5 = cubeTerain.CE5;
		TERAIN.CF5 = cubeTerain.CF5;
		TERAIN.CG5 = cubeTerain.CG5;
		TERAIN.CH5 = cubeTerain.CH5;
	 }
	if(
	 cubeTerain.CA7 == 1 &&
	 cubeTerain.CB7 == 1 &&
	 cubeTerain.CC7 == 1 &&
	 cubeTerain.CD7 == 1 &&
	 cubeTerain.CE7 == 1 &&
	 cubeTerain.CF7 == 1 &&
	 cubeTerain.CG7 == 1 &&
	 cubeTerain.CH7 == 1  
	 )
	 {		
	    SUBTRACTOR = cube->getShiftCubeDown(1,false,SUBTRACTOR);
		TERAIN = cube->subtract(TERAIN,SUBTRACTOR);
		TERAIN = cube->getShiftCubeDown(1,false,TERAIN);
		TERAIN.CA1 = cubeTerain.CA1;
		TERAIN.CB1 = cubeTerain.CB1;
		TERAIN.CC1 = cubeTerain.CC1;
		TERAIN.CD1 = cubeTerain.CD1;
		TERAIN.CE1 = cubeTerain.CE1;
		TERAIN.CF1 = cubeTerain.CF1;
		TERAIN.CG1 = cubeTerain.CG1;
		TERAIN.CH1 = cubeTerain.CH1;
		
		TERAIN.CA2 = cubeTerain.CA2;
		TERAIN.CB2 = cubeTerain.CB2;
		TERAIN.CC2 = cubeTerain.CC2;
		TERAIN.CD2 = cubeTerain.CD2;
		TERAIN.CE2 = cubeTerain.CE2;
		TERAIN.CF2 = cubeTerain.CF2;
		TERAIN.CG2 = cubeTerain.CG2;
		TERAIN.CH2 = cubeTerain.CH2;
		
		TERAIN.CA3 = cubeTerain.CA3;
		TERAIN.CB3 = cubeTerain.CB3;
		TERAIN.CC3 = cubeTerain.CC3;
		TERAIN.CD3 = cubeTerain.CD3;
		TERAIN.CE3 = cubeTerain.CE3;
		TERAIN.CF3 = cubeTerain.CF3;
		TERAIN.CG3 = cubeTerain.CG3;
		TERAIN.CH3 = cubeTerain.CH3;
		
		TERAIN.CA4 = cubeTerain.CA4;
		TERAIN.CB4 = cubeTerain.CB4;
		TERAIN.CC4 = cubeTerain.CC4;
		TERAIN.CD4 = cubeTerain.CD4;
		TERAIN.CE4 = cubeTerain.CE4;
		TERAIN.CF4 = cubeTerain.CF4;
		TERAIN.CG4 = cubeTerain.CG4;
		TERAIN.CH4 = cubeTerain.CH4;
		
		TERAIN.CA5 = cubeTerain.CA5;
		TERAIN.CB5 = cubeTerain.CB5;
		TERAIN.CC5 = cubeTerain.CC5;
		TERAIN.CD5 = cubeTerain.CD5;
		TERAIN.CE5 = cubeTerain.CE5;
		TERAIN.CF5 = cubeTerain.CF5;
		TERAIN.CG5 = cubeTerain.CG5;
		TERAIN.CH5 = cubeTerain.CH5;
		
		TERAIN.CA6 = cubeTerain.CA6;
		TERAIN.CB6 = cubeTerain.CB6;
		TERAIN.CC6 = cubeTerain.CC6;
		TERAIN.CD6 = cubeTerain.CD6;
		TERAIN.CE6 = cubeTerain.CE6;
		TERAIN.CF6 = cubeTerain.CF6;
		TERAIN.CG6 = cubeTerain.CG6;
		TERAIN.CH6 = cubeTerain.CH6;
	 }
	if(
	 cubeTerain.CA8 == 1 &&
	 cubeTerain.CB8 == 1 &&
	 cubeTerain.CC8 == 1 &&
	 cubeTerain.CD8 == 1 &&
	 cubeTerain.CE8 == 1 &&
	 cubeTerain.CF8 == 1 &&
	 cubeTerain.CG8 == 1 &&
	 cubeTerain.CH8 == 1  
	 )
	 {		
	  //  SUBTRACTOR = cube->getShiftCubeDown(1,false,SUBTRACTOR);
		TERAIN = cube->subtract(TERAIN,SUBTRACTOR);
		TERAIN = cube->getShiftCubeDown(1,false,TERAIN);
		TERAIN.CA1 = cubeTerain.CA1;
		TERAIN.CB1 = cubeTerain.CB1;
		TERAIN.CC1 = cubeTerain.CC1;
		TERAIN.CD1 = cubeTerain.CD1;
		TERAIN.CE1 = cubeTerain.CE1;
		TERAIN.CF1 = cubeTerain.CF1;
		TERAIN.CG1 = cubeTerain.CG1;
		TERAIN.CH1 = cubeTerain.CH1;
		
		TERAIN.CA2 = cubeTerain.CA2;
		TERAIN.CB2 = cubeTerain.CB2;
		TERAIN.CC2 = cubeTerain.CC2;
		TERAIN.CD2 = cubeTerain.CD2;
		TERAIN.CE2 = cubeTerain.CE2;
		TERAIN.CF2 = cubeTerain.CF2;
		TERAIN.CG2 = cubeTerain.CG2;
		TERAIN.CH2 = cubeTerain.CH2;
		
		TERAIN.CA3 = cubeTerain.CA3;
		TERAIN.CB3 = cubeTerain.CB3;
		TERAIN.CC3 = cubeTerain.CC3;
		TERAIN.CD3 = cubeTerain.CD3;
		TERAIN.CE3 = cubeTerain.CE3;
		TERAIN.CF3 = cubeTerain.CF3;
		TERAIN.CG3 = cubeTerain.CG3;
		TERAIN.CH3 = cubeTerain.CH3;
		
		TERAIN.CA4 = cubeTerain.CA4;
		TERAIN.CB4 = cubeTerain.CB4;
		TERAIN.CC4 = cubeTerain.CC4;
		TERAIN.CD4 = cubeTerain.CD4;
		TERAIN.CE4 = cubeTerain.CE4;
		TERAIN.CF4 = cubeTerain.CF4;
		TERAIN.CG4 = cubeTerain.CG4;
		TERAIN.CH4 = cubeTerain.CH4;
		
		TERAIN.CA5 = cubeTerain.CA5;
		TERAIN.CB5 = cubeTerain.CB5;
		TERAIN.CC5 = cubeTerain.CC5;
		TERAIN.CD5 = cubeTerain.CD5;
		TERAIN.CE5 = cubeTerain.CE5;
		TERAIN.CF5 = cubeTerain.CF5;
		TERAIN.CG5 = cubeTerain.CG5;
		TERAIN.CH5 = cubeTerain.CH5;
		
		TERAIN.CA6 = cubeTerain.CA6;
		TERAIN.CB6 = cubeTerain.CB6;
		TERAIN.CC6 = cubeTerain.CC6;
		TERAIN.CD6 = cubeTerain.CD6;
		TERAIN.CE6 = cubeTerain.CE6;
		TERAIN.CF6 = cubeTerain.CF6;
		TERAIN.CG6 = cubeTerain.CG6;
		TERAIN.CH6 = cubeTerain.CH6;
		
		TERAIN.CA7 = cubeTerain.CA7;
		TERAIN.CB7 = cubeTerain.CB7;
		TERAIN.CC7 = cubeTerain.CC7;
		TERAIN.CD7 = cubeTerain.CD7;
		TERAIN.CE7 = cubeTerain.CE7;
		TERAIN.CF7 = cubeTerain.CF7;
		TERAIN.CG7 = cubeTerain.CG7;
		TERAIN.CH7 = cubeTerain.CH7;
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
void ledCube8_Tetris::button1Player()
{
	while(checkForCollision(1) == false)
	{
		shiftDownAmount++;
		calculate();
	}
}
void ledCube8_Tetris::button2Player()
{
	if(checkForCollision(2))
	{
		
	}
	else
	{
		 shiftLeftAmount++;
		 calculate();
	}
	
	
}
void ledCube8_Tetris::button3Player()
{   
//activeObject3 = cube->getShiftCubeLeft(1,true,activeObject3);
	/*if(checkForCollision())
	 {
		 //activeObject3 = cube->getShiftCubeRight(1,true,activeObject3);
		// cubeTerain = cube->add(activeObject3,cubeTerain);
		 //shiftDownAmount = 0;
		 //activeObject = objects[1];
		 //shiftLeftAmount = 3;
	 }
	 else*/
	 if(checkForCollision(3))
	{
		
	}
	else
	{
		 shiftLeftAmount--;
		 calculate();
	}
	
}
void ledCube8_Tetris::button4Player()
{
	/*activeObject3 = cube->getShiftCubeRight(1,true,activeObject3);
	if(checkForCollision())
	 {
		 activeObject3 = cube->getShiftCubeLeft(1,true,activeObject3);
		// cubeTerain = cube->add(activeObject3,cubeTerain);
		 //shiftDownAmount = 0;
		 //activeObject = objects[1];
		 //shiftLeftAmount = 3;
	 }
	 else*/
	 
	 
	 if(checkForCollision(4))
	 {
		 
	 }
	 else
	 {
		 rotationAmount++;
		  if(rotationAmount > 3)
			 {
				rotationAmount = 0;
			 }
		 calculate();
	 }
	 
	
	 
}
/*void ledCube8_Tetris::button5Player()
{
	activeObject = cube->getRotate(1,activeObject);
	calculate();
}
void ledCube8_Tetris::button6Player()
{
	
	
}
*/
//===============================Player2=====================================
/*
void ledCube8_Tetris::button1Player2()
{
	
}
void ledCube8_Tetris::button2Player2()
{
	
}
void ledCube8_Tetris::button3Player2()
{
	
}
void ledCube8_Tetris::button4Player2()
{
	
}
void ledCube8_Tetris::button5Player2()
{

	
}
void ledCube8_Tetris::button6Player2()
{
	
}*/