#include "RadioFunctions.h"

uint8_t numPackets = 0;

void setup()
{
  Serial.begin(9600);  // Start up serial
  Serial1.begin(115200);
  rfBegin(13);  // Initialize ATmega128RFA1 radio on channel 13 (can be 11-26)
  
  Serial.print("setup complete\r\n");
}

char tmpBuf[128];

void loop()
{
  if (rfAvailable())  // If data receievd on radio...
  {
    numPackets++;
    sprintf(tmpBuf, "%u: Received %u at time %lu\r\n", numPackets, rfRead(), micros());
    Serial.print(tmpBuf);
  }
}
