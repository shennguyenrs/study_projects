#include <iostream>
using namespace std;

class Customers
{
  private:
    unsigned int accountNumber{0};
    float balance{0};
    float charges{0};
    float appliedCredit{0};
    float limitedCredit{0};

  public:
    // Set functions
    void SetAccountNumber(int a) { accountNumber = a; }
    void SetBalance(float a) { balance = a; }
    void SetCharges(float a) { charges = a; }
    void SetAppliedCredit(float a) { appliedCredit = a; }
    void SetLimitedCredit(float a) { limitedCredit = a; }

    // Get functions
    int GetAccountNumber() { return accountNumber; }
    float GetBalance() { return balance; }
    float GetCharges() { return charges; }
    float GetAppliedCredit() { return appliedCredit; }
    float GetLimitedCredit() { return limitedCredit; }

    // Calculate new balance
    void NewBalance() 
    { 
      float newBalance = balance + charges - appliedCredit;
      SetBalance(newBalance);
    }

    // Check if customer's credit exceeds
    bool IsCreditExceed() { return balance > limitedCredit ? true : false; }
};

int main()
{
  // Declare variables
  unsigned int n{1};
  bool isTrue{false};
  
  // Welcome screen
  cout << "================================" << endl; 
  cout << "           Homework 1           " << endl;
  cout << "================================" << endl; 
  cout << endl;
  
  do
  {
    // Menu
    cout << "1 = Input new customer" << endl;
    cout << "0 = Exit" << endl;
    cout << "------------------------------" << endl;
    cout << "Choose the function: ";
    cin >> n;
    cout << endl;

    // Input validation
    isTrue = ( n==1 || n ==0 );

    if(!isTrue)
    {
      cout << "You entered wrong number!" << endl;
      cout << "Please try again!" << endl;
      cout << "------------------------------" << endl;
    }

    // Main function of program
    if(n==1)
    {
      // Declare variables
      unsigned int accountNumber{0};
      float balance{0};
      float charges{0};
      float appliedCredit{0};
      float limitedCredit{0};

      // Input values
      cout << "Account Number: ";
      cin >> accountNumber;
      
      cout << "Beginning Balance: ";
      cin >> balance;

      cout << "Total Charges: ";
      cin >> charges;

      cout << "Applied Credit: ";
      cin >> appliedCredit;

      cout << "Credit Limit: ";
      cin >> limitedCredit;

      // Set values to class
      Customers cus;
      cus.SetAccountNumber(accountNumber);
      cus.SetBalance(balance);
      cus.SetCharges(charges);
      cus.SetAppliedCredit(appliedCredit);
      cus.SetLimitedCredit(limitedCredit);

      // Calculate new balance
      cus.NewBalance();

      // Check if balance exceeds
      if(cus.IsCreditExceed())
      {
        cout << "Credit Limit Exceeded!" << endl;
      }
    }
  }
  while(n!=0);

  return 0;
}
