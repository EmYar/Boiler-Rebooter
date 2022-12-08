// StateMonitor.h
#ifndef StateMonitor_h
#define StateMonitor_h

#include <Arduino.h>
#include <LiquidCrystal.h>

class StateMonitor {
  private:
    LiquidCrystal* lcd;

    uint8_t currentScreen = 0;
    const uint8_t lastScreen = 1;

    uint8_t attemptNumber = 0;

    uint8_t softRestarts = 0;
    uint8_t hardRestarts = 0;

    uint8_t currentBrightness = 0;

  public:
    StateMonitor(uint8_t pinRs, uint8_t pinEn, uint8_t pinDb4, uint8_t pinDb5, uint8_t pinDb6, uint8_t pinDb7);

    void rotateStatusScreens();

    void increaseAttemptNumber();
    uint8_t getAttemptNumber();
    void resetAttemptNumber();

    void displayResetAttempt();
    void displayManualResetRequest();
};

#endif