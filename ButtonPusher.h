// ButtonPusher.h
#ifndef ButtonPusher_h
#define ButtonPusher_h

#include <Arduino.h>

class ButtonPusher {
  private:
    int pin;
    int maxAngle;
    

  public:
    ButtonPusher(int pin);
    void pushButton();
};

#endif