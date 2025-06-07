/////////////////////////////////////////////////
// Modified from:     www.elegoo.com (2017.12.9)
// Modified for:      Team Voltage 386
// Date:              2025/05/16
/////////////////////////////////////////////////
#ifndef BUZZERSUBSYSTEM_H
#define BUZZERSUBSYSTEM_H

#include "Arduino.h"

// class BuzzerSubsystem
class BuzzerSubsystem
{
public:
  BuzzerSubsystem();
  BuzzerSubsystem(unsigned int port);
  void setup();
  void loop();

private:
  unsigned long prevMillis;
  unsigned long currMillis;

  bool buzzState;

  int myPort; // the pin of the active buzzer

  int soundDuration;
  int iBuzz;
};

#endif
