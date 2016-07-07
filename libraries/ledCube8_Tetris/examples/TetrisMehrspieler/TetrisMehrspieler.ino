#include <Wire.h>
#include "button.h"
#include "ledcube8.h"
#include "ledCube8_Tetris.h"
#include <LiquidCrystal_I2C.h>

//byte pins[12] = {2,3,4,5,6,7,8,9,10,11,12,13};
byte pins[12] =   {29,27,28,26,25,23,24,22};
ledCube8_Tetris game(pins);
void setup() {
Serial.begin(9600);



  game.but1P1->OnPressedEdge(button1Player1);
  game.but2P1->OnPressedEdge(button2Player1);
  game.but3P1->OnPressedEdge(button3Player1);
  game.but4P1->OnPressedEdge(button4Player1);
  
  game.but1P2->OnPressedEdge(button1Player2);
  game.but2P2->OnPressedEdge(button2Player2);
  game.but3P2->OnPressedEdge(button3Player2);
  game.but4P2->OnPressedEdge(button4Player2);


}
void loop()
{
  game.run();
}
void button1Player1()
{
  game.button1Player1();
 // game.button1Player2();
}
void button2Player1()
{
  game.button2Player1();
 // game.button2Player2();
}
void button3Player1()
{
  game.button3Player1();
 // game.button3Player2();
}
void button4Player1()
{
  game.button4Player1();
 // game.button4Player2();
}




//==================P2=====================
void button1Player2()
{
  game.button1Player2();
}
void button2Player2()
{
  game.button2Player2();
}
void button3Player2()
{
  game.button3Player2();
}
void button4Player2()
{
  game.button4Player2();
}
/*void button5Player2()
{
  game.button5Player2();
}
void button6Player2()
{
  game.button6Player2();
}
//========================================*/