#include "Main.h"	
#include "TinyRF_TX.h"
#include "Settings.h"

void DHT_TRANSMIT_VALUES(){
    send((byte*)message, strlen(message)+1);
  delay(USER_DEF_DELAY);
}