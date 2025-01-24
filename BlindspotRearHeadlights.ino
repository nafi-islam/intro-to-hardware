#include <Arduino.h>

// Pin assignments for LEDs
int leftLedPin = 5;  // Left LED
int rightLedPin = 6; // Right LED
int rearLedPin = 9; // Rear LED
int headlightLedPin = 7; // Headlight reminder LED

// Pin assignments for sensors
int leftSensorPin = 2;  // Left sensor
int rightSensorPin = 3; // Right sensor
int rearSensorPin = 4;  // Rear sensor

// Pin assignment for photoresistor
int photoresistorPin = A2;

// Threshold for darkness detection
int darknessThreshold = 300; // Adjust this value if needed

void setup() {
  // Define LEDs as output
  pinMode(leftLedPin, OUTPUT);
  pinMode(rightLedPin, OUTPUT);
  pinMode(rearLedPin, OUTPUT);
  pinMode(headlightLedPin, OUTPUT);

  // Define sensors as input
  pinMode(leftSensorPin, INPUT);
  pinMode(rightSensorPin, INPUT);
  pinMode(rearSensorPin, INPUT);

  // Initialize Serial Monitor
  Serial.begin(9600);
}

void loop() {
  int leftVal = digitalRead(leftSensorPin);  // Read left sensor
  int rightVal = digitalRead(rightSensorPin); // Read right sensor
  int rearVal = digitalRead(rearSensorPin);  // Read rear sensor

  // Control LEDs based on sensor values (turns on LED if obstacle detected)
  digitalWrite(leftLedPin, leftVal == LOW ? HIGH : LOW);  // Left LED
  digitalWrite(rightLedPin, rightVal == LOW ? HIGH : LOW); // Right LED
  digitalWrite(rearLedPin, rearVal == LOW ? HIGH : LOW);  // Rear LED

  // Read the light level from the photoresistor
  int lightLevel = analogRead(photoresistorPin);

  // Print the light level, will help you debug your darkness threshold
  Serial.print("Light Level: ");
  Serial.println(lightLevel);

  // Check if the light level is below the threshold
  if (lightLevel < darknessThreshold) {
    digitalWrite(headlightLedPin, LOW); // Turn on reminder LED
  } else {
    digitalWrite(headlightLedPin, HIGH); // Turn off reminder LED
  }

  delay(500); // Add a delay
}