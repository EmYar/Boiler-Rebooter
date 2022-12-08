// ButtonPusher.cpp
#include "ButtonPusher.h"

ButtonPusher::ButtonPusher(uint8_t servoPin, int servoDefaultAngle, int servoPushButtonAngle, int servoMaxAngle) {
  servo.attach(servoPin);
  this->servoDefaultAngle = servoDefaultAngle;
  this->servoPushButtonAngle = servoPushButtonAngle;
  this->servoMaxAngle = servoMaxAngle;

  servo.write(servoDefaultAngle);
}

void ButtonPusher::pushButton() {
  servo.write(servoPushButtonAngle);
  delay(250);
  servo.write(servoDefaultAngle);
  delay(250);
}

int ButtonPusher::getCurrentAngle() {
  return servo.read();
}
