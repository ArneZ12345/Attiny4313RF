#include "TinyDHT.h"
#include "Settings.h"
#include "Transmit.h"

DHT dht(DHTPIN, DHTTYPE);

void READ_VOLTAGE_1(){
voltagepin1 = digitalRead(READ_VOLTAGE_PIN_1);
voltagepin2 = digitalRead(READ_VOLTAGE_PIN_2);
}

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
    TRANSMIT_BUFFER[0] = t;
  }
  if (dipValue & (1 << 1)) {
    if(h != 255){
    TRANSMIT_BUFFER[1] = h;
  }
  }
  if (dipValue & (1 << 2)) {
    TRANSMIT_BUFFER[2] = voltagepin1;
  }
  if (dipValue & (1 << 3)) {
    TRANSMIT_BUFFER[3] = voltagepin2;
  }

sprintf(message, "%d,%d,%d,%d\r\n", TRANSMIT_BUFFER[0], TRANSMIT_BUFFER[1],
                                TRANSMIT_BUFFER[2], TRANSMIT_BUFFER[3]);
}