/*
  MIT License
  ---
  Arduino Workshops
  Class #2
  Program purpose: Potentiometer
  ---
  @author: Krzysztof Stezala
  ---
  Provided by CybAiR Science Club at 
  Institute of Control, Robotics and Information Engineering of
  Poznan University of Technology  
*/
#define BAUDRATE 9600
#define GREEN_LED 8
#define YELLOW_LED 9
#define RED_LED 10
#define POTENTIOMETER A1

int pot_value;

void setup(){
    Serial.begin(BAUDRATE);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(YELLOW_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);
    pinMode(POTENTIOMETER, INPUT);
}

void loop(){
    pot_value = analogRead(POTENTIOMETER);
    Serial.println(pot_value);
    if(pot_value == 0){
        digitalWrite(GREEN_LED,LOW);
        digitalWrite(YELLOW_LED,LOW);
        digitalWrite(RED_LED,LOW);
    }
    else if(pot_value < 350 && pot_value > 0){
        digitalWrite(GREEN_LED,HIGH);
        digitalWrite(YELLOW_LED,LOW);
        digitalWrite(RED_LED,LOW);
    }
    else if(pot_value >350 && pot_value < 700){
        digitalWrite(GREEN_LED,HIGH);
        digitalWrite(YELLOW_LED,HIGH);
        digitalWrite(RED_LED,LOW);
    }
    else {
        digitalWrite(GREEN_LED,HIGH);
        digitalWrite(YELLOW_LED,HIGH);
        digitalWrite(RED_LED,HIGH);
    }
}