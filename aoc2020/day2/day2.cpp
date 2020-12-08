#include <iostream>
#include <sstream>

#include "day2.hpp"
using namespace std;

struct myData
{
    string limit;
    char key;
    string str;
};

void addData(vector<myData> *vec)
{
    vector<string>::iterator itr = raw.begin();
    
    // O(n)
    while(itr!=raw.end())
    {
        stringstream ss(*itr);

        string str1, str2, str3, rest;

        ss >> str1 >> str2 >> str3 >> rest;

        struct myData input;

        input.limit = str1;
        input.key = str2[0];
        input.str = str3;

        vec->push_back(input);

        itr++;
    }
}

void doCount(vector<myData> *vec)
{
    unsigned int partOne{0};
    unsigned int partTwo{0};
    vector<myData>::iterator itr = vec->begin();

    // O(n)
    while(itr!=vec->end())
    {
        stringstream ss(itr->limit);
        unsigned int min;
        unsigned int max;
        char hyphen;

        ss >> min>> hyphen >> max;

        string str = itr->str;
        char key = itr->key;

        // Part one
        stringstream ss2(str);
        unsigned int count{0};
        char c;

        // O(n)
        while(ss2>>c)
        {
            if(c==key) count++;
        }

        if(count>=min && count<=max) partOne++;

        // Part two
        if(str[min-1]==key || str[max-1]==key)
        {
            if(str[min-1]!=str[max-1]) partTwo++;
        }

        itr++;
    }

    // Print out result
    cout << "Retsult of part one is: " << partOne << endl;
    cout << "Retsult of part two is: " << partTwo << endl;
}

int main()
{
    vector<myData> vec;

    addData(&vec);
    doCount(&vec);

    return 0;
}
