#include "TinyRF_TX.h"
#include "TinyDHT.h"

#define DHTPIN 6

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // transmitter default pin is pin #2. You can change it by editing Settings.h
  setupTransmitter();
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

char temp[8];
char humid[8];
dtostrf(t, 3, 1,  temp);
dtostrf(h, 3, 1, humid);

  //const char* msg = "Test Hello World";
  //send function accepts an array of bytes as first argument
  //second argument is the length of the array
  //char msg[4];          // enough for -128 → 127 + null
  //sprintf(msg, "%d", t);
  //send((byte*)msg, strlen(msg));   // now strlen(msg) makes sense
  //char msg[8];
  //sprintf(msg, "%d", t);               // convert temp to string
  send((byte*)temp, strlen(temp));
  send((byte*)humid, strlen(humid));
  //send((byte*)t, strlen(t));
  //make sure there's at least a TX_DELAY_MICROS delay between transmissions
  //otherwise the receiver's behavior will be undefined
  delayMicroseconds(TX_DELAY_MICROS);
  //delay(2000);
}