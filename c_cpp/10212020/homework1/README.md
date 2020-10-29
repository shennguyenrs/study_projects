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

The formula to calculate new balance after check for exceed.
```
New Balance = Begining Balance + Charges - Applied Credit
```

## Usage
Make output file using the script. The script also include creating tags that required installed `exuberant-ctags` package.
**This script can only be run on Debian or Ubuntu**
```
sh ./makenrun.sh filename headername
```
``` bash
sh ./makenrun.sh main customer
```
