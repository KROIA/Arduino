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
		 but1P1 = new Button(pins[0],activeHigh);
		 but2P1 = new Button(pins[1],activeHigh);
		 but3P1 = new Button(pins[2],activeHigh);
		 but4P1 = new Button(pins[3],activeHigh);
		 
		 but1P2 = new Button(pins[4],activeHigh);
		 but2P2 = new Button(pins[5],activeHigh);
		 but3P2 = new Button(pins[6],activeHigh);
		 but4P2 = new Button(pins[7],activeHigh);
		 

		but1P1->init();
		but2P1->init();
		but3P1->init();
		but4P1->init();
		but1P2->init();
		but2P2->init();
		but3P2->init();
		but4P2->init();
		
		Wire.begin();
		cube->time(20);
		
		
		
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
		cubeTerainp1 = {
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
		activeObjectAP1 		= random(0,7);
		scoreP1					= 0;
		rotationAmountP1		= 0;
		shiftDownAmountP1 		= 0;
		shiftLeftAmountP1 		= 3;
		
		activeObjectAP2 		= random(0,7);
		scoreP2					= 0;
		rotationAmountP2		= 0;
		shiftDownAmountP2 		= 0;
		shiftLeftAmountP2 		= 3;
		
		player1IsDeath			= false;
		player2IsDeath			= false;
		
		activeObject1p1	= objects[activeObjectAP1];
		activeObject2p1	= cubeData;
		activeObject3p1 = cubeData;
		cubeTerainp1	= cubeData;
		activeObject1p2	= objects[activeObjectAP2];
		activeObject2p2 = cubeData;
		activeObject3p2 = cubeData;
		cubeTerainp2	= cubeData;
}

void ledCube8_Tetris::run()
{
	startTime = millis();
	init();
	while(true)
	{
		
		
		time = millis();
		
		but1P1->checkButton();
		but2P1->checkButton();
		but3P1->checkButton();
		but4P1->checkButton();
		
		but1P2->checkButton();
		but2P2->checkButton();
		but3P2->checkButton();
		but4P2->checkButton();
		
		
		if((time -startTime) > shiftTime)
		{
			//Serial.println(scoreP1);
			activeObjectAP1 = random(0,7);
			activeObjectAP2 = random(0,7);
			//Serial.println(activeObjectAP1);
			/*Serial.println(shiftDownAmountP1);
			Serial.println(shiftLeftAmountP1);
			Serial.println(rotationAmountP1);*/
			//Serial.println("");
			startTime = time;
			//if(shiftDownAmountP1 < 6)
			{
				if(player1IsDeath == false)
				{
					shiftDownAmountP1++;
				}
				if(player2IsDeath == false)
				{
					shiftDownAmountP2++;
				}
			}
			/*else
			{
				shiftDownAmountP1 = 0;
				cubeTerainp1 		= cube->add(cubeTerainp1,activeObject3p1);
				activeObject1p1 	= objects[activeObjectAP1];
			}*/
			//calculate();
			if(checkForCollision(1,1)  && player1IsDeath == false)
			{
				/*shiftDownAmountP1--;
				calculate();*/
				
				shiftDownAmountP1 = 0;
				cubeTerainp1 		= cube->add(cubeTerainp1,activeObject3p1);
				activeObject1p1 	= objects[activeObjectAP1];
				
	
				
				 if(	 
					 cubeTerainp1.CA8 && activeObject3p1.CA8  == 1 ||
					 cubeTerainp1.CB8 && activeObject3p1.CB8  == 1 ||
					 cubeTerainp1.CC8 && activeObject3p1.CC8  == 1 ||
					 cubeTerainp1.CD8 && activeObject3p1.CD8  == 1 ||
					 cubeTerainp1.CE8 && activeObject3p1.CE8  == 1 ||
					 cubeTerainp1.CF8 && activeObject3p1.CF8  == 1 ||
					 cubeTerainp1.CG8 && activeObject3p1.CG8  == 1 ||
					 cubeTerainp1.CH8 && activeObject3p1.CH8  == 1 
				 )
				 {
					 player1IsDeath = true;
					/* Serial.println("--------------------------");
					 Serial.print("Score p1: ");
					 Serial.println(scoreP1);
					 Serial.println("--------------------------");
					 init();
					 send();
					 stop();*/
				 }
				// activeObject3p1	= cube->getShiftCubeUp(1,true,activeObject3p1);
				// cubeTerainp1 			= cube->add(activeObject3p1,cubeTerainp1);
				if( player1IsDeath == false)
				 {
					 shiftDownAmountP1 		= 0;
					 shiftLeftAmountP1 		= 3;
					 rotationAmountP1		= 0;
					 activeObject1p1 		= objects[activeObjectAP1];
					 
					 scoreP1++;
					 checkForDelete(1);
				 }
			}
			if(checkForCollision(1,2) && player2IsDeath == false)
			{
				/*shiftDownAmountP1--;
				calculate();*/
				
				shiftDownAmountP2 = 0;
				cubeTerainp2 		= cube->add(cubeTerainp2,activeObject3p2);
				activeObject1p2 	= objects[activeObjectAP2];
				
				
				
		
				
				 if(	 
					 cubeTerainp2.CA8 && activeObject3p2.CA8  == 1 ||
					 cubeTerainp2.CB8 && activeObject3p2.CB8  == 1 ||
					 cubeTerainp2.CC8 && activeObject3p2.CC8  == 1 ||
					 cubeTerainp2.CD8 && activeObject3p2.CD8  == 1 ||
					 cubeTerainp2.CE8 && activeObject3p2.CE8  == 1 ||
					 cubeTerainp2.CF8 && activeObject3p2.CF8  == 1 ||
					 cubeTerainp2.CG8 && activeObject3p2.CG8  == 1 ||
					 cubeTerainp2.CH8 && activeObject3p2.CH8  == 1 
				 )
				 {
					 player2IsDeath	= true;
					 
					 /*
					 Serial.println("--------------------------");
					 Serial.print("Score p2: ");
					 Serial.println(scoreP2);
					 Serial.println("--------------------------");
					 init();
					 send();
					 stop();
					 */
				 }
				// activeObject3p1	= cube->getShiftCubeUp(1,true,activeObject3p1);
				// cubeTerainp1 			= cube->add(activeObject3p1,cubeTerainp1);
				 if( player2IsDeath == false)
				 {
					 shiftDownAmountP2 		= 0;
					 shiftLeftAmountP2 		= 3;
					 rotationAmountP2			= 0;
					 activeObject1p2 			= objects[activeObjectAP2];
					 
					 scoreP2++;
					 checkForDelete(2);
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
		if(player1IsDeath == true && player2IsDeath == true)
		{
			Serial.println("******************************");
			Serial.print("Score p1: ");
			Serial.println(scoreP1);
			//Serial.println("--------------------------");
			
			
			
			Serial.println("--------------------------");
			Serial.print("Score p2: ");
			Serial.println(scoreP2);
			Serial.println("******************************");
			p_lcd->clear();
			p_lcd->                         setCursor  (0, 0);
			
		p_lcd->                         print      ("Player 1: ");
	
		p_lcd->                         print      (scoreP1);
		
		p_lcd->                         setCursor  (0, 1);
		
		p_lcd->                         print      ("Player 2: ");
	
		p_lcd->                         print      (scoreP2);
			//init();
			//send();
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
		/*cube->time(2000);
		cubeData = cube->invert(cube->getCube());
		cubeData.CA8 = scoreP1;
		cubeData.CC8 = scoreP2;
		cube->drawCube(cubeData);
		cube->time(1);*/
		init();
		return;
	}
}
void ledCube8_Tetris::calculate()
{
	for(int i = 0; i<2; i++)
	{
		if( i == 0)
		{
			activeObject2p1 = cube->getRotate(rotationAmountP1,activeObject1p1);
			if(shiftDownAmountP1 < 3)
			{
				activeObject3p1 = cube->getShiftCubeUp(3-shiftDownAmountP1,false,activeObject2p1);
			}
			else
			{
				activeObject3p1 = cube->getShiftCubeDown(shiftDownAmountP1-3,false,activeObject2p1);
			}
			if(shiftLeftAmountP1 < 3)
			{
				activeObject3p1 = cube->getShiftCubeRight(3-shiftLeftAmountP1,false,activeObject3p1);
			}
			else
			{
				activeObject3p1 = cube->getShiftCubeLeft(shiftLeftAmountP1-3,false,activeObject3p1);
			}
		}
		if( i == 1)
		{
			activeObject2p2 = cube->getRotate(rotationAmountP2,activeObject1p2);
			if(shiftDownAmountP2 < 3)
			{
				activeObject3p2 = cube->getShiftCubeUp(3-shiftDownAmountP2,false,activeObject2p2);
			}
			else
			{
				activeObject3p2 = cube->getShiftCubeDown(shiftDownAmountP2-3,false,activeObject2p2);
			}
			if(shiftLeftAmountP2 < 3)
			{
				activeObject3p2 = cube->getShiftCubeRight(3-shiftLeftAmountP2,false,activeObject3p2);
			}
			else
			{
				activeObject3p2 = cube->getShiftCubeLeft(shiftLeftAmountP2-3,false,activeObject3p2);
			}
			//activeObject3p2 = cube->getRotateUp(2,activeObject3p2);
			//cubeTerainp2	= cube->getRotateUp(2,cubeTerainp2);
		}
	}
	/*cubeData = cube->add(cubeTerainp1 , activeObject3p1);
	cubeData = cube->add(cubeTerainp2 , cubeData);
	cubeData = cube->add(activeObject3p2 , cubeData);*/
	//cubeData = activeObject1p1;
	cubeData = cube->add(cubeTerainp1,activeObject3p1);
	cubeData = cube->add(cubeData,cube->getRotateUp(2,cubeTerainp2));
	cubeData = cube->add(cubeData,cube->getRotateUp(2,activeObject3p2));
}

bool ledCube8_Tetris::checkForCollision(int mode,int player)
{


	CUBEDATACUBE vergleich;	 	 
	CUBEDATACUBE vergleichTerain; 
	
	if(player == 1)
	{
		vergleich	 	 = activeObject3p1;
		vergleichTerain  = cubeTerainp1;
	}   
	if(player == 2)
	{
		vergleich	 	 = activeObject3p2;
		vergleichTerain  = cubeTerainp2;
	}
	
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
			if(player == 1)
		{
			vergleich	 	 = activeObject3p1;
			//vergleichTerain  = cubeTerainp1;
		}   
		if(player == 2)
		{
			vergleich	 	 = activeObject3p2;
			//vergleichTerain  = cubeTerainp2;
		}
		
		//vergleich	 	= activeObject3p1;
		
		//Serial.println(mode);
		switch(mode)
		{
			case 1:
			{
				if(i==0 && player == 1)
				{
				vergleich = cube->getShiftCubeDown(1,true,activeObject3p1);
				}
				if(i==0 && player == 2)
				{
				vergleich = cube->getShiftCubeDown(1,true,activeObject3p2);
				}
				break;
			}
			case 2:
			{
				if(i==0 && player == 1)
				{
				vergleich = cube->getShiftCubeLeft(1,true,activeObject3p1);
				}
				if(i==0 && player == 2)
				{
				vergleich = cube->getShiftCubeLeft(1,true,activeObject3p2);
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
				if(i==0 && player == 1)
				{
				vergleich = cube->getShiftCubeRight(1,true,activeObject3p1);
				}
				if(i==0 && player == 2)
				{
				vergleich = cube->getShiftCubeRight(1,true,activeObject3p2);
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
				//Serial.println("Case 4");
				if(player == 1)
				{
					//Serial.println("Palyer 1");
					if(i==0)
					{
						vergleich = cube->getRotate(1,activeObject2p1);
						if(shiftDownAmountP1 < 3)
						{
							vergleich = cube->getShiftCubeUp(3-shiftDownAmountP1,false,vergleich);
						}
						else
						{
							vergleich = cube->getShiftCubeDown(shiftDownAmountP1-3,false,vergleich);
						}
						if(shiftLeftAmountP1 < 3)
						{
							vergleich = cube->getShiftCubeRight(3-shiftLeftAmountP1,false,vergleich);
						}
						else
						{
							vergleich = cube->getShiftCubeLeft(shiftLeftAmountP1-3,false,vergleich);
						}
					}
					
					if(i==1)
						{
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
					
					}
				}
				if(player == 2)
				{
					//Serial.println("Palyer 2");
					if(i==0)
					{
						vergleich = cube->getRotate(1,activeObject2p2);
						if(shiftDownAmountP2 < 3)
						{
							vergleich = cube->getShiftCubeUp(3-shiftDownAmountP2,false,vergleich);
						}
						else
						{
							vergleich = cube->getShiftCubeDown(shiftDownAmountP2-3,false,vergleich);
						}
						if(shiftLeftAmountP2 < 3)
						{
							vergleich = cube->getShiftCubeRight(3-shiftLeftAmountP2,false,vergleich);
						}
						else
						{
							vergleich = cube->getShiftCubeLeft(shiftLeftAmountP2-3,false,vergleich);
						}
					}
					//Serial.println(i);
					if(i==1)
					{
						vergleich = cube->getRotate(1,activeObject2p2);
						if(shiftDownAmountP2 < 3)
						{
							vergleich = cube->getShiftCubeUp(3-shiftDownAmountP2,false,vergleich);
						}
						else
						{
							vergleich = cube->getShiftCubeDown(shiftDownAmountP2-3,false,vergleich);
						}
						//Serial.println(shiftLeftAmountP2);
						if(shiftLeftAmountP2 < 2)
						{
							vergleich = cube->getShiftCubeRight(2-shiftLeftAmountP2,false,vergleich);
						}
						else
						{
							vergleich = cube->getShiftCubeLeft(shiftLeftAmountP2-4,false,vergleich);
						}
					}

				}
				if(i==1)
				{
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
				}
					//vergleich = cube->getShiftCubeLeft(1,false,vergleich);
				
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
void ledCube8_Tetris::checkForDelete(int mode)
{
	CUBEDATACUBE TERAIN;
	CUBEDATACUBE cubeDataCopy;
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
	if(mode == 1)
	{
		TERAIN = cubeTerainp1;
		cubeDataCopy = cubeTerainp1;
	}
	if(mode == 2)
	{
		TERAIN = cubeTerainp2;
		cubeDataCopy = cubeTerainp2;
	}
	if(
	 cubeDataCopy.CA1 == 1 &&
	 cubeDataCopy.CB1 == 1 &&
	 cubeDataCopy.CC1 == 1 &&
	 cubeDataCopy.CD1 == 1 &&
	 cubeDataCopy.CE1 == 1 &&
	 cubeDataCopy.CF1 == 1 &&
	 cubeDataCopy.CG1 == 1 &&
	 cubeDataCopy.CH1 == 1  
	 )
	 {
		 TERAIN = cube->getShiftCubeDown(1,false,TERAIN);
	 }
	 if(
	 cubeDataCopy.CA2 == 1 &&
	 cubeDataCopy.CB2 == 1 &&
	 cubeDataCopy.CC2 == 1 &&
	 cubeDataCopy.CD2 == 1 &&
	 cubeDataCopy.CE2 == 1 &&
	 cubeDataCopy.CF2 == 1 &&
	 cubeDataCopy.CG2 == 1 &&
	 cubeDataCopy.CH2 == 1  
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
	 cubeDataCopy.CA3 == 1 &&
	 cubeDataCopy.CB3 == 1 &&
	 cubeDataCopy.CC3 == 1 &&
	 cubeDataCopy.CD3 == 1 &&
	 cubeDataCopy.CE3 == 1 &&
	 cubeDataCopy.CF3 == 1 &&
	 cubeDataCopy.CG3 == 1 &&
	 cubeDataCopy.CH3 == 1  
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
	 cubeDataCopy.CA4 == 1 &&
	 cubeDataCopy.CB4 == 1 &&
	 cubeDataCopy.CC4 == 1 &&
	 cubeDataCopy.CD4 == 1 &&
	 cubeDataCopy.CE4 == 1 &&
	 cubeDataCopy.CF4 == 1 &&
	 cubeDataCopy.CG4 == 1 &&
	 cubeDataCopy.CH4 == 1  
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
	 cubeDataCopy.CA5 == 1 &&
	 cubeDataCopy.CB5 == 1 &&
	 cubeDataCopy.CC5 == 1 &&
	 cubeDataCopy.CD5 == 1 &&
	 cubeDataCopy.CE5 == 1 &&
	 cubeDataCopy.CF5 == 1 &&
	 cubeDataCopy.CG5 == 1 &&
	 cubeDataCopy.CH5 == 1  
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
	 cubeDataCopy.CA6 == 1 &&
	 cubeDataCopy.CB6 == 1 &&
	 cubeDataCopy.CC6 == 1 &&
	 cubeDataCopy.CD6 == 1 &&
	 cubeDataCopy.CE6 == 1 &&
	 cubeDataCopy.CF6 == 1 &&
	 cubeDataCopy.CG6 == 1 &&
	 cubeDataCopy.CH6 == 1  
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
	 cubeDataCopy.CA7 == 1 &&
	 cubeDataCopy.CB7 == 1 &&
	 cubeDataCopy.CC7 == 1 &&
	 cubeDataCopy.CD7 == 1 &&
	 cubeDataCopy.CE7 == 1 &&
	 cubeDataCopy.CF7 == 1 &&
	 cubeDataCopy.CG7 == 1 &&
	 cubeDataCopy.CH7 == 1  
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
	 cubeDataCopy.CA8 == 1 &&
	 cubeDataCopy.CB8 == 1 &&
	 cubeDataCopy.CC8 == 1 &&
	 cubeDataCopy.CD8 == 1 &&
	 cubeDataCopy.CE8 == 1 &&
	 cubeDataCopy.CF8 == 1 &&
	 cubeDataCopy.CG8 == 1 &&
	 cubeDataCopy.CH8 == 1  
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


	 if(mode == 1)
	{
		cubeTerainp1 = TERAIN;
	}
	if(mode == 2)
	{
		cubeTerainp2 = TERAIN;
	}
	
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
void ledCube8_Tetris::button1Player1()
{
	if(player1IsDeath == false)
	{
	while(checkForCollision(1,1) == false)
	{
		shiftDownAmountP1++;
		calculate();
	}
	}
}
void ledCube8_Tetris::button2Player1()
{
	if(player1IsDeath == false)
	{
	if(checkForCollision(2,1))
	{
		
	}
	else
	{
		 shiftLeftAmountP1++;
		 calculate();
	}
	}
	
}
void ledCube8_Tetris::button3Player1()
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
	 if(player1IsDeath == false)
	{
	 if(checkForCollision(3,1))
	{
		
	}
	else
	{
		 shiftLeftAmountP1--;
		 calculate();
	}
	}
}
void ledCube8_Tetris::button4Player1()
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
	 if(player1IsDeath == false)
	{ 
	 
	 if(checkForCollision(4,1))
	 {
		 
	 }
	 else
	 {
		 rotationAmountP1++;
		  if(rotationAmountP1 > 3)
			 {
				rotationAmountP1 = 0;
			 }
		 calculate();
	 }
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

void ledCube8_Tetris::button1Player2()
{
	if(player2IsDeath == false)
	{
		
	while(checkForCollision(1,2) == false)
	{
		shiftDownAmountP2++;
		calculate();
		
	}
	//Serial.println(shiftDownAmountP2);
	}
}
void ledCube8_Tetris::button2Player2()
{
	if(player2IsDeath == false)
	{
	if(checkForCollision(2,2))
	{
		
	}
	else
	{
		 shiftLeftAmountP2++;
	//	 Serial.println(shiftLeftAmountP2);
		 calculate();
	}
	}
}
void ledCube8_Tetris::button3Player2()
{
	 if(player2IsDeath == false)
	{
	 if(checkForCollision(3,2))
	{
		
	}
	else
	{
		 shiftLeftAmountP2--;
		//  Serial.println(shiftLeftAmountP2);
		 calculate();
	}
	}
}
void ledCube8_Tetris::button4Player2()
{
	if(player2IsDeath == false)
	{ 
	 
	 if(checkForCollision(4,2))
	 {
		 
	 }
	 else
	 {
		 rotationAmountP2++;
		  if(rotationAmountP2 > 3)
			 {
				rotationAmountP2 = 0;
			 }
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