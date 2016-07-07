//==========================================LED CUBE TETRIS=================== 
// Autor: 									Alex Krieg
// Erstellt:								20.5.16
// Version 									1.0.0
// Kompatibel mit den versionen: 			ledCube9.h : 3.0.3 BUILD ARduino Mega(2560)
// Funktionen:								*****

//Zweiscpieler Modus
//Mit BIN score anzeige


#ifndef LEDCUBE8_TETRIS_H
#define LEDCUBE8_TETRIS_H

#include "ledcube8.h"
#include "button.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


class ledCube8_Tetris
{
	public:
	ledCube8_Tetris(byte pins[]);
	~ledCube8_Tetris();
	
	void run();
	
	void button1Player1();
	void button2Player1();
	void button3Player1();
	void button4Player1();
	
	void button1Player2();
	void button2Player2();
	void button3Player2();
	void button4Player2();
	                  
	Button *but1P1;
	Button *but2P1;
	Button *but3P1;
	Button *but4P1;
	Button *but1P2;
	Button *but2P2;
	Button *but3P2;
	Button *but4P2;
	
	
	private:
	
	LiquidCrystal_I2C   *p_lcd;
	
	void init();
	void calculate();
	bool checkForCollision(int mode,int player);		// 1=down  2=left 3=right 4=rotation
	void checkForDelete(int mode);
	void send();
	void stop();
	
	
	
	LedCube8* cube;
	
	int shiftDownAmountP1;
	int shiftLeftAmountP1;
	int rotationAmountP1;
	int activeObjectAP1;
	int scoreP1;
	
	int shiftDownAmountP2;
	int shiftLeftAmountP2;
	int rotationAmountP2;
	int activeObjectAP2;
	int scoreP2;
	
	unsigned long startTime;
	unsigned long time;
	unsigned long shiftTime;
	
	bool player1IsDeath;
	bool player2IsDeath;
	
	
	CUBEDATACUBE objects[7];
	
	CUBEDATACUBE activeObject1p1;
	CUBEDATACUBE activeObject2p1;
	CUBEDATACUBE activeObject3p1;
	CUBEDATACUBE cubeTerainp1;
	
	CUBEDATACUBE activeObject1p2;
	CUBEDATACUBE activeObject2p2;
	CUBEDATACUBE activeObject3p2;
	CUBEDATACUBE cubeTerainp2;
	
	CUBEDATACUBE cubeData;
	
};


#endif







