// 1- Nygel Sotomayor 655654678
// 2- Lab 4 - Multiple Inputs and Outputs 
// 3- Description - This code reads the photoresistors analog value and if the number is in a certain range it will either turn all 4 LEDS on, only turn 2 on, or turn all 4 on
//                  while also reading the analog input from the potentiometer and changing the tone of the passive buzzer based off the value the potentiometer is returning
// 4- There weren't much assumptions made, the lab was straightforward
// 5- References - The only reference I utilized was for the passive buzzer https://create.arduino.cc/projecthub/SURYATEJA/use-a-buzzer-module-piezo-speaker-using-arduino-uno-89df45
// 6- Demo: https://youtu.be/gVgH5P1uTVU 
const int LED1 = 12;
const int LED2 = 11;
const int LED3 = 10;
const int LED4 = 9;
const int buzzer = 6;
int LED1STATE = LOW;
int LED2STATE = LOW;
int LED3STATE = LOW;
int LED4STATE = LOW;
void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(6, OUTPUT);
}


void loop() {
  int value = analogRead(A0);
  int pot = analogRead(A2);
  Serial.println("Analog value : ");
  Serial.println(value);
  Serial.println(pot);
  delay(250);
  tone(buzzer, pot);
  if (value > 280) {
    LED1STATE = LOW;
    LED2STATE = LOW;
    LED3STATE = LOW;
    LED4STATE = LOW;
    digitalWrite(LED1, LED1STATE);
    digitalWrite(LED2, LED2STATE);
    digitalWrite(LED3, LED3STATE);
    digitalWrite(LED4, LED4STATE);
  } else if (value < 300 && value > 150) {
    LED1STATE = HIGH;
    LED2STATE = HIGH;
    digitalWrite(LED1, LED1STATE);
    digitalWrite(LED2, LED2STATE);
    digitalWrite(LED3, LED3STATE);
    digitalWrite(LED4, LED4STATE);
  } else if (value < 150) {
    LED1STATE = HIGH;
    LED2STATE = HIGH;
    LED3STATE = HIGH;
    LED4STATE = HIGH;
    digitalWrite(LED1, LED1STATE);
    digitalWrite(LED2, LED2STATE);
    digitalWrite(LED3, LED3STATE);
    digitalWrite(LED4, LED4STATE);
  }
}
