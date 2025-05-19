#include <KeypadSubsystem.h>

// <<constructor>>
KeypadSubsystem::KeypadSubsystem()
{
  // myRows = ROWS;
  // myCols = COLS;

  // rowPins[0] = 9; //connect to the row pinouts of the keypad
  // rowPins[1] = 8; //connect to the row pinouts of the keypad
  // rowPins[2] = 7; //connect to the row pinouts of the keypad
  // rowPins[3] = 6; //connect to the row pinouts of the keypad
  // colPins[0] = 5; //connect to the column pinouts of the keypad
  // colPins[1] = 4; //connect to the column pinouts of the keypad
  // colPins[2] = 3; //connect to the column pinouts of the keypad
  // colPins[3] = 2; //connect to the column pinouts of the keypad

  // initialize an instance of class NewKeypad
  // customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, myRows,
  // myCols);

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
    customKey = customKeypad.getKey();

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
