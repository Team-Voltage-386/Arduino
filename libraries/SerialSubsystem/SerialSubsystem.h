/////////////////////////////////////////////////
// Modified from:     www.elegoo.com (2017.12.9)
// Modified for:      Team Voltage 386
// Date:              2025/05/16
/////////////////////////////////////////////////
#ifndef SERIALSUBSYSTEM_H
#define SERIALSUBSYSTEM_H

#include "Arduino.h"

// class SerialSubsystem
class SerialSubsystem
{
public:
  SerialSubsystem();
  SerialSubsystem(unsigned int baud);
  void setup();
  void loop();
  void printKey(char key);

private:
  char ch;
  unsigned int baudRate;
  unsigned int chInt;
};

#endif
