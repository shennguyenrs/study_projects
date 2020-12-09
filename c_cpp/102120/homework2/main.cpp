#include "income.hpp"

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  // Declare variables
  string sales;
  string choose;
  bool isTrue{false};

  // Welcome screen
  cout << "==============================" << endl;
  cout << "           Homework 2         " << endl;
  cout << "==============================" << endl;
  cout << endl;

  // Set precision by 2 numbers after decimal point
  cout << fixed << setprecision(2);

  do
  {
    // Menu
    cout << "1 = Calculate income" << endl;
    cout << "0 = Exit" << endl;
    cout << "-----------------------------" << endl;
    cout << "Choose function: ";
    cin >> choose;
    
    isTrue = (choose=="1" || choose=="0");

    // Input validation for charater
    if(!isTrue)
    {
      cout << endl;
      cout << "Your choose is not available!" << endl;
      cout << "Please try again!" << endl;
      cout << "-----------------------------" << endl;
    }

    // Calculate the income
    // and print out result
    if(choose=="1")
    {
      // Prompt
      cout << endl;
      cout << "Cautions: Only allow positive integer and floating-point number!" << endl; 
      cout << "          Error message will be print out, if type error occurs!" << endl; 
      cout << endl;

      cout << "Enter gross sales: ";
      cin >> sales;

      Income grossSales(sales);

      // Input validation for numbers
      if(grossSales.validateFloat())
      {
        cout << endl;
        cout << "-----------------------------" << endl;
        cout << "Your income: " << grossSales.toIncome() << " Euros" << endl;
        cout << "-----------------------------" << endl;
        cout << endl;
      }
      else
      {
        cout << endl;
        cout << "You entered charaters or negative value!" << endl;
        cout << "Please enter again!" << endl;
        cout << "-----------------------------" << endl;
        cout << endl;
      }
    }
  }
  while(choose!="0");
  
  return 0;
}
