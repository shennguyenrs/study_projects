#include <iostream>
#include <random>
#include <array>
#include <iomanip>
#include <chrono>

using namespace std;

static default_random_engine generator;
static uniform_int_distribution<unsigned int> distribution(1, 6);
static array<unsigned long int, 11> counters{0};

void doCount(unsigned int times)
{
    unsigned int i;

    for(i=0; i<times; i++)
    {
        unsigned int a = distribution(generator);
        unsigned int b = distribution(generator);

        auto itr = counters.begin();
        advance(itr, a+b-2);
        *itr+=1;
    }
}

int main() 
{
    unsigned int i;
    unsigned int tasks{36000000};

    auto start = chrono::high_resolution_clock::now();

    doCount(tasks);

    auto stop = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> dur = stop - start;
    cout << "In milliseconds: " << dur.count() << endl;
    cout << endl;

    cout << "Sum" << setw(10) << "Frequency" << endl;
    for(i=0; i<counters.size(); i++ )
    {
        cout << setw(3) << i+2 << setw(10) << counters[i] << endl;
    }

    return 0;
}