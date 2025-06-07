/////////////////////////////////////////////////
// Modified from:     www.elegoo.com (2017.12.9)
// Modified for:      Team Voltage 386
// Date:              2025/05/16
/////////////////////////////////////////////////
#include <SerialSubsystem.h>

// <<constructor>>
SerialSubsystem::SerialSubsystem() { baudRate = 9600; }

// <<constructor>>
SerialSubsystem::SerialSubsystem(unsigned int baud) { baudRate = baud; }

// Call this in setup() function
void SerialSubsystem::setup()
{
  Serial.begin(baudRate);

  while (!Serial)
    ;
  Serial.println("Serial Subsystem is running...");
}

// Call this in loop() function
void SerialSubsystem::loop()
{
  if (Serial.available())
  {
    ch = Serial.read();
    if (ch >= '0' && ch <= '9')
    {
      chInt = ch - '0';
      Serial.print("Received Number ");
      Serial.println(chInt);
    }

    if (ch == 'x')
    {
      Serial.println("Cleared");
    }
  }
}

void SerialSubsystem::printKey(char key)
{
  Serial.print("Received keypad character: ");
  Serial.println(key);
}
