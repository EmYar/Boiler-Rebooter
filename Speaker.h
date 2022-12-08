// Speaker.h
#ifndef Speaker_h
#define Speaker_h

#include <Arduino.h>

class Speaker {
  private:
    uint8_t pin;
    
  public:
    Speaker(uint8_t pin);
    void init();
    void playSoftResetSuccessful();
    void playHardResetRequest();
};

#endif