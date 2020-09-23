#include "piches.h"

#define buttonPin 4
#define buzzerPin 13
int buttonState = 0;

// Tone in the song
int melody[] = {
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_F4, NOTE_E4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_F4, NOTE_C4, NOTE_C4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_F4
};

// Number of notes
int n = 25;

// note durations: 4 = quarter note, 8 = eight note, etc.
int noteDurations[] = {
  8, 8, 4, 4, 4, 2, 8, 8, 4, 4, 4, 2, 8, 8, 4, 4, 4, 4, 4, 8, 8, 4, 4, 4, 2, 
};

void PlayMelody()
{
    for(int thisNote=0; thisNote<n; thisNote++)
  {
    int noteDuration = 1200/noteDurations[thisNote];
    int pause = noteDuration*1.575;
    
    tone(buzzerPin, melody[thisNote], noteDuration);
    delay(pause);
    noTone(buzzerPin);
  }
}

void setup()
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop()
{
  buttonState = digitalRead(buttonPin);

  if(buttonState==HIGH)
  {
    PlayMelody();
  }
  else
  {
    noTone(buzzerPin);
  }
} 
