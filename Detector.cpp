// Detector.cpp
#include "Detector.h"

Detector::Detector(uint8_t potPin, uint8_t ledPin, uint8_t threshold) {
  this->potPin = potPin;
  this->ledPin = ledPin;
  this->threshold = threshold;

  pinMode(ledPin, OUTPUT);
}

bool Detector::updateAndGetState() {
  bool heaterLedIsOn = analogRead(potPin) > threshold;
  digitalWrite(ledPin, heaterLedIsOn);
  return heaterLedIsOn;
}