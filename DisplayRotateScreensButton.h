// DisplayRotateScreensButton.h

#ifndef DisplayRotateScreensButton_h
#define DisplayRotateScreensButton_h

#include <Arduino.h>
#include "StateMonitor.h"

class DisplayRotateScreensButton {
  private:
    uint8_t pin;
    StateMonitor* stateMonitor;

  public:
    DisplayRotateScreensButton(uint8_t pin, StateMonitor* stateMonitor);
    void init();
    void processPush();
};

#endif