#include "Button.h"

Button::Button(byte pin, unsigned int lockDelay)
{
    _pin = pin;
    _lockDelay = lockDelay;
}

void Button::init()
{
    pinMode(_pin, INPUT);
}

void Button::nextTick()
{
    if (pressed != digitalRead(_pin))
    {
        pressed = !pressed;

        if (pressed)
        {
            millisAtPush = millis();
        }
        else if (!locked && !lockDelayElapsed)
        {
            enabled = !enabled;
            if (enabled)
            {
                onEnable();
            }
            else
            {
                onDisable();
            }
        }

        lockDelayElapsed = false;
    }

    if (!lockDelayElapsed && pressed && millis() - millisAtPush > _lockDelay)
    {
        lockDelayElapsed = true;
        locked = !locked;

        if (locked)
        {
            onLock();
            enabled = false;
            onDisable();
        }
        else
        {
            onUnlock();
        }
    }
}