/* ****************************************************************** */
/* Variable Sized Arrays (HackerRank)                                 */
/*                                                                    */
/* variable_sized_arrays.cpp                                          */
/* Created 26.02.2020 by shennguyenrs                                 */
/*                                                                    */
/* ****************************************************************** */

#include <vector>
#include <iostream>
using namespace std;

int main() 
{
  int n, q; //n is the numbers of array, q is the number of querries
  cin >> n >> q;

//define 2d matrix with n rows
  vector<vector<int> > arr(n);

  for (int i=0; i<n; i++)
  {
    int k; //the elements (columns) of i row

    cin >> k;

    arr[i].resize(k); //resize column of the i row fits to k elements

//input elements into i row and j column
//of the matrix
    for (int j=0; j<k; j++)
    {
      cin >> arr[i][j];
    }
  }

//print out the elements base on the rows and columns index
//following the number of querries q
  for (int i=0; i<q; i++)
  {
    int row, col; //the index
    
    cin >> row >> col;
    cout << arr[row][col] << endl;

  }

  return 0;
}
