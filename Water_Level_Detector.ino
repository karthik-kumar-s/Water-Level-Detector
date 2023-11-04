const int capacitiveSensorPin = 9; // Digital pin connected to the capacitive sensor
const int ledPin = 13; // Digital pin connected to the LED

int threshold = 1000; // Adjust this value based on your sensor calibration

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(ledPin, OUTPUT); // Set ledPin as OUTPUT
}

void loop() {
  int sensorValue = capacitiveSensor(capacitiveSensorPin); // Read capacitive sensor value
  
  Serial.print("Water Level: ");
  Serial.println(sensorValue);

  if (sensorValue > threshold) {
    digitalWrite(ledPin, HIGH); // Turn on the LED if water level is above the threshold
  } else {
    digitalWrite(ledPin, LOW); // Turn off the LED if water level is below the threshold
  }

  delay(1000); // Delay for 1 second before taking the next reading
}
