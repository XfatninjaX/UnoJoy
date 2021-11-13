/*******************************************************
 * Instructions:                                       *
 * Pleae, refer to the "Instructions.txt" file in the  *
 * root directory.                                     *
 * *****************************************************
 */

// Imports UnoJoy.h library.
#include "UnoJoy.h"
 
void setup() {
  setupPins();
  setupUnoJoy();
  Serial.begin(38400);
}

void loop() {
  // Always be getting fresh data
  dataForController_t controllerData = getControllerData();
  setControllerData(controllerData);
  const int xAxis = analogRead(A0);
  const int yAxis = analogRead(A1);
  //Serial.print(xAxis);
  //Serial.print("\n");
  //Serial.print(yAxis);
  //Serial.print("\n");
}

void setupPins(void) {
  // Sets digital pins as inputs
  // with the pull-up enabled, except for the
  // two serial line pins
  // The for loop below will set digital pins 2
  // through 5. If using more buttons, adjust
  // the second number accordingly. Do not skip pins.
  for (int i = 2; i <= 6; i++) {
    pinMode(i, INPUT);
    digitalWrite(i, HIGH);
  }
  pinMode(A0, INPUT);
  //digitalWrite(A0, HIGH);
  pinMode(A1, INPUT);
  //digitalWrite(A1, HIGH);
}

dataForController_t getControllerData(void) {

  // Set up a place for our controller data
  //  Use the getBlankDataForController() function, since
  //  just declaring a fresh dataForController_t tends
  //  to get you one filled with junk from other, random
  //  values that were in those memory locations before
  dataForController_t controllerData = getBlankDataForController();
  // Since our buttons are all held high and
  //  pulled low when pressed, we use the "!"
  //  operator to invert the readings from the pins

  // If your controller has more buttons, uncomment
  // additional controllerData statements and set
  // to correct digital pin number if different.
  controllerData.triangleOn = !digitalRead(2);
  controllerData.circleOn = !digitalRead(3);
  controllerData.squareOn = !digitalRead(4);
  controllerData.crossOn = !digitalRead(5);
  //controllerData.dpadUpOn = !digitalRead(6);
  //controllerData.dpadDownOn = !digitalRead(7);
  //controllerData.dpadLeftOn = !digitalRead(8);
  //controllerData.dpadRightOn = !digitalRead(9);
  //controllerData.l1On = !digitalRead(10);
  //controllerData.r1On = !digitalRead(11);
  //controllerData.selectOn = !digitalRead(12);
  //controllerData.startOn = !digitalRead(A4);
  //controllerData.homeOn = !digitalRead(A5);

  // Set the analog sticks
  //  Since analogRead(pin) returns a 10 bit value,
  //  we need to perform a bit shift operation to
  //  lose the 2 least significant bits and get an
  //  8 bit number that we can use

  // If your controller has a second analog stick,
  // uncomment additional controllerData statements,
  // one for each axis, and set to correct analog pin numbers.
  controllerData.leftStickX = analogRead(A0) >> 2;
  controllerData.leftStickY = analogRead(A1) >> 2;
  //controllerData.rightStickX = analogRead(A2) >> 2;
  //controllerData.rightStickY = analogRead(A3) >> 2;
  // And return the data!
  return controllerData;
}
