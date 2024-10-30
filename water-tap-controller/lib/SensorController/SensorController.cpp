#include "SensorController.h"

SensorController::SensorController(byte openPin, byte closePin)
{
    _openPin = openPin;
    _closePin = closePin;
}

void SensorController::begin()
{
    pinMode(_openPin, OUTPUT);
    pinMode(_closePin, OUTPUT);
}

bool SensorController::isActive()
{
    if (open == false && digitalRead(_openPin) == HIGH)
    {
        open = true;
    }
    else if (open == true && digitalRead(_closePin) == HIGH)
    {
        open = false;
    }

    return open;
}
