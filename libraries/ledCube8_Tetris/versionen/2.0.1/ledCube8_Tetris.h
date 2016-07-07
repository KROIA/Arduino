//==========================================LED CUBE TETRIS=================== 
// Autor: 									Alex Krieg
// Erstellt:								19.5.16
// Version 									2.0.1
// Kompatibel mit den versionen: 			ledCube9.h : 3.0.3 BUILD ARduino Mega(2560)
// Funktionen:								*****

//Nur Einzelspieler
//Ohne score anzeige


#ifndef LEDCUBE8_TETRIS_H
#define LEDCUBE8_TETRIS_H

#include "ledcube8.h"
#include "button.h"
#include <Wire.h>


class ledCube8_Tetris
{
	public:
	ledCube8_Tetris(byte pins[]);
	~ledCube8_Tetris();
	
	void run();
	
	void button1Player();
	void button2Player();
	void button3Player();
	void button4Player();
	
	                  
	Button *but1P;
	Button *but2P;
	Button *but3P;
	Button *but4P;

	
	private:
	void init();
	void calculate();
	bool checkForCollision(int mode);		// 1=down  2=left 3=right 4=rotation
	void checkForDelete();
	void send();
	void stop();
	
	
	
	LedCube8* cube;
	
	int shiftDownAmount;
	int shiftLeftAmount;
	int rotationAmount;
	int activeObjectA;
	int score;
	
	unsigned long startTime;
	unsigned long time;
	unsigned long shiftTime;
	
	
	CUBEDATACUBE objects[7];
	
	CUBEDATACUBE activeObject1;
	CUBEDATACUBE activeObject2;
	CUBEDATACUBE activeObject3;
	CUBEDATACUBE cubeTerain;
	CUBEDATACUBE cubeData;
	
};


#endif