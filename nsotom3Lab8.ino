// 1- Nygel Sotomayor 655654678
// 2- Lab 8 - Graphing sensor data on a PC
// 3- Description - This code essentially initializes the potentiometer and photoresistor as a analog input as we did in lab 4 and utilizes processing to graph our analog values.
// 4- Assumptions - There wasn't much assumptions that I made for this lab except for the two analog inputs being on the same lab
// 5- References - The references I used for this lab were as followed
//                 and https://create.arduino.cc/projecthub/MisterBotBreak/how-to-use-a-photoresistor-46c5eb for the photoresistor
//                 and https://learn.sparkfun.com/tutorials/connecting-arduino-to-processing#introduction for using processing, I referenced their code skeleton in setting up processing
//                 and https://docs.arduino.cc/built-in-examples/basics/AnalogReadSerial for setting up my potentiometer
// 6- In Person Demo: Anjani

void setup() {
  //Initialize the serial monitor
  Serial.begin(9600);
}

void loop() {

  int photo = analogRead(A0);
  int pot = analogRead(A1);
  Serial.println(photo);
  Serial.println(pot);
  //delay(2000);
  
}
