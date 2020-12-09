#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    // Set floating-point numbers
    cout << fixed << setprecision(2);

    // Declare variables
    float principal{};
    float rate{};
    unsigned int year{};
    unsigned int i;

    // Prompts
    cout << "Initial principal: ";
    cin >> principal;
    cout << "    Interest rate: ";
    cin >> rate;
    cout << "             Year: ";
    cin >> year;
    cout << endl;

    // Print out the headers of the table
    cout << "Year" << setw(20) << "Amount on deposit" << endl;

    // Print out the year with the interest
    for(i=0; i<=year; i++)
    {
        // Calculcate the amount of deposit
        float amount = principal * pow(1.0+rate, i);

        // Print out the result
        cout << setw(4) << i << setw(20) << amount << endl;
    };

    return 0;
}
