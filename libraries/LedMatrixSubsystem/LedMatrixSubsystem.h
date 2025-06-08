/////////////////////////////////////////////////
// Modified from:     www.elegoo.com (2017.12.9)
// Modified for:      Team Voltage 386
// Date:              2025/05/16
/////////////////////////////////////////////////
#ifndef LEDMATRIXSUBSYSTEM_H
#define LEDMATRIXSUBSYSTEM_H

#include "Arduino.h"
#include "LedControl.h"

class LedMatrixSubsystem
{
public:
  enum pacmanDirection {
    RIGHT,
    LEFT,
    UP,
    DOWN
  };

  enum matrixOutput {
    VOLTAGE,
    PACMAN
  };  

  void updateToNextTeamVoltage();
  void displayCurrentTeamVoltage();
  void displayValue(const unsigned char value[]);
  LedMatrixSubsystem();
  void writeArduinoOnMatrix();
  void rows();
  void columns();
  void single();
  void writeVoltageMatrix();
  void setup();
  void loop();

  void LedMatrixSubsystem::setPacmanDirection(LedMatrixSubsystem::pacmanDirection direction);
  void setPacmanIsMoving(bool isMoving);
  void movePacman();

  void setMatrixOutput(matrixOutput output);
  void nextMatrixOutput();

private:
  /*
  Now we need a LedControl to work with.
  ***** These pin numbers will probably not work with your hardware *****
  pin 12 is connected to the DataIn 
  pin 11 is connected to LOAD(CS)
  pin 10 is connected to the CLK 
  We have only a single MAX72XX.
  */
  LedControl lc=LedControl(12,10,11,1);

  /* we always wait a bit between updates of the display */
  unsigned long delaytime1;
  unsigned long delaytime2;
  unsigned int charIndex;
  unsigned int col; 

  unsigned long prevMillis;
  unsigned long currMillis;

  const unsigned char *currentValue;
  unsigned int indexOfValue;

  //https://stackoverflow.com/questions/55090907/arduino-8x8-led-matrix-letters
  /*
  Name:      Arduino8x8MatrixStackOverflow.ino
  Created:   3/10/2019 5:21:02 PM
  Author:    jjman
  */
  static const unsigned char A[];
  static const unsigned char B[];
  static const unsigned char C[];
  static const unsigned char D[];
  static const unsigned char E[];
  static const unsigned char F[];
  static const unsigned char G[];
  static const unsigned char H[];
  static const unsigned char I[];
  static const unsigned char J[];
  static const unsigned char K[];
  static const unsigned char L[];
  static const unsigned char M[];
  static const unsigned char N[];
  static const unsigned char O[];
  static const unsigned char P[];
  static const unsigned char Q[];
  static const unsigned char R[];
  static const unsigned char S[];
  static const unsigned char T[];
  static const unsigned char U[];
  static const unsigned char V[];
  static const unsigned char W[];
  static const unsigned char X[];
  static const unsigned char Y[];
  static const unsigned char Z[];
  static const unsigned char CLR[];
  static const unsigned char N0[];
  static const unsigned char N1[];
  static const unsigned char N2[];
  static const unsigned char N3[];
  static const unsigned char N4[];
  static const unsigned char N5[];
  static const unsigned char N6[];
  static const unsigned char N7[];
  static const unsigned char N8[];
  static const unsigned char N9[];
  static const unsigned char ALL[];

  pacmanDirection myPacmanDirection;
  unsigned int myPacmanIndex;
  bool myPacmanIsMoving;

  //RIGHT
  static const unsigned char LedMatrixSubsystem::PACMAN_R0[];
  static const unsigned char LedMatrixSubsystem::PACMAN_R1[];
  static const unsigned char LedMatrixSubsystem::PACMAN_R2[];
  static const unsigned char LedMatrixSubsystem::PACMAN_R3[];
  //LEFT
  static const unsigned char LedMatrixSubsystem::PACMAN_L0[];
  static const unsigned char LedMatrixSubsystem::PACMAN_L1[];
  static const unsigned char LedMatrixSubsystem::PACMAN_L2[];
  static const unsigned char LedMatrixSubsystem::PACMAN_L3[];
  //UP
  static const unsigned char LedMatrixSubsystem::PACMAN_U0[];
  static const unsigned char LedMatrixSubsystem::PACMAN_U1[];
  static const unsigned char LedMatrixSubsystem::PACMAN_U2[];
  static const unsigned char LedMatrixSubsystem::PACMAN_U3[];
  //DOWN
  static const unsigned char LedMatrixSubsystem::PACMAN_D0[];
  static const unsigned char LedMatrixSubsystem::PACMAN_D1[];
  static const unsigned char LedMatrixSubsystem::PACMAN_D2[];
  static const unsigned char LedMatrixSubsystem::PACMAN_D3[];

  matrixOutput myMatrixOutput;
};

#endif
