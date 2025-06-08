/////////////////////////////////////////////////
// Modified from:     www.elegoo.com (2017.12.9)
// Modified for:      Team Voltage 386
// Date:              2025/05/16
/////////////////////////////////////////////////
#include <SerialSubsystem.h>

// <<constructor>>
SerialSubsystem::SerialSubsystem() { 
  baudRate = 9600; 

  myButton = false;
  myX = 0;  
  myY = 0;

  prevMillis = 0;
  currMillis = 0;
  updateInterval = 1000; // Default update interval
}

// <<constructor>>
SerialSubsystem::SerialSubsystem(unsigned int baud) { 
  baudRate = baud; 
  prevMillis = 0;
  currMillis = 0;
  updateInterval = 1000; // Default update interval
}

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
  
  // save the current ms step count
  currMillis = millis();

  // if curr - prev is greater or equal to blink interval, blink
  if (currMillis - prevMillis >= updateInterval)
  {
    prevMillis = currMillis;
    printJoystickData();
  }

}

void SerialSubsystem::printKey(char key)
{
  Serial.print("Received keypad character: ");
  Serial.println(key);
}

void SerialSubsystem::setJoystickData(bool button, int x, int y)
{
  myButton = button;
  myX = x;
  myY = y;
}

void SerialSubsystem::printJoystickData()
{
  Serial.print("Joystick Button: ");
  Serial.print(myButton);
  Serial.print(", X-axis: ");
  Serial.print(myX);
  Serial.print(", Y-axis: ");
  Serial.println(myY);
}
