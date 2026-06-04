/////////////////////////////////////////////////
// Modified from:     www.elegoo.com (2017.12.9)
// Modified for:      Team Voltage 386
// Date:              2025/05/16
/////////////////////////////////////////////////
#include <PassiveLedMatrixSubsystem.h>

// 2-dimensional array of row pin numbers:
const int PassiveLedMatrixSubsystem::pRow[8] = {
  //2, 7, 19, 5, 13, 18, 12, 16
  //11, 4, 7, 19, 5, 18, 12, 16
  19, 18, 11, 7, 12, 5, 4, 16
};

// 2-dimensional array of column pin numbers:
const int PassiveLedMatrixSubsystem::pCol[8] = {
  //6, 11, 10, 3, 17, 4, 8, 9
  //6, 3, 8, 2, 10, 9, 17, 13
  13, 17, 9, 10, 2, 8, 3, 6
};

// default character display time
const unsigned int PassiveLedMatrixSubsystem::defaultDisplayTime = 250;

const unsigned char PassiveLedMatrixSubsystem::A[] =   {B00000000,B00111100,B01100110,B01100110,B01111110,B01100110,B01100110,B01100110};
const unsigned char PassiveLedMatrixSubsystem::B[] =   {B01111000,B01001000,B01001000,B01110000,B01001000,B01000100,B01000100,B01111100};
const unsigned char PassiveLedMatrixSubsystem::C[] =   {B00000000,B00011110,B00100000,B01000000,B01000000,B01000000,B00100000,B00011110};
const unsigned char PassiveLedMatrixSubsystem::D[] =   {B00000000,B00111000,B00100100,B00100010,B00100010,B00100100,B00111000,B00000000};
const unsigned char PassiveLedMatrixSubsystem::E[] =   {B00000000,B00111100,B00100000,B00111000,B00100000,B00100000,B00111100,B00000000};
const unsigned char PassiveLedMatrixSubsystem::F[] =   {B00000000,B00111100,B00100000,B00111000,B00100000,B00100000,B00100000,B00000000};
const unsigned char PassiveLedMatrixSubsystem::G[] =   {B00000000,B00111110,B00100000,B00100000,B00101110,B00100010,B00111110,B00000000};
const unsigned char PassiveLedMatrixSubsystem::H[] =   {B00000000,B00100100,B00100100,B00111100,B00100100,B00100100,B00100100,B00000000};
const unsigned char PassiveLedMatrixSubsystem::I[] =   {B00000000,B00111000,B00010000,B00010000,B00010000,B00010000,B00111000,B00000000};
const unsigned char PassiveLedMatrixSubsystem::J[] =   {B00000000,B00011100,B00001000,B00001000,B00001000,B00101000,B00111000,B00000000};
const unsigned char PassiveLedMatrixSubsystem::K[] =   {B00000000,B00100100,B00101000,B00110000,B00101000,B00100100,B00100100,B00000000};
const unsigned char PassiveLedMatrixSubsystem::L[] =   {B00000000,B00100000,B00100000,B00100000,B00100000,B00100000,B00111100,B00000000};
const unsigned char PassiveLedMatrixSubsystem::M[] =   {B00000000,B00000000,B01000100,B10101010,B10010010,B10000010,B10000010,B00000000};
const unsigned char PassiveLedMatrixSubsystem::N[] =   {B00000000,B00100010,B00110010,B00101010,B00100110,B00100010,B00000000,B00000000};
const unsigned char PassiveLedMatrixSubsystem::O[] =   {B00000000,B00111100,B01000010,B01000010,B01000010,B01000010,B00111100,B00000000};
const unsigned char PassiveLedMatrixSubsystem::P[] =   {B00000000,B00111000,B00100100,B00100100,B00111000,B00100000,B00100000,B00000000};
const unsigned char PassiveLedMatrixSubsystem::Q[] =   {B00000000,B00111100,B01000010,B01000010,B01000010,B01000110,B00111110,B00000001};
const unsigned char PassiveLedMatrixSubsystem::R[] =   {B00000000,B00111000,B00100100,B00100100,B00111000,B00100100,B00100100,B00000000};
const unsigned char PassiveLedMatrixSubsystem::S[] =   {B00000000,B00111100,B00100000,B00111100,B00000100,B00000100,B00111100,B00000000};
const unsigned char PassiveLedMatrixSubsystem::T[] =   {B00000000,B01111100,B00010000,B00010000,B00010000,B00010000,B00010000,B00000000};
const unsigned char PassiveLedMatrixSubsystem::U[] =   {B00000000,B01000010,B01000010,B01000010,B01000010,B00100100,B00011000,B00000000};
const unsigned char PassiveLedMatrixSubsystem::V[] =   {B00000000,B00100010,B00100010,B00100010,B00010100,B00010100,B00001000,B00000000};
const unsigned char PassiveLedMatrixSubsystem::W[] =   {B00000000,B10000010,B10010010,B01010100,B01010100,B00101000,B00000000,B00000000};
const unsigned char PassiveLedMatrixSubsystem::X[] =   {B00000000,B01000010,B00100100,B00011000,B00011000,B00100100,B01000010,B00000000};
const unsigned char PassiveLedMatrixSubsystem::Y[] =   {B00000000,B01000100,B00101000,B00010000,B00010000,B00010000,B00010000,B00000000};
const unsigned char PassiveLedMatrixSubsystem::Z[] =   {B00000000,B00111100,B00000100,B00001000,B00010000,B00100000,B00111100,B00000000};
const unsigned char PassiveLedMatrixSubsystem::CLR[] = {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};
const unsigned char PassiveLedMatrixSubsystem::N0[] =  {B01110000,B10001000,B10011000,B10101000,B11001000,B10001000,B01110000,B00000000};
const unsigned char PassiveLedMatrixSubsystem::N1[] =  {B01000000,B11000000,B01000000,B01000000,B01000000,B01000000,B11100000,B00000000};
const unsigned char PassiveLedMatrixSubsystem::N2[] =  {B01110000,B10001000,B00001000,B00010000,B00100000,B01000000,B11111000,B00000000};
const unsigned char PassiveLedMatrixSubsystem::N3[] =  {B11111000,B00010000,B00100000,B00010000,B00001000,B10001000,B01110000,B00000000};
const unsigned char PassiveLedMatrixSubsystem::N4[] =  {B00010000,B00110000,B01010000,B10010000,B11111000,B00010000,B00010000,B00000000};
const unsigned char PassiveLedMatrixSubsystem::N5[] =  {B11111000,B10000000,B11110000,B00001000,B00001000,B10001000,B01110000,B00000000};
const unsigned char PassiveLedMatrixSubsystem::N6[] =  {B00110000,B01000000,B10000000,B11110000,B10001000,B10001000,B01110000,B00000000};
const unsigned char PassiveLedMatrixSubsystem::N7[] =  {B11111000,B10001000,B00001000,B00010000,B00100000,B00100000,B00100000,B00000000};
const unsigned char PassiveLedMatrixSubsystem::N8[] =  {B01110000,B10001000,B10001000,B01110000,B10001000,B10001000,B01110000,B00000000};
const unsigned char PassiveLedMatrixSubsystem::N9[] =  {B01110000,B10001000,B10001000,B01111000,B00001000,B00010000,B01100000,B00000000};
const unsigned char PassiveLedMatrixSubsystem::ALL[] = {B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111};

const unsigned char PassiveLedMatrixSubsystem::TEST0[] = {B10000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};
const unsigned char PassiveLedMatrixSubsystem::TEST1[] = {B01000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};

//RIGHT
const unsigned char PassiveLedMatrixSubsystem::PACMAN_R0[] ={B00011000,B00111100,B01111110,B01100000,B01111110,B01111110,B00111100,B00011000};
const unsigned char PassiveLedMatrixSubsystem::PACMAN_R1[] ={B00011000,B00111100,B01111110,B01100000,B01100000,B01111110,B00111100,B00011000};
const unsigned char PassiveLedMatrixSubsystem::PACMAN_R2[] ={B00011000,B00111110,B01110000,B01100000,B01100000,B01110000,B00111110,B00011000};
const unsigned char PassiveLedMatrixSubsystem::PACMAN_R3[] ={B00011000,B00111100,B01111110,B01100000,B01100000,B01111110,B00111100,B00011000};
//LEFT
const unsigned char PassiveLedMatrixSubsystem::PACMAN_L0[] ={B00011000,B00111100,B01111110,B00000110,B01111110,B01111110,B00111100,B00011000};
const unsigned char PassiveLedMatrixSubsystem::PACMAN_L1[] ={B00011000,B00111100,B01111110,B00000110,B00000110,B01111110,B00111100,B00011000};
const unsigned char PassiveLedMatrixSubsystem::PACMAN_L2[] ={B00011000,B01111100,B00001110,B00000110,B00000110,B00001110,B01111100,B00011000};
const unsigned char PassiveLedMatrixSubsystem::PACMAN_L3[] ={B00011000,B00111100,B01111110,B00000110,B00000110,B01111110,B00111100,B00011000};
//UP
const unsigned char PassiveLedMatrixSubsystem::PACMAN_U0[] ={B00000000,B00101100,B01101110,B11101111,B11101111,B01111110,B00111100,B00000000};
const unsigned char PassiveLedMatrixSubsystem::PACMAN_U1[] ={B00000000,B00100100,B01100110,B11100111,B11100111,B01111110,B00111100,B00000000};
const unsigned char PassiveLedMatrixSubsystem::PACMAN_U2[] ={B00000000,B01000010,B01000010,B11000011,B11100111,B01111110,B00111100,B00000000};
const unsigned char PassiveLedMatrixSubsystem::PACMAN_U3[] ={B00000000,B00100100,B01100110,B11100111,B11100111,B01111110,B00111100,B00000000};
//DOWN
const unsigned char PassiveLedMatrixSubsystem::PACMAN_D0[] ={B00000000,B00111100,B01111110,B11101111,B11101111,B01101110,B00101100,B00000000};
const unsigned char PassiveLedMatrixSubsystem::PACMAN_D1[] ={B00000000,B00111100,B01111110,B11100111,B11100111,B01100110,B00100100,B00000000};
const unsigned char PassiveLedMatrixSubsystem::PACMAN_D2[] ={B00000000,B00111100,B01111110,B11100111,B11000011,B01000010,B01000010,B00000000};
const unsigned char PassiveLedMatrixSubsystem::PACMAN_D3[] ={B00000000,B00111100,B01111110,B11100111,B11100111,B01100110,B00100100,B00000000};

//RIGHT
const unsigned char PassiveLedMatrixSubsystem::SPRITE_R0[] ={B10011001,B00111100,B01111110,B01100000,B01111110,B01111110,B00111100,B10011001};
const unsigned char PassiveLedMatrixSubsystem::SPRITE_R1[] ={B10011001,B00111100,B01111110,B01100000,B01100000,B01111110,B00111100,B10011001};
const unsigned char PassiveLedMatrixSubsystem::SPRITE_R2[] ={B10011001,B00111110,B01110000,B01100000,B01100000,B01110000,B00111110,B10011001};
const unsigned char PassiveLedMatrixSubsystem::SPRITE_R3[] ={B10011001,B00111100,B01111110,B01100000,B01100000,B01111110,B00111100,B10011001};
//LEFT
const unsigned char PassiveLedMatrixSubsystem::SPRITE_L0[] ={B10011001,B00111100,B01111110,B00000110,B01111110,B01111110,B00111100,B10011001};
const unsigned char PassiveLedMatrixSubsystem::SPRITE_L1[] ={B10011001,B00111100,B01111110,B00000110,B00000110,B01111110,B00111100,B10011001};
const unsigned char PassiveLedMatrixSubsystem::SPRITE_L2[] ={B10011001,B01111100,B00001110,B00000110,B00000110,B00001110,B01111100,B10011001};
const unsigned char PassiveLedMatrixSubsystem::SPRITE_L3[] ={B10011001,B00111100,B01111110,B00000110,B00000110,B01111110,B00111100,B10011001};
//UP
const unsigned char PassiveLedMatrixSubsystem::SPRITE_U0[] ={B10000001,B00101100,B01101110,B11101111,B11101111,B01111110,B00111100,B10000001};
const unsigned char PassiveLedMatrixSubsystem::SPRITE_U1[] ={B10000001,B00100100,B01100110,B11100111,B11100111,B01111110,B00111100,B10000001};
const unsigned char PassiveLedMatrixSubsystem::SPRITE_U2[] ={B10000001,B01000010,B01000010,B11000011,B11100111,B01111110,B00111100,B10000001};
const unsigned char PassiveLedMatrixSubsystem::SPRITE_U3[] ={B10000001,B00100100,B01100110,B11100111,B11100111,B01111110,B00111100,B10000001};
//DOWN
const unsigned char PassiveLedMatrixSubsystem::SPRITE_D0[] ={B10000001,B00111100,B01111110,B11101111,B11101111,B01101110,B00101100,B10000001};
const unsigned char PassiveLedMatrixSubsystem::SPRITE_D1[] ={B10000001,B00111100,B01111110,B11100111,B11100111,B01100110,B00100100,B10000001};
const unsigned char PassiveLedMatrixSubsystem::SPRITE_D2[] ={B10000001,B00111100,B01111110,B11100111,B11000011,B01000010,B01000010,B10000001};
const unsigned char PassiveLedMatrixSubsystem::SPRITE_D3[] ={B10000001,B00111100,B01111110,B11100111,B11100111,B01100110,B00100100,B10000001};

int testRow = 0;
int testCol = 0;

// <<constructor>>
PassiveLedMatrixSubsystem::PassiveLedMatrixSubsystem()
{
  /* we always wait a bit between updates of the display */
  delaytime1=100;
  delaytime2=50;

  prevMillis = 0;
  currMillis = 0;

  currentValue = CLR;
  indexOfValue = 0;

  mySpriteDirection = RIGHT;
  myPacmanIndex = 0;
  mySpriteIsMoving = false;

  mySpriteIndex = 0;

  myMatrixOutput = VOLTAGE;

  joystickMotionEnabled = false;

}

/*
 This method will display the characters for the
 word "Arduino" one after the other on the matrix. 
 (you need at least 5x7 leds to see the whole chars)
 */
void PassiveLedMatrixSubsystem::writeArduinoOnMatrix() {
  /* here is the data for the characters */
  byte a[8]={B01111110,B10001000,B10001000,B10001000,B01111110,B00000000,B00000000,B00000000};
  byte r[8]={B00010000,B00100000,B00100000,B00010000,B00111110,B00000000,B00000000,B00000000};
  byte d[8]={B11111110,B00010010,B00100010,B00100010,B00011100,B00000000,B00000000,B00000000};
  byte u[8]={B00111110,B00000100,B00000010,B00000010,B00111100,B00000000,B00000000,B00000000};
  byte i[8]={B00000000,B00000010,B10111110,B00100010,B00000000,B00000000,B00000000,B00000000};
  byte n[8]={B00011110,B00100000,B00100000,B00010000,B00111110,B00000000,B00000000,B00000000};
  byte o[8]={B00011100,B00100010,B00100010,B00100010,B00011100,B00000000,B00000000,B00000000};

  /* now display them one by one with a small delay */
  displayValue(a, defaultDisplayTime);
  delay(delaytime1);
  displayValue(r, defaultDisplayTime);
  delay(delaytime1);
  displayValue(d, defaultDisplayTime);
  delay(delaytime1);
  displayValue(u, defaultDisplayTime);
  delay(delaytime1);
  displayValue(i, defaultDisplayTime);
  delay(delaytime1);
  displayValue(n, defaultDisplayTime);
  delay(delaytime1);
  displayValue(o, defaultDisplayTime);
  delay(delaytime1);
}

/*
  Display letter.
*/
void PassiveLedMatrixSubsystem::displayValue(const unsigned char value[], unsigned int displayTime) {
  char buffer[64];

  snprintf(buffer, sizeof(buffer), "Displaying value on matrix...");
  Serial.println(buffer);  

  // Populate the pPixels array based on the bits in the value array
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      pPixels[i][j] = (value[i] & (1 << (7 - j))) ? HIGH : LOW;
    }
  }

  for (int i = 0; i < 8; i++) {
    String line = "";
    for (int j = 0; j < 8; j++) {
      line += pPixels[i][j] == HIGH ? "X" : " ";
    }
    Serial.println(line);
  }

  // Write the pPixels array to the matrix and repaint the display
  // A value of 1 is translated to HIGH on column and LOW on ROW
  // A value of 0 is translated to LOW on column and HIGH on ROW
  // Display one row at a time while blanking out the rest of the rows to prevent ghosting
  // Repeat the display of the value for a few seconds to ensure it is visible
  unsigned long startTime = millis();
  while (millis() - startTime < displayTime) { // Display for displayTime milliseconds
    for (int row = 0; row < 8; row++) {
      // Set all columns LOW and all rows HIGH to blank out the display
      for (int c = 0; c < 8; c++) {
        digitalWrite(pCol[c], LOW);
      }
      for (int r = 0; r < 8; r++) {
        digitalWrite(pRow[r], HIGH);
      }

      // Set the target columns HIGH and the target row LOW to turn on the LEDs for this row
      for (int col = 0; col < 8; col++) {
        if (pPixels[row][col] == HIGH) {
          digitalWrite(pCol[col], HIGH);
        }
      }
      digitalWrite(pRow[row], LOW);

      delay(1); // Short delay to allow the LEDs to light up before moving to the next row
    }
  }

  // After displaying the value, blank out the display
  for (int c = 0; c < 8; c++) {
    digitalWrite(pCol[c], LOW);
  }
  for (int r = 0; r < 8; r++) {
    digitalWrite(pRow[r], HIGH);
  }

  snprintf(buffer, sizeof(buffer), "Done displaying value on matrix...");
  Serial.println(buffer);  
}

void PassiveLedMatrixSubsystem::testPassivePins()
{
  char buffer[64];
  snprintf(buffer, sizeof(buffer), "Testing passive pins...");
  Serial.println(buffer);

  // Cycle col HIGH and ROW lOW for each LED in the matrix to test if the correct LED turns on
  // Set all other cols LOW and all other rows HIGH to ensure only the target LED turns on

  // Set all columns LOW and all rows HIGH
  for (int c = 0; c < 8; c++) {
    digitalWrite(pCol[c], LOW);
  }
  for (int r = 0; r < 8; r++) {
    digitalWrite(pRow[r], HIGH);
  }

  // Set the target column HIGH and the target row LOW to turn on the LED
  digitalWrite(pCol[testCol], HIGH);
  digitalWrite(pRow[testRow], LOW);

  snprintf(buffer, sizeof(buffer), "Testing LED at row %d, column %d, rowPin %d, colPin %d", testRow, testCol, pRow[testRow], pCol[testCol]);
  Serial.println(buffer);

  delay(500); // Wait a bit to visually confirm the LED is on

  // Set the target column LOW to turn off the LED
  digitalWrite(pCol[testCol], LOW);

  // Move to the next LED
  testCol++;
  if (testCol >= 8) {
    testCol = 0;
    testRow++;
    if (testRow >= 8) {
      testRow = 0;
    }
  }
}

void PassiveLedMatrixSubsystem::testPassivePinsManually()
{
  char buffer[64];
  snprintf(buffer, sizeof(buffer), "Testing passive pins...");
  Serial.println(buffer);

  // Test each pin by turning it on and off
  digitalWrite(pCol[0], LOW);
  digitalWrite(pCol[1], LOW);  
  digitalWrite(pCol[2], LOW);
  digitalWrite(pCol[3], HIGH);
  digitalWrite(pCol[4], HIGH);
  digitalWrite(pCol[5], LOW);
  digitalWrite(pCol[6], LOW);
  digitalWrite(pCol[7], LOW);

  digitalWrite(pRow[0], HIGH); 
  digitalWrite(pRow[1], HIGH); 
  digitalWrite(pRow[2], HIGH); 
  digitalWrite(pRow[3], LOW); 
  digitalWrite(pRow[4], LOW); 
  digitalWrite(pRow[5], HIGH); 
  digitalWrite(pRow[6], HIGH); 
  digitalWrite(pRow[7], HIGH); 

  snprintf(buffer, sizeof(buffer), "Finished testing passive pins.");
  Serial.println(buffer);
}

/*
  Write Voltage
*/
void PassiveLedMatrixSubsystem::writeVoltageOnMatrix() {
  displayValue(T, defaultDisplayTime);
  delay(delaytime1);
  displayValue(E, defaultDisplayTime);
  delay(delaytime1);
  displayValue(A, defaultDisplayTime);
  delay(delaytime1);
  displayValue(M, defaultDisplayTime);
  delay(delaytime1);
  displayValue(CLR, defaultDisplayTime);
  delay(delaytime1);

  displayValue(V, defaultDisplayTime);
  delay(delaytime1);
  displayValue(O, defaultDisplayTime);
  delay(delaytime1);
  displayValue(L, defaultDisplayTime);
  delay(delaytime1);
  displayValue(T, defaultDisplayTime);
  delay(delaytime1);
  displayValue(A, defaultDisplayTime);
  delay(delaytime1);
  displayValue(G, defaultDisplayTime);
  delay(delaytime1);
  displayValue(E, defaultDisplayTime);
  delay(delaytime1);
  displayValue(CLR, defaultDisplayTime);
  delay(delaytime1);

  displayValue(N3, defaultDisplayTime);
  delay(delaytime1);
  displayValue(N8, defaultDisplayTime);
  delay(delaytime1);
  displayValue(N6, defaultDisplayTime);
  delay(delaytime1);
  displayValue(CLR, defaultDisplayTime);
  delay(delaytime1);

  delay(delaytime1);
}

void PassiveLedMatrixSubsystem::updateToNextTeamVoltage()
{
  // Increment the character index
  indexOfValue++;
  
  // If we reach the end of the characters, loop back to the start
  if (indexOfValue >= 21) {
    indexOfValue = 0;
  }

  // Set the current value to the next character
  switch (indexOfValue) {
    case 0: currentValue = ALL; break;
    case 1: currentValue = CLR; break;
    case 2: currentValue = ALL; break;
    case 3: currentValue = CLR; break;
    case 4: currentValue = T; break;
    case 5: currentValue = E; break;
    case 6: currentValue = A; break;
    case 7: currentValue = M; break;
    case 8: currentValue = CLR; break;
    case 9: currentValue = V; break;
    case 10: currentValue = O; break;
    case 11: currentValue = L; break;
    case 12: currentValue = T; break;
    case 13: currentValue = A; break;
    case 14: currentValue = G; break;
    case 15: currentValue = E; break;
    case 16: currentValue = CLR; break;
    case 17: currentValue = N3; break;
    case 18: currentValue = N8; break;
    case 19: currentValue = N6; break;
    case 20: currentValue = CLR; break;
    default: currentValue = CLR; break; // Default case to avoid uninitialized access
  }
}

void PassiveLedMatrixSubsystem::displayCurrentTeamVoltage()
{
  displayValue(currentValue, defaultDisplayTime);
}

void PassiveLedMatrixSubsystem::setSpriteDirection(spriteDirection direction)
{
  mySpriteDirection = direction;
}

void PassiveLedMatrixSubsystem::setSpriteIsMoving(bool isMoving) {
  mySpriteIsMoving = isMoving;
}

void PassiveLedMatrixSubsystem::checkWASD()
{
  if (Serial.available() > 0) {
    char inputChar = Serial.read();
    switch (inputChar) {
      case '0':
        testRow = 0;
        testCol = 0;
        setSpriteIsMoving(false);
        setMatrixOutput(TEST);
        joystickMotionEnabled = false;
        Serial.println("Received input: 0, switching to TEST");        
        break;

      case '1':
        setSpriteIsMoving(false);
        setMatrixOutput(VOLTAGE);
        joystickMotionEnabled = false;
        Serial.println("Received input: 1, switching to VOLTAGE");
        break;

      case '2':
        setSpriteIsMoving(true);
        setMatrixOutput(PACMAN);
        joystickMotionEnabled = false;
        Serial.println("Received input: 2, switching to PACMAN");
        break;

      case '3':
        setSpriteIsMoving(true);
        setMatrixOutput(SPRITE);
        joystickMotionEnabled = false;
        Serial.println("Received input: 3, switching to SPRITE");
        break;

      case '4':
        setSpriteIsMoving(false);
        setMatrixOutput(PACMAN_WITH_JOYSTICK);
        joystickMotionEnabled = true;
        Serial.println("Received input: 4, switching to PACMAN with JOYSTICK control");
        break;        

      case '5':
        setSpriteIsMoving(false);
        setMatrixOutput(SPRITE_WITH_JOYSTICK);
        joystickMotionEnabled = true;
        Serial.println("Received input: 5, switching to SPRITE with JOYSTICK control");
        break;

      case 'w':
        setSpriteDirection(UP);
        Serial.println("Received input: w, setting direction to UP");
        break;
      case 'a':
        setSpriteDirection(LEFT);
        Serial.println("Received input: a, setting direction to LEFT");
        break;
      case 's':
        setSpriteDirection(DOWN);
        Serial.println("Received input: s, setting direction to DOWN");
        break;
      case 'd':
        setSpriteDirection(RIGHT);
        Serial.println("Received input: d, setting direction to RIGHT");
        break;
    }
  }
}

void PassiveLedMatrixSubsystem::movePacman()
{
  if (!mySpriteIsMoving) {
    return; // If Pacman is not moving, do nothing
  }

  // Update the Pacman's position based on the direction
  myPacmanIndex++;

  if (myPacmanIndex > 3) {
    myPacmanIndex = 0; // Loop back to the first frame
  }

  // Display the new Pacman position
  switch (mySpriteDirection) {
    case RIGHT:
      displayValue(myPacmanIndex == 0 ? PACMAN_R0 : (myPacmanIndex == 1 ? PACMAN_R1 : (myPacmanIndex == 2 ? PACMAN_R2 : PACMAN_R3)), defaultDisplayTime);
      break;
    case LEFT:
      displayValue(myPacmanIndex == 0 ? PACMAN_L0 : (myPacmanIndex == 1 ? PACMAN_L1 : (myPacmanIndex == 2 ? PACMAN_L2 : PACMAN_L3)), defaultDisplayTime);
      break;
    case UP:
      displayValue(myPacmanIndex == 0 ? PACMAN_U0 : (myPacmanIndex == 1 ? PACMAN_U1 : (myPacmanIndex == 2 ? PACMAN_U2 : PACMAN_U3)), defaultDisplayTime);
      break;
    case DOWN:
      displayValue(myPacmanIndex == 0 ? PACMAN_D0 : (myPacmanIndex == 1 ? PACMAN_D1 : (myPacmanIndex == 2 ? PACMAN_D2 : PACMAN_D3)), defaultDisplayTime);
      break;
  }
}

void PassiveLedMatrixSubsystem::moveSprite()
{

  if (!mySpriteIsMoving) {
    return; // If Sprite is not moving, do nothing
  }

  // Update the Pacman's position based on the direction
  mySpriteIndex++;

  if (mySpriteIndex > 3) {
    mySpriteIndex = 0; // Loop back to the first frame
  }

  // Display the new Sprite position
  switch (mySpriteDirection) {
    case RIGHT:
      displayValue(mySpriteIndex == 0 ? SPRITE_R0 : (mySpriteIndex == 1 ? SPRITE_R1 : (mySpriteIndex == 2 ? SPRITE_R2 : SPRITE_R3)), defaultDisplayTime);
      break;
    case LEFT:
      displayValue(mySpriteIndex == 0 ? SPRITE_L0 : (mySpriteIndex == 1 ? SPRITE_L1 : (mySpriteIndex == 2 ? SPRITE_L2 : SPRITE_L3)), defaultDisplayTime);
      break;
    case UP:
      displayValue(mySpriteIndex == 0 ? SPRITE_U0 : (mySpriteIndex == 1 ? SPRITE_U1 : (mySpriteIndex == 2 ? SPRITE_U2 : SPRITE_U3)), defaultDisplayTime);
      break;
    case DOWN:
      displayValue(mySpriteIndex == 0 ? SPRITE_D0 : (mySpriteIndex == 1 ? SPRITE_D1 : (mySpriteIndex == 2 ? SPRITE_D2 : SPRITE_D3)), defaultDisplayTime);
      break;
  }
}

void PassiveLedMatrixSubsystem::setMatrixOutput(matrixOutput output)
{
  myMatrixOutput = output;
} 

// Initialize Passive Pins
void PassiveLedMatrixSubsystem::initPassivePins() {
    for (int thisPin = 0; thisPin < 8; thisPin++) {  
      pinMode(pCol[thisPin], OUTPUT);
      digitalWrite(pCol[thisPin], LOW);
      pinMode(pRow[thisPin], OUTPUT);
      digitalWrite(pRow[thisPin], LOW);    
    }
}

bool PassiveLedMatrixSubsystem::getJoystickMotionEnabled() {
  return joystickMotionEnabled;
}

// Call this in setup() function
void PassiveLedMatrixSubsystem::setup()
{
  initPassivePins();

  Serial.begin(115200);
  // Wait for serial connection to be established before proceeding with setup
  while (!Serial)
    ;

  Serial.println("Started PassiveLedMatrixSubsystem...");
}

// Call this in loop() function
void PassiveLedMatrixSubsystem::loop()
{
  // save the current ms step count
  currMillis = millis();

  // if curr - prev is greater or equal to blink interval, blink
  if (currMillis - prevMillis >= delaytime1)
  {
    prevMillis = currMillis;

    checkWASD();
    
    if(myMatrixOutput == TEST) {
      testPassivePins();
    } else if(myMatrixOutput == VOLTAGE) {
      updateToNextTeamVoltage();
      displayCurrentTeamVoltage();
    } else if (myMatrixOutput == PACMAN) {
      movePacman();
    } else if (myMatrixOutput == SPRITE) {
      moveSprite();
    } else if (myMatrixOutput == PACMAN_WITH_JOYSTICK) {
      movePacman();
    } else if (myMatrixOutput == SPRITE_WITH_JOYSTICK) {
      moveSprite();
    }
  }
}
