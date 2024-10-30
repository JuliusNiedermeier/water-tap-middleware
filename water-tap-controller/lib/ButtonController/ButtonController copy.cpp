#include "ButtonController.h"

ButtonController::ButtonController(byte pin)
{
    _pin = pin;
}

void ButtonController::begin()
{
    pinMode(_pin, OUTPUT);
}

ButtonStates ButtonController::getState()
{
    pressed = digitalRead(_pin);

    if (pressed)
    {
        if (millisAtPressDown == 0)
        {
            millisAtPressDown = millis();
        }

        millisSincePressDown = millis() - millisAtPressDown;

        if (millisSincePressDown > 1000)
        {

            if (!canUnlock && state != ButtonStates::LOCKED)
            {
                state = ButtonStates::LOCKED;
            }
            else if (canUnlock && state == ButtonStates::LOCKED)
            {
                state = ButtonStates::OFF;
            }
        }
    }

    if (!pressed)
    {
        if (millisSincePressDown > 0)
        {
            if (state == ButtonStates::OFF)
            {
                if (canUnlock)
                {
                    canUnlock = false;
                }
                else
                {
                    state = ButtonStates::ON;
                }
            }
            else if (state == ButtonStates::ON)
            {
                state = ButtonStates::OFF;
            }
            else if (state == ButtonStates::LOCKED)
            {
                canUnlock = true;
            }

            millisAtPressDown = 0;
            millisSincePressDown = 0;
        }
    }

    return state;
}

void ButtonController::resetState()
{
    state = ButtonStates::OFF;
}