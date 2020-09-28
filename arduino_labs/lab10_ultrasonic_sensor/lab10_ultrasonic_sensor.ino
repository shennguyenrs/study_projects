#include <LiquidCrystal.h>

// LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

#define trigPin 7
#define echoPin 6
#define wait 2000
#define sendingTime 10
#define delaySending 2

const float sonicVelocity = 0.034;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  lcd.begin(16, 2);
  
  lcd.setCursor(0, 0);
  lcd.print("Lab 10:");
  lcd.setCursor(0, 1);
  lcd.print("UltrasonicSensor");
  delay(wait);
}

void loop() {
  int duration;
  float distance;
  
  // Clear trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(delaySending);
    
  // Start to send ultrasonic
  digitalWrite(trigPin, HIGH);
  delay(sendingTime);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm
  distance = duration*sonicVelocity*0.5;
  
  // Print to the display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm");
  
  delay(wait);
}
