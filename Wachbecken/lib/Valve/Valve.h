#ifndef Valve_h
#define Valve_h
#include <Arduino.h>

class Valve
{

public:
    Valve(byte openPin, byte closePin);
    void init();
    void open();
    void close(unsigned int lag = 0);

private:
    byte _openPin;
    byte _closePin;
    void sendControlPulse(byte pin);
};

#endif