# Homework 1
Terminal application to validate the balance of one customer is exceeded or not
base on the inputted information: Account Number, Beginning Balance, Charge,
Applied Credit, and Limit Credit.

The header title and order of information can be changed in the header file `customer.hpp`
```cpp
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
```

## Usage
Make output file using the script: 
```
sh ./makenrun.sh filename headername
```
``` bash
sh ./makenrun.sh main income
```
