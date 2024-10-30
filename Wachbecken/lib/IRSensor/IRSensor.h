#ifndef IRSensor_h
#define IRSensor_h
#include <Arduino.h>

class IRSensor
{

public:
    IRSensor(byte activatePin, byte deactivatePin);
    void init();
    void nextTick();
    void (*onActivate)();
    void (*onDeactivate)();

private:
    byte _activatePin;
    byte _deactivatePin;
    bool activated = false;
};

#endif