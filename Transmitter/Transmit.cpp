#include "Main.h"	
#include "TinyRF_TX.h"

void DHT_TRANSMIT_VALUES(){
  send((byte*)temp, strlen(temp));
  send((byte*)humid, strlen(humid));
  delayMicroseconds(TX_DELAY_MICROS);
  memset(temp, 0, sizeof(temp));
  memset(humid, 0, sizeof(humid));
}