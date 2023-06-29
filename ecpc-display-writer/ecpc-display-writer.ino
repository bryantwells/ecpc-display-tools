/*********************************************************************
  ECPC Identity Display Adafruit_SH110x

  Adapted from: 
  https://github.com/adafruit/Adafruit_SH110x/tree/master/examples
*********************************************************************/

// Headers
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
/*******************************************************************
  CUSTOM FONT
  Uncomment this if you want to display text
  make sure this font is installed in your arduino folder
  {path_to_arduino_folder}/libraries/Adafruit_GFX_Library/Fonts
*******************************************************************/
#include <Fonts/VenusMedium7pt7b.h> 

// Global Definitions
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 128
#define OLED_RESET -1
Adafruit_SH1107 display = Adafruit_SH1107(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET, 1000000, 100000);
#define LINE_HEIGHT 14

// Setup
void setup()   {
  Serial.begin(9600);
  delay(250);
  display.begin(0x3D, true);

  /*******************************************************************
    DRAW TEXT
    Uncomment the line below if you want to display text
  *******************************************************************/
  drawText();
  /******************************************************************/

  /*******************************************************************
    DRAW LINES
    Uncomment the line below if you want to display lines.
    the argument is an interger *between 0 and 36* which represents
    the number of lines that will be drawn. The lines should equal
    the number of days that have passed since day 1 of the program.
  *******************************************************************/
  // drawLines(3);
  /******************************************************************/

}

void loop() {
}

// Draw Text
void drawText() {
  display.clearDisplay();
  display.setFont(&VenusMedium7pt7b);
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  int16_t i = 1;

  /*******************************************************************
    TEXT CONTENT
    Edit the strings below to change the copy displayed on-screen
  *******************************************************************/
  printLine("ECPC", i);
  i++;
  printLine("", i);
  i++;
  printLine("Electronic Cafe for", i);
  i++;
  printLine("Poetic Computation", i);
  i++;
  printLine("in Session at Recess", i);
  i++;
  printLine("", i);
  i++;
  printLine("", i);
  i++;
  printLine("Jul 8 -  Aug 12", i);
  /******************************************************************/

  display.display();
}

// Draw Lines
void drawLines(int16_t lineCount) {
  display.clearDisplay();
  int16_t i;
  int16_t r = 200;
  int16_t x1 = 64;
  int16_t y1 = 127;
  for (int16_t i = 0; i <= lineCount; i++) {
    float theta = PI + (PI/36) * i;
    float x2 = r * cos(theta) + x1;
    float y2 = r * sin(theta) + y1;
    display.drawLine(x1, y1, x2, y2, SH110X_WHITE);
  }
  display.display();
}

// Print (Text) Line
void printLine(char *text, int16_t i) {
  int16_t  x1, y1;
  uint16_t w, h;
  int16_t xOffset = 0;
  int16_t yOffset = 7 + LINE_HEIGHT * i;
  display.getTextBounds(text, 0, 0, &x1, &y1, &w, &h);
  xOffset = display.width() / 2 - w / 2;
  display.setCursor(xOffset, yOffset);
  display.print(text);
}