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
