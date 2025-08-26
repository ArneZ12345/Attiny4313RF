#include <Arduino.h>
#include "Settings.h"

  char temp[8];
  char humid[8];
  float h;
  float t;
  int switchValue;
  bool SWITCH_ON;
  int TRANSMIT_BUFFER[4] = {0, 0, 0, 0};
  char message[32];

void setupDIPSW(){
pinMode(DIPPIN_1, INPUT_PULLUP);
pinMode(DIPPIN_2, INPUT_PULLUP);
pinMode(DIPPIN_3, INPUT_PULLUP);
pinMode(DIPPIN_4, INPUT_PULLUP);
}