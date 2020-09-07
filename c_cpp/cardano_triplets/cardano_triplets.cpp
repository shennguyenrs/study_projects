#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// Test integer number
/*
 *bool TestInteger(float c)
 *{
 *  float fracPart = c - int(c);
 *  return fracPart > 0 ? false : true;
 *}
 */

int main()
{
  // Declare a, b and c followed the equation
  unsigned int a=1, b=1, c=1, leftPart, denomirator;
  //float c;

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

        if(leftPart<denomirator)
        {
          break;
        }

        if((leftPart%denomirator)==0)
        {
          c = leftPart/(27*pow(b,2)); // Take from the equation
          unsigned int sum = a+b+c;
          count = sum<=x ? count+1 : count+0;
        }
        //c = leftPart/(27.0*pow(b,2)); // Take from the equation
        //int sum = a+b+c;

        // If c is an integer and sum
        //count = (TestInteger(c) && sum<=x) ? count+1 : count+0;

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
