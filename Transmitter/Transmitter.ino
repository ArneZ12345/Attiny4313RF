#include "TinyRF_TX.h"
#include "TinyDHT.h"
#include "Main.h"
#include "Transmit.h"

void setup() {
  setupTransmitter();
  dht.begin();
}

void loop() {
  DHT_GET_VALUES();
  DHT_STRING_VALUES();
  DHT_TRANSMIT_VALUES();
}