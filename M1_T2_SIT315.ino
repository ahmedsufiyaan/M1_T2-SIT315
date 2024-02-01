const int MOTION_SENSOR_PIN = 3;  // Connect motion sensor output to this pin

const int LED = 7;  // Connect LED to this pin

void setup() {
  Serial.begin(9600);  // Initialize serial communication

  pinMode(MOTION_SENSOR_PIN, INPUT);  // Set motion sensor pin to input
  pinMode(LED, OUTPUT);  // Set LED pin to output
   // Attach interrupt for motion sensor
  attachInterrupt(digitalPinToInterrupt(MOTION_SENSOR_PIN), motionDetected, CHANGE); 
}

void loop() {
  delay(100);  // Delay to prevent interrupt conflicts
}

void motionDetected() {
  if (digitalRead(MOTION_SENSOR_PIN) == HIGH) {
    Serial.println("Motion detected!");
    digitalWrite(LED, HIGH);  // Turn on the LED
  } else {
    Serial.println("Motion stopped!");
    digitalWrite(LED, LOW);  // Turn off the LED
  }

  delay(500);  // Add delay for interrupt debounce
}
