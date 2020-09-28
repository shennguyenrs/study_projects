#include <dht.h>
#include <LiquidCrystal.h>

// Setup for LCD
// LiquidCrystal(rs, enable, d4, d5, d6, d7)
#define rs 13
#define enable 12
#define d4 11
#define d5 10
#define d6 9
#define d7 8

LiquidCrystal lcd(rs, enable, d4, d5, d6, d7);

// Setup for dht11
#define dataPin 4

dht sensor;

#define wait 2000

void setup()
{
  // Setting LCD screen
  lcd.begin(16, 2);
  
  // Print name of the lab
  lcd.setCursor(0, 0);
  lcd.print("Lab 12:");
  lcd.setCursor(0, 1);
  lcd.print("DHT11 Sensor");
  delay(wait);
  lcd.clear();
}

void loop()
{
    lcd.clear();
    sensor.read11(dataPin);
    
    lcd.setCursor(0, 0);
    lcd.print("Humi: ");
    lcd.print((float)sensor.humidity, 1);
    lcd.print("%");
    
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print((float)sensor.temperature, 1);
    lcd.print((char)223);
    lcd.print("C");
    
    delay(wait);
}
