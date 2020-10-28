#include <iostream>
#include <iomanip>
using namespace std;

class Customers
{
  private:
    unsigned int accountNumber;
    float balance;
    float charges;
    float appliedCredit;
    float limitedCredit;

  public:
    // Initializer
    Customers(unsigned int a, float b, float c, float d, float e) :
      accountNumber(a),
      balance(b),
      charges(c),
      appliedCredit(d),
      limitedCredit(e)
    {}

    // Set new values
    void setBalance(float newBalance)
    {
      balance = newBalance;
    }
    
    // Calculate new balance
    void calculateNewBalance() 
    { 
      float newBalance = balance + charges - appliedCredit;
      setBalance(newBalance);
    }

    // Check if customer's credit exceeds
    bool isCreditExceed() 
    { 
      return balance > limitedCredit ? true : false; 
    }
};

int main()
{
  // Declare variables
  unsigned int n{0};
  bool isTrue{false};
  
  // Welcome screen
  cout << "================================" << endl; 
  cout << "           Homework 1           " << endl;
  cout << "================================" << endl; 
  cout << endl;

  // Set precision
  cout << fixed << setprecision(2);
  
  // Input information
  // and print out messages loop
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

      // Input values prompts
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

      cout << endl;

      // Create new object
      // and set the values to object
      Customers customer(accountNumber, balance, charges, appliedCredit, limitedCredit);

      // Calculate new balance
      customer.calculateNewBalance();

      // Print out the messages
      // if the credit of customer is exceeded
      if(customer.isCreditExceed())
      {
        cout << "Credit Limit Exceeded!" << endl;
      }

      cout << "------------------------------" << endl;
    }
  }
  while(n!=0);

  return 0;
}
