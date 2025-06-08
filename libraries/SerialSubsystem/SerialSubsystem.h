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
  void setJoystickData(bool button, int x, int y);
  void printJoystickData();

private:
  char ch;
  unsigned int baudRate;
  unsigned int chInt;

  unsigned long prevMillis;
  unsigned long currMillis;  
  unsigned long updateInterval;

  bool myButton;
  unsigned int myX;
  unsigned int myY;  
};

#endif
