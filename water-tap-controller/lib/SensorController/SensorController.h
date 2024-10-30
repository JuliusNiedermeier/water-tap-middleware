#ifndef SensorController_h
#define SensorController_h
#include <Arduino.h>

class SensorController
{

public:
    SensorController(byte openPin, byte closePin);
    void begin();
    bool isActive();

private:
    byte _openPin;
    byte _closePin;
    bool open = false;
};

#endif