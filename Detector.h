// Detector.h
#ifndef Detector_h
#define Detector_h

#include <Arduino.h>

class Detector {
  private:
    uint8_t potPin;
    uint8_t ledPin;

    uint8_t threshold;
    
  public:
    Detector(uint8_t potPin, uint8_t ledPin, uint8_t threshold);
    bool updateAndGetState();
};

#endif