// 1- Nygel Sotomayor 655654678
// 2- Lab 2 - Input and Output 
// 3- Description - This code turns on the leds relative to the binary value equal to the amount of button presses the user performs from 1-6
// 4- The only assumption I made was that I decide what happens when the number of presses is 7>= or <=0 which I represented by having all lights stay lit untill it goes back in range
// 5- References - The only reference I utilized was https://docs.arduino.cc/learn/programming/functions to see how to implement functions in the Arduino IDE
// our constants
// 6- Demo: https://youtu.be/C9DLPJkgA2g
const int button1Pin = 6;     // the number of the pushbutton pin
const int button2Pin = 5;     // the number of the pushbutton pin
const int ledPin1 =  13;      // the number of the LED pin
const int ledPin2 =  12;      // the number of the LED pin
const int ledPin3 =  11;      // the number of the LED pin
// variables that will change
int LED1STATE = LOW;          // LED states
int LED2STATE = LOW;
int LED3STATE = LOW;
int button1State = 0;         // variable for reading the button status
int button2State = 0;
int binaryCounter = 0;        // counter variable for button
int binaryArray[3] = {0,0,0}; // array to hold binary number

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  // initialize the button pin as an input:
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  // initialize the console
  Serial.begin(9600);
}

void loop() {
  // read the state of the button
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  
  // check if the button is pressed, if so delay another button press for set time and add to counter
  if (button1State == LOW) {
    binaryCounter++;
    delay(500);
  } else if (button2State == LOW) {
    binaryCounter--;
    delay(500);
  }
  // where we control our LEDS
  if (binaryCounter >= 7 || binaryCounter <= 0){  // If equal or greater than 7 or equal or lower than 0 all lights stay lit
    LED1STATE = HIGH;
    LED2STATE = HIGH;
    LED3STATE = HIGH;
  } else {
   binaryArray[0] = 0;    // constantly reset array values to avoid hanging 1's 
   binaryArray[1] = 0;
   binaryArray[2] = 0;
   binaryCalculator(binaryCounter); // our function for converting to binary and storing in our global array
   //Serial.println("BINARY");     for debugging in console
   //Serial.println(binaryCounter);
   //Serial.println(binaryArray[0]);
   //Serial.println(binaryArray[1]);
   //Serial.println(binaryArray[2]);
   if (binaryArray[0] == 1) {  //set led 1 on if 1 is in array index, else set led off
     LED1STATE = HIGH;
   } else {
     LED1STATE = LOW;
   }
   if (binaryArray[1] == 1) {  //set led 2 on if 1 is in array index, else set led off
     LED2STATE = HIGH;
   } else {
     LED2STATE = LOW;
   }
   if (binaryArray[2] == 1) {  //set led 3 on if 1 is in array index, else set led off
     LED3STATE = HIGH;
   } else {
     LED3STATE = LOW;
   }
  }
  digitalWrite(ledPin1, LED1STATE); //Sets LED 1 to determined state
  digitalWrite(ledPin2, LED2STATE); //Sets LED 2 to determined state
  digitalWrite(ledPin3, LED3STATE); //Sets LED 3 to determined state
}
void binaryCalculator (int counter){
   int i = 0; //Iterator
   counter = binaryCounter; //Current Value
   while (counter > 0) {
    binaryArray[i] = counter % 2;
    counter = counter / 2;
    i++;
   }
}
