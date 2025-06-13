/////////////////////////////////////////////////
// Modified from:     www.elegoo.com (2017.12.9)
// Modified for:      Team Voltage 386
// Date:              2025/05/16
/////////////////////////////////////////////////

#include <BlinkSubsystem.h>
#include <SerialSubsystem.h>

BlinkSubsystem m_blink = BlinkSubsystem(250);     // Create blink w/ 250 ms period
SerialSubsystem m_serial = SerialSubsystem(9600); // Create serial at 9600 baud

void setup()
{
  m_blink.setup();  // setup the LED blink subsystem
  m_serial.setup(false); // setup the serial subsystem with joystick disabled
}

void loop()
{
  m_blink.loop();  // execute the blink loop
  m_serial.loop(); // execute the serial loop
}
