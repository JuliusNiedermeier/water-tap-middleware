#ifndef Button_h
#define Button_h
#include <Arduino.h>

class Button
{
public:
    Button(byte pin, unsigned int lockDelay = 1000);
    void init();
    void nextTick();
    void (*onEnable)();
    void (*onDisable)();
    void (*onLock)();
    void (*onUnlock)();
    bool enabled = false;
    bool locked = false;

private:
    byte _pin;
    unsigned int _lockDelay;
    bool pressed = false;
    bool lockDelayElapsed = false;
    unsigned long millisAtPush;
};

#endif