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
String userCommand;
String commandValue;
 
// Variables will change:
int ledState = LOW;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated
bool if_flicker = false;
 
// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long interval = 1000;           // interval at which to blink (milliseconds)

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(BAUDRATE);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

// the loop function runs over and over again forever
void loop() {
    unsigned long currentMillis = millis();
 
    if(currentMillis - previousMillis > interval && if_flicker) {
        // save the last time you blinked the LED 
        previousMillis = currentMillis;   
 
        // if the LED is off turn it on and vice-versa:
        if (ledState == LOW){
            ledState = HIGH;
        }
        else{
            ledState = LOW;
        }
        // set the LED with the ledState of the variable:
        digitalWrite(LED_PIN, ledState);
    }

    if(Serial.available()>0){
        readData = Serial.readStringUntil('\n');

        // Convert from String Object to String.
        char sz[] = "Command Value";
        char buf[sizeof(sz)];
        readData.toCharArray(buf, sizeof(buf));
        char *p = buf;
        char *str;
        for(int i = 0; i<2;i++)
        {
            str = strtok_r(p, " ", &p);
            if(i==0){
                userCommand= str;
            }
            if(i==1){
                commandValue = str;
                
            }
        }
        if(userCommand == "flicker"){
            Serial.print("Flickering diode with ms interval: ");
            Serial.println(commandValue);
            interval = commandValue.toInt();
            if_flicker = true;
        }
    }
}
