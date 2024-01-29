// 1- Nygel Sotomayor 655654678
// 2- Lab 7 - Interruption
// 3- Description - This code essentially calls the attachInterrupt fucntion on my 2 buttons with their respective interupt or reset functions and outputs to the LED SCREEN 
// 4- The assumptions I made was the format of my output to the lcd screen and utilizing a counter instead of millis and delaying by one second each time
// 5- References - The references I utilized was given by the professor https://docs.arduino.cc/learn/electronics/lcd-displays to see how to implement the LED Screen
//                 and https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/ to see how to implement the attachInterrupt function
// 6- In Person Demo: Brian
#include <LiquidCrystal.h>
//Time Libraries
#include <TimeLib.h>
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
// Our constants
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 8, d7 = 9, btn1 = 3, btn2 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//Our global variables for time and state
int seconds = 0;
bool state = false;
//int state11 = 0;
//int state2 = 0;
//Our Setup
void setup() {
  //Initialize the serial monitor
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP); 

  attachInterrupt(digitalPinToInterrupt(btn1), Inter, CHANGE); 
  attachInterrupt(digitalPinToInterrupt(btn2), Reset, CHANGE);
}

void loop() {
  //Serial.print("1");
  if(state == false) {
    lcd.clear();
    state = false;
    lcd.setCursor(0, 0);
    lcd.print("Waiting for: ");
    lcd.setCursor(0, 1);
    lcd.print(seconds);
    lcd.print(" seconds");
    seconds++;
    delay(1000);
    lcd.clear();
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Interupt recieved!");
    lcd.setCursor(0,1);
    lcd.print("Press btn2 reset");
    delay(100);
    lcd.clear();
  }
  /*
  state11 = digitalRead(btn1);
  state2 = digitalRead(btn2);
  if(state11 == LOW) {
    Serial.print("1");
  }
  if (state2 == LOW){
    Serial.print("2");
  }
  */
}
void Inter()
{
  state = true;
  Serial.print("1");
}

// called when the yellow button is pressed
void Reset()
{
  if (state == true)
  {
    seconds = 0;
    Serial.print("2");
    state = false;
  }
}
