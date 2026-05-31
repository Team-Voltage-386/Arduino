/////////////////////////////////////////////////
// Modified from:     ESP-NOW Broadcast Master / Lucas Saavedra Vaz - 2024
// Modified from:     www.elegoo.com (2017.12.9)
// Modified for:      Team Voltage 386
// Date:              2026/04/26
/////////////////////////////////////////////////

#include <BlinkSubsystem.h>
#include <ESPNowMasterSubsystem.h>

BlinkSubsystem m_blink = BlinkSubsystem(2, 500);     // Create blink
ESPNowMasterSubsystem m_master = ESPNowMasterSubsystem(2000);     // Create ESP Now Master

void setup()
{
  m_blink.setup();  // setup the LED blink subsystem
  m_master.setup(); // setup the ESP Now Master subsystem
}

void loop()
{
  m_blink.loop();  // execute the blink loop
  m_master.loop(); // execute the ESP Now Master loop
}
