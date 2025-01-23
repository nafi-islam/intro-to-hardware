#include <Arduino.h>

int sensorPin = 10; // IR sensor connected to digital pin 10

void setup() {
  pinMode(sensorPin, INPUT); // Set IR sensor pin as input
  Serial.begin(9600); // Initialize Serial Monitor
}

void loop() {
  int sensorValue = digitalRead(sensorPin); // Read sensor state (HIGH or LOW)
  
  // Print the sensor value
  if (sensorValue == LOW) {
    Serial.println("Obstacle detected!");
  } else {
    Serial.println("No obstacle.");
  }
  
  delay(500); // Add a delay
}
