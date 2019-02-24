/*
  MIT License
  ---
  Arduino Workshops
  Class #1
  Program purpose: Blinking LED diode
  ---
  @author: Krzysztof Stezala
  ---
  Provided by CybAiR Science Club at 
  Institute of Control, Robotics and Information Engineering of
  Poznan University of Technology  
*/

#define LED_PIN 8                     // LED diode pin definition

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(LED_PIN, OUTPUT);          // initialize digital pin LED_PIN as an output.
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_PIN, HIGH);       // turn the LED on (HIGH is the voltage level)
  delay(2000);                       // wait for a second
  digitalWrite(LED_PIN, LOW);        // turn the LED off by making the voltage LOW
  delay(2000);                       // wait for a second
}
