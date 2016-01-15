int led[14] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13};
int layer[6] = {A0,A1,A2,A3,A4,A5};
byte d = B11111111;  //c Steht für die pins 2-9 die gesetzt werden sollen
byte e = B1001;
byte f = B1111;
byte counter = B00000000;
void setup() {
 for(int i=0; i<14; i++)
 {
   pinMode(led[i],OUTPUT);
 }
  for(int i=0; i<6; i++)
 {
    pinMode(layer[i],OUTPUT);
 }
 Serial.begin(9600);
 digitalWrite(led[8],HIGH);
}

void loop() 
{
  
writePins(d);
writeAddress(e);
writeLayer(f);
Serial.println("hi");
//count();
}

void writePins(byte c)
{
  PORTB = (PORTB & B00000011) | ((c&B11000000)>>6);                        //Setzt die pins 8-9
  PORTD = (PORTB & B00000011) | c;                                         //Setzt die pins 2-7
}
void writeAddress(byte c)
{
  PORTB = (PORTB & B000011) | (c << 2);                                   //Setzt die pins 10-13
}
void writeLayer(byte c)
{
  PORTC = (PORTB & B110000) |c;                                         //Setzt die pins A0-A3
}

void count()
{
  Serial.println(counter,BIN);
  counter = counter + B00000001;
  delay(500);
}
