/*
  MIT License
  ---
  Arduino Workshops
  Class #2
  Program purpose: Light Sensor
  ---
  @author: Krzysztof Stezala
  ---
  Provided by CybAiR Science Club at 
  Institute of Control, Robotics and Information Engineering of
  Poznan University of Technology  
*/
#define BAUDRATE 9600
#define SENSOR A0

int ledPins[] = { 8, 9, 10 };
int ledCount = 3;

void setup(){
    Serial.begin(BAUDRATE);
    // loop over the pin array and set them all to output:
    for (int thisLed = 0; thisLed < ledCount; thisLed++) {
        pinMode(ledPins[thisLed], OUTPUT);
        digitalWrite(ledPins[thisLed], LOW);
    }
    pinMode(SENSOR, INPUT);
}

void loop(){
    // read the potentiometer:
    int sensorReading = analogRead(SENSOR);
    Serial.print(sensorReading);
    Serial.print(" ");
    // map the result to a range from 0 to the number of LEDs:
    int ledLevel = map(sensorReading, 0, 1023, 0, ledCount);
    Serial.println(ledLevel);

    // loop over the LED array:
    for (int thisLed = 0; thisLed < ledCount; thisLed++) {
        // if the array element's index is less than ledLevel,
        // turn the pin for this element on:
        if (thisLed < ledLevel) {
            digitalWrite(ledPins[thisLed], HIGH);
        }
        // turn off all pins higher than the ledLevel:
        else {
            digitalWrite(ledPins[thisLed], LOW);
        }
    }
    
    delay(1000);
}