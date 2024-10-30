#include "Speaker.h"

Speaker::Speaker(byte pin)
{
    _pin = pin;
}

void Speaker::init()
{
    pinMode(_pin, OUTPUT);
}

void Speaker::play(unsigned int frequency, unsigned int duration)
{
    tone(_pin, frequency, duration);
}