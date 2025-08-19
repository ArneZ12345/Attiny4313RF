#include "TinyRF_TX.h"
#include "TinyDHT.h"
#include "Main.h"
 

void setup() {
  setupTransmitter();
  dht.begin();
}

void loop() {
  DHT_GET_VALUES();
  dtostrf(t, 3, 1, temp);
  dtostrf(h, 3, 1, humid);
  send((byte*)temp, strlen(temp));
  send((byte*)humid, strlen(humid));
  delayMicroseconds(TX_DELAY_MICROS);
}