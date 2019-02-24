/*
  MIT License
  ---
  Arduino Workshops
  Class #4
  Program purpose: LED control with H-bridge
  ---
  @author: Krzysztof Stezala
  ---
  Provided by CybAiR Science Club at 
  Institute of Control, Robotics and Information Engineering of
  Poznan University of Technology  
*/
#define ENABLE_PIN 6
#define YELLOW_LED 7
#define RED_LED 8

void setup() { 
    // Enable pin is used for control of the LEDS
    pinMode(ENABLE_PIN, OUTPUT); 
    digitalWrite(ENABLE_PIN, HIGH);
  
    pinMode(YELLOW_LED, OUTPUT); 
    pinMode(RED_LED, OUTPUT);
} 

void loop()  { 
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(RED_LED, LOW);

    delay(2000);
    
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, HIGH);

    delay(2000);
}
