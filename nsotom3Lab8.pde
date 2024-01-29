import processing.serial.*;
Serial myPort;
String val; 
int xPos = 1; 
float inByte = 0;
void setup()
{
    size(400, 300);
    background(0);
    String portName = Serial.list()[1];
    myPort = new Serial(this, portName, 9600);
    myPort.bufferUntil('\n');
}
void draw()
{
    stroke(127, 34, 255);
    line(xPos, height, xPos, height - inByte);
    if (xPos >= width) {
      xPos = 0;
      background(0);
    } else {
      xPos++;
    }
  /*if ( myPort.available() > 0) {
    val = myPort.readStringUntil('\n');
  } 
  println(val);
  */
}
void serialEvent (Serial myPort) {
    String inString = myPort.readStringUntil('\n');
    if (inString != null) {
      // trim off any whitespace:
      inString = trim(inString);
      // convert to an int and map to the screen height:
      inByte = float(inString);
      println(inByte);
      inByte = map(inByte, 0, 1023, 0, height);
    }
  }
