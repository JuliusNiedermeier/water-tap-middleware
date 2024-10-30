#include <Arduino.h>
#include "ValveController.h"
#include "SensorController.h"
#include "ButtonController.h"

SensorController sensor(2, 3);
ValveController valve(4, 5);
ButtonController button(6);

void setup()
{
  Serial.begin(9600);
  sensor.begin();
  valve.begin();
  button.begin();
}

void loop()
{

  // Wenn wasser angeht starte einen generellen Timer von 60 Sekunden, nachdem dann das Wasser in jedem Fall wieder abgestellt wird. Egal durch was es gestartet wurde. Resette den Button.
  if (button.getState() == ButtonStates::ON)
  {
    valve.open();
  }
  else if (button.getState() == ButtonStates::OFF)
  {

    if (sensor.isActive())
    {
      valve.open();
    }
    else
    {
      valve.close();
    }
  }
  else if (button.getState() == ButtonStates::LOCKED)
  {
    valve.close();
  }
}