#include <iostream>
using namespace std;

int main()
{
  string filename[] = {"test1", "test2"};

  cout << sizeof(filename)/sizeof(filename[0]) << endl;
  return 0;
}
