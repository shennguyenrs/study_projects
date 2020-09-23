#include<Servo.h>
Servo servo;

#define servoPin 9
#define wait 15
int pos = 0; // Begin position
int maxPos = 180; // Max position

void setup()
{
    servo.attach(servoPin);
}

void loop()
{
    // Go from 0 to 180
    for(; pos<=maxPos; pos++)
    {
        servo.write(pos);
        delay(wait);
    }
    
    // Go from 180 to 0
    for(pos=maxPos; pos>=0; pos--)
    {
        servo.write(pos);
        delay(wait);
    }
}
