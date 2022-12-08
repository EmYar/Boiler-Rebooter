// ButtonPusher.h
#ifndef ButtonPusher_h
#define ButtonPusher_h

#include <Arduino.h>
#include <Servo.h>

class ButtonPusher {
  private:
    Servo servo;
    int servoDefaultAngle;
    int servoPushButtonAngle;
    int servoMaxAngle;

  public:
    ButtonPusher(uint8_t servoPin, int servoDefaultAngle, int servoPushButtonAngle, int servoMaxAngle);
    void pushButton();
    int getCurrentAngle();
};

#endif