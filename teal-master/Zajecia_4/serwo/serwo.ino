/*
  MIT License 2019
  ---
  Arduino Workshops
  Class #3
  Program purpose: Servo360 presentation
  ---
  @author: Michael Grabowski
  ---
  Provided by CybAiR Science Club at 
  Institute of Control, Robotics and Information Engineering of
  Poznan University of Technology  
*/
#include <Servo.h> 

Servo servo;

int position=92;      // current servo position
int readValue = 0;    // value read from user
int rotDirection=1;   // 1 is for one direction, -1 for another
int deltaV=0;         // speed change

void setup()
{
  Serial.begin (9600);
  servo.attach(9);
  servo.write(position);//92 stop
  pinMode(10, INPUT_PULLUP);}

void loop(){
  readValue=analogRead(A2);
  deltaV=((int)(readValue/30));
  if (digitalRead(10) == LOW)
  {
    rotDirection=rotDirection*(-1);
    delay(50);//stop for a brief time
  }

  if(rotDirection==1)
  {
    servo.write(92+deltaV);
  }
  else if(rotDirection==-1)
  {
    servo.write(92-deltaV);
  }
  delay(50); //if delay is not big enough, it can be hard to accurately push button
}
