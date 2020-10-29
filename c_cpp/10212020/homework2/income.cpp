#include "income.hpp"

#include <string>
#include <sstream>

using namespace std;

// Convert string to numbers
float Income::toNumber()
{
  float n{0};
  stringstream ss(input);

  ss >> n;
  
  return n;
}

// Validate string if it is a float
bool Income::validateFloat()
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

// Calculate income
float Income::toIncome()
{
  Income grossSales(input);
  return BASE + BONUS_RATIO*grossSales.toNumber();
}
