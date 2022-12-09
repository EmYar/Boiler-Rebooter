// StateMonitor.h
#ifndef StateMonitor_h
#define StateMonitor_h

#include <Arduino.h>
#include <LiquidCrystal.h>
#include "Detector.h"
#include "ButtonPusher.h"

class StateMonitor {
  private:
    LiquidCrystal* lcd;

    uint8_t currentScreen = 0;
    const uint8_t lastScreen = 1;
    bool isScreenRotationEnabled = true;

    uint8_t attemptNumber = 0;

    uint16_t softRestarts = 0;
    uint16_t hardRestarts = 0;

    Detector* detector = nullptr;
    ButtonPusher* buttonPusher = nullptr;


  public:
    StateMonitor(
      uint8_t pinRs,
      uint8_t pinEn,
      uint8_t pinDb4,
      uint8_t pinDb5,
      uint8_t pinDb6,
      uint8_t pinDb7,
      Detector* detector
    );

    void init();

    void rotateStatusScreens();
    void displayStatusScreen();

    void increaseAttemptNumber();
    uint8_t getAttemptNumber() const;
    void resetAttemptNumber();

    void displayResetAttempt();
    void displayManualResetRequest();

    void registerSoftReset();
    void registerHardReset();
};

#endif