#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 6;
const int redLedPin = 2;
const int blueLedPin = 3;

const long openDistance = 20; // Distance in cm to trigger the door open

Servo myServo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);

  myServo.attach(servoPin);
  myServo.write(0); // Ensure the door starts in the closed position

  Serial.begin(9600);
}

void loop() {
  long duration, distance;
  
  // Send a pulse to trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echo pin
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1; // Convert duration to distance in cm
  
  // Print distance for debugging
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < openDistance) {
    // Object detected within distance, open the door
    myServo.write(90); // Open the door
    digitalWrite(yellowLedPin, HIGH); // Turn on yellow LED
    digitalWrite(blueLedPin, LOW); // Turn off blue LED
  } else {
    // No object detected, close the door
    myServo.write(0); // Close the door
    digitalWrite(yellowLedPin, LOW); // Turn off yellow LED
    digitalWrite(blueLedPin, HIGH); // Turn on blue LED
  }
  
  delay(500); // Small delay to stabilize readings
}
