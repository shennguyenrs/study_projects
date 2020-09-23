#include<Keypad.h>

// Define number of rows and cols
const int row = 4;
const int col = 4;

// Define keypads
char keys[row][col] =
{
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

// Define pin for row and col
byte pinRows[row] = {9, 8 , 7, 6};
byte pinCols[col] = {5, 4, 3, 2};

Keypad keypad = Keypad( makeKeymap(keys), pinRows, pinCols, row, col);

void setup(){
    // Start Serial terminal
    Serial.begin(9600);
}

void loop(){
    char key = keypad.getKey();
    
    if (key)
    {
        Serial.println(key);
    }
}