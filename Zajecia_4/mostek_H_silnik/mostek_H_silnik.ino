/*
  MIT License
  ---
  Arduino Workshops
  Class #4
  Program purpose: DC Motor PWM control
  ---
  @author: Krzysztof Stezala
  ---
  Provided by CybAiR Science Club at 
  Institute of Control, Robotics and Information Engineering of
  Poznan University of Technology  
*/
#define ENABLE_PIN 6
#define LEFT_ROTATE 7
#define RIGHT_ROTATE 8

void setup() { 
    // Enable pin is used for PWM control of the motors
    pinMode(ENABLE_PIN, OUTPUT); 
  
    // These pins determine the direction of rotation 
    // of the single motor 
    pinMode(LEFT_ROTATE, OUTPUT); 
    pinMode(RIGHT_ROTATE, OUTPUT);

    // Initial values set for the rotation; To the left
    digitalWrite(LEFT_ROTATE, LOW);
    digitalWrite(RIGHT_ROTATE, HIGH);
} 
 
void loop()  { 
    // Ramping the motor step by step to the left
    for (int i = 0; i <= 255; i++) {
        analogWrite(ENABLE_PIN, i); 
        delay(25);
    }
    // Letting the motor go; optionally
    delay(2000);

    digitalWrite(LEFT_ROTATE, HIGH);
    digitalWrite(RIGHT_ROTATE, LOW);

    // Ramping the motor step by step to the right
    for (int i = 0; i <= 255; i++) {
        analogWrite(ENABLE_PIN, i);
        delay(25);
    }
    // Letting the motor go; optionally
    delay(2000);
    
    //Changing direction
    digitalWrite(LEFT_ROTATE, LOW);
    digitalWrite(RIGHT_ROTATE, HIGH);
}
