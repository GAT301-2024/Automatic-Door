# Automatic-Door
NAME:SSEBAGEYA HENRY
STUDENT No:2301001404
REG No:23/U/1404/GAT/PS

This Arduino project uses an ultrasonic sensor (HC-SR04) to detect the presence of an object and control a servo motor to open or close a door. Additionally, it uses LEDs to indicate the status of the door.

Components Required
Arduino Board (e.g., Arduino Uno)
HC-SR04 Ultrasonic Sensor
Servo Motor
Yellow LED
Blue LED
Resistors (220 ohm for LEDs)
Jumper Wires
Breadboard
Circuit Diagram
Connect the trigPin of the HC-SR04 to digital pin 9 on the Arduino.
Connect the echoPin of the HC-SR04 to digital pin 10 on the Arduino.
Connect the servo motor signal pin to digital pin 6 on the Arduino.
Connect the yellow LED to digital pin 2 on the Arduino with a 220 ohm resistor in series.
Connect the blue LED to digital pin 3 on the Arduino with a 220 ohm resistor in series.
Connect the GND pins of the HC-SR04, servo motor, and LEDs to the GND pin on the Arduino.
Connect the VCC pin of the HC-SR04 to the 5V pin on the Arduino.
Connect the power and ground pins of the servo motor to the 5V and GND pins on the Arduino, respectively.
Code Explanation
Libraries
#include <Servo.h>: Includes the Servo library to control the servo motor.
Constants
trigPin: Pin connected to the trigger pin of the HC-SR04.
echoPin: Pin connected to the echo pin of the HC-SR04.
servoPin: Pin connected to the signal pin of the servo motor.
yellowLedPin: Pin connected to the yellow LED.
blueLedPin: Pin connected to the blue LED.
openDistance: Distance in cm to trigger the door open.
Global Variables
myServo: Servo object to control the servo motor.
setup() Function
Sets the pin modes for the trigger, echo, LED, and servo pins.
Attaches the servo motor to the specified pin and sets it to the closed position (0 degrees).
Initializes the serial communication for debugging purposes.
loop() Function
Sends a pulse to the trigger pin of the HC-SR04 to initiate a distance measurement.
Reads the duration of the echo pulse and converts it to distance in cm.
Prints the measured distance to the serial monitor for debugging.
If the measured distance is less than openDistance, the door is opened by setting the servo to 90 degrees, and the yellow LED is turned on.
If the measured distance is greater than or equal to openDistance, the door is closed by setting the servo to 0 degrees, and the blue LED is turned on.
A small delay is added to stabilize the readings.
Usage
Connect the components as described in the circuit diagram.
Upload the code to your Arduino board.
Open the Serial Monitor in the Arduino IDE to view the measured distance.
Place an object within the specified distance (openDistance) to trigger the door to open.
Remove the object to close the door.

> Reviewed and Evaluated by AJr.Allan
