/*
  MIT License
  ---
  Arduino Workshops
  Class #2
  Program purpose: Serial
  ---
  @author: Krzysztof Stezala
  ---
  Provided by CybAiR Science Club at 
  Institute of Control, Robotics and Information Engineering of
  Poznan University of Technology  
*/
#define BAUDRATE 9600

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(BAUDRATE);
  Serial.println("Numbers:");
  //print numbers
  for(int i = 0; i < 20; i++){
    Serial.print(i);
    Serial.print(" ");
  }
  Serial.println();

  Serial.println("Alphabet:");
  //print ASCII alphabet
  for(int i = 65; i < 91; i++){
    Serial.write(i);
    Serial.print(" ");
  }
  Serial.println();
  Serial.println();

  Serial.println("Different number systems:");
  Serial.println("BIN: OCT: DEC: HEX:");
  //print different number systems
  for(int i = 0; i < 16; i++){
    Serial.print(i, BIN);
    Serial.print(" ");
    Serial.print(i, OCT);
    Serial.print(" ");
    Serial.print(i, DEC);
    Serial.print(" ");
    Serial.print(i, HEX);
    Serial.print("\n");
  }
}

// the loop function runs over and over again forever
void loop() {
  
}