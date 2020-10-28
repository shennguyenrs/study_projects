#pragma once

#include <string>
using namespace std;

//#ifndef _INCOME_H_
//#define _INCOME_H_

// Declare constants
const float BONUS_RATIO = 0.12;
const float BASE = 150.0;

// Class Definition
class Income
{
  private:
    string input;
  public:
    // Initializer
    Income(string str) : input{str} {};

    // Convert string to numbers
    float toNumber();

    // Validate string if it is a float
    bool validateFloat();

    // Calculate income
    float toIncome();
};

//#endif
