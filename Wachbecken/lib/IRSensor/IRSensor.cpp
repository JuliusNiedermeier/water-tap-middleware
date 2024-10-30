#include "IRSensor.h"

IRSensor::IRSensor(byte activatePin, byte deactivatePin)
{
    _activatePin = activatePin;
    _deactivatePin = deactivatePin;
}

void IRSensor::init()
{
    pinMode(_activatePin, INPUT);
    pinMode(_deactivatePin, INPUT);
}

void IRSensor::nextTick()
{
    if (activated && digitalRead(_deactivatePin))
    {
        activated = false;
        onDeactivate();
    }
    else if (!activated && digitalRead(_activatePin))
    {
        activated = true;
        onActivate();
    }
}