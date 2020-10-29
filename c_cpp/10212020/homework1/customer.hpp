#pragma once

#include <string>
#include <vector>
using namespace std;

//#ifndef _CUSTOMER_H_
//#define _CUSTOMER_H_
//
const unsigned int accountNumber = 0;
const unsigned int balance = 1;
const unsigned int charge = 2;
const unsigned int appliedCredit = 3;
const unsigned int limitedCredit = 4;

const string headers[]
{
  "Account Number",
  "Beginning Balance",
  "Charge",
  "Applied Credit",
  "Limit Credit"
};

class Customers
{
  private:
    vector<pair<string,string>> customer;

  public:
    // Initializer
    Customers(): customer() {};
    
    // Validate integer and float
    bool validateDigits(string input);

    // Validate customer's values
    bool validateCustomer();

    // Set values to class
    void setValues(string values[]);

    // Set new balance
    void setBalance(string newBalance);

    // Get balance value
    string getBalance();
    
    // Calculate new balance
    void calculateNewBalance(); 

    // Check if customer's credit exceeds
    bool isCreditExceed(); 

    // Convert string to numbers
    float toNumber(string input);
};


//#endif
