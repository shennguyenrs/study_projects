#include "ArrayHeader/ArrayHeader.hpp"

#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;

int main()
{
  // Set precision
  cout << fixed << setprecision(3);

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
  cout << "Insert 5 records (in milliseconds): " << dur.count();
  cout << endl;

  start = chrono::high_resolution_clock::now();
  cout << endl;

  // Search record
  data.searchItem("Vaasa");
  //data.searchItem("5,6");

  stop = chrono::high_resolution_clock::now();
  dur = stop - start;
  cout << "Search record for \"Vaasa\" (in milliseconds): " << dur.count();
  cout << endl;

  start = chrono::high_resolution_clock::now();
  cout << endl;

  // Delete record
  //data.deleteItem("Kok");
  data.deleteItem("1,3");
  
  stop = chrono::high_resolution_clock::now();
  dur = stop - start;
  cout << "Delete record have x=1 y=3 (in milliseconds): " << dur.count();
  cout << endl;

  start = chrono::high_resolution_clock::now();
  cout << endl;

  // Print out records
  data.printRecords();

  stop = chrono::high_resolution_clock::now();
  dur = stop - start;
  cout << "Printing records (in milliseconds): " << dur.count();
  cout << endl;

  return 0;
}
