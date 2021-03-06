/*
  MIT License 2019
  ---
  Arduino Workshops
  Class #5
  Program purpose: Arduino Radar
  ---
  @author: Krzysztof Stezala
  ---
  Provided by CybAiR Science Club at 
  Institute of Control, Robotics and Information Engineering of
  Poznan University of Technology  
*/
#include <Servo.h>

#define BAUDRATE 9600
#define TRIG_PIN 10
#define ECHO_PIN 11

long signalDuration = 0;
int objectDistance = 0;

Servo myServo;

void setup(){
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    
    Serial.begin(BAUDRATE);

    myServo.attach(12);
}

void loop(){
    objectDistance = calculate_distance();  
    Serial.println(objectDistance);
    delay(50);
}

int calculate_distance(){

    // lower Trig pin for a while
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(TRIG_PIN, HIGH);

    // Send the sound wave
    delayMicroseconds(10);

    // Cut the signal
    digitalWrite(TRIG_PIN, LOW);

    // Reads the echoPin, returns the sound wave travel time in microseconds
    signalDuration = pulseIn(ECHO_PIN, HIGH); 

    // calculate distance according to the producer recommendations
    int distance = signalDuration / 58;

    return distance;

}
