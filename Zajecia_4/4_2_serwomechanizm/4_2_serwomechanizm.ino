#include <Servo.h> 
#define servo_pin 6
Servo my_servo; 
int angle=0; 
int gain = 20;

void setup() {
my_servo.attach(servo_pin); 
}

void loop() {
  if(angle<180)
  {
    my_servo.write(angle);
  }
  else
  {
    angle=0;
  }
  angle=angle+gain; 
  delay(200); 
}
