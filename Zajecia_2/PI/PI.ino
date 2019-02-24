/*
  MIT License
  ---
  Arduino Workshops
  Class #2
  Program purpose: PI
  ---
  @author: Krzysztof Stezala
  ---
  Provided by CybAiR Science Club at 
  Institute of Control, Robotics and Information Engineering of
  Poznan University of Technology  
*/
#define BAUDRATE 9600
int digits_after_decimal = 10;

// the setup function runs once when you press reset or power the board
void setup() {
    Serial.begin(BAUDRATE);

    Serial.print("PI: ");
    Serial.println(PI);

    Serial.print("PI (extended): ");
    Serial.println(PI, digits_after_decimal);
}

// the loop function runs over and over again forever
void loop() {
  
}