// StateMonitor.cpp
#include "StateMonitor.h"

StateMonitor::StateMonitor(
      uint8_t pinRs,
      uint8_t pinEn,
      uint8_t pinDb4,
      uint8_t pinDb5,
      uint8_t pinDb6,
      uint8_t pinDb7,
      Detector* detector
) {
  lcd = new LiquidCrystal(pinRs, pinEn, pinDb4, pinDb5, pinDb6, pinDb7);
  this->detector = detector;
}

void StateMonitor::init() {
  lcd->begin(16, 2);
  lcd->clear();
}

void StateMonitor::rotateStatusScreens() {
  if (!isScreenRotationEnabled) {
    return;
  }

  if (++currentScreen > lastScreen) {
    currentScreen = 0;
  }

  displayStatusScreen();
}

void StateMonitor::displayStatusScreen() {
  lcd->clear();
  lcd->setCursor(0, 0);

  isScreenRotationEnabled = true;

  if (currentScreen == 0) {
      auto uptimeMs = millis();
      // time in "hh:mm:ss" format
      lcd->print("Uptime:");
      lcd->print(uptimeMs / 3600000);
      lcd->print(":");
      lcd->print((uptimeMs / 60000) % 60);
      lcd->print(":");
      lcd->print((uptimeMs / 1000) % 60);
      // resets stats in "Sft:00,Hrd:00" format
      lcd->setCursor(0, 1);
      lcd->print("Sft:");
      lcd->print(softRestarts);
      lcd->print(",Hrd:");
      lcd->print(hardRestarts);
  } else if (currentScreen == 1) {
      lcd->print("Brightness");
      lcd->setCursor(0, 1);
      lcd->print(detector->getBrightness());
  }
}

void StateMonitor::increaseAttemptNumber() {
  attemptNumber++;
}

uint8_t StateMonitor::getAttemptNumber() const {
  return attemptNumber;
}

void StateMonitor::resetAttemptNumber() {
  attemptNumber = 0;
}

void StateMonitor::displayResetAttempt() {
  lcd->clear();
  lcd->setCursor(0, 0);

  isScreenRotationEnabled = false;

  lcd->print("Trying to reset");
  lcd->setCursor(0, 1);
  lcd->print("the boiler..");
  lcd->print(attemptNumber + 1);
 }

 void StateMonitor::displayManualResetRequest() {
  lcd->clear();
  lcd->setCursor(0, 0);

  isScreenRotationEnabled = false;

  lcd->print("Failed to reset");
  lcd->setCursor(0, 1);
  lcd->print("Unplug a boiler");
 }

void StateMonitor::registerSoftReset() {
  softRestarts++;
}

 void StateMonitor::registerHardReset() {
  hardRestarts++;   
}