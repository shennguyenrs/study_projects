#include <iostream>
using namespace std;

// Declare constants
const float BONUS_RATIO = 0.12;
const float BASE = 150;

int main()
{
  // Declare variables
  float sales{0};
  bool isTrue{false};
  unsigned int n{0};

  // Welcome screen
  cout << "==============================" << endl;
  cout << "           Homework 2         " << endl;
  cout << "==============================" << endl;
  cout << endl;

  do
  {
    // Menu
    cout << "1 = Calculate income" << endl;
    cout << "0 = Exit" << endl;
    cout << "-----------------------------" << endl;
    cout << "Choose function: ";
    cin >> n;
    cout << endl;

    // Input validation
    isTrue = ( n==1 || n==0 );

    if(!isTrue)
    {
      cout << "You enter wrong number!" << endl;
      cout << "Pleas try again!" << endl;
      cout << "-----------------------------" << endl;
      cout << endl;
    }
    
    // Calculate the income
    // and print out result
    if(n==1)
    {
      cout << "Enter gross sales: ";
      cin >> sales;
      cout << "-----------------------------" << endl;
      cout << "Your income: " << BASE + sales*BONUS_RATIO << " Euros" << endl;
      cout << "-----------------------------" << endl;
      cout << endl;
    }
  }
  while(n!=0);
  
  return 0;
}
