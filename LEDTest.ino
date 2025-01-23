#include <Arduino.h>

int ledPin = 3; // LED connected to digital pin 3

void setup() {
  pinMode(ledPin, OUTPUT);  // Set LED pin as output
}

void loop() {
  digitalWrite(ledPin, HIGH); // Turn the LED on
  delay(1000);               // Wait for 1 second
  digitalWrite(ledPin, LOW);  // Turn the LED off
  delay(1000);               // Wait for 1 second
}
