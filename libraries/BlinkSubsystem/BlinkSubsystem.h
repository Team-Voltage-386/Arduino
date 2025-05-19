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
  unsigned long prevBlinkMillis;
  unsigned long currBlinkMillis;
  unsigned long blinkInterval;
  bool blinkState;
};

#endif
