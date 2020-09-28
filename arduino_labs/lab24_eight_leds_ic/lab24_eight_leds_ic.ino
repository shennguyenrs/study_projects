#define dataPin 13 // DS
#define latchPin 12 // ST_CP
#define clockPin 11 // SH_CP
#define wait 500

void setup()
{
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
}

void loop()
{
  // Count from 0 to 255 in binary
  for (int j = 0; j < 256; j++) 
  {
    digitalWrite(latchPin, LOW);
     	
    // Shift out the bit
    shiftOut(dataPin, clockPin, MSBFIRST, j);
    digitalWrite(latchPin, HIGH);
      
    delay(wait);
  }
}