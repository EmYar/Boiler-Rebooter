#include "Detector.h"
#include "ButtonPusher.h"
#include "StateMonitor.h"
#include "DisplayRotateScreensButton.h"
#include "Speaker.h"

constexpr uint8_t POT_PIN = A0;

constexpr uint8_t LED_PIN = 2;

constexpr uint8_t BUZZER_PIN = 3;

constexpr uint8_t SERVO_PIN = 5;

constexpr uint8_t LCD_PIN_RS = 6;
constexpr uint8_t LCD_PIN_EN = 7;
constexpr uint8_t LCD_PIN_DB4 = 8;
constexpr uint8_t LCD_PIN_DB5 = 9;
constexpr uint8_t LCD_PIN_DB6 = 10;
constexpr uint8_t LCD_PIN_DB7 = 11;

constexpr uint8_t BUTTON_PIN = 13;

constexpr int SERVO_DEFAULT_ANGLE = 90;
constexpr int SERVO_PRESS_BUTTON_ANGLE = 120;

constexpr int BRIGHTNESS_THRESHOLD = 300;

constexpr uint8_t maxAttemptsCount = 3;

Detector boilerResetLedDetector(POT_PIN, LED_PIN, BRIGHTNESS_THRESHOLD);
ButtonPusher buttonPusher(SERVO_PIN, SERVO_DEFAULT_ANGLE, SERVO_PRESS_BUTTON_ANGLE);
StateMonitor stateMonitor(LCD_PIN_RS, LCD_PIN_EN, LCD_PIN_DB4, LCD_PIN_DB5, LCD_PIN_DB6, LCD_PIN_DB7, &boilerResetLedDetector);
DisplayRotateScreensButton displayRotateScreensButton(BUTTON_PIN, &stateMonitor);
Speaker speaker(BUZZER_PIN);

void setup() {
  boilerResetLedDetector.init();
  buttonPusher.init();
  stateMonitor.init();
  displayRotateScreensButton.init();
  speaker.init();
}

void loop() {
  if (boilerResetLedDetector.updateAndGetState()) {
    if (stateMonitor.isHardResetNeeded()) {
      stateMonitor.displayHardResetRequest();
      speaker.playHardResetRequest();
    } else {
      pressHeaterResetButton();
    }
  } else if (stateMonitor.isHardResetNeeded()) {
    stateMonitor.registerHardReset();
    stateMonitor.setHardResetNeeded(false);
    stateMonitor.displayStatusScreen();
  } else {
    stateMonitor.displayStatusScreen();
  }

  displayRotateScreensButton.processPush();

  delay(1000);
}

void pressHeaterResetButton() {
  for (uint8_t attemptNumber = 1; attemptNumber <= maxAttemptsCount; attemptNumber++) {
    stateMonitor.displayResetAttempt(attemptNumber);
    buttonPusher.pushButton();

    delay(15000);

    if (!boilerResetLedDetector.updateAndGetState()) {
      stateMonitor.registerSoftReset();
      speaker.playSoftResetSuccessful();
      stateMonitor.displayStatusScreen();
      return;
    }
  }

  stateMonitor.setHardResetNeeded(true);
}
