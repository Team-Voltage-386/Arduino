/////////////////////////////////////////////////
// Modified from:     ESP-NOW Broadcast Slave / Lucas Saavedra Vaz - 2024
// Modified from:     www.elegoo.com (2017.12.9)
// Modified for:      Team Voltage 386
// Date:              2026/04/26
/////////////////////////////////////////////////

#include <BlinkSubsystem.h>
#include <ESPNowSlaveSubsystem.h>

BlinkSubsystem m_blink = BlinkSubsystem(2, 500);     // Create blink period
ESPNowSlaveSubsystem m_slave = ESPNowSlaveSubsystem();     // Create ESP Now Slave

void setup()
{
  m_blink.setup();  // setup the LED blink subsystem
  m_slave.setup(); // setup the ESP Now Slave subsystem
}

void loop()
{
  m_blink.loop();  // execute the blink loop
  m_slave.loop(); // execute the ESP Now Slave loop
}
