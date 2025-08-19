#include "TinyDHT.h"
#include "Settings.h"

DHT dht(DHTPIN, DHTTYPE);

DHT_GET_VALUES(){
h = dht.readHumidity();
t = dht.readTemperature();
}
