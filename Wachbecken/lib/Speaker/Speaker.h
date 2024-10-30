#ifndef Speaker_h
#define Speaker_h
#include <Arduino.h>

class Speaker
{

public:
    Speaker(byte pin);
    void init();
    void play(unsigned int frequency = 5000, unsigned int duration = 250);

private:
    byte _pin;
};

#endif