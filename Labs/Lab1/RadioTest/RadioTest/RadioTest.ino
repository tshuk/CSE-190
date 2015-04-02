/*
  ATmega128RFA1 Dev Board Basic Chat
  by: Jim Lindblom
      SparkFun Electronics
  date: July 3, 2012
  License: Beerware. Feel free to use, reuse, and modify this code
  as you please. If you find it useful, you can buy me a beer.

  This code sets up the ATmega128RFA1's wireless transciever in
  the most basic way possible to serve as a serial gateway.
  Serial into the ATmega128RFA1's UART0 will go out the RF radio.
  Data into the RF radio will go out the MCU's UART0.
*/

#include "RadioFunctions.h"

uint8_t numPackets = 0;

void setup()
{
  Serial.begin(9600);  // Start up serial
  Serial1.begin(115200);
  rfBegin(13);  // Initialize ATmega128RFA1 radio on channel 11 (can be 11-26)
  
  // Send a message to other RF boards on this channel
  //rfPrint("ATmega128RFA1 Dev Board Online!\r\n");
  Serial.print("setup complete\r\n");
  
  // single frame transmission test
  uint8_t testFrame[126];
  for(int i = 0; i < 126; i++)
  {
    testFrame[i] = i % 10;
  }
  
  rfWriteFrame(&testFrame[0]);
}

/* Original BasicChat loop
 */
/*void loop()
{
  
  if (Serial.available())  // If serial comes in...
  {
    rfWrite(Serial.read()); // ...send it out the radio.
  }
  if (rfAvailable())  // If data receievd on radio...
  {
    Serial.print(rfRead());  // ... send it out serial.
  }
}*/

/* Idle loop for tests run in setup.
 */
void loop()
{
  
}

/* Transmit loop
 * Send 100 data packets as quickly as possible.
 * Data is the current time as given by millis().
 */
/*void loop()
{
  if (numPackets < 100)
  {
    rfWrite(millis());
    numPackets++;
    Serial.print(numPackets + "\r\n");
  }
}*/

/* Receive loop
 *
 */
/*char tmpBuf[128];

void loop()
{
  if (rfAvailable())  // If data receievd on radio...
  {
    numPackets++;
    sprintf(tmpBuf, "%u: Received %u at time %u\r\n", numPackets, rfRead(), millis());
    Serial.print(tmpBuf);
  }
}*/
