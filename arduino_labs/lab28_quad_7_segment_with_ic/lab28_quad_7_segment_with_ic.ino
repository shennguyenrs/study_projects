// Declare IC
#define dataPin 13 // DS
#define clockPin 11 // SH_CP
#define latchPin 12 // ST_CP

// Declare digit pins
int digitNum = 4;
int digitPin[4] = {10, 9, 8, 7}; // DP1, DP2, DP3, DP4
int digitBuffer[4] = {8, 6, 7, 5};

// Declare global variables
int count = 0;
int wait = 2;

// Declare number array 7-seg
byte numbers[10] = {
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

void TurnOffScreen()
{
  for(int i=0; i<digitNum; i++)
  {
    digitalWrite(digitPin[i], HIGH);
  }
}

void setup()
{
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);

  for(int i=0; i<digitNum; i++)
  {
    pinMode(digitPin[i], OUTPUT);
  }

  TurnOffScreen();
}

void loop()
{
  TurnOffScreen();
  digitalWrite(latchPin, LOW);
    
  // Shift out the bit
  shiftOut(dataPin, clockPin, MSBFIRST, numbers[digitBuffer[count]]);
  digitalWrite(digitPin[count], LOW);
  digitalWrite(latchPin, HIGH);

  count++;
  if(count>digitNum-1)
  {
    count = 0;
  }

  delay(wait);
}
