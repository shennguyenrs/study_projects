// Declare button 
#define buttonPin 10
int buttonState = 0;

// Declare IC
#define dataPin 13 // DS
#define clockPin 11 // SH_CP
#define latchPin 12 // ST_CP

#define wait 1000

// Declare number array 7-seg
int numbers[10] = {
  B11111100, // 0
  B01100000, // 1
  B11011010, // 2
  B11110010, // 3
  B01100110, // 4
  B10110110, // 5
  B10111110, // 6
  B11100000, // 7
  B11111110, // 8
  B11110110  // 9
};

void setup()
{
  pinMode(buttonPin, INPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
}

void loop()
{
  buttonState = digitalRead(buttonPin);
  int position = random(0, 9); // Get random value
  
  if(buttonState==1)
  {
    digitalWrite(latchPin, LOW);
    
    // Shift out the bit
    shiftOut(dataPin, clockPin, MSBFIRST, numbers[position]);
    digitalWrite(latchPin, HIGH);
    
    delay(wait);
  }
}