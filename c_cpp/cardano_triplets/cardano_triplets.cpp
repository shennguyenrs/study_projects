#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
  // Declare a, b and c followed the equation
  unsigned int a=0, b=0, c=0;
  double leftPart, denomirator;

  // Declare variables
  unsigned int q, n, i=0, count=0;
  vector<unsigned int> vec;

  // Program flow
  // Input number of queries q and n
  cin >> q;
  while((i<q) && (cin>>n))
  {
    vec.push_back(n);
    i++;
  }

  for(unsigned int x: vec)
  {
    while(a+b<x)
    {
      while(a+b<x)
      {
        leftPart = 8*pow(a,3) + 15*pow(a,2) + 6*a - 1; // Take from the equation
        denomirator = 27*pow(b,2); //Take the equation

        // Skip if the fraction is below than 1
        if(leftPart<denomirator)
        {
          break;
        }

        // Skip if c is not an integer
        if(fmod(leftPart, denomirator)==0)
        {
          c = leftPart/(27*pow(b,2)); // Take from the equation
          unsigned int sum = a+b+c;
          count += sum<=x ? 1 : 0;
        }

        // Increment b
        b++;
        c=1;
      }
      
      // Increment a
      a++;
      b=1;
    }

    cout << count << endl;
  }

  return 0;
}
