/* In this lab, we used a library called SevSeg from Github.com
 * Link: https://github.com/DeanIsMe/SevSeg
 */

#include "SevSeg.h"
SevSeg sevseg;

// Using time counter to display from 0 to 9
// Pause 1 second before change to new number
void ToTen()
{
  // Declare variables
  static int max = 10; // Maxium value
  static int timer = millis(); // Capture the time when start the loop
  static int count = 0;
  int now = millis();

  if(now-timer>=1000)
  {
    timer+=1000;
    count++;

    // Reset when count reaches 9
    if(count==max)
    {
      count=0;
    }

    // Print count
    sevseg.setNumber(count, 3); // Delete 3 to disable zeros
  }
  sevseg.refreshDisplay();
}

void setup()
{
  // Declare variable
  byte numDigits = 4; // The number of digits should be display
  byte digitPins[] = {7, 8, 9, 10}; // 4 pin of D4, D3, D2 & D1
  byte segmentPins[] = {13, 11, 3, 5, 6, 12, 2, 4}; // 8 Pins of A, B, C , D, E , F, G & DP

  bool resistorsOnSegments = true; // In the circuit, we have resistors so left it as "True"
  bool updateWithDelaysIn = false; // Recomend as "False"
  bool leadingZeros = false; // "True" to keep leading zeros
  bool disableDecPoint = true; // "False" if we print a floating point number
  byte hardwareConfig = COMMON_CATHODE;
   
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelaysIn, leadingZeros, disableDecPoint);
  sevseg.setBrightness(90); // Set the brightness of the display
}

void loop(){
    ToTen();
}
