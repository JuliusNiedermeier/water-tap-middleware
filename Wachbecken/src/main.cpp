#include <Arduino.h>
#include <IRSensor.h>
#include <Valve.h>
#include <Button.h>
#include <Speaker.h>

IRSensor sensor(2, 3);
Valve valve(4, 5);
Button button(6, 1000);
Speaker speaker(7);

void setup()
{
  Serial.begin(9600);

  sensor.init();
  valve.init();
  button.init();
  speaker.init();

  sensor.onActivate = []()
  {
    Serial.println("IR Sensor activated");
    if (!button.locked)
    {
      valve.open();
    }
  };

  sensor.onDeactivate = []()
  {
    Serial.println("IR Sensor deactivated");
    if (!button.enabled && !button.locked)
    {
      valve.close(3000);
    }
  };

  button.onEnable = []()
  {
    Serial.println("Button enabled");
    valve.open();
  };

  button.onDisable = []()
  {
    Serial.println("Button disabled");
    valve.close();
  };

  button.onLock = []()
  {
    Serial.println("Button locked");
    speaker.play();
  };

  button.onUnlock = []()
  {
    Serial.println("Button unlocked");
    speaker.play();
  };
}

void loop()
{
  sensor.nextTick();
  button.nextTick();
}