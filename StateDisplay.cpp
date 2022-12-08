// StateDisplay.cpp
#include "StateDisplay.h"

StateDisplay::StateDisplay(uint8_t pinRs, uint8_t pinEn, uint8_t pinDb4, uint8_t pinDb5, uint8_t pinDb6, uint8_t pinDb7) {
  lcd = new LiquidCrystal(pinRs, pinEn, pinDb4, pinDb5, pinDb6, pinDb7);
  lcd->clear();
}

void StateDisplay::rotateStatusScreens() {
  if (++currentScreen == lastScreen) {
    currentScreen = 0;
  }

  lcd->clear();
  lcd->setCursor(0, 0);

  switch (currentScreen) {
    case 0:
      auto uptimeMs = millis();
      // time in "hh:mm:ss" format
      lcd->print(uptimeMs / 3600000);
      lcd->print(":");
      lcd->print(uptimeMs / 60000);
      lcd->print(":");
      lcd->print((uptimeMs / 1000) % 60);
      // resets stats in "Sft:00,Hrd:00" format
      lcd->setCursor(0, 1);
      lcd->print("Sft:");
      lcd->print(softRestarts);
      lcd->print(",Hrd:");
      lcd->print(hardRestarts);
      break;
    case 1:
      lcd->print("Current brt");
      lcd->print(currentBrightness);
      break;
  }
}

void StateDisplay::displayResetAttempt() {
  lcd->clear();
  lcd->setCursor(0, 0);

  lcd->println("Trying to reset");
  lcd->print("the boiler..");
  lcd->print(tryNumber);
 }