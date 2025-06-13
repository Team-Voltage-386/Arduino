/////////////////////////////////////////////////
// Modified from:     www.elegoo.com (2017.12.9)
// Modified for:      Team Voltage 386
// Date:              2025/05/16
/////////////////////////////////////////////////

#include <BlinkSubsystem.h>

BlinkSubsystem m_blink = BlinkSubsystem(1000);     // Create blink w/ 1000 ms period

void setup()
{
  m_blink.setup();  // setup the LED blink subsystem
}

void loop()
{
  m_blink.loop();  // execute the blink loop
}
