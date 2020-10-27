#include <iostream>
#include <iomanip>
#include <string>
#include "dollaramount.h"
using namespace std;

int main()
{
    // Create sample object
    DollarAmount d1{12345}; // $123.45
    DollarAmount d2{1576}; // $15.76

    // Add d2 to d1
    cout << "After adding d2 (" << d2.ToString() << ") into d1 (" << d1.ToString() << "), d1=";
    d1.add(d2);
    cout << d1.ToString() << endl;

    // Subtract d2 to d1
    cout << "After subtracting d2(" << d2.ToString() << ") from d1 (" << d1.ToString() << "), d1=";
    d1.subtract(d2);
    cout << d1.ToString() << endl;

    // Subtract d1 to d2
    cout << "After subtracting d1(" << d1.ToString() << ") from d2 (" << d2.ToString() << "), d2=";
    d2.subtract(d1);
    cout << d2.ToString() << endl << endl;

    cout << "Enter integer interest rate and divisor. For Example:" << endl
        << "for     2%, enter    2    100" << endl
        << "for   2.3%, enter   23   1000" << endl
        << "for  2.37%, enter  237  10000" << endl
        << "for 2.375%, enter 2375 100000" << endl;

    // Variables definition
    int rate;
    int divisor;
    unsigned int i;
    unsigned int year{10};
    
    cin >> rate >> divisor;

    DollarAmount balance{100000};
    cout << endl << "Initial Balance: " << balance.ToString() << endl;

    // Display headers
    cout << "Year" << setw(20) << "Amount on deposit" << endl;

    for(i=1; i<=year; i++)
    {
        balance.AddInterest(rate, divisor);
        cout << setw(4) << i << setw(20) << balance.ToString() << endl;
    }

    return 0;
}
