#include <ArduinoJson.h>
#include <Servo.h>

// Create a servo object
Servo myServo1;
Servo myServo2;
// Define the pin for the onboard LED
const int ledPin = LED_BUILTIN;

// Define the maximum size of the JSON object
const size_t capacity = JSON_OBJECT_SIZE(2);
DynamicJsonDocument doc(capacity);

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps 8N1
  myServo1.attach(9); // Attach the servo to pin 9
  myServo2.attach(10); // Attach the servo to pin 10
  pinMode(ledPin, OUTPUT); // Set the LED pin as an output
}

void loop() {
    if (Serial.available()) {
        // Read data from serial
        String data = Serial.readStringUntil('\n');
        
        // Parse JSON data
        deserializeJson(doc, data);

        // Extract values from JSON
        int x = doc["x"];
        int y = doc["y"];

        // Process the received data
        myServo1.write(x);
        myServo2.write(y);

      }
    }
