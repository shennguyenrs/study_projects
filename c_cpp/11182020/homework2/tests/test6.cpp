#include <iostream>
using namespace std;

#define RED "\x1B[31m"
#define RESET "\x1B[0m"

int main(int argc, char** argv)
{
  cout << RED << "test" << RESET << endl;
  cout << "test" << endl;
  return 0;
}
