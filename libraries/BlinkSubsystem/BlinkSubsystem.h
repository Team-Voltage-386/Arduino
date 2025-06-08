/////////////////////////////////////////////////
// Modified from:     www.elegoo.com (2017.12.9)
// Modified for:      Team Voltage 386
// Date:              2025/05/16
/////////////////////////////////////////////////
#ifndef BLINKSUBSYSTEM_H
#define BLINKSUBSYSTEM_H

#include "Arduino.h"

// class BlinkSubsystem
class BlinkSubsystem
{
public:
  BlinkSubsystem();
  BlinkSubsystem(unsigned long interval);
  void setup();
  void loop();

private:
  unsigned long prevMillis;
  unsigned long currMillis;
  unsigned long blinkInterval;
  bool blinkState;
};

#endif
