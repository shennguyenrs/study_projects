#include <Keypad.h>
#include <LiquidCrystal.h>

#define wait 5000

// Setup for LCD
// LiquidCrystal(rs, enable, d4, d5, d6, d7)
#define rs 13
#define enable 12
#define d4 11
#define d5 10
#define d6 9
#define d7 8

LiquidCrystal lcd(rs, enable, d4, d5, d6, d7);

// Set up for Keypad
const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 4; //four columns

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3', '+'},
  {'4','5','6', '-'},
  {'7','8','9', '*'},
  {'C','0','=', '/'}
};

byte pin_rows[ROW_NUM] = {1, 2, 3, 4}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {5, 6, 7, 0}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

// Decleare global variables
int num_one, num_two, num;
char key, action;
bool result;

// Reset data after every calculation
// or Clear function
void ClearData()
{
  num_one = 0;
  num_two = 0;
  num = 0;
  result = false;
}

// Detect buttons
void DetectButton()
{
  lcd.clear();
  
  // Number 1
  if(key=='1')
  {
    if(num==0)
    {
      num = 1;
    }
    else
    {
      num = num*10 + 1;
    }
  }

  // Number 2
  if(key=='2')
  {
    if(num==0)
    {
      num = 2;
    }
    else
    {
      num = num*10 + 2;
    }
  }

  // Number 3
  if(key=='3')
  {
    if(num==0)
    {
      num = 3;
    }
    else
    {
      num = num*10 + 3;
    }
  }

  // Number 4
  if(key=='4')
  {
    if(num==0)
    {
      num = 4;
    }
    else
    {
      num = num*10 + 4;
    }
  }

  // Number 5
  if(key=='5')
  {
    if(num==0)
    {
      num = 5;
    }
    else
    {
      num = num*10 + 5;
    }
  }

  // Number 6
  if(key=='6')
  {
    if(num==0)
    {
      num = 6;
    }
    else
    {
      num = num*10 + 6;
    }
  }

  // Number 7
  if(key=='7')
  {
    if(num==0)
    {
      num = 7;
    }
    else
    {
      num = num*10 + 7;
    }
  }

  // Number 8
  if(key=='8')
  {
    if(num==0)
    {
      num = 8;
    }
    else
    {
      num = num*10 + 8;
    }
  }

  // Number 9
  if(key=='9')
  {
    if(num==0)
    {
      num = 9;
    }
    else
    {
      num = num*10 + 9;
    }
  }

  // Operators
  if(key=='+' || key=='-' || key=='*' || key=='/')
  {
    num_one = num;
    num = 0;

    if(key=='+') { action = '+'; }
    if(key=='-') { action = '-'; }
    if(key=='*') { action = '*'; }
    if(key=='/') { action = '/'; }
  }

  // Functions
  if(key=='=')
  {
    num_two = num;
    num = 0;
    result = true;
  }

  if(key=='C')
  {
    ClearData();
  }
}

void Calculation()
{
  if(action=='+')
  { 
    num = num_one + num_two;
  }

  if(action=='-')
  { 
    num = num_one - num_two;
  }

  if(action=='*')
  { 
    num = num_one * num_two;
  }

  if(action=='/')
  { 
    num = num_one / num_two;
  }
}

void DisplayResult()
{
  lcd.setCursor(0, 0);
  lcd.print(num_one);
  lcd.print(action);
  lcd.print(num_two);

  if(result==true)
  {
    lcd.print("=");
    lcd.print(num);
    
    ClearData();
  }
  
  lcd.setCursor(0, 1);
  lcd.print(num);
}

void setup()
{
  // Setting LCD screen
  lcd.begin(16, 2);
  
  // Print name of the lab
  lcd.setCursor(0, 0);
  lcd.print("Lab 11:");
  lcd.setCursor(0, 1);
  lcd.print("Keypad 4x4");
  delay(wait);
  lcd.clear();

  // Print operation buttons
  lcd.setCursor(0, 0);
  lcd.print("A is +    B is -");
  lcd.setCursor(0, 1);
  lcd.print("C is *    D is /");
  delay(wait);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("* is Clear C");
  lcd.setCursor(0, 1);
  lcd.print("# is Equal =");
  delay(wait);
  lcd.clear();
}

void loop()
{
  lcd.setCursor(0, 0);
  key = keypad.getKey();
  if(key)
  {
    DetectButton();
    if(result)
    {
      Calculation();
    }
    DisplayResult();
  }
}
