/*
  MIT License
  ---
  Arduino Workshops
  Class #2
  Program purpose: LED Control
  ---
  @author: Krzysztof Stezala
  ---
  Provided by CybAiR Science Club at 
  Institute of Control, Robotics and Information Engineering of
  Poznan University of Technology  
*/
#define BAUDRATE 9600
#define LED_PIN 8
String readData;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(BAUDRATE);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

// the loop function runs over and over again forever
void loop() {
  if(Serial.available()>0){
    readData = Serial.readStringUntil('\n');
    if(readData =="on"){
      Serial.println("Turn on diode");
      digitalWrite(LED_PIN, HIGH);
    }
    else if(readData == "off"){
      Serial.println("Turn off diode");
      digitalWrite(LED_PIN, LOW);
    } 
  }
}
