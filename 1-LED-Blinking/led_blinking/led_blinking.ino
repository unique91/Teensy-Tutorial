const int led = 13;   // Teensy4.0 LED on pin 13

// The setup function runs once when you press reset or power the board
void setup() {
 pinMode(led, OUTPUT);   // Initialize digital pin 13 as an output
}

// The loop function runs repeatedly
void loop() {
 digitalWrite(led, HIGH);   // Turn the LED on
 delay(500);                // Wait 500ms
 digitalWrite(led, LOW);    // Turn the LED off
 delay(500);                // Wait 500ms
}
