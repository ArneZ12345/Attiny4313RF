#include "TinyRF_TX.h"
#include "TinyDHT.h"
#include "Main.h"
//#include "Transmit.h"
#include "Settings.h"

void setup() {
  setupTransmitter();
  dht.begin();
  setupDIPSW();
  setupVOLTAGEPIN();
}

void loop() {
  READ_VOLTAGE_1();
  DHT_GET_VALUES();
  CHECK_DIPSW();
}