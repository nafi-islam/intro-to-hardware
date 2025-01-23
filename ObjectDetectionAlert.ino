#include <Arduino.h>

int ledPin = 3; // LED Pin Assignment on Arduino

int sensorPin = 10; // Avoidance Sensor Pin Assignment on Arduino

int val; // Store result

void setup() {
  pinMode(ledPin, OUTPUT); // Define LED as output interface

  pinMode(sensorPin, INPUT);  // Define avoidance sensor as input interface
}

void loop() {
  val = digitalRead(sensorPin); // Read sensor value
  
  if (val == LOW) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}