// Detector.h
#ifndef Detector_h
#define Detector_h

#include <Arduino.h>

class Detector {
  private:
    uint8_t potPin;
    uint8_t ledPin;

    int threshold;

    int brightness;
    
  public:
    Detector(uint8_t potPin, uint8_t ledPin, int threshold);
    void init();
    bool updateAndGetState();
    int getBrightness();
};

#endif