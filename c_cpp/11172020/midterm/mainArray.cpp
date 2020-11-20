#include "ArrayHeader.hpp"

#include <iostream>
#include <chrono>
using namespace std;

int main()
{
  //auto start = chrono::high_resolution_clock::now();
  //auto stop = chrono::high_resolution_clock::now();
  //chrono::duration<double, milli> dur = stop - start;
  //cout << dur.count();

  // Insert test data
  ArrayDatabase data;

  Location lo1("Kok", 1, 2);
  data.insertItem(lo1);

  Location lo2("Hel", 2, 3);
  data.insertItem(lo2);

  Location lo3("Tam", 3, 4);
  data.insertItem(lo3);

  Location lo4("Tur", 4, 5);
  data.insertItem(lo4);

  Location lo5("Vaa", 5, 6);
  data.insertItem(lo5);

  data.printRecords();

  return 0;
}
