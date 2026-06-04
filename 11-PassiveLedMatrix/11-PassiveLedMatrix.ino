/*
  Row-Column Scanning an 8x8 LED matrix with X-Y input

  This example controls an 8x8 LED matrix using two analog inputs.

  This example works for the Lumex LDM-24488NI Matrix. See
  https://sigma.octopart.com/140413/datasheet/Lumex-LDM-24488NI.pdf
  for the pin connections.

  For other LED cathode column matrixes, you should only need to change the pin
  numbers in the row[] and column[] arrays.

  rows are the anodes
  cols are the cathodes
  ---------

  Pin numbers:
  Matrix:
  - digital pins 2 through 13,
  - analog pins 2 through 5 used as digital 16 through 19
  Potentiometers:
  - center pins are attached to analog pins 0 and 1, respectively
  - side pins attached to +5V and ground, respectively

  created 27 May 2009
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/display/RowColumnScanning/
*/
#include <PassiveLedMatrixSubsystem.h>
#include <JoystickSubsystem.h>

PassiveLedMatrixSubsystem m_ledMatrix = PassiveLedMatrixSubsystem();
JoystickSubsystem m_joystick = JoystickSubsystem(); // Create joystick subsystem
JoystickSubsystem::JoystickData joystickData;

void setup() {
  m_joystick.setup(false); // setup the joystick subsystem without button input
  m_ledMatrix.setup(); // setup the LED matrix subsystem
}

void loop() {
  m_ledMatrix.loop(); // Execute the main LED subsystem loop
  m_joystick.loop(); // Execute the joystick loop to gather data

  joystickData = m_joystick.getData(); // get the joystick data from joystick subsystem

  if(m_ledMatrix.getJoystickMotionEnabled())
  {
    Serial.println("Joystick Data - Button: " + String(joystickData.button) + ", X: " + String(joystickData.x) + ", Y: " + String(joystickData.y));

    if (joystickData.x > 750) {
      m_ledMatrix.setSpriteIsMoving(true); // set pacman is moving to true
      m_ledMatrix.setSpriteDirection(PassiveLedMatrixSubsystem::DOWN); // set pacman direction
    } else if (joystickData.x < 250) {
      m_ledMatrix.setSpriteIsMoving(true); // set pacman is moving to true
      m_ledMatrix.setSpriteDirection(PassiveLedMatrixSubsystem::UP); // set pacman direction
    } else if (joystickData.y > 750) {
      m_ledMatrix.setSpriteIsMoving(true); // set pacman is moving to true
      m_ledMatrix.setSpriteDirection(PassiveLedMatrixSubsystem::LEFT); // set pacman direction
    } else if (joystickData.y < 250) {
      m_ledMatrix.setSpriteIsMoving(true); // set pacman is moving to true
      m_ledMatrix.setSpriteDirection(PassiveLedMatrixSubsystem::RIGHT); // set pacman direction
    }
    else {
      m_ledMatrix.setSpriteIsMoving(false); // set pacman is moving to false
    }
  }
}
