#include <NewPing.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

#define TOTAL_SENSORS 4
const int trigPin[TOTAL_SENSORS] = {2, 4, 6, 8};
const int echoPin[TOTAL_SENSORS] = {3, 5, 7, 9};
const int buzzerPin = 10;
const int servoPin = 11;
const int maxDistance = 100;
const int sensorAngleOffsets[TOTAL_SENSORS] = {0, 90, 180, 270}; // Fixed sensor positions relative to the front

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

NewPing sonar[TOTAL_SENSORS] = {
  NewPing(trigPin[0], echoPin[0], maxDistance),
  NewPing(trigPin[1], echoPin[1], maxDistance),
  NewPing(trigPin[2], echoPin[2], maxDistance),
  NewPing(trigPin[3], echoPin[3], maxDistance)
};

Servo myServo;
int servoAngle = 0;
int previousAngle = -1;  // Initial previous angle
int currentAngle = 0;
int displayAngle = -1;   // Initial display angle

void setup() {
  myServo.attach(servoPin);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.print("RADAR SYSTEM");
}

void loop() {
  for (servoAngle = 0; servoAngle <= 180; servoAngle++) {
    myServo.write(servoAngle);
    delay(100); // Delay for servo stabilization
    scanAndDisplay();
  }
  for (servoAngle = 180; servoAngle >= 0; servoAngle--) {
    myServo.write(servoAngle);
    delay(100); // Delay for servo stabilization
    scanAndDisplay();
  }
}

void scanAndDisplay() {
  for (int i = 0; i < TOTAL_SENSORS; i++) {
    unsigned int distance = sonar[i].ping_cm();
    if (distance > 0 && distance <= maxDistance) {
      currentAngle = (servoAngle + sensorAngleOffsets[i]) % 360; // Calculate the current absolute angle of the detected object
      if (distance <= 5) { // Close object detected
        if (previousAngle == -1 || displayAngle == -1) { // First detection
          displayAngle = currentAngle;
          previousAngle = currentAngle; // Set previous angle on first detection
        } else if (abs(previousAngle - currentAngle) >= 5) {
          displayAngle = currentAngle;
          previousAngle = currentAngle; // Update previous angle when display angle is updated
        }
        digitalWrite(buzzerPin, HIGH);
        displayObjectInfo(distance, displayAngle, i);
      } else {
        digitalWrite(buzzerPin, LOW);
      }
    }
  }
}


void displayObjectInfo(unsigned int distance, int angle, int sensorIndex) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sensor ");
  lcd.print(sensorIndex + 1);
  lcd.print(": ");
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print("cm, ");
  lcd.print(angle);
  lcd.print("deg");
}
