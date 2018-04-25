
/*

Knitting Machine motor control
Upload this sketch to an arduino and use it to change the speed
of the a stepper motor.
The circular knitting machine modified for Textile Academy 2017 by Saverio Silli in Shanghai
use a Shanghaino board and a simple stepper driver shield with a potentiometer.

The motor is attached to digital pins 8 - 9 of the Arduino.
A potentiometer is connected to analog input 0.

 "The motor will rotate in a clockwise direction. The higher the potentiometer value,
 the faster the motor speed. Because setSpeed() sets the delay between steps,
 you may notice the motor is less responsive to changes in the sensor value at
 low speeds."
 
 Based on:
 
 Stepper Motor Control - speed control

 Created 30 Nov. 2009
 Modified 28 Oct 2010
 by Tom Igoe

 */

#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor
const int maxspeed = 400; //maximum speed of the motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

int stepCount = 0;  // number of steps the motor has taken

void setup() {
  // nothing to do inside the setup
}

void loop() {
  // read the sensor value:
  int sensorReading = analogRead(A0);
  // map it to a range from 0 to maxspeed (you can increase the maximum speed):
  int motorSpeed = map(sensorReading, 0, 1023, 0, maxspeed);
  // set the motor speed:
  if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed);
    // step 1/100 of a revolution:
    myStepper.step(stepsPerRevolution / 100);
  }
}


