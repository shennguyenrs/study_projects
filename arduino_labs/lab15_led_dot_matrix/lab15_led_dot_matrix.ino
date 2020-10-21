#include "LedControl.h"

#define wait 1000

#define DinPin 12
#define ClkPin 10
#define CsPin 11

LedControl lc = LedControl(DinPin, ClkPin, CsPin);

// Put values in arrays
const byte IMAGES[][8] = {
{
  B00000000,
  B01100000,
  B01100000,
  B01100000,
  B01100000,
  B01100000,
  B01100000,
  B01111110
},{
  B00000000,
  B00000000,
  B00000000,
  B00111100,
  B00000110,
  B00111110,
  B01100110,
  B00111110
},{
  B00000000,
  B01100000,
  B01100000,
  B01100000,
  B01111100,
  B01100110,
  B01100110,
  B01111100
},{
  B00000000,
  B00011000,
  B00011000,
  B00111000,
  B00011000,
  B00011000,
  B00011000,
  B01111110
},{
  B00000000,
  B01111110,
  B01100000,
  B01111100,
  B00000110,
  B00000110,
  B01100110,
  B00111100
}};

const int IMAGES_LEN = sizeof(IMAGES)/8;

//  Take values in Arrays and Display them
void DrawImage(const byte * image)
{
  for(int i=0; i<8; i++)  
  {
      for(int j=0; j<8; j++)
      {
          lc.setLed(0, i, j, bitRead(image[i], 7-j));
      }
  }
}

void setup()
{
  lc.shutdown(0,false);  // Wake up displays
  lc.setIntensity(0,5);  // Set intensity levels
  lc.clearDisplay(0);  // Clear Displays
}

int i =0;

void loop()
{
    DrawImage(IMAGES[i]);
    if(++i>=IMAGES_LEN) { i=0;}
    delay(wait);
}
