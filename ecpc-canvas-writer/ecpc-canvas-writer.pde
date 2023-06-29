/*********************************************************************
  ECPC Identity Display Writer
*********************************************************************/

// Global Defs
int LINE_HEIGHT = 14;

// Setup
void setup() {
  noSmooth();
  pixelDensity(1);
  size(128,128);
  background(0);
  stroke(255);
  PFont font = createFont("VenusMedium.otf", 14);
  textFont(font);
  textAlign(CENTER);
  noLoop();
}

// Draw
void draw() {
  
  
  /*******************************************************************
    DRAW TEXT
    Uncomment the line below if you want to display text
  *******************************************************************/
  //drawText();
  /******************************************************************/
  
  
  /*******************************************************************
    DRAW LINES
    Uncomment the line below if you want to display lines.
    the argument is an interger *between 1 and 36* which represents
    the number of lines that will be drawn. The lines should equal
    the number of days that have passed since day 1 of the program.
  *******************************************************************/
   drawLines(15);
  /******************************************************************/
    
      
  /*******************************************************************
    SAVE
    Uncomment the line below if you want to save an image of result.
  *******************************************************************/
  // save("filename.png");
  /******************************************************************/
  
  
  filter(THRESHOLD);
}

void drawText() {
  // counter variable
  int i = 1;
  
  /*******************************************************************
    TEXT CONTENT
    Edit the strings below to change the copy displayed on-screen
  *******************************************************************/
  drawTextLine("ECPC", i);
  i++;
  drawTextLine("", i);
  i++;
  drawTextLine("Electronic Cafe for", i);
  i++;
  drawTextLine("Poetic Computation", i);
  i++;
  drawTextLine("in Session at Recess", i);
  i++;
  drawTextLine("", i);
  i++;
  drawTextLine("", i);
  i++;
  drawTextLine("Jul 8 -  Aug 12", i);
  i++;
  /******************************************************************/
}

// Draw Lines
void drawLines(int count) {
  int r = 200;
  int x1 = 64;
  int y1 = 127;
  for (int i = 0; i <= count; i++) {
    float theta = PI + (PI/36) * i;
    float x2 = r * cos(theta) + x1;
    float y2 = r * sin(theta) + y1;
    line(x1, y1, x2, y2);
  }
}

// Print (Text) Line
void drawTextLine(String text, int i) {
  int yOffset = 7 + LINE_HEIGHT * i;
  text(text, width/2, yOffset);
}
