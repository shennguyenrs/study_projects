#include <iostream>
#include <iterator>
#include <algorithm>

#include "day1.hpp"

using namespace std;

void findCouple()
{
    vector<int>::iterator itr1 = mySet.begin();
    vector<int>::iterator itr2 = prev(mySet.end());

    sort(mySet.begin(), mySet.end());

    // O(n)
    while (*itr1<*itr2)
    {
        unsigned int sum = *itr1 + *itr2;
        
        if (sum==2020)
        {
            cout << "The first number is: " << *itr1 << endl;
            cout << "The second number is: " << *itr2 << endl;
            cout << "Their multiply is: " << *itr1 * *itr2 << endl;
            break;
        }
        else if (sum>2020) itr2--;
        else itr1++;
    }
}

void findTriplet()
{
    vector<int>::iterator itr1;
    vector<int>::iterator itr2;
    vector<int>::iterator itr3;

    sort(mySet.begin(), mySet.end());

    // O(n^2)
    for (itr1=mySet.begin(); itr1!=prev(mySet.end(), 2); itr1++) // O(n)
    {
        itr2 = next(itr1);
        itr3 = prev(mySet.end());

        while (*itr2<*itr3) // O(n)
        {
            unsigned int sum = *itr1 + *itr2 + *itr3;

            if (sum==2020)
            {
                cout << "The first number is: " << *itr1 << endl;
                cout << "The second number is: " << *itr2 << endl;
                cout << "The third number is: " << *itr3 << endl;
                cout << "Their multiply is: " << *itr1 * *itr2 * *itr3 << endl;
                break;
            }
            else if (sum<2020) itr2++;
            else itr3--;
        }
    }
}

int main()
{
    cout << "----- Part One -----" << endl;
    findCouple();
    cout << endl;
    cout << "----- Part Two -----" << endl;
    findTriplet();

    return 0;
}
