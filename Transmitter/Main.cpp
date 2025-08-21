#include "TinyDHT.h"
#include "Settings.h"

DHT dht(DHTPIN, DHTTYPE);

void DHT_GET_VALUES(){
h = dht.readHumidity();
t = dht.readTemperature();
}

void DHT_STRING_VALUES(){
dtostrf(t, 3, 1, temp);
dtostrf(h, 3, 1, humid);
}

int DIPSWITCHES(){
  switchValue |= (!digitalRead(DIPPIN_1))<<0;
  switchValue |= (!digitalRead(DIPPIN_2))<<1;
  switchValue |= (!digitalRead(DIPPIN_2))<<2;
  switchValue |= (!digitalRead(DIPPIN_2))<<3;
  switchValue |= (!digitalRead(DIPPIN_2))<<4;
  return switchValue;
}

void CHECK_DIPSW(){
int dipValue = DIPSWITCHES();
switch(dipValue) {
  case 0:  
  break;
}   
}