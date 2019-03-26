/*
  MIT License 2019
  ---
  Arduino Workshops
  Class #1
  Program purpose: Button enabled LED diode
  ---
  @author: Krzysztof Stezala
  ---
  Provided by CybAiR Science Club at 
  Institute of Control, Robotics and Information Engineering of
  Poznan University of Technology  
*/

#define LED_PIN 8                     // LED diode pin definition
#define BUTTON_PIN 9                  // Button pin definition

/* the setup function runs once when you press reset or power the board */
void setup() {
  pinMode(LED_PIN, OUTPUT);          // initialize digital pin LED_PIN as an output
  pinMode(BUTTON_PIN, INPUT);        // initialize digital pin BUTTON_PIN as an input
}

/* the loop function runs over and over again forever */
void loop() {
  if(digitalRead(BUTTON_PIN) == LOW){
     digitalWrite(LED_PIN, LOW);        // turn the LED off by making the voltage LOW 
  }
  else{
    digitalWrite(LED_PIN, HIGH);       // turn the LED on (HIGH is the voltage level) 
  }
}