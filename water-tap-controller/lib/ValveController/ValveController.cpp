#include "ValveController.h"

ValveController::ValveController(byte openPin, byte closePin)
{
    _openPin = openPin;
    _closePin = closePin;
}

void ValveController::begin()
{
    pinMode(_openPin, OUTPUT);
    pinMode(_closePin, OUTPUT);
    close(true);
}

void ValveController::sendControlPulse(byte pin)
{
    digitalWrite(pin, HIGH);
    delay(100);
    digitalWrite(pin, LOW);
}

void ValveController::open()
{
    if (!isOpen)
    {
        ValveController::sendControlPulse(_openPin);
        isOpen = true;
    }
}

void ValveController::close(bool force)
{
    if (force || isOpen)
    {
        ValveController::sendControlPulse(_closePin);
        isOpen = false;
    }
}

byte ValveController::getOpenPin()
{
    return _openPin;
}

byte ValveController::getClosePin()
{
    return _closePin;
}