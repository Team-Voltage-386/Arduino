/////////////////////////////////////////////////
// Modified from:     www.elegoo.com (2017.12.9)
// Modified for:      Team Voltage 386
// Date:              2025/05/16
/////////////////////////////////////////////////
#ifndef JOYSTICKSUBSYSTEM_H
#define JOYSTICKSUBSYSTEM_H

#include "Arduino.h"

class JoystickSubsystem
{
public:
  struct JoystickData {
    bool button;
    unsigned int x;
    unsigned int y;
  };

  JoystickSubsystem();
  JoystickData getData();
  void setup();
  void loop();

private:
  JoystickData joystickData;

  // Arduino pin numbers
  static const int SW_pin; // digital pin connected to switch output
  static const int X_pin; // analog pin connected to X output
  static const int Y_pin; // analog pin connected to Y output  
};

#endif
