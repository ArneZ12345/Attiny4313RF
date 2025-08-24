#include "TinyDHT.h"
#include "Settings.h"
#include "Transmit.h"

DHT dht(DHTPIN, DHTTYPE);

void DHT_GET_VALUES(){
h = dht.readHumidity();
t = dht.readTemperature();
}

void DHT_STRING_VALUES(){
//dtostrf(t, 3, 1, temp);
//dtostrf(h, 3, 1, humid);
}

int DIPSWITCHES(){
  switchValue = 0;
  switchValue |= (!digitalRead(DIPPIN_1))<<0;
  switchValue |= (!digitalRead(DIPPIN_2))<<1;
  switchValue |= (!digitalRead(DIPPIN_3))<<2;
  switchValue |= (!digitalRead(DIPPIN_4))<<3;
  return switchValue;
}

void CHECK_DIPSW(){
int dipValue = DIPSWITCHES();
if (dipValue & (1<<0)){
DHT_TRANSMIT_VALUES();
}
if (dipValue & (1<<1)){
dtostrf(t, 3, 1, temp);
}
if (dipValue & (1<<2)){
dtostrf(h, 3, 1, humid);
} 
if (dipValue & (1<<3)){
  
}  
}