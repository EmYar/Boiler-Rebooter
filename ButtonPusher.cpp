// ButtonPusher.cpp
#include "ButtonPusher.h"

ButtonPusher::ButtonPusher(uint8_t servoPin, uint8_t servoDefaultAngle, uint8_t servoPushButtonAngle, uint8_t servoMaxAngle) {
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

