// 1- Nygel Sotomayor 655654678
// 2- Lab 6 - Serial Communication
// 3- Description - This code utilizes the SoftwareSerial Library to create a SoftwareSerial object which essentially handles stuff written to the Software port via the serial.read and vice versa
//                  which then turns on the respective light on the board
// 4- The only assumptions I made were in utilizing the SoftwareSerial Library
// 5- References - The references I utilized was the Arduino writeup for the SoftwareSerial Library https://www.arduino.cc/en/Reference/softwareSerial
// 6- In Person Demo: Anjani
#include <SoftwareSerial.h>
//All our global variables
SoftwareSerial mySerial(11, 9); // RX, TX
const int buttonPin1 = 4; // BLUE
const int ledPin1 = 3; // BLUE
const int buttonPin2 = 6; // RED
const int ledPin2 = 5; // RED
const int bufSize = 2;
char buf1[bufSize];
char buf2[bufSize];

int state1 = 0;
int state2 = 0;
void setup()
{
  //Begin our SoftwareSerial and digitalSerial
  Serial.begin(9600);
  mySerial.begin(9600);
  //Setup our inputs and outputs
  pinMode(buttonPin1, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(ledPin2, OUTPUT);
  
}
// Functions to handle inputs and outputs
void writeSerial(){
  if(digitalRead(buttonPin1) == HIGH){
    Serial.write("1");
  }
  else{
    Serial.write("0");
  }
}

void readSerial(){
  buf1[0] = Serial.read();
  buf1[1] = '\0';
  //Serial.println(buf[0]);
  
  if(buf1[0] == '1'){
    state1 = 1;
  } else {
    state1 = 0;
  }

  digitalWrite(ledPin1, state1);
}

void writeSoftware(){
  if(digitalRead(buttonPin2) == HIGH){
    mySerial.write("1");
  }
  else{
    mySerial.write("0");
  }
}

void readSoftware(){
  buf2[0] = mySerial.read();
  buf2[1] = '\0';
  //Serial.println(buf[0]);
  
  if(buf2[0] == '1'){
    state2 = 1;
  } else {
    state2 = 0;
  }

  digitalWrite(ledPin2, state2);
}
//Our Main Loop
void loop()
{
  writeSerial();
  readSerial();
  writeSoftware();
  readSoftware();
  //Below for debugging buttons and LED's
  /*
  if(digitalRead(buttonPin2) == HIGH){
    Serial.println("2");
    digitalWrite(ledPin2, HIGH);
  } else {
    digitalWrite(ledPin2, LOW);
  }
  if(digitalRead(buttonPin1) == HIGH){
    Serial.println("1");
    digitalWrite(ledPin1,HIGH);
  } else {
    digitalWrite(ledPin1, LOW);
  }
  */
  /* if (mySerial.available())
    Serial.write(mySerial.read());
  if (Serial.available())
    mySerial.write(Serial.read());
    */
}
