/*
  MIT License
  ---
  Arduino Workshops
  Class #2
  Program purpose: Precision
  ---
  @author: Krzysztof Stezala
  ---
  Provided by CybAiR Science Club at 
  Institute of Control, Robotics and Information Engineering of
  Poznan University of Technology  
*/

#define BAUDRATE 9600
int digits_after_decimal = 10;

float myfloat_1 = 1.2345;
float myfloat_2 = 5.9876;

// the setup function runs once when you press reset or power the board
void setup() {
    Serial.begin(BAUDRATE);

    Serial.print("myfloat1: ");
    Serial.println(myfloat_1, digits_after_decimal);

    Serial.print("myfloat2: ");
    Serial.println(myfloat_2);

    float result = myfloat_1 + myfloat_2;
    Serial.print("result (sum): ");
    Serial.println(result, digits_after_decimal);

    result = myfloat_1 - myfloat_2;
    Serial.print("result (substraction): ");
    Serial.println(result, digits_after_decimal);
    
    result = myfloat_1 * myfloat_2;
    Serial.print("result (multiplication): ");
    Serial.println(result, digits_after_decimal);

    result = myfloat_1 / myfloat_2;
    Serial.print("result (division): ");
    Serial.println(result, digits_after_decimal);
}

// the loop function runs over and over again forever
void loop() {
  
}