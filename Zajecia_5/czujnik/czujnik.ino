/*
  MIT License
  ---
  Arduino Workshops
  Class #5
  Program purpose: HC-SR04 sensor
  ---
  @author: Krzysztof Stezala
  ---
  Provided by CybAiR Science Club at 
  Institute of Control, Robotics and Information Engineering of
  Poznan University of Technology  
*/

#define BAUDRATE 9600

#define TRIG_PIN 10
#define ECHO_PIN 11
#define BUZZER_PIN 2

int ledPins[] = { 5, 6, 7 };
int ledCount = 3;
int ledLevel = 0;
 
void setup() {

    /* Initialize*/
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);

    /* Initialize serial communications */
    Serial.begin(BAUDRATE);

    /* Initialize LED pins */
    for (int thisLed = 0; thisLed < ledCount; thisLed++) {
        pinMode(ledPins[thisLed], OUTPUT);
        digitalWrite(ledPins[thisLed], LOW);
    }
}
 
void loop() {  
    range(20, 50);
    delay(500);
} 
 
int getDistance() {
    long pulseTime, distance;

    /* sensor procedure */
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    /* getting the pulse */
    pulseTime = pulseIn(ECHO_PIN, HIGH);

    /* calculating the distance */
    distance = pulseTime / 58;
    Serial.println(distance);
    return distance;
}

void range(int min_range, int max_range) {
    int range = getDistance();
    
    lightUpLed(range);
    if( (range > min_range) && (range < max_range)) {
        digitalWrite(BUZZER_PIN, HIGH);
    }
    else{
        digitalWrite(BUZZER_PIN, LOW);
    }
}

void lightUpLed(int range){

    if(range<50){
        ledLevel = map(range, 0, 50, 0, ledCount);
    }
    else{
        ledLevel = 0;
    }

    
    
    // loop over the LED array:
    for (int thisLed = 0; thisLed <= ledCount; thisLed++) {
        // if the array element's index is less than ledLevel,
        // turn the pin for this element on:
        if (thisLed >= ledLevel) {
            digitalWrite(ledPins[thisLed], HIGH);
        }
        // turn off all pins higher than the ledLevel:
        else {
            digitalWrite(ledPins[thisLed], LOW);
        }
    }
}
