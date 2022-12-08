// Detector.cpp
#include "Detector.h"

Detector::Detector(uint8_t potPin, uint8_t ledPin, int threshold) {
  this->potPin = potPin;
  this->ledPin = ledPin;
  this->threshold = threshold;
}

void Detector::init() {
  pinMode(ledPin, OUTPUT);
}

bool Detector::updateAndGetState() {
  brightness = analogRead(potPin);

  bool heaterLedIsOn = brightness >= threshold;
  digitalWrite(ledPin, heaterLedIsOn);

  return heaterLedIsOn;
}

int Detector::getBrightness() {
  return brightness;
}