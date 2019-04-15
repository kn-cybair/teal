#define PWM_pin 6

int gain = 5;
int modulation=0;

void setup() {
pinMode(PWM_pin, OUTPUT);
}

void loop() {
analogWrite(PWM_pin, modulation); 

if (modulation < 255) 
{ 
modulation = modulation + gain; 
} 
else 
{
modulation = 0; 
}
delay(100); 
}
