#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{
  ifstream file;
  string filename;

  filename = argv[1];

  file.open(filename);

  if(file.is_open())
  {
    string line;

    while(getline(file, line))
    {
      cout << line << endl;
    }

    file.close();
  }

  return 0;
}
