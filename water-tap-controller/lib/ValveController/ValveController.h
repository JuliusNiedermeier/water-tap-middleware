#ifndef ValveController_h
#define ValveController_h
#include <Arduino.h>

class ValveController
{

public:
    ValveController(byte openPin, byte closePin);
    void begin();
    void open();
    void close(bool force = false);
    byte getOpenPin();
    byte getClosePin();

private:
    bool isOpen;
    byte _openPin;
    byte _closePin;
    void sendControlPulse(byte pin);
};

#endif