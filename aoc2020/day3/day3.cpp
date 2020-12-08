#include <iostream>
#include <iterator>

#include "day3.hpp"
using namespace std;

unsigned int countTree(unsigned int const xSlope, unsigned int const ySlope)
{
    vector<string>::iterator itr = raw.begin();
    unsigned int counter{0};
    unsigned int x{0};

    // O(n)
    while(itr!=raw.end())
    {
        string line = *itr;
        unsigned int len = line.length();

        if('#'==line[x]) counter++;

        x = (x+xSlope)%len;

        advance(itr, ySlope);

        if(static_cast<unsigned long int>(distance(raw.begin(), itr))>raw.size()) break;
    }

    return counter;
}

int main()
{
    unsigned long int result{1};

    // Part one
    cout << "----- Part One -----" << endl;
    cout << countTree(3, 1) << endl;
    cout << endl;

    // Part two
    result *= countTree(1, 1);
    result *= countTree(3, 1);
    result *= countTree(5, 1);
    result *= countTree(7, 1);
    result *= countTree(1, 2);

    cout << "----- Part Two -----" << endl;
    cout << result << endl;

    return 0;
}
