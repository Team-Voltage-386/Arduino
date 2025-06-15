/////////////////////////////////////////////////
// Modified from:     www.elegoo.com (2017.12.9)
// Modified for:      Team Voltage 386
// Date:              2025/05/16
/////////////////////////////////////////////////
#include <KeypadSubsystem.h>

const byte KeypadSubsystem::myRows = ROWS;
const byte KeypadSubsystem::myCols = COLS;

char KeypadSubsystem::hexaKeys[ROWS][COLS] = {{'1', '2', '3', 'A'},
                               {'4', '5', '6', 'B'},
                               {'7', '8', '9', 'C'},
                               {'*', '0', '#', 'D'}};
byte KeypadSubsystem::rowPins[ROWS] = {9, 8, 7, 6}; // connect to the row pinouts of the keypad
byte KeypadSubsystem::colPins[COLS] = {5, 4, 3, 2}; // connect to the column pinouts of the keypad

// <<constructor>>
KeypadSubsystem::KeypadSubsystem()
{
  // initialize an instance of class NewKeypad
  customKeypad = new Keypad(makeKeymap(hexaKeys), rowPins, colPins, myRows, myCols);

  customKey = 0;
  holdKey = false;
}

// Call this in setup() function
void KeypadSubsystem::setup()
{
  customKey = 0;
  holdKey = false;
}

// Call this in loop() function
void KeypadSubsystem::loop()
{
  if (!holdKey)
  {
    customKey = customKeypad->getKey();

    // if the key returned is not null, hold it
    if (customKey)
    {
      holdKey = true;
    }
  }
}

char KeypadSubsystem::getKey()
{
  holdKey = false;
  return customKey;
}

bool KeypadSubsystem::hasKey()
{
  if (customKey)
  {
    return true;
  }
  else
  {
    return false;
  }
}
