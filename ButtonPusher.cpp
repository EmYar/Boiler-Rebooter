// ButtonPusher.cpp
#include "ButtonPusher.h"

ButtonPusher::ButtonPusher(uint8_t pin, int servoDefaultAngle, int servoPushButtonAngle) {
  this->pin = pin;
  this->servoDefaultAngle = servoDefaultAngle;
  this->servoPushButtonAngle = servoPushButtonAngle;
}

void ButtonPusher::init() {
  servo.attach(pin);
  servo.write(servoDefaultAngle);
  delay(delayMs);
}

void ButtonPusher::pushButton() {
  servo.write(servoPushButtonAngle);
  delay(delayMs);
  servo.write(servoDefaultAngle);
  delay(delayMs);
}

int ButtonPusher::getCurrentAngle() {
  return servo.read();
}
