#include<iostream>
#include<vector>
using namespace std;

int main()
{
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

  // Test for k
  for(auto x: vec)
  {
    unsigned int k=0, count=0;
    for(;(12*k+8)<=x;k++)
    {
      count++;
    }
    cout << count << endl;
  }

  return 0;
}
