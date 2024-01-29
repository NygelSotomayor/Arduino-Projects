// 1- Nygel Sotomayor 655654678
// 2- Lab 3 - Scrolling Output 
// 3- Description - This code turns on the LED Screen and Displays my name and the first few lines of my chosen quote that scrolls across the screen.
// 4- The only assumption I made was that I decide what happens when the number of presses is 7>= or <=0 which I represented by having all lights stay lit untill it goes back in range
// 5- References - The only reference I utilized was given by the professor https://docs.arduino.cc/learn/electronics/lcd-displays to see how to implement the LED Screen and how to scroll the text
// 6- In Person Demo: Micheal 
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
// Our constants
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//Our global position variable
int cursorPosition = 0;
//Our quote
String myQuote = "Somebody once told me the world is gonna roll me I ain't the sharpest tool in the shed. She was looking kind of dumb with her finger and her thumb In the shape of an L on her forehead";
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Nygel Sotomayor");
}

void loop() {
  //lcd.setCursor(0,1);//setting cursor on LCD
  //lcd.print("Somebody once told me the world is gonna roll me I ain't the sharpest tool in the shed. She was looking kind of dumb with her finger and her thumb In the shape of an L on her forehead");
  //length of quote
  int lengthOfQuote = myQuote.length();
  // if at end of quote reset to beginning
  if (cursorPosition == (lengthOfQuote - 1)) {
    cursorPosition = 0;
  }
  //cursor to first spot on screen
  lcd.setCursor(0,1);
  // our loops to traverse down the quote till the last 16 letters
  if(cursorPosition < lengthOfQuote - 16) {
    for (int i = cursorPosition; i < cursorPosition + 16; i++) {
      lcd.print(myQuote[i]);
    }
  } else {
    for (int i = cursorPosition; i < lengthOfQuote - 1; i++) {
      lcd.print(myQuote[i]);
    }
    for (int i = 0; i <= 16 - (lengthOfQuote - cursorPosition); i++) {
      lcd.print(myQuote[i]);
    }
  }
  cursorPosition++;
  // our scrolling speed in a sense
  delay(250);
}
