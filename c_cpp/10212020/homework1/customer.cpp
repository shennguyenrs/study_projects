#include "customer.hpp"

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// Validate integer and float
bool Customers::validateDigits(string input)
{
  bool result{true};
  unsigned int i{0};
  unsigned int len = input.length();
  char period = '.';

  // Find alphabets or punctuations
  // except period
  for(; i<len; i++)
  {
    if(!isdigit(input[i]) && input[i]!=period)
    {
      result = false;
      break;
    }
  }

  return result;
}

// Validate customer's values
bool Customers::validateCustomer()
{
  bool result{true};

  // Check for every variables in the class
  for(auto i: customer)
  {
    result &= validateDigits(i.second);

    if(!validateDigits(i.second))
    {
      cout << i.first << ": " << "\"" << i.second << "\"" << " is wrong type!" << endl;
    }
  }

  return result;
}

// Set values to class
void Customers::setValues(string values[])
{
  unsigned int len{5};
  unsigned int i{0};
  
  // Push new values to the back
  for(; i<len; i++)
  {
    customer.push_back(make_pair(headers[i], values[i]));
  }
}

// Set new balance
void Customers::setBalance(float newBalance)
{
  // Erase value in the position
  customer.erase(customer.begin()+balance);

  // Insert new value
  customer.insert(
      customer.begin()+balance, 
      make_pair(headers[balance], to_string(newBalance))
      );
}

// Get balance value
string Customers::getBalance()
{
  return customer[balance].second;
}

// Calculate new balance
void Customers::calculateNewBalance() 
{ 
  float newBalance = toNumber(customer[balance].second)
                  + toNumber(customer[charge].second)
                  - toNumber(customer[appliedCredit].second)
                  ;

  setBalance(newBalance);
}

// Check if customer's credit exceeds
bool Customers::isCreditExceed() 
{ 
  return toNumber(customer[balance].second) 
        > toNumber(customer[limitedCredit].second) 
        ? true : false; 
}

// Convert string to numbers
float Customers::toNumber(string input)
{
  float n{0};
  stringstream ss(input);

  ss >> n;
  
  return n;
}
