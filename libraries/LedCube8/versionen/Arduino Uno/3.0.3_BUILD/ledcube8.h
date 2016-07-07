// Autor: 									Alex Krieg
// Erstellt:								13.5.16
// Version 									3.0.3 BUILD
// Kompatibel mit den versionen: 			3.0.0 BUILD
// Funktionen:								*****
// Hardware									Arduino Uno


#ifndef LEDCUBE8_H
#define LEDCUBE8_H
#include "Arduino.h"
	struct CUBEDATALAYER
{
  byte Layer;
  byte A; 
  byte B; 
  byte C; 
  byte D; 
  byte E; 
  byte F; 
  byte G; 
  byte H; 
};
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
	struct POS
{
  int X;
  int Y;
  int Z;
};


class LedCube8
{
	public:
		 LedCube8();
		 ~LedCube8();
		
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
			
		struct CUBEDATALAYER getShiftLayerRight  (int count,bool reload, struct CUBEDATALAYER data);
		struct CUBEDATALAYER getShiftLayerLeft   (int count,bool reload, struct CUBEDATALAYER data);
		struct CUBEDATALAYER getShiftLayerRight90(int count,bool reload, struct CUBEDATALAYER data);
		struct CUBEDATALAYER getShiftLayerLeft90 (int count,bool reload, struct CUBEDATALAYER data);
		struct CUBEDATALAYER getShiftLayerDown   (int count,bool reload, struct CUBEDATALAYER data);
		struct CUBEDATALAYER getShiftLayerUp 	(int count,bool reload, struct CUBEDATALAYER data);
		
		struct CUBEDATACUBE getShiftCubeRight	(int count,bool reload, struct CUBEDATACUBE data);
		struct CUBEDATACUBE getShiftCubeLeft	(int count,bool reload, struct CUBEDATACUBE data);
		struct CUBEDATACUBE getShiftCubeRight90	(int count,bool reload, struct CUBEDATACUBE data);
		struct CUBEDATACUBE getShiftCubeLeft90	(int count,bool reload, struct CUBEDATACUBE data);								
		struct CUBEDATACUBE getShiftCubeUp		(int count,bool reload, struct CUBEDATACUBE data);
		struct CUBEDATACUBE getShiftCubeDown	(int count,bool reload, struct CUBEDATACUBE data);
	 
		 //----------------------------------------------
		void init();
		void draw(struct CUBEDATALAYER data);
		void drawCube(struct CUBEDATACUBE data);
	
		
		void drawLayer(byte layer);
		void drawWall(byte wall);
		void drawWall90(byte wall);
		
		void shiftLayerRight    (int count,bool reload, struct CUBEDATALAYER data);
		void shiftLayerLeft    (int count,bool reload, struct CUBEDATALAYER data);
		void shiftLayerRight90  (int count,bool reload, struct CUBEDATALAYER data);
		void shiftLayerLeft90  (int count,bool reload, struct CUBEDATALAYER data);
		void shiftLayerDown (int count,bool reload, struct CUBEDATALAYER data);
		void shiftLayerUp 	(int count,bool reload, struct CUBEDATALAYER data);
		
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
			
		struct CUBEDATALAYER calculateShiftLayerRight    (int count,bool reload, struct CUBEDATALAYER data);
		struct CUBEDATALAYER calculateShiftLayerLeft    (int count,bool reload, struct CUBEDATALAYER data);
		struct CUBEDATALAYER calculateShiftLayerRight90  (int count,bool reload, struct CUBEDATALAYER data);
		struct CUBEDATALAYER calculateShiftLayerLeft90  (int count,bool reload, struct CUBEDATALAYER data);
		struct CUBEDATALAYER calculateShiftLayerDown (int count,bool reload, struct CUBEDATALAYER data);
		struct CUBEDATALAYER calculateShiftLayerUp 	(int count,bool reload, struct CUBEDATALAYER data);
				
		struct CUBEDATACUBE calculateShiftCubeRight		(int count,bool reload, struct CUBEDATACUBE data);
		struct CUBEDATACUBE calculateShiftCubeLeft		(int count,bool reload, struct CUBEDATACUBE data);
		struct CUBEDATACUBE calculateShiftCubeRight90	(int count,bool reload, struct CUBEDATACUBE data);
		struct CUBEDATACUBE calculateShiftCubeLeft90	(int count,bool reload, struct CUBEDATACUBE data);								
		struct CUBEDATACUBE calculateShiftCubeUp	(int count,bool reload, struct CUBEDATACUBE data);
		struct CUBEDATACUBE calculateShiftCubeDown	(int count,bool reload, struct CUBEDATACUBE data);
		
		
		
		
		
		
		
		
		byte countAddress();								//zählt "counter" um 1 hoch
		void setPin(byte pin, byte address);				//setzt pins bei den pins 2-9
		void saveToFlipFlop(byte address);					//setzt pins in Binär bei 10-13
		void setLayer(byte layer);	//setzt pins in Binär bei A0-A4
		
		byte *ledpin;
		byte *ledAddresspin;
		byte *layerpin;
		
		byte led;
		byte ledAddress;
		byte layerAddress;
		
		byte counter;
		byte helligkeit;
		unsigned long Time;
		
		
		bool hackLightStatus;
		unsigned long startMillis;
		unsigned long referenzMillis;
		unsigned long benotigtMillis;
		
	   
};
#endif