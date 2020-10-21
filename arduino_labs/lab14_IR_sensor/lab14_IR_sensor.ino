/* Lab 14: IR Modules
* Press the button from 0-9 to change the specific color
* Press Channel up or down can also change the color by increase or decrease the order
*/

#include <IRremote.h>
#include "RemoteKey.h"

// Define RGB Led pins
#define RED 10
#define GREEN 6
#define BLUE 9

// Define color modes
int position = 0;

int colors[10][3] = {
    {249, 65, 68}, // Red Salsa
    {243, 114, 44}, // Orange Red
    {248, 150, 30}, // Yellow Orange
    {249, 132, 74}, // Mango Tango
    {249, 199, 79}, // Maize Crayola
    {144, 190, 109}, // Pistachio
    {67, 170, 139}, // Zomp
    {77, 174, 142}, // Cadet Blue
    {87, 177, 144}, // Queen Blue
    {39, 125, 161} // CG Blue
};

void ChangeColor(int position)
{
    analogWrite(RED, colors[position][0]);
    analogWrite(GREEN, colors[position][1]);
    analogWrite(BLUE, colors[position][2]);
}

// Define IR sensor
#define RECV_PIN 4
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
    // Declare pin
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);
  
    irrecv.enableIRIn();
  	irrecv.blink13(true);

    Serial.begin(9600);
}

void loop()
{
    if (irrecv.decode(&results))
    {    
        Serial.println(results.value, HEX);
        
        switch(results.value)
        {
            case Button0:
                position = 0;
                ChangeColor(position);
                break;
            case Button1:
                position = 1;
                ChangeColor(position);
                break;
            case Button2:
                position = 2;
                ChangeColor(position);
                break;
            case Button3:
                position = 3;
                ChangeColor(position);
                break;
            case Button4:
                position = 4;
                ChangeColor(position);
                break;
            case Button5:
                position = 5;
                ChangeColor(position);
                break;
            case Button6:
                position = 6;
                ChangeColor(position);
                break;
            case Button7:
                position = 7;
                ChangeColor(position);
                break;
            case Button8:
                position = 8;
                ChangeColor(position);
                break;
            case Button9:
                position = 9;
                ChangeColor(position);
                break;
            case ChannelUp:
                position+=1;
                if(position>9) { position=0;}
                ChangeColor(position);
                break;
            case ChannelDown:
                position-=1;
                if(position<0) { position=9;}
                ChangeColor(position);
                break;
            //default:
            //    position = 0;
            //    ChangeColor(position);
            //    break;
        }

        irrecv.resume();
  	}
}
