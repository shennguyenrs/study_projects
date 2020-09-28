#include <Keypad.h>
#include <LiquidCrystal.h>

#define wait 2000

// Setup for LCD
// LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

// Set up for Keypad
const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 4; //four columns

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};

byte pin_rows[ROW_NUM] = {1, 2, 3, 4}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {5, 6, 7, 0}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

void setup()
{
  lcd.begin(16, 2);
  
  lcd.setCursor(0, 0);
  lcd.print("Lab 11:");
  lcd.setCursor(0, 1);
  lcd.print("Keypad 4x4");
  delay(wait);
    lcd.clear();
}

void loop()
{
  lcd.setCursor(0, 0);
  
  // Input first number
  lcd.print("Input key:");
  char key = keypad.getKey();
  
  lcd.setCursor(0, 1);
  if(key)
  {
    lcd.print(key);
  }
}
