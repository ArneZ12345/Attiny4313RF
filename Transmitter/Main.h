#ifndef MAIN_H
#define MAIN_H

#include "TinyDHT.h"
extern DHT dht;

void DHT_GET_VALUES();
void DHT_STRING_VALUES();
void DHT_TRANSMIT_VALUES();

int DIPSWITCHES();

void CHECK_DIPSW();

#endif
  