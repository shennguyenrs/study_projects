#include <LiquidCrystal.h>
#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;
char weekDay[7][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

// LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

#define wait 2000

void setup() 
{
  Wire.begin();
  rtc.begin();
  
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Lab 19:");
  lcd.setCursor(0, 1);
  lcd.print("Real Time Clock");
  delay(wait);

  lcd.clear();
}

void loop()
{
  DateTime now = rtc.now();
    
  lcd.setCursor(0, 1);
  lcd.print(now.minute());
  lcd.print(':');
  lcd.print(now.hour());
  lcd.print(':');
  lcd.print(now.second());

  lcd.setCursor(0, 0);
  lcd.print(weekDay[now.dayOfTheWeek()]);
  lcd.print(" ");
  lcd.print(now.day());
  lcd.print('/');
  lcd.print(now.month());
  lcd.print('/');
  lcd.print(now.year());

  delay(wait/2);
  lcd.clear();
}
