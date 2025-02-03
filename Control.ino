#include <NewPing.h>

// Motor pins
#define MOTOR_LEFT1 2
#define MOTOR_LEFT2 3
#define MOTOR_RIGHT1 4
#define MOTOR_RIGHT2 5

// Ultrasonic sensors
#define FRONT_TRIG 6
#define FRONT_ECHO 7
#define LEFT_TRIG 8
#define LEFT_ECHO 9
#define RIGHT_TRIG 10
#define RIGHT_ECHO 11

// IR sensors (for edge detection)
#define IR_LEFT 12
#define IR_RIGHT 13

// Button pin
#define BUTTON_PIN A0

// Distance thresholds (in cm)
#define FRONT_DISTANCE 20
#define SIDE_DISTANCE 15

// Edge detection delay (time to reverse/turn)
#define EDGE_DETECTED 500 // 500ms

// Ultrasonic sensor objects
NewPing frontSonar(FRONT_TRIG, FRONT_ECHO, 200); // Max distance 200cm
NewPing leftSonar(LEFT_TRIG, LEFT_ECHO, 200);
NewPing rightSonar(RIGHT_TRIG, RIGHT_ECHO, 200);

// Global variables
bool started = false; // Flag to check if the robot has started

void setup() {
  // Motor pins
  pinMode(MOTOR_LEFT1, OUTPUT);
  pinMode(MOTOR_LEFT2, OUTPUT);
  pinMode(MOTOR_RIGHT1, OUTPUT);
  pinMode(MOTOR_RIGHT2, OUTPUT);

  // IR sensors
  pinMode(IR_LEFT, INPUT_PULLUP);
  pinMode(IR_RIGHT, INPUT_PULLUP);

  // Button pin
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Wait for button press
  while (digitalRead(BUTTON_PIN) == HIGH) {
    // Do nothing until button is pressed
  }

  // 5-second delay after button press
  delay(5000);

  // Robot starts autonomous mode
  started = true;
}

void loop() {
  if (!started) return; // Do nothing until the robot starts

  // Edge detection (highest priority)
  if (digitalRead(IR_LEFT) == LOW) { // Left IR detects black line
    evadeEdge(true); // Evade left edge
    return;
  }
  if (digitalRead(IR_RIGHT) == LOW) { // Right IR detects black line
    evadeEdge(false); // Evade right edge
    return;
  }

  // Read distances from ultrasonic sensors
  int frontDist = frontSonar.ping_cm();
  int leftDist = leftSonar.ping_cm();
  int rightDist = rightSonar.ping_cm();

  // Obstacle handling
  if (frontDist > 0 && frontDist < FRONT_DISTANCE) { // Front obstacle detected
    dashForward(); // Dash forward
  } else if (leftDist > 0 && leftDist < SIDE_DISTANCE) { // Left obstacle detected
    turnLeft(); // Rotate left
    delay(300); // Adjust rotation time as needed
    dashForward(); // Dash forward
  } else if (rightDist > 0 && rightDist < SIDE_DISTANCE) { // Right obstacle detected
    turnRight(); // Rotate right
    delay(300); // Adjust rotation time as needed
    dashForward(); // Dash forward
  } else {
    stopMotors(); // No obstacle detected, stop motors
  }
}

// Function to evade edge
void evadeEdge(bool leftEdge) {
  reverse(); // Reverse away from the edge
  delay(EDGE_DETECTED); // Reverse for 500ms
  if (leftEdge) {
    turnRight(); // Turn right if left edge detected
  } else {
    turnLeft(); // Turn left if right edge detected
  }
  delay(EDGE_DETECTED); // Turn for 500ms
  stopMotors(); // Stop motors after evading
}

// Movement functions
void dashForward() {
  digitalWrite(MOTOR_LEFT1, HIGH);
  digitalWrite(MOTOR_LEFT2, LOW);
  digitalWrite(MOTOR_RIGHT1, HIGH);
  digitalWrite(MOTOR_RIGHT2, LOW);
}

void reverse() {
  digitalWrite(MOTOR_LEFT1, LOW);
  digitalWrite(MOTOR_LEFT2, HIGH);
  digitalWrite(MOTOR_RIGHT1, LOW);
  digitalWrite(MOTOR_RIGHT2, HIGH);
}

void turnLeft() {
  digitalWrite(MOTOR_LEFT1, LOW);
  digitalWrite(MOTOR_LEFT2, HIGH);
  digitalWrite(MOTOR_RIGHT1, HIGH);
  digitalWrite(MOTOR_RIGHT2, LOW);
}

void turnRight() {
  digitalWrite(MOTOR_LEFT1, HIGH);
  digitalWrite(MOTOR_LEFT2, LOW);
  digitalWrite(MOTOR_RIGHT1, LOW);
  digitalWrite(MOTOR_RIGHT2, HIGH);
}

void stopMotors() {
  digitalWrite(MOTOR_LEFT1, LOW);
  digitalWrite(MOTOR_LEFT2, LOW);
  digitalWrite(MOTOR_RIGHT1, LOW);
  digitalWrite(MOTOR_RIGHT2, LOW);
}
