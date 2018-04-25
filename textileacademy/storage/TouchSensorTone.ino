/*
This code was created by Saverio Silli for Textile Academy 2017
www.textileacademy.org, based on the:

 Arduino Starter Kit example
 Project 13  - Touch Sensor Lamp
 Created 18 September 2012
 by Scott Fitzgerald
 http://www.arduino.cc/starterKit

 Software required :
 CapacitiveSensor library by Paul Badger
 http://www.arduino.cc/playground/Main/CapacitiveSensor

 This example code is part of the public domain
 */

// import the library (must be located in the
// Arduino/libraries directory)
#include <CapacitiveSensor.h>

// create an instance of the library
// pin 4 sends electrical energy
// pin 2 senses senses a change
CapacitiveSensor capSensor = CapacitiveSensor(4, 2);

// threshold for turning the piezo on
int threshold = 10000;

void setup() {
  // open a serial connection
  Serial.begin(9600);
}

void loop() {
  // store the value reported by the sensor in a variable
  long sensorValue = capSensor.capacitiveSensor(30);

  // print out the sensor value
  Serial.println(sensorValue);

  // if the value is greater than the threshold
  if (sensorValue > threshold) {

  // map the sensor values to a wide range of pitches
  int pitch = map(sensorValue, 300, 25000, 50, 4000);

  // play the tone for 100 ms on pin 8
  tone(8, pitch, 100);

  // wait for a moment
  delay(100);
  }
  
  // if it's lower than the threshold
  else {
    // turn the piezo off
    noTone(8);
  }


}



