#ifndef ButtonController_h
#define ButtonController_h
#include <Arduino.h>

enum ButtonStates : byte
{
    OFF,
    ON,
    LOCKED,
};

class ButtonController
{

public:
    ButtonController(byte pin);
    void begin();
    ButtonStates getState();
    void resetState();

private:
    byte _pin;
    ButtonStates state = ButtonStates::OFF;
    bool canUnlock = false;
    bool pressed = false;
    unsigned long millisAtPressDown = 0;
    unsigned long millisSincePressDown = 0;
};

#endif