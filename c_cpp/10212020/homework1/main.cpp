#include "customer.hpp"

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
  // Declare variables
  string choose;
  bool isTrue{false};
  
  // Welcome screen
  cout << "================================" << endl; 
  cout << "           Homework 1           " << endl;
  cout << "================================" << endl; 
  cout << endl;

  // Set precision
  cout << fixed << setprecision(2);
  
  do
  {
    // Menu
    cout << "1 = Input new customer" << endl;
    cout << "0 = Exit" << endl;
    cout << "------------------------------" << endl;
    cout << "Choose the function: ";
    cin >> choose;
    cout << endl;

    // Input validation
    isTrue = ( choose=="1" || choose=="0" );

    if(!isTrue)
    {
      cout << "You entered wrong option!" << endl;
      cout << "Please try again!" << endl;
      cout << endl;
    }

    // Main function of program
    if(choose=="1")
    {
      // Declare variables
      string values[5];

      // Input values prompts
      cout << "Enter the values to customer account" << endl;
      cout << "Cautions: Only integer and floating-point number are allowed!" << endl;
      cout << "          If errors occur, the messages will be print out" << endl; 
      cout << "          after every forms are inputted!" << endl;

      cout << endl;
      cout << headers[accountNumber] << ": ";
      cin >> values[accountNumber];
      
      cout << headers[balance] << ": ";
      cin >> values[balance];

      cout << headers[charge] << ": ";
      cin >> values[charge];

      cout << headers[appliedCredit] << ": ";
      cin >> values[appliedCredit];

      cout << headers[limitedCredit] << ": ";
      cin >> values[limitedCredit];

      cout << "------------------------------" << endl;

      // Create new object
      Customers customer;

      // Set values to the customer
      customer.setValues(values);

      // Validate the input values
      bool result = customer.validateCustomer();

      if(result)
      {
        // Calculcate new balance
        customer.calculateNewBalance();
        
        // Print the new balance
        cout << "New balance is " << customer.getBalance() << endl;

        // Print out the messages
        // if the credit of customer is exceeded
        if(customer.isCreditExceed())
        {
          cout << "Credit Limit Exceeded!" << endl;
        }
      }
      
      cout << "------------------------------" << endl;
      cout << endl;
    }
  }
  while(choose!="0");

  return 0;
}
