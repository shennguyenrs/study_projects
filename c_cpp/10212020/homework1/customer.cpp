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
  char dash = '-';

  // Find alphabets or punctuations
  // except period and the begining dash
  for(; i<len; i++)
  {
    if(i==0)
    {
      result = input[i]==dash || isdigit(input[i]) ? true : false;
    }
    else
    {
      result = input[i]==period || isdigit(input[i]) ? true : false;
    }

    // Break loop if false
    if(result==false)
    {
      break;
    }
  }

  // Check for second period
  bool secondPeriod = input.find(period, input.find(period)+1)!=string::npos ? true : false;

  return result && !secondPeriod;
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
void Customers::setBalance(string newBalance)
{
  // Erase value in the position
  customer.erase(customer.begin()+balance);

  // Insert new value
  customer.insert(
      customer.begin()+balance, 
      make_pair(headers[balance], newBalance)
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

  // Convert new balance to string
  stringstream ss;
  ss << newBalance;

  string str = ss.str();

  // Set new balance to account
  setBalance(str);
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
