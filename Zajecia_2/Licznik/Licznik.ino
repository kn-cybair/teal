/*
  MIT License
  ---
  Arduino Workshops
  Class #2
  Program purpose: Counter
  ---
  @author: Krzysztof Stezala
  ---
  Provided by CybAiR Science Club at 
  Institute of Control, Robotics and Information Engineering of
  Poznan University of Technology  
*/
#define BAUDRATE 9600
//int counter = 0;
//short counter = 0;
//double counter = 0;
char counter = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(BAUDRATE);
}

// the loop function runs over and over again forever
void loop() {
  Serial.print(counter);
  Serial.print(" ");
  counter++;
  delay(5);
}