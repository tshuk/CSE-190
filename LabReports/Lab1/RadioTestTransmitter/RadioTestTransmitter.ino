#include "RadioFunctions.h"

uint8_t numPackets = 0;

void setup()
{
  Serial.begin(9600);  // Start up serial
  Serial1.begin(115200);
  rfBegin(13);  // Initialize ATmega128RFA1 radio on channel 13 (can be 11-26)
  
  Serial.print("setup complete\r\n");
}

/* Transmit loop
 * Send 100 data packets as quickly as possible.
 * Data is the packet number.
 */
void loop()
{
  if (numPackets < 100)
  {
    numPackets++;
    rfWrite(numPackets);
  }
}
