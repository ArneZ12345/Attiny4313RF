#include "Main.h"	
#include "TinyRF_TX.h"

void DHT_TRANSMIT_VALUES(){
  send((byte*)message, strlen(message)+1);
  delayMicroseconds(TX_DELAY_MICROS);
}