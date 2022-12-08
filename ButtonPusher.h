// ButtonPusher.h
#ifndef ButtonPusher_h
#define ButtonPusher_h

#include <Arduino.h>
#include <Servo.h>

class ButtonPusher {
  private:
    Servo servo;
    uint8_t pin;
    int servoDefaultAngle;
    int servoPushButtonAngle;
    const uint16_t delayMs = 500;

  public:
    ButtonPusher(uint8_t pin, int servoDefaultAngle, int servoPushButtonAngle);
    void init();
    void pushButton();
    int getCurrentAngle();
};

#endif