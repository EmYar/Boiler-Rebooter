#include <Servo.h>
#include <LiquidCrystal.h>

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

constexpr uint8_t SERVO_DEFAULT_ANGLE = 90;
constexpr uint8_t SERVO_PRESS_BUTTON_ANGLE = 120;
constexpr uint8_t SERVO_MAX_ANGLE = 180;

constexpr uint8_t BRIGHTNESS_THRESHOLD = 300;

LiquidCrystal lcd(LCD_PIN_RS, LCD_PIN_EN, LCD_PIN_DB4, LCD_PIN_DB5, LCD_PIN_DB6, LCD_PIN_DB7);
Servo servo;

int attemptsCount = 0;

struct ButtonPresser {
  
};

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  servo.attach(SERVO_PIN);

  lcd.begin(16, 2);

  moveServo(SERVO_DEFAULT_ANGLE);
}

void loop() {
  if (checkHeaterAndUpdateLed()) {
    pressHeaterResetButton();
  } else {
    attemptsCount = 0;
  }

}

/**
  * Updates LED status. On — if if boiler needs to be restarted, off — overwise
  *
  * @returns true if boiler needs to be restarted 
**/
bool checkHeaterAndUpdateLed() {
  bool heaterLedIsOn = analogRead(POT_PIN) > BRIGHTNESS_THRESHOLD;
  digitalWrite(LED_PIN, heaterLedIsOn);
  return heaterLedIsOn;
}

void setScreenState() {
  
}

void pressHeaterResetButton() {
  if (attemptsCount == 3) {
    requestManualReset();
    return;
  }

  moveServo(SERVO_PRESS_BUTTON_ANGLE);
  moveServo(SERVO_DEFAULT_ANGLE);

  attemptsCount++;
  //playResetPressed();

  delay(10000);

  /*if (checkHeaterLedAndUpdateLed()) {
    pressHeaterResetButton();
  }*/
}

void requestManualReset() {

  tone(BUZZER_PIN, 3000, 250);
  tone(BUZZER_PIN, 3000, 250);
  tone(BUZZER_PIN, 3000, 250);
}

void moveServo(int angle) {
  angle = int(angle % SERVO_MAX_ANGLE);
  servo.write(angle);
  delay(250);
}








