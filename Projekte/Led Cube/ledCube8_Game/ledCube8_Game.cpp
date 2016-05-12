//==========================================LED CUBE GAME=================== 
// Autor: 									Alex Krieg
// Erstellt:								12.5.16
// Version 									1.0.0
// Kompatibel mit den versionen: 			ledCube9.h : 3.0.2 BUILD
// Funktionen:								*****






#include "ledCube8_Game.h"

ledCube8_Game::ledCube8_Game(byte pins[])
{
	
		 cube = new LedCube8;
		 but1P1 = new Button(pins[0],activeHigh);
		 but2P1 = new Button(pins[1],activeHigh);
		 but3P1 = new Button(pins[2],activeHigh);
		 but4P1 = new Button(pins[3],activeHigh);
		 but5P1 = new Button(pins[4],activeHigh);
		 but6P1 = new Button(pins[5],activeHigh);
		 
		 but1P2 = new Button(pins[6],activeHigh);
		 but2P2 = new Button(pins[7],activeHigh);
		 but3P2 = new Button(pins[8],activeHigh);
		 but4P2 = new Button(pins[9],activeHigh);
		 but5P2 = new Button(pins[10],activeHigh);
		 but6P2 = new Button(pins[11],activeHigh);
		 

		but1P1->init();
		but2P1->init();
		but3P1->init();
		but4P1->init();
		but5P1->init();
		but6P1->init();
		
		but1P2->init();
		but2P2->init();
		but3P2->init();
		but4P2->init();
		but5P2->init();
		but6P2->init();
		
		Wire.begin();
		
		pos[0] 		= {1,1,1};
		pos[1] 		= {8,8,1};
		points[0] 	= 0;
		points[1]	= 0;
		coinAmount 	= 16;
		playerAmount= 2;
		
		gameIsRunning = true;
		startTime 	= 0;
		time		= 0;
		stopTime 	= 60000;
	//	coin[coinAmount];
		
		
		coins = {
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0
		};
		scene = {
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0
		};
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
		player = {
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,1
		};
		//init();
}
ledCube8_Game::~ledCube8_Game()
{
	
}


void ledCube8_Game:: intro()
{
	for(int i=0;i<8;i++)
	{
		cubeData = cube->getShiftCubeDown(1,true,cubeData);
		send();
		delay(100);
	}
	/*for(int i = 0;i<coinAmount;i++)
		{
			coin[i].X--;
			coin[i].Y--;
			coin[i].Z--;
		}*/
	startTime = millis();
}
void ledCube8_Game::init()
{	
	if(coinAmount > 16)
	{
		coinAmount = 16;
	}
	for(int i = 0;i<coinAmount;i++)
		{
		coin[i].X = random(1,8);
		coin[i].Y = random(1,8);
		coin[i].Z = random(1,8);
		setCoin(coin[i]);
		}
	for(int i=0;i<playerAmount; i++)
	{
		setPlayer(pos[i]);
	}
	calculate();
	//send();
	//
}

void ledCube8_Game::run()
{
	init();
	intro();
	while(gameIsRunning)
	{
		
		time = millis();
		if((time - startTime) > stopTime)
		{
			stop();
		}
		
		
	but1P1->checkButton();
	but2P1->checkButton();
	but3P1->checkButton();
	but4P1->checkButton();
	but5P1->checkButton();
	but6P1->checkButton();
	
	but1P2->checkButton();
	but2P2->checkButton();
	but3P2->checkButton();
	but4P2->checkButton();
	but5P2->checkButton();
	but6P2->checkButton();
	checkForCollision();
	}
	while(true)
	{
		
	}
}
void ledCube8_Game::calculate()
{
	checkForCollision();
	
	cubeData = cube->add(player,player);
	cubeData = cube->add(player,scene);
	cubeData = cube->add(cubeData,coins);
}
void ledCube8_Game::stop()
{
	gameIsRunning = false;
	CUBEDATACUBE reset {
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0
	};
	cubeData = reset;
	send();
	Serial.print("Spieler 1 hat ");
	Serial.print(points[0]);
	Serial.println(" Punkte");
	Serial.print("Spieler 2 hat ");
	Serial.print(points[1]);
	Serial.println(" Punkte");
	if(points[0]!=points[1])
	{
		if(points[0]>points[1])
		{
			Serial.println("Spieler 1 hat gewonnen");
		}
		else
		{
			Serial.println("Spieler 2 hat gewonnen");
		}
	}
	else
	{
		Serial.println("Unentschieden");
	}
	
}
//===========================SEND===========================================
void ledCube8_Game::send()
{
	
	int reference = 1;
	Wire.beginTransmission(1); // transmit to device #1
	/*Wire.write(dataL.Layer);
	Wire.write(dataL.A);        
	Wire.write(dataL.B);
	Wire.write(dataL.C);
	Wire.write(dataL.D);
	Wire.write(dataL.E);
	Wire.write(dataL.F);
	Wire.write(dataL.G);
	Wire.write(dataL.H);*/
	
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
	Wire.endTransmission();    // stop transmitting
}
void ledCube8_Game::checkForCollision()
{
	for(int i=0;i<coinAmount;i++)
	{
		for(int e=0;e<playerAmount;e++)
		{
			if(coin[i].X == pos[e].X && coin[i].Y == pos[e].Y && coin[i].Z == pos[e].Z)
			{
				deleteCoin(coin[i]);
				coin[i] = {10,10,10};
				
				/*coin[i].X = random(1,8);
				coin[i].Y = random(1,8);
				coin[i].Z = random(1,8);*/
				points[e]++;
				//setCoin(coin[i]);
			}
		}
	}
}
void ledCube8_Game::setCoin(POS coinPos)
{
	CUBEDATACUBE buffer = {
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,1
	};
	
	buffer = cube->getShiftCubeLeft(coinPos.X-1,false,buffer);
	buffer = cube->getShiftCubeLeft90(coinPos.Y-1,false,buffer);
	buffer = cube->getShiftCubeUp(coinPos.Z-1,false,buffer);
	
	coins = cube->add(coins,buffer);
	
	
}
void ledCube8_Game::deleteCoin(POS coinPos)
{
	CUBEDATACUBE buffer = {
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,1
	};
	
	buffer = cube->getShiftCubeLeft(coinPos.X-1,false,buffer);
	buffer = cube->getShiftCubeLeft90(coinPos.Y-1,false,buffer);
	buffer = cube->getShiftCubeUp(coinPos.Z-1,false,buffer);
	
	coins = cube->subtract(coins,buffer);
}
void ledCube8_Game::setPlayer(POS coinPos)
{
	CUBEDATACUBE buffer = {
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,1
	};
	
	buffer = cube->getShiftCubeLeft(coinPos.X-1,false,buffer);
	buffer = cube->getShiftCubeLeft90(coinPos.Y-1,false,buffer);
	buffer = cube->getShiftCubeUp(coinPos.Z-1,false,buffer);
	
	player = cube->add(player,buffer);
	
	
}
void ledCube8_Game::deletePlayer(POS coinPos)
{
	CUBEDATACUBE buffer = {
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,1
	};
	
	buffer = cube->getShiftCubeLeft(coinPos.X-1,false,buffer);
	buffer = cube->getShiftCubeLeft90(coinPos.Y-1,false,buffer);
	buffer = cube->getShiftCubeUp(coinPos.Z-1,false,buffer);
	
	player = cube->subtract(player,buffer);
}
//===========================BUTTONS========================================
//===========================Player1========================================
void ledCube8_Game::button1Player1()
{
	deletePlayer(pos[0]);
	pos[0].X--;
	if(pos[0].X < 1)
	{
		pos[0].X = 1;
	}
	else
	{
	
	
	//player = cube->getShiftCubeRight(1,false,player);
	
	}
	setPlayer(pos[0]);
	calculate();
	send();
}
void ledCube8_Game::button2Player1()
{
	deletePlayer(pos[0]);
	pos[0].X++;
	if(pos[0].X > 8)
	{
		pos[0].X = 8;
	}
	else
	{
	
	
	//player = cube->getShiftCubeLeft(1,false,player);
	}
	setPlayer(pos[0]);
	calculate();
	send();
}
void ledCube8_Game::button3Player1()
{
	deletePlayer(pos[0]);
	pos[0].Y--;
	if(pos[0].Y < 1)
	{
		pos[0].Y = 1;
	}
	else
	{
	
	
	//player = cube->getShiftCubeRight90(1,false,player);
	}
	setPlayer(pos[0]);
	calculate();
	send();
}
void ledCube8_Game::button4Player1()
{
	deletePlayer(pos[0]);
	pos[0].Y++;
	if(pos[0].Y > 8)
	{
		pos[0].Y = 8;
	}
	else
	{
	
	
	//player = cube->getShiftCubeLeft90(1,false,player);
	}
	setPlayer(pos[0]);
	calculate();
	send();
}
void ledCube8_Game::button5Player1()
{
	deletePlayer(pos[0]);
	pos[0].Z--;
	if(pos[0].Z < 1)
	{
		pos[0].Z = 1;
	}
	else
	{
	
	
	//player = cube->getShiftCubeDown(1,false,player);
	}
	setPlayer(pos[0]);
	calculate();
	send();
}
void ledCube8_Game::button6Player1()
{
	deletePlayer(pos[0]);
	pos[0].Z++;
	if(pos[0].Z > 8)
	{
		pos[0].Z = 8;
	}
	else
	{
	
	
	//player = cube->getShiftCubeUp(1,false,player);
	}
	setPlayer(pos[0]);
	calculate();
	send();
}
//===============================Player2=====================================

void ledCube8_Game::button1Player2()
{
	deletePlayer(pos[1]);
	pos[1].X--;
	if(pos[1].X < 1)
	{
		pos[1].X = 1;
	}
	else
	{
	
	
	//player = cube->getShiftCubeRight(1,false,player);
	}
	setPlayer(pos[1]);
	calculate();
	send();
}
void ledCube8_Game::button2Player2()
{
	deletePlayer(pos[1]);
	pos[1].X++;
	if(pos[1].X > 8)
	{
		pos[1].X = 8;
	}
	else
	{
	
	
	//player = cube->getShiftCubeLeft(1,false,player);
	}
	setPlayer(pos[1]);
	calculate();
	send();
}
void ledCube8_Game::button3Player2()
{
	deletePlayer(pos[1]);
	pos[1].Y--;
	if(pos[1].Y < 1)
	{
		pos[1].Y = 1;
	}
	else
	{
	
	
	//player = cube->getShiftCubeRight90(1,false,player);
	}
	setPlayer(pos[1]);
	calculate();
	send();
}
void ledCube8_Game::button4Player2()
{
	deletePlayer(pos[1]);
	pos[1].Y++;
	if(pos[1].Y > 8)
	{
		pos[1].Y = 8;
	}
	else
	{
	
	
	//player = cube->getShiftCubeLeft90(1,false,player);
	}
	setPlayer(pos[1]);
	calculate();
	send();
}
void ledCube8_Game::button5Player2()
{
	deletePlayer(pos[1]);
	pos[1].Z--;
	if(pos[1].Z < 1)
	{
		pos[1].Z = 1;
	}
	else
	{
	
	
	//player = cube->getShiftCubeDown(1,false,player);
	}
	setPlayer(pos[1]);
	calculate();
	send();
}
void ledCube8_Game::button6Player2()
{
	deletePlayer(pos[1]);
	pos[1].Z++;
	if(pos[1].Z > 8)
	{
		pos[1].Z = 8;
	}
	else
	{
	
	
	//player = cube->getShiftCubeUp(1,false,player);
	}
	setPlayer(pos[1]);
	calculate();
	send();
}