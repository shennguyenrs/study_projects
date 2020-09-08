#include<iostream>
#include<vector>
#include<cmath>
#include<chrono>
using namespace std;

bool isInteger(float a)
{
  float result = fmod(a,1);
  return result==0 ? true : false;
}

int main()
{
  // Start timer
  auto start = chrono::high_resolution_clock::now();

  // Declare Variables
  unsigned int q, n, i=0;
  vector<unsigned int> vec;

  // Input number of queries q and integer n
  cin >> q;
  while((i<q) && (cin>>n))
  {
    vec.push_back(n);
    i++;
  }

  for(auto x: vec)
  {
    unsigned int k=0, count=0;

    while((3*k+2)<x)
    {
      // Declare expr to control the loop
      unsigned int c=1;
      unsigned int expr = pow((k+1),2)*(8*k+5);
      unsigned int a = 3*k+2;

      // Because b is an integer so c have to be greater than expr
      // b = sqrt(expr/c)
      while((a+c)<x && expr>=c) 
      {
        if(fmod(expr,c)==0)
        {
          float b = sqrt(expr/c);
          count += isInteger(b) && (a+b+c<=x) ? 1 : 0;
        }

        // Increment c
        c++;
      }

      // Increment k
      k++;
    }

    // Print count
    cout << count << endl;
  }

  // Stop timer
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::seconds>(stop-start);
  cout << duration.count() << 's' << endl;

  return 0;
}
