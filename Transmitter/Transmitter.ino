#include "TinyRF_TX.h"
#include "TinyDHT.h"
#include "Main.h"
 

void setup() {
  setupTransmitter();
  dht.begin();
}

void loop() {
  DHT_GET_VALUES();
  DHT_STRING_VALUES();
  send((byte*)temp, strlen(temp));
  send((byte*)humid, strlen(humid));
  delayMicroseconds(TX_DELAY_MICROS);
}