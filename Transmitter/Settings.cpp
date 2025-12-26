#include <Arduino.h>
#include "Settings.h"


  int h;
  int t;
  int switchValue;
  char message[32];
  char hexString[10];
  int voltagepin1;
  int voltagepin2;

void setupDIPSW(){
pinMode(DIPPIN_1, INPUT_PULLUP);
pinMode(DIPPIN_2, INPUT_PULLUP);
pinMode(DIPPIN_3, INPUT_PULLUP);
pinMode(DIPPIN_4, INPUT_PULLUP);
}

void setupVOLTAGEPIN(){
  pinMode(READ_VOLTAGE_PIN_1, INPUT_PULLUP);
  pinMode(READ_VOLTAGE_PIN_2, INPUT_PULLUP);
}