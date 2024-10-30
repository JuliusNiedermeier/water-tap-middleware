#include "Valve.h"

Valve::Valve(byte openPin, byte closePin)
{
    _openPin = openPin;
    _closePin = closePin;
}

void Valve::init()
{
    pinMode(_openPin, OUTPUT);
    pinMode(_closePin, OUTPUT);
    close();
}

void Valve::open()
{
    sendControlPulse(_openPin);
}

void Valve::close(unsigned int lag)
{
    delay(lag);
    sendControlPulse(_closePin);
}

void Valve::sendControlPulse(byte pin)
{
    digitalWrite(pin, HIGH);
    delay(100);
    digitalWrite(pin, LOW);
}