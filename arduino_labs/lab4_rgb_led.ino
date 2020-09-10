#include<Arduino.h>

// Define pins
#define RED 11 // Red pin
#define GREEN 9 // Green pin
#define BLUE 10 // Blue pin
#define wait 500 // wait in milliseconds

void changeValue(int red, int green, int blue)
{
    analogWrite(RED, red);
    analogWrite(GREEN, green);
    analogWrite(BLUE, blue);
}

// Color modes
// Rainbow color changing
void rainbowColor()
{
    int red, green, blue;
    int i=0;
    int frequency=3;
    for(;i<32;i++)
    {
        red = sin(frequency*i+0)*127+128;
        green = sin(frequency*i+2)*127+128;
        blue = sin(frequency*i+4)*127+128;

        // Write values to Led
        changeValue(red, green, blue);
        delay(wait);
    }

}

void setup()
{
    // Declare pin
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);

    // Power-on three colors 
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, HIGH);
}

void loop()
{
    rainbowColor();
}