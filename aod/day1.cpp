#include <iostream>
#include <iterator>

#include ".day1.hpp"

using namespace std;

void findCouple()
{
    set<int>::iterator itr1;
    set<int>::iterator itr2;

    // O(n log n)
    for(itr1=mySet.begin(); itr1!=mySet.end(); itr1++) // O(n)
    {
        int second = 2020 - *itr1;
        itr2 = mySet.find(second); // O(log n)

        if(itr2!=mySet.end())
        {
            cout << "The first number is: " << *itr1 << endl;
            cout << "The second number is: " << *itr2 << endl;
            cout << "Their multiply is: " << *itr1 * *itr2 << endl;
            break;
        }
    }
}

void findTriplet()
{
    set<int>::iterator itr1;
    set<int>::iterator itr2;
    set<int>::iterator itr3;

    // O(n^2 log n)
    for(itr1=mySet.begin(); itr1!=mySet.end(); itr1++) // O(n)
    {
        for(itr2=next(itr1); itr2!=mySet.end(); itr2++) // O(n)
        {
            int third = 2020 - *itr1 - *itr2;

            if(third>*mySet.begin())
            {
                itr3 = mySet.find(third); // O(log n)

                if(itr3!=mySet.end())
                {
                    cout << "The first number is: " << *itr1 << endl;
                    cout << "The second number is: " << *itr2 << endl;
                    cout << "The third number is: " << *itr3 << endl;
                    cout << "Their multiply is: " << *itr1 * *itr2 * *itr3 << endl;
                    break;
                }
            }
        }
    }
}

int main()
{
    return 0;
}
