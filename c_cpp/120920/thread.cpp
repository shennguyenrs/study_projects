#include <iostream>
#include <random>
#include <array>
#include <iomanip>
#include <thread>
#include <queue>
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

class Pool
{
    private:
        queue<thread> worker;
        unsigned int maxWorker{thread::hardware_concurrency()};

    public:
        void submitTask(unsigned int times)
        {
            worker.push(thread( [=]
            {
                doCount(times);
            }));
        }

        void terminateWorkers()
        {
            while(!worker.empty())
            {
                worker.front().join();
                worker.pop();
            }
        }

        void doTask(unsigned int tasks)
        {
            unsigned int quotient{tasks/maxWorker};
            unsigned int remainder{tasks%maxWorker};
            unsigned int workerOnWork{maxWorker};

            // Do the quotient of tasks
            if(quotient!=0)
            {
                while(workerOnWork>0)
                {
                    submitTask(quotient);
                    workerOnWork--;
                }
                
                terminateWorkers();
            }

            // Do the remainder if it is exist
            if(remainder!=0)
            {
                submitTask(remainder);
                terminateWorkers();
            }
        }

};

int main() 
{
    unsigned int i;
    unsigned int tasks{36000000};

    Pool pool;

    auto start = chrono::high_resolution_clock::now();

    pool.doTask(tasks);

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