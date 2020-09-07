#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// Test integer number
bool TestInteger(float c)
{
  float fracPart = c - int(c);
  return fracPart > 0 ? false : true;
}

int main()
{
  // Declare a, b and c followed the equation
  unsigned int a=1, b=1, leftPart, sum=a+b;
  float c;

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
    while(sum<=x)
    {
      while(sum-a<=x)
      {
        leftPart = 8*pow(a,3) + 15*pow(a,2) + 6*a - 1; // Take from the equation
        c = leftPart/(27.0*pow(b,2)); // Take from the equation
        sum = a+b+c;

        // If c is an integer and sum
        count = (TestInteger(c) && sum<=x) ? count+1 : count+0;

        // Increment b
        b++;
      }
      
      // Increment a
      a++;
    }

    cout << count << endl;
  }

  return 0;
}
