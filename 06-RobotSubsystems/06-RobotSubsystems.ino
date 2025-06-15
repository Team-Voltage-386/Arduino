/////////////////////////////////////////////////
// Modified from:     www.elegoo.com (2017.12.9)
// Modified for:      Team Voltage 386
// Date:              2025/05/16
/////////////////////////////////////////////////

#include <BlinkSubsystem.h>
#include <SerialSubsystem.h>
#include <LedMatrixSubsystem.h>
#include <KeypadSubsystem.h>
#include <JoystickSubsystem.h>
//#include <BuzzerSubsystem.h>
//#include <MelodySubsystem.h>

BlinkSubsystem m_blink = BlinkSubsystem(250);     // Create blink w/ 250 ms period
SerialSubsystem m_serial = SerialSubsystem(9600); // Create serial at 9600 baud
LedMatrixSubsystem m_ledmat = LedMatrixSubsystem();     // Create Led Matrix
KeypadSubsystem m_keypad = KeypadSubsystem();     // Create keypad
JoystickSubsystem m_joystick = JoystickSubsystem(); // Create joystick subsystem
//BuzzerSubsystem m_buzzer = BuzzerSubsystem(12); //Create buzzer on port 12
//MelodySubsystem m_melody = MelodySubsystem(12, 500); //Create melody on port 12 w/ 1000 duration

JoystickSubsystem::JoystickData joystickData;

void setup()
{
  m_blink.setup();  // setup the LED blink subsystem
  m_serial.setup(true); // setup the serial subsystem (with joystick data enabled)
  m_ledmat.setup(); // setup the LED matrix subsystem
  m_keypad.setup(); // set the keypad subsystem
  m_joystick.setup(); // setup the joystick subsystem
  //m_buzzer.setup();  //setup the buzzer subsystem
  //m_melody.setup();  //setup the melody subsystem
}

char keypadKey;
//int keyIndex;

void loop()
{
  m_blink.loop();  // execute the blink loop
  m_ledmat.loop(); // execute the LED matrix loop
  m_keypad.loop(); // execute the keypad loop

  joystickData = m_joystick.getData(); // get the joystick data

  if (joystickData.x > 750) {
    m_ledmat.setPacmanIsMoving(true); // set pacman is moving to true
    m_ledmat.setPacmanDirection(LedMatrixSubsystem::DOWN); // set pacman direction
  } else if (joystickData.x < 250) {
    m_ledmat.setPacmanIsMoving(true); // set pacman is moving to true
    m_ledmat.setPacmanDirection(LedMatrixSubsystem::UP); // set pacman direction
  } else if (joystickData.y > 750) {
    m_ledmat.setPacmanIsMoving(true); // set pacman is moving to true
    m_ledmat.setPacmanDirection(LedMatrixSubsystem::LEFT); // set pacman direction
  } else if (joystickData.y < 250) {
    m_ledmat.setPacmanIsMoving(true); // set pacman is moving to true
    m_ledmat.setPacmanDirection(LedMatrixSubsystem::RIGHT); // set pacman direction
  }
  else {
    m_ledmat.setPacmanIsMoving(false); // set pacman is moving to false
  }

  if(joystickData.button == 0) {
    m_ledmat.nextMatrixOutput();
  }

  m_joystick.loop(); // execute the joystick loop

  m_serial.setJoystickData(joystickData.button, joystickData.x, joystickData.y); // print the joystick data to serial
  m_serial.loop(); // execute the serial loop

  //m_buzzer.loop();  //execute the buzzer loop
  //m_melody.loop(); //execute the melody loop

  if (m_keypad.hasKey())
  {
    keypadKey = m_keypad.getKey();
    m_serial.printKey(keypadKey);
  //  keyIndex = keypadKey - '0';
  //  m_melody.selectNote(keyIndex);
  }
}
