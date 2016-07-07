//==========================================LED CUBE GAME=================== 
// Autor: 									Alex Krieg
// Erstellt:								12.5.16
// Version 									1.0.0
// Kompatibel mit den versionen: 			ledCube9.h : 3.0.2 BUILD
// Funktionen:								*****


//Anzahl Spieler:		2
//Prinzip:				Wer inerhalb einer Minute mehr Punkte hat gewinnt. 
//

#ifndef LEDCUBE8_GAME_H
#define LEDCUBE8_GAME_H

#include "ledcube8.h"
#include "button.h"
#include <Wire.h>


class ledCube8_Game
{
	public:
	ledCube8_Game(byte pins[]);
	~ledCube8_Game();
	
	void run();
	
	void button1Player1();
	void button2Player1();
	void button3Player1();
	void button4Player1();
	void button5Player1();
	void button6Player1();
	
	void button1Player2();
	void button2Player2();
	void button3Player2();
	void button4Player2();
	void button5Player2();
	void button6Player2();
	                  
	Button *but1P1;
	Button *but2P1;
	Button *but3P1;
	Button *but4P1;
	Button *but5P1;
	Button *but6P1;
	
	Button *but1P2;
	Button *but2P2;
	Button *but3P2;
	Button *but4P2;
	Button *but5P2;
	Button *but6P2;
	
	private:
	void init();
	void calculate();
	void send();
	void checkForCollision();
	void setCoin(POS coinPos);
	void deleteCoin(POS coinPos);
	void setPlayer(POS coinPos);
	void deletePlayer(POS coinPos);
	void stop();
	void intro();
	
	LedCube8* cube;
	
	POS pos[2];
	int coinAmount;
	int playerAmount;
	unsigned int startTime;
	unsigned long time;
	unsigned long stopTime;
	bool gameIsRunning;
	byte points[2];
	POS coin[16];
	CUBEDATACUBE scene;
	CUBEDATACUBE cubeData;
	CUBEDATACUBE player;
	CUBEDATACUBE coins;

	
};


#endif