// Include the Servo library to control the servo motor
#include <Servo.h>

// Pin Definitions
const int rainSensorPin = 2; // Digital Out (DO) pin of the Rain Sensor connected to Arduino Digital Pin 2
const int servoPin = 9;      // Signal pin of the Servo Motor connected to Arduino Digital Pin 9

// Create the Servo object
Servo stickServo;

// Servo Positions (Angles) for the 'Stick' movement
// You might need to adjust these angles based on your physical setup.
const int STICK_OUT_ANGLE = 0;   // The angle when the stick is 'Out' (Dry state)
const int STICK_IN_ANGLE = 180;  // The angle when the stick is 'In' (Wet/Rain state)

void setup() {
  // Initialize the Serial Monitor for debugging
  Serial.begin(9600);
  
  // Set the rain sensor pin as input
  pinMode(rainSensorPin, INPUT);
  
  // Attach the servo motor to the specified pin
  stickServo.attach(servoPin);
  
  // Initially set the stick to the 'Out' position (assuming dry conditions)
  stickServo.write(STICK_OUT_ANGLE);
  Serial.println("System Initialized. Stick is OUT (Dry State).");
}

void loop() {
  // Read the digital value from the rain sensor
  // LOW typically means WET (Rain Detected)
  // HIGH typically means DRY (No Rain)
  int rainState = digitalRead(rainSensorPin);

  if (rainState == LOW) {
    // ☔ If the sensor is WET (Rain Detected)
    Serial.println("🌧️ RAIN DETECTED! Pulling Stick IN.");
    
    // Move the stick to the 'In' position
    if (stickServo.read() != STICK_IN_ANGLE) {
        stickServo.write(STICK_IN_ANGLE);
        delay(500); // Give the servo time to move
    }
  } else {
    // ☀️ If the sensor is DRY (No Rain)
    Serial.println("☀️ DRY CONDITIONS. Pushing Stick OUT.");
    
    // Move the stick to the 'Out' position
    if (stickServo.read() != STICK_OUT_ANGLE) {
        stickServo.write(STICK_OUT_ANGLE);
        delay(500); // Give the servo time to move
    }
  }

  // Check the sensor status every 1 second
  delay(1000); 
}
