/////////////////////////////////////////////////
// Modified from:     www.elegoo.com (2017.12.9)
// Modified for:      Team Voltage 386
// Date:              2025/05/16
/////////////////////////////////////////////////
#ifndef KEYPADSUBSYSTEM_H
#define KEYPADSUBSYSTEM_H

#include "Arduino.h"
#include <Keypad.h>

#define ROWS 4
#define COLS 4

class KeypadSubsystem
{
public:
  KeypadSubsystem();
  void setup();
  void loop();
  char getKey();
  bool hasKey();

private:
  static const byte myRows;
  static const byte myCols;

  static char hexaKeys[ROWS][COLS];

  static byte rowPins[ROWS]; // connect to the row pinouts of the keypad
  static byte colPins[COLS]; // connect to the column pinouts of the keypad

  // Keypad instance
  Keypad *customKeypad; //pointer for forward declaration

  char customKey;
  bool holdKey;
};

#endif
