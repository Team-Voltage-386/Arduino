/////////////////////////////////////////////////
// Modified from:     www.elegoo.com (2017.12.9)
// Modified for:      Team Voltage 386
// Date:              2025/05/16
/////////////////////////////////////////////////
#include <LedMatrixSubsystem.h>

const unsigned char LedMatrixSubsystem::A[] =   {B00000000,B00111100,B01100110,B01100110,B01111110,B01100110,B01100110,B01100110};
const unsigned char LedMatrixSubsystem::B[] =   {B01111000,B01001000,B01001000,B01110000,B01001000,B01000100,B01000100,B01111100};
const unsigned char LedMatrixSubsystem::C[] =   {B00000000,B00011110,B00100000,B01000000,B01000000,B01000000,B00100000,B00011110};
const unsigned char LedMatrixSubsystem::D[] =   {B00000000,B00111000,B00100100,B00100010,B00100010,B00100100,B00111000,B00000000};
const unsigned char LedMatrixSubsystem::E[] =   {B00000000,B00111100,B00100000,B00111000,B00100000,B00100000,B00111100,B00000000};
const unsigned char LedMatrixSubsystem::F[] =   {B00000000,B00111100,B00100000,B00111000,B00100000,B00100000,B00100000,B00000000};
const unsigned char LedMatrixSubsystem::G[] =   {B00000000,B00111110,B00100000,B00100000,B00101110,B00100010,B00111110,B00000000};
const unsigned char LedMatrixSubsystem::H[] =   {B00000000,B00100100,B00100100,B00111100,B00100100,B00100100,B00100100,B00000000};
const unsigned char LedMatrixSubsystem::I[] =   {B00000000,B00111000,B00010000,B00010000,B00010000,B00010000,B00111000,B00000000};
const unsigned char LedMatrixSubsystem::J[] =   {B00000000,B00011100,B00001000,B00001000,B00001000,B00101000,B00111000,B00000000};
const unsigned char LedMatrixSubsystem::K[] =   {B00000000,B00100100,B00101000,B00110000,B00101000,B00100100,B00100100,B00000000};
const unsigned char LedMatrixSubsystem::L[] =   {B00000000,B00100000,B00100000,B00100000,B00100000,B00100000,B00111100,B00000000};
const unsigned char LedMatrixSubsystem::M[] =   {B00000000,B00000000,B01000100,B10101010,B10010010,B10000010,B10000010,B00000000};
const unsigned char LedMatrixSubsystem::N[] =   {B00000000,B00100010,B00110010,B00101010,B00100110,B00100010,B00000000,B00000000};
const unsigned char LedMatrixSubsystem::O[] =   {B00000000,B00111100,B01000010,B01000010,B01000010,B01000010,B00111100,B00000000};
const unsigned char LedMatrixSubsystem::P[] =   {B00000000,B00111000,B00100100,B00100100,B00111000,B00100000,B00100000,B00000000};
const unsigned char LedMatrixSubsystem::Q[] =   {B00000000,B00111100,B01000010,B01000010,B01000010,B01000110,B00111110,B00000001};
const unsigned char LedMatrixSubsystem::R[] =   {B00000000,B00111000,B00100100,B00100100,B00111000,B00100100,B00100100,B00000000};
const unsigned char LedMatrixSubsystem::S[] =   {B00000000,B00111100,B00100000,B00111100,B00000100,B00000100,B00111100,B00000000};
const unsigned char LedMatrixSubsystem::T[] =   {B00000000,B01111100,B00010000,B00010000,B00010000,B00010000,B00010000,B00000000};
const unsigned char LedMatrixSubsystem::U[] =   {B00000000,B01000010,B01000010,B01000010,B01000010,B00100100,B00011000,B00000000};
const unsigned char LedMatrixSubsystem::V[] =   {B00000000,B00100010,B00100010,B00100010,B00010100,B00010100,B00001000,B00000000};
const unsigned char LedMatrixSubsystem::W[] =   {B00000000,B10000010,B10010010,B01010100,B01010100,B00101000,B00000000,B00000000};
const unsigned char LedMatrixSubsystem::X[] =   {B00000000,B01000010,B00100100,B00011000,B00011000,B00100100,B01000010,B00000000};
const unsigned char LedMatrixSubsystem::Y[] =   {B00000000,B01000100,B00101000,B00010000,B00010000,B00010000,B00010000,B00000000};
const unsigned char LedMatrixSubsystem::Z[] =   {B00000000,B00111100,B00000100,B00001000,B00010000,B00100000,B00111100,B00000000};
const unsigned char LedMatrixSubsystem::CLR[] = {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};
const unsigned char LedMatrixSubsystem::N0[] =  {B01110000,B10001000,B10011000,B10101000,B11001000,B10001000,B01110000,B00000000};
const unsigned char LedMatrixSubsystem::N1[] =  {B01000000,B11000000,B01000000,B01000000,B01000000,B01000000,B11100000,B00000000};
const unsigned char LedMatrixSubsystem::N2[] =  {B01110000,B10001000,B00001000,B00010000,B00100000,B01000000,B11111000,B00000000};
const unsigned char LedMatrixSubsystem::N3[] =  {B11111000,B00010000,B00100000,B00010000,B00001000,B10001000,B01110000,B00000000};
const unsigned char LedMatrixSubsystem::N4[] =  {B00010000,B00110000,B01010000,B10010000,B11111000,B00010000,B00010000,B00000000};
const unsigned char LedMatrixSubsystem::N5[] =  {B11111000,B10000000,B11110000,B00001000,B00001000,B10001000,B01110000,B00000000};
const unsigned char LedMatrixSubsystem::N6[] =  {B00110000,B01000000,B10000000,B11110000,B10001000,B10001000,B01110000,B00000000};
const unsigned char LedMatrixSubsystem::N7[] =  {B11111000,B10001000,B00001000,B00010000,B00100000,B00100000,B00100000,B00000000};
const unsigned char LedMatrixSubsystem::N8[] =  {B01110000,B10001000,B10001000,B01110000,B10001000,B10001000,B01110000,B00000000};
const unsigned char LedMatrixSubsystem::N9[] =  {B01110000,B10001000,B10001000,B01111000,B00001000,B00010000,B01100000,B00000000};

// <<constructor>>
LedMatrixSubsystem::LedMatrixSubsystem()
{
  /* we always wait a bit between updates of the display */
  delaytime1=500;
  delaytime2=50;

  prevMillis = 0;
  currMillis = 0;

  currentValue = CLR;
  indexOfValue = 0;
}

/*
 This method will display the characters for the
 word "Arduino" one after the other on the matrix. 
 (you need at least 5x7 leds to see the whole chars)
 */
void LedMatrixSubsystem::writeArduinoOnMatrix() {
  /* here is the data for the characters */
  byte a[5]={B01111110,B10001000,B10001000,B10001000,B01111110};
  byte r[5]={B00010000,B00100000,B00100000,B00010000,B00111110};
  byte d[5]={B11111110,B00010010,B00100010,B00100010,B00011100};
  byte u[5]={B00111110,B00000100,B00000010,B00000010,B00111100};
  byte i[5]={B00000000,B00000010,B10111110,B00100010,B00000000};
  byte n[5]={B00011110,B00100000,B00100000,B00010000,B00111110};
  byte o[5]={B00011100,B00100010,B00100010,B00100010,B00011100};

  /* now display them one by one with a small delay */
  lc.setRow(0,0,a[0]);
  lc.setRow(0,1,a[1]);
  lc.setRow(0,2,a[2]);
  lc.setRow(0,3,a[3]);
  lc.setRow(0,4,a[4]);
  delay(delaytime1);
  lc.setRow(0,0,r[0]);
  lc.setRow(0,1,r[1]);
  lc.setRow(0,2,r[2]);
  lc.setRow(0,3,r[3]);
  lc.setRow(0,4,r[4]);
  delay(delaytime1);
  lc.setRow(0,0,d[0]);
  lc.setRow(0,1,d[1]);
  lc.setRow(0,2,d[2]);
  lc.setRow(0,3,d[3]);
  lc.setRow(0,4,d[4]);
  delay(delaytime1);
  lc.setRow(0,0,u[0]);
  lc.setRow(0,1,u[1]);
  lc.setRow(0,2,u[2]);
  lc.setRow(0,3,u[3]);
  lc.setRow(0,4,u[4]);
  delay(delaytime1);
  lc.setRow(0,0,i[0]);
  lc.setRow(0,1,i[1]);
  lc.setRow(0,2,i[2]);
  lc.setRow(0,3,i[3]);
  lc.setRow(0,4,i[4]);
  delay(delaytime1);
  lc.setRow(0,0,n[0]);
  lc.setRow(0,1,n[1]);
  lc.setRow(0,2,n[2]);
  lc.setRow(0,3,n[3]);
  lc.setRow(0,4,n[4]);
  delay(delaytime1);
  lc.setRow(0,0,o[0]);
  lc.setRow(0,1,o[1]);
  lc.setRow(0,2,o[2]);
  lc.setRow(0,3,o[3]);
  lc.setRow(0,4,o[4]);
  delay(delaytime1);
  lc.setRow(0,0,0);
  lc.setRow(0,1,0);
  lc.setRow(0,2,0);
  lc.setRow(0,3,0);
  lc.setRow(0,4,0);
  delay(delaytime1);

}

/*
  This function lights up a some Leds in a row.
 The pattern will be repeated on every row.
 The pattern will blink along with the row-number.
 row number 4 (index==3) will blink 4 times etc.
 */
void LedMatrixSubsystem::rows() {
  for(int row=0;row<8;row++) {
    delay(delaytime2);
    lc.setRow(0,row,B10100000);
    delay(delaytime2);
    lc.setRow(0,row,(byte)0);
    for(int i=0;i<row;i++) {
      delay(delaytime2);
      lc.setRow(0,row,B10100000);
      delay(delaytime2);
      lc.setRow(0,row,(byte)0);
    }
  }
}

/*
  This function lights up a some Leds in a column.
 The pattern will be repeated on every column.
 The pattern will blink along with the column-number.
 column number 4 (index==3) will blink 4 times etc.
 */
void LedMatrixSubsystem::columns() {
  for(int col=0;col<8;col++) {
    delay(delaytime2);
    lc.setColumn(0,col,B00100000);
    delay(delaytime2);
    lc.setColumn(0,col,(byte)0);
    for(int i=0;i<col;i++) {
      delay(delaytime2);
      lc.setColumn(0,col,B00100000);
      delay(delaytime2);
      lc.setColumn(0,col,(byte)0);
    }
  }
}

/* 
 This function will light up every Led on the matrix.
 The led will blink along with the row-number.
 row number 4 (index==3) will blink 4 times etc.
 */
void LedMatrixSubsystem::single() {
  for(int row=0;row<8;row++) {
    for(int col=0;col<8;col++) {
      delay(delaytime2);
      lc.setLed(0,row,col,true);
      delay(delaytime2);
      for(int i=0;i<col;i++) {
        lc.setLed(0,row,col,false);
        delay(delaytime2);
        lc.setLed(0,row,col,true);
        delay(delaytime2);
      }
    }
  }
}

/*
  Display letter.
*/
void LedMatrixSubsystem::displayValue(const unsigned char value[]) {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, value[i]);
  }
}

/*
  Write Voltage
*/
void LedMatrixSubsystem::writeVoltageMatrix() {
  displayValue(T);
  delay(delaytime1);
  displayValue(E);
  delay(delaytime1);
  displayValue(A);
  delay(delaytime1);
  displayValue(M);
  delay(delaytime1);
  displayValue(CLR);
  delay(delaytime1);

  displayValue(V);
  delay(delaytime1);
  displayValue(O);
  delay(delaytime1);
  displayValue(L);
  delay(delaytime1);
  displayValue(T);
  delay(delaytime1);
  displayValue(A);
  delay(delaytime1);
  displayValue(G);
  delay(delaytime1);
  displayValue(E);
  delay(delaytime1);
  displayValue(CLR);
  delay(delaytime1);

  displayValue(N3);
  delay(delaytime1);
  displayValue(N8);
  delay(delaytime1);
  displayValue(N6);
  delay(delaytime1);
  displayValue(CLR);
  delay(delaytime1);

  delay(delaytime1);
}

void LedMatrixSubsystem::updateToNextValue()
{
  // Increment the character index
  indexOfValue++;
  
  // If we reach the end of the characters, loop back to the start
  if (indexOfValue >= 17) {
    indexOfValue = 0;
  }

  // Set the current value to the next character
  switch (indexOfValue) {
    case 0: currentValue = T; break;
    case 1: currentValue = E; break;
    case 2: currentValue = A; break;
    case 3: currentValue = M; break;
    case 4: currentValue = CLR; break;
    case 5: currentValue = V; break;
    case 6: currentValue = O; break;
    case 7: currentValue = L; break;
    case 8: currentValue = T; break;
    case 9: currentValue = A; break;
    case 10: currentValue = G; break;
    case 11: currentValue = E; break;
    case 12: currentValue = CLR; break;
    case 13: currentValue = N3; break;
    case 14: currentValue = N8; break;
    case 15: currentValue = N6; break;
    case 16: currentValue = CLR; break;
    default: currentValue = LedMatrixSubsystem::CLR; break; // Default case to avoid uninitialized access
  }
}

void LedMatrixSubsystem::displayCurrentValue()
{
  displayValue(currentValue);
}

// Call this in setup() function
void LedMatrixSubsystem::setup()
{
  /*
  The MAX72XX is in power-saving mode on startup,
  we have to do a wakeup call
  */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
}

// Call this in loop() function
void LedMatrixSubsystem::loop()
{
  // If you uncomment this line, the led matrix subsystem will never let go
  //writeVoltageMatrix();

  // save the current ms step count
  currMillis = millis();

  // if curr - prev is greater or equal to blink interval, blink
  if (currMillis - prevMillis >= delaytime1)
  {
    prevMillis = currMillis;
    updateToNextValue();
  }

  //display the value
  displayCurrentValue();
}
