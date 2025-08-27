#include "TinyRF_TX.h"
#include "TinyDHT.h"
#include "Main.h"
//#include "Transmit.h"
#include "Settings.h"

void setup() {
  setupTransmitter();
  dht.begin();
  setupDIPSW();
}

void loop() {
  DHT_GET_VALUES();
  CHECK_DIPSW();
  EMBED_MESSAGE();
}