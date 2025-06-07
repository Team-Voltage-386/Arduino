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
  KeypadSubsystem(unsigned int port);
  void setup();
  void loop();
  char getKey();
  bool hasKey();

private:
  byte myRows = ROWS;
  byte myCols = COLS;

  // define the cymbols on the buttons of the keypads
  char hexaKeys[ROWS][COLS] = {{'1', '2', '3', 'A'},
                               {'4', '5', '6', 'B'},
                               {'7', '8', '9', 'C'},
                               {'*', '0', '#', 'D'}};

  byte rowPins[ROWS] = {9, 8, 7, 6}; // connect to the row pinouts of the keypad
  byte colPins[COLS] = {5, 4, 3,
                        2}; // connect to the column pinouts of the keypad

  // byte rowPins[ROWS]; //connect to the row pinouts of the keypad
  // byte colPins[COLS]; //connect to the column pinouts of the keypad

  // Keypad instance
  // Keypad customKeypad;
  Keypad customKeypad =
      Keypad(makeKeymap(hexaKeys), rowPins, colPins, myRows, myCols);

  char customKey;
  bool holdKey;
};

#endif
