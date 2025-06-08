/////////////////////////////////////////////////
// Modified from:     www.elegoo.com (2017.12.9)
// Modified for:      Team Voltage 386
// Date:              2025/05/16
/////////////////////////////////////////////////
#include <JoystickSubsystem.h>

// Arduino pin numbers
const int JoystickSubsystem::SW_pin = 52; // digital pin connected to switch output
const int JoystickSubsystem::X_pin = 0; // analog pin connected to X output
const int JoystickSubsystem::Y_pin = 1; // analog pin connected to Y output

// <<constructor>>
JoystickSubsystem::JoystickSubsystem()
{
  prevMillis = 0;
  currMillis = 0;
  delaytime1 = 500;
  dataIsReady = false;

  joystickData.button = false;
  joystickData.x = 0;
  joystickData.y = 0; 

  joystickSavedData.button = false;
  joystickSavedData.x = 0;
  joystickSavedData.y = 0;

  savedDataError = false; // Initialize saved data error flag
}

bool JoystickSubsystem::isDataReady()
{
  return dataIsReady;
}

JoystickSubsystem::JoystickData JoystickSubsystem::getData()
{
  return joystickData;
}

JoystickSubsystem::JoystickData JoystickSubsystem::getSavedData()
{
  if (!dataIsReady) {
    // If data is not ready, flag an error
    savedDataError = true;
  }

  dataIsReady = false; // Reset data ready flag

  return joystickSavedData;
}

bool JoystickSubsystem::hasSavedDataError()
{
  return savedDataError; // Return the saved data error flag status
}

void JoystickSubsystem::clearSavedDataError()
{
  savedDataError = false; // Clear the saved data error flag
}

// Call this in setup() function
void JoystickSubsystem::setup()
{
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
}

// Call this in loop() function
void JoystickSubsystem::loop()
{
  // save the current ms step count
  currMillis = millis();

  // if curr - prev is greater or equal to blink interval, blink
  if (currMillis - prevMillis >= delaytime1)
  {
    prevMillis = currMillis;
    dataIsReady = true; // Set data as ready to be read
    joystickSavedData.button = digitalRead(SW_pin);
    joystickSavedData.x = analogRead(X_pin);
    joystickSavedData.y = analogRead(Y_pin);
  }

  joystickData.button = digitalRead(SW_pin);
  joystickData.x = analogRead(X_pin);
  joystickData.y = analogRead(Y_pin);

}
