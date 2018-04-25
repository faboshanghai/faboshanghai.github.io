/*
* This code, modified by Saverio Silli for Textile Academy 2017
* www.textileacademy.org
* It is made for an Attiny44, it can run on 3.2volts
* It uses a slider potentiometer to select 8 colors combination from a RGB LED
* the max brightness of the led is set to 125 as it is more bright than 256. Maybe should set 255? have to try
* based on a sketch by:
* Clay Shirky <clay.shirky@nyu.edu> 
*/

// INPUT: Potentiometer should be connected to 5V and GND
int potPin = A1; // Potentiometer output connected to analog pin 3
int potVal = 0; // Variable to store the input from the potentiometer

// OUTPUT: Use digital pins 6-8 (attiny equivalent), with Pulse-width Modulation (PWM)
// LED's cathodes should be connected to digital GND (longer leg)
int redPin = 8;   // Red LED,   connected to digital pin 8
int grnPin = 7;  // Green LED, connected to digital pin 7
int bluPin = 6;  // Blue LED,  connected to digital pin 6

// Program variables
int redVal = 0;   // Variables to store the values to send to the pins
int grnVal = 0;
int bluVal = 0;

void setup()
{

}

// Main program
void loop()
{
  potVal = analogRead(potPin);   // read the potentiometer value at the input pin

  if (potVal < 128)  // Lowest eight of the potentiometer's range (0-128)
  { 
    redVal = 125; // Red on
    grnVal = 0;   // Green off
    bluVal = 0;   // Blue off
  }
  else if (potVal < 256) // Second eight of potentiometer's range (128-256)
  {
    redVal = 0;   // Red off
    grnVal = 0;   // Green off
    bluVal = 125; // Blue on
  }
    else if (potVal < 384) // Third eight of potentiometer's range (256-384)
  {
    redVal = 0;   // Red off
    grnVal = 125; // Green on
    bluVal = 0;   // Blue off
  }
    else if (potVal < 512) // Fourth eight of potentiometer's range (384-512)
  {
    redVal = 0;   // Red off
    grnVal = 125; // Green on
    bluVal = 125; // Blue on
  }
    else if (potVal < 640) // Fifht eight of potentiometer's range (512-640)
  {
    redVal = 125; // Red on
    grnVal = 0;   // Green off
    bluVal = 125; // Blue on
  }
    else if (potVal < 768) // Sixth eight of potentiometer's range (640-768)
  {
    redVal = 125;  // Red on
    grnVal = 125; // Green on
    bluVal = 0;  // Blue off
  }
    else if (potVal < 896) // Seventh eight of potentiometer's range (768-896)
  {
    redVal = 125; // Red on
    grnVal = 125; // Green on
    bluVal = 125; // Blue on
  }
  else  // Upper eight of potentiometer"s range (896-1023)
  {
    redVal = 0; // Red off
    grnVal = 0; // Green off
    bluVal = 0; // Blue off
  }
  analogWrite(redPin, redVal);   // Write values to LED pins
  analogWrite(grnPin, grnVal); 
  analogWrite(bluPin, bluVal);  
  delay(100); // Delay to avoid blinkings and interference
}

