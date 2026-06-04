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
  buttonEnabled = true;
  joystickData.button = false;
  joystickData.x = 0;
  joystickData.y = 0; 
}

JoystickSubsystem::JoystickData JoystickSubsystem::getData()
{
  return joystickData;
}

// Call this in setup() function
void JoystickSubsystem::setup()
{
  buttonEnabled = true;
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
}

// Call this in setup() function
void JoystickSubsystem::setup(bool hasButton)
{
  buttonEnabled = hasButton;
  // Initialize the button pin only if it is present
  if(hasButton) {
    pinMode(SW_pin, INPUT);
    digitalWrite(SW_pin, HIGH);
  }
}

// Call this in loop() function
void JoystickSubsystem::loop()
{
  // Read only the button state if button is enabled
  if(buttonEnabled) {
    joystickData.button = digitalRead(SW_pin);
  } else {
    joystickData.button = false; // Set to false if button is not enabled
  }

  joystickData.x = analogRead(X_pin);
  joystickData.y = analogRead(Y_pin);
}
