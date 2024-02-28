
void setup() {
  // Start the serial communication
  Serial.begin(9600);
}

void loop() {
  // Send "Hello, World!" to the serial monitor
  Serial.println("Hello, World!");

  // Wait for a moment
  delay(1000);
}
