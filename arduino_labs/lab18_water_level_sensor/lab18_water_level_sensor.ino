#include <LiquidCrystal.h>

// LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

#define wait 2000
#define smallWait 10

// Sensor pins
#define sensorPin A0

// Value for storing water level
int val = 0;

int ReadSensor() 
{
	delay(smallWait);
  val = analogRead(sensorPin);
  return val;
}

void setup() 
{
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Lab 18:");
  lcd.setCursor(0, 1);
  lcd.print("WaterLevelSensor");
  delay(wait);
}

void loop()
{
  int level = ReadSensor();
  
  // Print to the display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Water Level:");
  lcd.setCursor(0, 1);
  lcd.print(level);
  
  delay(wait);
}
