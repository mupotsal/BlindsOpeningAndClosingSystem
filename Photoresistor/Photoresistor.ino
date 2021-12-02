/*
  SparkFun Inventor's Kit
  Example sketch 07

  PHOTORESISTOR

  Read a photoresistor (light sensor) to detect "darkness" and turn on an LED when it
  is "dark" and turn back off again when it is "bright.

  This sketch was written by SparkFun Electronics,
  with lots of help from the Arduino community.
  This code is completely free for any use.
  Visit http://learn.sparkfun.com/products/2 for SIK information.
  Visit http://www.arduino.cc to learn about the Arduino.
*/


// As usual, we'll create constants to name the pins we're using.
// This will make it easier to follow the code below.

const int sensorPin = A4;
const int ledPin = 8;
int buttonState = 0;  
int last_state=0;

// We'll also set up some global variables for the light level a calibration value and
//and a raw light value
const int ENABLE=9;
const int DIRL=10;
const int DIRR=11;
int lightVal;


void setup()
{
  // We'll set up the LED pin to be an output.
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ENABLE, OUTPUT);
  pinMode(DIRL,OUTPUT);
  pinMode(DIRR,OUTPUT);
  //we will take a single reading from the light sensor and store it in the lightCal
  //variable. This will give us a prelinary value to compare against in the loop
  Serial.begin(300);
}


void loop()
{
  //Take a reading using analogRead() on sensor pin and store it in lightVal
  lightVal = analogRead(sensorPin);
  Serial.println(lightVal);

  //if lightVal is less than our initial reading (lightCal) minus 50 it is dark and
  //turn pin 9 HIGH. The (-50) part of the statement sets the sensitivity. The smaller
  //the number the more sensitive the circuit will be to variances in light.


  
  if (lightVal < 10 and last_state ==0 )
  {
    digitalWrite(8, HIGH);
    //left
    digitalWrite(ENABLE,HIGH);
    digitalWrite(DIRL,HIGH);
    digitalWrite(DIRR,LOW);
    delay(3000);
    digitalWrite(ENABLE,LOW);
    Serial.println("Pressed");
    last_state = 1;
  }

  //else, it is bright, turn pin 9 LOW
  if ( lightVal >10 and last_state==1)
  {
    //right
    digitalWrite(8, LOW);
    digitalWrite(ENABLE,HIGH);
    digitalWrite(DIRL,LOW);
    digitalWrite(DIRR,HIGH);
    delay(3000);
    digitalWrite(ENABLE,LOW);
    last_state = 0;
  }

}
