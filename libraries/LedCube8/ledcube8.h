// Autor: 									Alex Krieg
// Erstellt:								16.9.16
// Version 									5.0.0
// Kompatibel mit den versionen: 			*****
// Funktionen:								*****
// Hardware									Arduino Mega (2560)
// Hardware Cube 							Rev3

#ifndef LEDCUBE8_H
#define LEDCUBE8_H
#include "Arduino.h"
#include <Wire.h>

#define readFromSD

	struct CUBEDATACUBE
{
  byte CA8; 
  byte CB8; 
  byte CC8; 
  byte CD8; 
  byte CE8; 
  byte CF8; 
  byte CG8; 
  byte CH8;
  
  byte CA7; 
  byte CB7; 
  byte CC7; 
  byte CD7; 
  byte CE7; 
  byte CF7; 
  byte CG7; 
  byte CH7; 
  
  byte CA6; 
  byte CB6; 
  byte CC6; 
  byte CD6; 
  byte CE6; 
  byte CF6; 
  byte CG6; 
  byte CH6;
  
  
  byte CA5; 
  byte CB5; 
  byte CC5; 
  byte CD5; 
  byte CE5; 
  byte CF5; 
  byte CG5; 
  byte CH5; 
  
  byte CA4; 
  byte CB4; 
  byte CC4; 
  byte CD4; 
  byte CE4; 
  byte CF4; 
  byte CG4; 
  byte CH4; 
  
  byte CA3; 
  byte CB3; 
  byte CC3; 
  byte CD3; 
  byte CE3; 
  byte CF3; 
  byte CG3; 
  byte CH3; 
  
  byte CA2; 
  byte CB2; 
  byte CC2; 
  byte CD2; 
  byte CE2; 
  byte CF2; 
  byte CG2; 
  byte CH2; 
  
  byte CA1; 
  byte CB1; 
  byte CC1; 
  byte CD1; 
  byte CE1; 
  byte CF1; 
  byte CG1; 
  byte CH1; 
};


class LedCube8
{
	public:
		 LedCube8();
		 ~LedCube8();
		
		//------SD
		struct CUBEDATACUBE readSD();
		//------SD
		
		void rotate90(int count,struct CUBEDATACUBE data);
		void rotate(int count,struct CUBEDATACUBE data);
		void rotateUp(int count,struct CUBEDATACUBE data);
		
		struct CUBEDATACUBE getRotate90(int count,struct CUBEDATACUBE data);
		struct CUBEDATACUBE getRotate(int count,struct CUBEDATACUBE data);
		struct CUBEDATACUBE getRotateUp(int count,struct CUBEDATACUBE data);
		
		struct CUBEDATACUBE add(struct CUBEDATACUBE data1,struct CUBEDATACUBE data2); 
		struct CUBEDATACUBE subtract(struct CUBEDATACUBE data1,struct CUBEDATACUBE data2); 
		struct CUBEDATACUBE invert(struct CUBEDATACUBE data); 
		 
		 //-------------------EDITS----------------------
		struct CUBEDATACUBE getCube();
		struct CUBEDATACUBE getLayer(byte layer);
		struct CUBEDATACUBE getWall(byte wall);
		struct CUBEDATACUBE getWall90(byte wall);	
		struct CUBEDATACUBE getShiftCubeRight	(int count,bool reload, struct CUBEDATACUBE data);
		struct CUBEDATACUBE getShiftCubeLeft	(int count,bool reload, struct CUBEDATACUBE data);
		struct CUBEDATACUBE getShiftCubeRight90	(int count,bool reload, struct CUBEDATACUBE data);
		struct CUBEDATACUBE getShiftCubeLeft90	(int count,bool reload, struct CUBEDATACUBE data);								
		struct CUBEDATACUBE getShiftCubeUp		(int count,bool reload, struct CUBEDATACUBE data);
		struct CUBEDATACUBE getShiftCubeDown	(int count,bool reload, struct CUBEDATACUBE data);
	 
		 //----------------------------------------------
		void init();
		void drawCube(struct CUBEDATACUBE data);
	
		
		void drawLayer(byte layer);
		void drawWall(byte wall);
		void drawWall90(byte wall);	
		void shiftCubeRight		(int count,bool reload, struct CUBEDATACUBE data);
		void shiftCubeLeft		(int count,bool reload, struct CUBEDATACUBE data);
		void shiftCubeRight90	(int count,bool reload, struct CUBEDATACUBE data);
		void shiftCubeLeft90	(int count,bool reload, struct CUBEDATACUBE data);								
		void shiftCubeUp	(int count,bool reload, struct CUBEDATACUBE data);
		void shiftCubeDown	(int count,bool reload, struct CUBEDATACUBE data);
		
		void light(byte L);
		void rain(byte count,byte amount);
		void writeLayer(char text[],byte lenge,byte layer);
		
		void time(int t);
		void hackLight(bool status);
	
	private:
	    struct CUBEDATACUBE calculateRotate90(int count,struct CUBEDATACUBE data);
		struct CUBEDATACUBE calculateRotate(int count,struct CUBEDATACUBE data);
		struct CUBEDATACUBE calculateRotateUp(int count,struct CUBEDATACUBE data);
	
		struct CUBEDATACUBE calculateDrawLayer(byte layer);
		struct CUBEDATACUBE calculateDrawWall(byte wall);
		struct CUBEDATACUBE calculateDrawWall90(byte wall);		
		struct CUBEDATACUBE calculateShiftCubeRight		(int count,bool reload, struct CUBEDATACUBE data);
		struct CUBEDATACUBE calculateShiftCubeLeft		(int count,bool reload, struct CUBEDATACUBE data);
		struct CUBEDATACUBE calculateShiftCubeRight90	(int count,bool reload, struct CUBEDATACUBE data);
		struct CUBEDATACUBE calculateShiftCubeLeft90	(int count,bool reload, struct CUBEDATACUBE data);								
		struct CUBEDATACUBE calculateShiftCubeUp	(int count,bool reload, struct CUBEDATACUBE data);
		struct CUBEDATACUBE calculateShiftCubeDown	(int count,bool reload, struct CUBEDATACUBE data);
		
		
		void resetICs();
		void setICs(byte data1,byte data2,byte data3,byte data4,byte data5,byte data6,byte data7,byte data8,byte layer);
		
		byte IC_OE;
		byte IC_C2;
		byte IC_RESET;
		byte IC_C1;
		byte *IC_SERIAL;
		
		
		
		
		byte helligkeit;
		unsigned long Time;
		
		
		bool hackLightStatus;
		unsigned long startMillis;
		unsigned long referenzMillis;
		unsigned long benotigtMillis;
		
	   
};
#endif