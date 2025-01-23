#include <Arduino.h>

// Pin assignments for LEDs
int leftLedPin = 2;  // Left LED
int rightLedPin = 3; // Right LED
int rearLedPin = 4; // Rear LED

// Pin assignments for sensors
int leftSensorPin = 9;  // Left sensor
int rightSensorPin = 10; // Right sensor
int rearSensorPin = 11;  // Rear sensor


void setup() {
  // Define LEDs as output
  pinMode(leftLedPin, OUTPUT);
  pinMode(rightLedPin, OUTPUT);
  pinMode(rearLedPin, OUTPUT);

  // Define sensors as input
  pinMode(leftSensorPin, INPUT);
  pinMode(rightSensorPin, INPUT);
  pinMode(rearSensorPin, INPUT);
}

void loop() {
  int leftVal = digitalRead(leftSensorPin);  // Read left sensor
  int rightVal = digitalRead(rightSensorPin); // Read right sensor
  int rearVal = digitalRead(rearSensorPin);  // Read rear sensor

  // Control LEDs based on sensor values (turns on LED if obstacle detected)
  digitalWrite(leftLedPin, leftVal == LOW ? HIGH : LOW);  // Left LED
  digitalWrite(rightLedPin, rightVal == LOW ? HIGH : LOW); // Right LED
  digitalWrite(rearLedPin, rearVal == LOW ? HIGH : LOW);  // Rear LED
}
