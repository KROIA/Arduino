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
	
	void button1();
	void button2();
	void button3();
	void button4();
	void button5();
	void button6();
	void button7();
	void button8();

	                  
	Button *but1;
	Button *but2;
	Button *but3;
	Button *but4;
	Button *but5;
	Button *but6;
	Button *but7;
	Button *but8;
	
	private:
	
	LiquidCrystal_I2C   *p_lcd;
	
	void init();
	void calculate();
	bool checkForCollision(int mode, int rotateMode);		// 1=down  2=left 3=right 4=rotation 5=Y+ 6=Y-
	void checkForDelete();
	void send();
	void stop();
	
	
	
	LedCube8* cube;
	
	int shiftDownAmount;
	int shiftLeftAmount;
	int shiftYAmount;
	int rotationXAmount;
	int rotationYAmount;
	int rotationZAmount;
	int activeObjectA;
	int score;
	

	
	unsigned long startTime;
	unsigned long time;
	unsigned long shiftTime;
	
	bool playerIsDeath;

	
	
	CUBEDATACUBE objects[7];
	
	CUBEDATACUBE activeObject1;
	CUBEDATACUBE activeObjectOnlyRotate;
	CUBEDATACUBE activeObject2;
	CUBEDATACUBE activeObject3;
	CUBEDATACUBE cubeTerain;
	
	
	CUBEDATACUBE cubeData;
	
};


#endif







