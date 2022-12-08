// ButtonPusher.h
#ifndef ButtonPusher_h
#define ButtonPusher_h

#include <Arduino.h>
#include <Servo.h>

class ButtonPusher {
  private:
    Servo servo;
    uint8_t servoDefaultAngle;
    uint8_t servoPushButtonAngle;
    uint8_t servoMaxAngle;

  public:
    ButtonPusher(uint8_t servoPin, uint8_t servoDefaultAngle, uint8_t servoPushButtonAngle, uint8_t servoMaxAngle);
    void pushButton();
};

#endif