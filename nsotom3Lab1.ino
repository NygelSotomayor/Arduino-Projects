
// 1- Nygel Sotomayor 655654678
// 2- Lab 1 - Get started with Arduino 
// 3- Description - This code turns on and off the 3 connected LEDS sequentually with a timer increasing by 2 times the last lights timer,
//                  while also checking if the other lights are currently off aswell to not overlap with eachother 
// 4- There weren't much assumptions made, the lab was straightforward
// 5- References - The only reference I utilized was https://www.arduino.cc/reference/en/language/functions/time/millis/ to see the functionality of the millis() function 
// 6- Demo: https://youtu.be/9V-nkYybnMo 
long timeDelay = 3000;
const int LED1 = 13;
const int LED2 = 12;
const int LED3 = 11;
int LED1STATE = LOW;
int LED2STATE = LOW;
int LED3STATE = LOW;
unsigned long lastTime1 = 0;
unsigned long lastTime2 = 0;
unsigned long lastTime3 = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(13, OUTPUT);
pinMode(12, OUTPUT);
pinMode(11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime = millis();
  if (currentTime - lastTime1 >= 200) {
    lastTime1 = currentTime;
    if ( LED1STATE == LOW && LED2STATE == LOW && LED3STATE == LOW) {
      LED1STATE = HIGH;
    } else {
      LED1STATE = LOW;
    }
    digitalWrite(LED1, LED1STATE);
  }
  if (currentTime - lastTime2 >= 400) {
    lastTime2 = currentTime;
    if ( LED2STATE == LOW && LED1STATE == LOW && LED3STATE == LOW) {
      LED2STATE = HIGH;
    } else {
      LED2STATE = LOW;
    }
    digitalWrite(LED2, LED2STATE);
  }
  if (currentTime - lastTime3 >= 800) {
    lastTime3 = currentTime;
    if ( LED3STATE == LOW && LED2STATE == LOW && LED1STATE == LOW) {
      LED3STATE = HIGH;
    } else {
      LED3STATE = LOW;
    }
    digitalWrite(LED3, LED3STATE);
}
}
