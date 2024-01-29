// 1- Nygel Sotomayor 655654678
// 2- Lab 9 - Recovery Lab
// 3- Description - This code essentially initializes the LCD Screen as show previously, we also set up the potentiometer as a analog input as we did in lab 4.
//                  Essentially based on the light level read in through the photoresistor, I output the current light level in 3 set ranges I defined (Well Lit, Medium Level, Low Level)
// 4- The assumptions I made was the format of my output to the lcd screen and that I can just have 3 ranges of light levels
// 5- References - The references I utilized was given by the professor https://docs.arduino.cc/learn/electronics/lcd-displays to see how to implement the LED Screen
//                 and https://create.arduino.cc/projecthub/MisterBotBreak/how-to-use-a-photoresistor-46c5eb for the photoresistor
// 6- In Person Demo: Anjani
#include <LiquidCrystal.h>
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
// Our constants
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//Our Setup
void setup() {
  //Initialize the serial monitor
  Serial.begin(9600);
  //Print prompt to serial monitor
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Light Status: ");
  lcd.setCursor(0,1);
  int value = analogRead(A0);
  Serial.println("Analog value : ");
  Serial.println(value);
  if (value > 700) { //High Light Level
  lcd.print("Well Lit");
  } else if (value < 700 && value > 600) { //Medium Light Level
  lcd.print("Semi Well Lit");
  } else if (value < 600 && value > 400) { // Light Level
  lcd.print("Meduim Lit");
  } else if (value < 400 && value > 200) {
    lcd.print("Low Lit");
  } else if (value < 200) { 
    lcd.print("Darkness");
  }
  delay(2000);
  
}
