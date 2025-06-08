/////////////////////////////////////////////////
// Modified from:     www.elegoo.com (2017.12.9)
// Modified for:      Team Voltage 386
// Date:              2025/05/16
/////////////////////////////////////////////////
#include <BlinkSubsystem.h>

// <<constructor>>
BlinkSubsystem::BlinkSubsystem()
{
  prevMillis = 0;
  currMillis = 0;
  blinkState = LOW;
  blinkInterval = 250;
}

// <<constructor>>
BlinkSubsystem::BlinkSubsystem(unsigned long interval)
{
  prevMillis = 0;
  currMillis = 0;
  blinkState = LOW;
  blinkInterval = interval;
}

// Call this in setup() function
void BlinkSubsystem::setup() { pinMode(LED_BUILTIN, OUTPUT); }

// Call this in loop() function
void BlinkSubsystem::loop()
{
  // save the current ms step count
  currMillis = millis();

  // if curr - prev is greater or equal to blink interval, blink
  if (currMillis - prevMillis >= blinkInterval)
  {
    prevMillis = currMillis;
    blinkState = !blinkState;
    digitalWrite(LED_BUILTIN, blinkState); // Blink the LED
  }
}
