#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isPalindrome(string str)
{
  bool result{true};

  stack<char> bwStr;
  stack<char> fwStr;
  
  unsigned int len = str.length();
  unsigned int mid = len/2;
  unsigned int mod = len%2;
  unsigned int i;

  // Move string to backward stack
  for(i=0; i<mid; i++)
  {
    bwStr.push(str[i]);
  }

  // Move string to forward stack
  for(i=len-1; i>=mid+mod; i--)
  {
    fwStr.push(str[i]);
  }

  // Compare 2 stack
  while(!bwStr.empty() || !fwStr.empty())
  {
    if(bwStr.top()!=fwStr.top())
    {
      result &= false;
      return result;
    }

    // Pop the top
    bwStr.pop();
    fwStr.pop();
  }

  return result;
}

int main()
{
  // Variable definition
  string str;

  cout << "Input your string: ";
  cin >> str;

  cout << (isPalindrome(str) ? "It is a palindrome!" : "It is not a palindrome!") << endl; 

  return 0;
}
