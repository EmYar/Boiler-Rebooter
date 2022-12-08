#include "Detector.h"
#include "StateMonitor.h"
#include "ButtonPusher.h"
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

constexpr uint8_t SERVO_DEFAULT_ANGLE = 90;
constexpr uint8_t SERVO_PRESS_BUTTON_ANGLE = 120;
constexpr uint8_t SERVO_MAX_ANGLE = 180;

constexpr uint8_t BRIGHTNESS_THRESHOLD = 300;

constexpr uint8_t maxAttemptsCount = 3;

Detector detector(POT_PIN, LED_PIN, BRIGHTNESS_THRESHOLD);
StateMonitor stateMonitor(LCD_PIN_RS, LCD_PIN_EN, LCD_PIN_DB4, LCD_PIN_DB5, LCD_PIN_DB6, LCD_PIN_DB7);
Speaker speaker(BUZZER_PIN);
ButtonPusher buttonPusher(SERVO_PIN, SERVO_DEFAULT_ANGLE, SERVO_PRESS_BUTTON_ANGLE, SERVO_MAX_ANGLE);

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  if (detector.updateAndGetState()) {
    pressHeaterResetButton();
  } else {
    if (stateMonitor.getAttemptNumber() == maxAttemptsCount) {
      stateMonitor.registerHardReset();
    }
    stateMonitor.resetAttemptNumber();
    stateMonitor.displayStatusScreen();
  }

  if (checkDisplayRotateButton()) {
    stateMonitor.rotateStatusScreens();
  }

  delay(1000);
}

void pressHeaterResetButton() {
  if (stateMonitor.getAttemptNumber() == maxAttemptsCount) {
    stateMonitor.displayManualResetRequest();
    speaker.playHardResetRequest();
    return;
  }

  buttonPusher.pushButton();
  stateMonitor.increaseAttemptNumber();

  delay(10000);

  if (detector.updateAndGetState()) {
    pressHeaterResetButton();
  } else {
    stateMonitor.registerSoftReset();
    speaker.playSoftResetSuccessful();
    stateMonitor.resetAttemptNumber();
  }
}

bool checkDisplayRotateButton() {
  if (!digitalRead(BUTTON_PIN)) {
    delay(10);
    if (!digitalRead(BUTTON_PIN)) {
      return true;
    }
  }
  return false;
}







