// DisplayRotateScreensButton.cpp

#include "DisplayRotateScreensButton.h"

DisplayRotateScreensButton::DisplayRotateScreensButton(uint8_t pin, StateMonitor* stateMonitor) {
  this->pin = pin;
  this->stateMonitor = stateMonitor;
}

void DisplayRotateScreensButton::init() {
  pinMode(pin, INPUT_PULLUP);
}

void DisplayRotateScreensButton::processPush() {
  if (!digitalRead(pin)) {
    delay(10);
    if (!digitalRead(pin)) {
      stateMonitor->rotateStatusScreens();
    }
  }
}