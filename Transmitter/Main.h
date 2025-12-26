#ifndef MAIN_H
#define MAIN_H

#include "TinyDHT.h"
extern DHT dht;

void READ_VOLTAGE_1();
void DHT_GET_VALUES();
void DHT_TRANSMIT_VALUES();

int DIPSWITCHES();

void TRANSMIT_VALUES();

#endif
  