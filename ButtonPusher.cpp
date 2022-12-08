// ButtonPusher.cpp
#include "ButtonPusher.h"

ButtonPusher::ButtonPusher(uint8_t servoPin, int servoDefaultAngle, int servoPushButtonAngle) {
  this->servoDefaultAngle = servoDefaultAngle;
  this->servoPushButtonAngle = servoPushButtonAngle;

  servo.attach(servoPin, 0, 180);
  servo.write(servoDefaultAngle);
}

void ButtonPusher::pushButton() {
  servo.write(servoPushButtonAngle);
  delay(1000);
  servo.write(servoDefaultAngle);
  delay(1000);
}

int ButtonPusher::getCurrentAngle() {
  return servo.read();
}
