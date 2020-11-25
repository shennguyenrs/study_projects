#include "LinkedlistHeader/LinkedlistHeader.hpp"

#include <iostream>
#include <chrono>
#include <ratio>
#include <iomanip>
using namespace std;

int main()
{
  // Set precision
  cout << fixed << setprecision(3);

  auto start = chrono::high_resolution_clock::now();

  // Insert items
  Node* head = NULL;
  LinkedDatabase data;

  Location lo1("Kok", 1, 2);
  data.insertItem(&head, make_pair(lo1.getCity(), lo1.makeCor()));

  Location lo2("Hel", 2, 3);
  data.insertItem(&head, make_pair(lo2.getCity(), lo2.makeCor()));

  Location lo3("Tam", 3, 4);
  data.insertItem(&head, make_pair(lo3.getCity(), lo3.makeCor()));

  Location lo4("Tur", 4, 5);
  data.insertItem(&head, make_pair(lo4.getCity(), lo4.makeCor()));

  Location lo5("Vaa", 5, 6);
  data.insertItem(&head, make_pair(lo5.getCity(), lo5.makeCor()));

  auto stop = chrono::high_resolution_clock::now();
  chrono::duration<double, milli> dur = stop - start;
  cout << "Insert 5 records (in milliseconds): " << dur.count();
  cout << endl;

  start = chrono::high_resolution_clock::now();
  cout << endl;

  // Search record
  data.searchItem(&head, "Vaasa");
  //data.searchItem(&head, "5,6");

  stop = chrono::high_resolution_clock::now();
  dur = stop - start;
  cout << "Search record for \"Vaasa\" (in milliseconds): " << dur.count();
  cout << endl;

  start = chrono::high_resolution_clock::now();
  cout << endl;

  start = chrono::high_resolution_clock::now();
  cout << endl;

  // Delete record
  //data.deleteItem(&head, "Kok");
  data.deleteItem(&head, "1,3");
  
  stop = chrono::high_resolution_clock::now();
  dur = stop - start;
  cout << "Delete record have x=1 y=3 (in milliseconds): " << dur.count();
  cout << endl;

  start = chrono::high_resolution_clock::now();
  cout << endl;

  // Print records
  data.printRecords(head);

  stop = chrono::high_resolution_clock::now();
  dur = stop - start;
  cout << "Printing records (in milliseconds): " << dur.count();
  cout << endl;

  delete head;

  return 0;
}
