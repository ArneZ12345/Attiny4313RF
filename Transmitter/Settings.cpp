#include <Arduino.h>
#include "Settings.h"

  char temp[8];
  char humid[8];
  float h;
  float t;
  int switchValue;

void setupDIPSW(){
pinMode(DIPPIN_1, INPUT_PULLUP);
pinMode(DIPPIN_2, INPUT_PULLUP);
pinMode(DIPPIN_3, INPUT_PULLUP);
pinMode(DIPPIN_4, INPUT_PULLUP);
pinMode(DIPPIN_5, INPUT_PULLUP);
}