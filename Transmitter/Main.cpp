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

void TRANSMIT_VALUES() {  
  int dipValue = DIPSWITCHES();

sprintf(hexString, "%X", dipValue);

sprintf(message, "%d,%d,%s,%d,%d\r\n", 
            t, h, hexString, voltagepin1, voltagepin2);
}