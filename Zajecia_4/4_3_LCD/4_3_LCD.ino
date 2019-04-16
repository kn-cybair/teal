#define RS_pin 2
#define e_pin 3
#define data1 4
#define data2 5
#define data3 6
#define data4 7
#include <LiquidCrystal.h> 
LiquidCrystal lcd(RS_pin, e_pin, data1, data2, data3, data4);
void setup() {
  lcd.begin(16, 2); 
  lcd.setCursor(0, 0); 
  lcd.print("Hello..."); 
  lcd.setCursor(0, 1); 
  lcd.print("...world!"); 
}
void loop() {
}
