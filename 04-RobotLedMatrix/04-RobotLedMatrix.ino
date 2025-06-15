/////////////////////////////////////////////////
// Modified from:     www.elegoo.com (2017.12.9)
// Modified for:      Team Voltage 386
// Date:              2025/05/16
/////////////////////////////////////////////////

#include <BlinkSubsystem.h>
#include <SerialSubsystem.h>
#include <LedMatrixSubsystem.h>
#include <KeypadSubsystem.h>

BlinkSubsystem m_blink = BlinkSubsystem(250);     // Create blink w/ 250 ms period
SerialSubsystem m_serial = SerialSubsystem(9600); // Create serial at 9600 baud
LedMatrixSubsystem m_ledmat = LedMatrixSubsystem();     // Create Led Matrix
KeypadSubsystem m_keypad = KeypadSubsystem();     // Create keypad

void setup()
{
  m_blink.setup();  // setup the LED blink subsystem
  m_serial.setup(true); // setup the serial subsystem (with joystick data enabled)
  m_ledmat.setup(); // setup the LED matrix subsystem
  m_keypad.setup(); // set the keypad subsystem
}

char keypadKey;

void loop()
{
  m_blink.loop();  // execute the blink loop
  m_ledmat.loop(); // execute the LED matrix loop
  m_keypad.loop(); // execute the keypad loop
  m_serial.loop(); // execute the serial loop

  if (m_keypad.hasKey())
  {
    keypadKey = m_keypad.getKey();
    m_serial.printKey(keypadKey);
  }
}
