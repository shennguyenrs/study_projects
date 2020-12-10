#include <iostream>
#include <random>
#include <array>
#include <iomanip>
#include <iterator>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <chrono>

using namespace std;

static default_random_engine generator;
static uniform_int_distribution<unsigned int> distribution(1, 6);
static array<unsigned long int, 11> counters{0};

void doCount(unsigned int const times, array<unsigned long int, 11> *arr)
{
    unsigned int i;

    for(i=0; i<times; i++)
    {
        unsigned int a = distribution(generator);
        unsigned int b = distribution(generator);

        auto itr = arr->begin();
        advance(itr, a+b-2);
        *itr+=1;
    }
}

int main() 
{
    unsigned int i{0};
    unsigned int tasks{36000000};

    unsigned int quotient{tasks/4};
    unsigned int remainder{tasks%4};

    pid_t pid1;
    pid_t pid2;

    array<unsigned long int, 11> *shared = 
        static_cast<array<unsigned long int, 11>*>
            (
                mmap
                (
                    NULL, counters.size(), PROT_READ | PROT_WRITE, 
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0
                )
            );

    auto start = chrono::high_resolution_clock::now();

    pid1 = fork();
    pid2 = fork();

    if(pid1==0 && pid2>0)
    {
        doCount(quotient, shared);
        exit(0);
    }
    else if(pid1>0 && pid2==0)
    {
        doCount(quotient, shared);
        exit(0);
    }
    else if(pid1==0 && pid2==0)
    {
        doCount(quotient, shared);
        exit(0);
    }
    else
    {
        // In parent
        waitpid(pid1, NULL, 0);
        waitpid(pid2, NULL, 0);
        doCount(quotient, shared);
    }

    if(remainder!=0) doCount(remainder, shared);

    auto stop = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> dur = stop - start;
    cout << "In milliseconds: " << dur.count() << endl;
    cout << endl;

    cout << "Sum" << setw(10) << "Frequency" << endl;

    for(auto itr=shared->begin(); itr!=shared->end(); itr++)
    {
        cout << setw(3) << i+2 << setw(10) << *itr << endl;
        i++;
    }

    munmap(shared, counters.size());

    return 0;
}