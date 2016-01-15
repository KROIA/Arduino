/*!
    @file     bleuart_cmdmode.ino
    @author   hathach, ktown (Adafruit Industries)

    This demo will show you how to send and receive data in COMMAND mode 
    (without needing to put the module into DATA mode or using the MODE pin)
*/
#include <string.h>
#include <Arduino.h>
#include <SPI.h>
#include <SoftwareSerial.h>

#include "Adafruit_BLE.h"
#include "Adafruit_BLE_HWSPI.h"
#include "Adafruit_BluefruitLE_UART.h"

// If you are using Software Serial....
// The following macros declare the pins used for SW serial, you should
// use these pins if you are connecting the UART Friend to an UNO
#define BLUEFRUIT_SWUART_RXD_PIN        9    // Required for software serial!
#define BLUEFRUIT_SWUART_TXD_PIN        10   // Required for software serial!
#define BLUEFRUIT_UART_CTS_PIN          11   // Required for software serial!
#define BLUEFRUIT_UART_RTS_PIN          -1   // Optional, set to -1 if unused

// If you are using Hardware Serial
// The following macros declare the Serial port you are using. Uncomment this
// line if you are connecting the BLE to Leonardo/Micro or Flora
#define BLUEFRUIT_HWSERIAL_NAME           Serial1

// Other recommended pins!
#define BLUEFRUIT_UART_MODE_PIN         12   // Optional but recommended, set to -1 if unused

// Sketch Settings
#define BUFSIZE                         128   // Read buffer size for incoming data
#define VERBOSE_MODE                    true  // Enables full debug output is 'true'

/* Create the bluefruit object, either software serial... */

//SoftwareSerial bluefruitSS = SoftwareSerial(BLUEFRUIT_SWUART_TXD_PIN, BLUEFRUIT_SWUART_RXD_PIN);

//Adafruit_BluefruitLE_UART ble(bluefruitSS, BLUEFRUIT_UART_MODE_PIN,
//                      BLUEFRUIT_UART_CTS_PIN, BLUEFRUIT_UART_RTS_PIN);

/* ...or hardware serial, which does not need the RTS/CTS pins. Uncomment this line */
Adafruit_BluefruitLE_UART ble(BLUEFRUIT_HWSERIAL_NAME, BLUEFRUIT_UART_MODE_PIN);


// A small helper
void error(const __FlashStringHelper*err) {
  Serial.println(err);
  while (1);
}

/**************************************************************************/
/*!
    @brief  Sets up the HW an the BLE module (this function is called
            automatically on startup)
*/
/**************************************************************************/
void setup(void)
{
  while (!Serial);  // required for Flora & Micro
  delay(500);

  Serial.begin(115200);
  Serial.println(F("Adafruit Bluefruit Command Mode Example"));
  Serial.println(F("---------------------------------------"));

  /* Initialise the module */
  Serial.print(F("Initialising the Bluefruit LE module: "));
  if ( !ble.begin(VERBOSE_MODE) )
  {
    error(F("Couldn't find Bluefruit, make sure it's in CoMmanD mode & check wiring?"));
  }
  Serial.println( F("OK!") );

  /* Perform a factory reset to make sure everything is in a known state */
  Serial.print(F("Performing a factory reset: "));
  if (! ble.factoryReset() ){
       error(F("Couldn't factory reset"));
  }

  /* Disable command echo from Bluefruit */
  ble.echo(false);

  Serial.println("Requesting Bluefruit info:");
  /* Print Bluefruit information */
  ble.info();

  Serial.println(F("Please use Adafruit Bluefruit LE app to connect in UART mode"));
  Serial.println(F("Then Enter characters to send to Bluefruit"));
  Serial.println();
  
  ble.verbose(false);  // debug info is a little annoying after this point!
  
  /* Wait for connection */
  while (! ble.isConnected()) {
      delay(500);
  }
  
  Serial.println(F("*****************"));
}

/**************************************************************************/
/*!
    @brief  Constantly poll for new command or response data
*/
/**************************************************************************/
void loop(void)
{
  // Check for user input
  char inputs[BUFSIZE+1];
  
  if ( getUserInput(inputs, BUFSIZE) )
  {
    // Send characters to Bluefruit
    Serial.print("[Send] ");
    Serial.println(inputs);
    
    ble.print("AT+BLEUARTTX=");
    ble.println(inputs);

    // check response stastus
    if (! ble.waitForOK() ) {
      Serial.println(F("Failed to send?"));
    }
  }
  
  // Check for incoming characters from Bluefruit
  ble.println("AT+BLEUARTRX");
  ble.readline(100);  // 100ms timeout
  if (strcmp(ble.buffer, "OK") == 0) {
    // no data
    return;
  } 
  // Some data was found, its in the buffer
  Serial.print(F("[Recv] ")); Serial.println(ble.buffer);
  ble.waitForOK();
}

/**************************************************************************/
/*!
    @brief  Checks for user input (via the Serial Monitor)
*/
/**************************************************************************/
bool getUserInput(char buffer[], uint8_t maxSize)
{
  // timeout in 100 milliseconds
  TimeoutTimer timeout(100);

  memset(buffer, 0, maxSize);
  while( (Serial.peek() < 0) && !timeout.expired() ) {}

  if ( timeout.expired() ) return false;

  delay(2);
  uint8_t count=0;
  do
  {
    count += Serial.readBytes(buffer+count, maxSize);
    delay(2);
  } while( (count < maxSize) && !(Serial.peek() < 0) );

  return true;
}
