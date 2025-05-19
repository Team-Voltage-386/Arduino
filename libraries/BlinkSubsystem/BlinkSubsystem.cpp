#include <BlinkSubsystem.h>

// <<constructor>>
BlinkSubsystem::BlinkSubsystem()
{
  prevBlinkMillis = 0;
  currBlinkMillis = 0;
  blinkState = LOW;
  blinkInterval = 250;
}

// <<constructor>>
BlinkSubsystem::BlinkSubsystem(unsigned long interval)
{
  prevBlinkMillis = 0;
  currBlinkMillis = 0;
  blinkState = LOW;
  blinkInterval = interval;
}

// Call this in setup() function
void BlinkSubsystem::setup() { pinMode(LED_BUILTIN, OUTPUT); }

// Call this in loop() function
void BlinkSubsystem::loop()
{
  // save the current ms step count
  currBlinkMillis = millis();

  // if curr - prev is greater or equal to blink interval, blink
  if (currBlinkMillis - prevBlinkMillis >= blinkInterval)
  {
    prevBlinkMillis = currBlinkMillis;
    blinkState = !blinkState;
    digitalWrite(LED_BUILTIN, blinkState); // Blink the LED
  }
}
