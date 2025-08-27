#include "TinyDHT.h"
#include "Settings.h"
#include "Transmit.h"

DHT dht(DHTPIN, DHTTYPE);

void DHT_GET_VALUES() {
  h = dht.readHumidity();
  t = dht.readTemperature();
}

int DIPSWITCHES() {
  switchValue = 0;
  switchValue |= (!digitalRead(DIPPIN_1)) << 0;
  switchValue |= (!digitalRead(DIPPIN_2)) << 1;
  switchValue |= (!digitalRead(DIPPIN_3)) << 2;
  switchValue |= (!digitalRead(DIPPIN_4)) << 3;
  return switchValue;
}

void CHECK_DIPSW() {
  int dipValue = DIPSWITCHES();

  for (int i = 0; i < 4; i++) {
    TRANSMIT_BUFFER[i] = 0;
  }

  if (dipValue & (1 << 0)) {
    DHT_TRANSMIT_VALUES();
  }
  if (dipValue & (1 << 1)) {
    TRANSMIT_BUFFER[0] = (int)t;
  }
  if (dipValue & (1 << 2)) {
    TRANSMIT_BUFFER[1] = (int)h;
  }
  if (dipValue & (1 << 3)) {
  }
}

void EMBED_MESSAGE() {
  sprintf(message, "%d,%d,%d,%d", TRANSMIT_BUFFER[0], TRANSMIT_BUFFER[1],
          TRANSMIT_BUFFER[2], TRANSMIT_BUFFER[3]);
}