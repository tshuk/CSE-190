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

uint8_t val = 0;

void setup()
{
  Serial.begin(9600);  // Start up serial
  Serial1.begin(115200);
  rfBegin(13);  // Initialize ATmega128RFA1 radio on channel 11 (can be 11-26)
  
  // Send a message to other RF boards on this channel
  rfPrint("ATmega128RFA1 Dev Board Online!\r\n");
  Serial.print("setup complete\n");
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

/* Transmit loop
 * Send data as quickly as possible. Data is an 8-bit value val which is
 * initialized to 0 and increments after each message. The receiver should
 * track the values received and calculate the number of dropped packets
 * using the data values (i.e. receiving 10 then 12 implies packet 11 was lost).
 */
/*void loop()
{
  rfWrite(val);
  val++;
}*/

/* Receive loop
 *
 */
char tmpBuf[128];

void loop()
{
  if (rfAvailable())  // If data receievd on radio...
  {
    sprintf(tmpBuf, "Expected %i, received %i\n", val++, rfRead());
    Serial.print(tmpBuf);
  }
}
