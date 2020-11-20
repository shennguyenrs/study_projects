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

  auto start = chrono::high_resolution_clock::now();

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

  auto stop = chrono::high_resolution_clock::now();
  chrono::duration<double, milli> dur = stop - start;
  cout << "Insert time (in  milliseconds): " << dur.count();
  cout << endl;

  start = chrono::high_resolution_clock::now();
  cout << endl;

  // Search record
  data.searchItem("Vaasa");
  //data.searchItem("5,6");

  stop = chrono::high_resolution_clock::now();
  dur = stop - start;
  cout << "Search time (in  milliseconds): " << dur.count();
  cout << endl;

  start = chrono::high_resolution_clock::now();
  cout << endl;

  // Delete record
  //data.deleteItem("Kok");
  data.deleteItem("1,3");
  
  stop = chrono::high_resolution_clock::now();
  dur = stop - start;
  cout << "Delete time (in  milliseconds): " << dur.count();
  cout << endl;

  start = chrono::high_resolution_clock::now();
  cout << endl;

  // Print out records
  data.printRecords();

  stop = chrono::high_resolution_clock::now();
  dur = stop - start;
  cout << "Printing time (in  milliseconds): " << dur.count();
  cout << endl;

  return 0;
}
