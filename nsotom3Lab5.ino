// 1- Nygel Sotomayor 655654678
// 2- Lab 5 - Communication
// 3- Description - This code turns on the LED Screen and prompts the user in the serial monitor for input in the form of mm/dd/yyyy hh/mm/ss which it then checks the validity of the input
//                  and outputs the time starting at the given user input
// 4- The assumptions I made was the format of my output to the lcd screen
// 5- References - The references I utilized was given by the professor https://docs.arduino.cc/learn/electronics/lcd-displays to see how to implement the LED Screen
//                 and https://www.arduino.cc/reference/en/language/functions/communication/serial/parseint/ to utilize the parseint functionality
//                 and other references given by the professor in the project documentation
// 6- In Person Demo: Anjani
#include <LiquidCrystal.h>
//Time Libraries
#include <TimeLib.h>
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
// Our constants
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//Our global variables for time input
int months = 0;
int days = 0;                  
int years = 0;
int hours = 0;          
int minutes = 0;
int seconds = 0;
bool validInput = false;
//Our Setup
void setup() {
  //Initialize the serial monitor
  Serial.begin(9600);
  //Print prompt to serial monitor
  Serial.println("Enter MM/DD/YYYY & HH/MM/SS");
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  //While serial monitor is open
  while(Serial.available() > 0){
    months = Serial.parseInt();
    days = Serial.parseInt();
    years = Serial.parseInt();
    hours = Serial.parseInt();
    minutes = Serial.parseInt();
    seconds = Serial.parseInt();
    //Check Months
    if (months > 12 || months < 1){
      Serial.println("Invalid Month");
      break;
    }
    //Check Days in Months
    if (months == 1|| months == 3 || months == 5 || months == 7 || months == 8 || months == 10 || months == 12){
      if(days >= 1 && days <= 31){
        //Do nothing
      } else {
        Serial.println("Invalid Days");
        break;
      }
    } else if (months == 4 || months == 6 || months == 9 || months == 11){
      if(days >= 1 && days <= 30){
      //Do nothing
      } else {
        Serial.println("Invalid Days");
        break;
      }
    } else if (months == 2){
      if(days >= 1 && days <= 28){
        //Do nothing
      } else {
        Serial.println("Invalid Days");
        break;
      }   
    } else {
      Serial.println("Invalid Days/Months");
      break;
    }
    //Check Hours
    if (hours < 0 || hours > 24) {
      Serial.println("Invalid Hours");
      break;
    }
    //Check Minutes
    if (minutes < 0 || minutes >= 59) {
      Serial.println("Invalid Minutes");
      break;
    }
    //Check Seconds
    if (seconds < 0 || seconds >= 59) {
      Serial.println("Invalid Seconds");
      break;
    }

    //set our inputed time
    setTime(hours,minutes,seconds,days,months,years);
    validInput = true;
  }
    if (validInput == true) {
      time_t time = now();
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(month(time));
      lcd.print("/");
      lcd.print(day(time));
      lcd.print("/");
      lcd.print(year(time));
      lcd.setCursor(0,1);
      lcd.print(hour(time));
      lcd.print(":");
      lcd.print(minute(time));
      lcd.print(":");
      lcd.print(second(time));
      delay(1000);
      
      
    }
}
