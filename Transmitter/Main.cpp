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
