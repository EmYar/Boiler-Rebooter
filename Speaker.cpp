// Speaker.cpp

#include "Speaker.h"

Speaker::Speaker(uint8_t pin) {
  this->pin = pin;

  pinMode(pin, OUTPUT);
}

void Speaker::playSoftResetSuccessful() {
  tone(pin, 250, 250);
}

void Speaker::playHardResetRequest() {
  tone(pin, 3000, 500);
  tone(pin, 3000, 500);
  tone(pin, 3000, 500);
}