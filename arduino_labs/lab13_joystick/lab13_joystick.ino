#include <LiquidCrystal.h>

#define wait 2000
#define smallWait 500

// Declare joystick variable
#define joyX A0
#define joyY A1

// Setup for LCD
// LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
 
void setup() {
    lcd.begin(16, 2);
    
    lcd.setCursor(0, 0);
    lcd.print("Lab 13:");
    lcd.setCursor(0, 1);
    lcd.print("Joystick");
    delay(wait);
    lcd.clear();
}
 
void loop() {
    // Reading x and y values
    int xValue = analogRead(joyX);
    int yValue = analogRead(joyY);
    
    lcd.clear();
    
    // Print out the value to the lcd screen
    lcd.setCursor(0, 0);
    lcd.print("X: ");
    lcd.print(xValue);

    lcd.setCursor(0, 1);
    lcd.print("Y: ");
    lcd.print(yValue);

    delay(smallWait);
}
