/////////////////////////////////////////////////
// Modified from:     www.elegoo.com (2017.12.9)
// Modified for:      Team Voltage 386
// Date:              2025/05/16
/////////////////////////////////////////////////
#include <BuzzerSubsystem.h>

// <<constructor>>
BuzzerSubsystem::BuzzerSubsystem()
{
  prevMillis = 0;
  currMillis = 0;

  buzzState = LOW;

  myPort = 13; // the pin of the active buzzer

  soundDuration = 500;
  iBuzz = 0;
}

// <<constructor>>
BuzzerSubsystem::BuzzerSubsystem(unsigned int port)
{
  prevMillis = 0;
  currMillis = 0;

  buzzState = LOW;

  myPort = port; // the pin of the active buzzer

  soundDuration = 500;
  iBuzz = 0;
}

// Call this in setup() function
void BuzzerSubsystem::setup()
{
  pinMode(myPort, OUTPUT); // initialize the buzzer pin as an output
}

// Call this in loop() function
void BuzzerSubsystem::loop()
{
  currMillis = millis();

  // use the if function to gradually shorten the interval of the sound
  if (iBuzz < 5)
  {
    soundDuration = 500;
  }
  else if (iBuzz < 10)
  {
    soundDuration = 300;
  }
  else if (iBuzz < 20)
  {
    soundDuration = 100;
  }

  // if curr - prev is greater or equal to blink interval, blink
  if (currMillis - prevMillis >= soundDuration)
  {
    if (iBuzz == 19)
    {
      iBuzz = 0;
    }
    else
    {
      iBuzz++;
      // Serial.println("Reached 20");
    }

    prevMillis = currMillis;

    // activate the active buzzer
    digitalWrite(myPort, buzzState);
    buzzState = !buzzState;
  }
}
