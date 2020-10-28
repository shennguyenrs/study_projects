/* Task 18: Generate random number of a dice in 100 times
 * and count for results of every result
 *
 * By using rand(), program can generate random number
 * from 0 to RAND_MAX
 *
 * Combine rand() with modulo operator, program can generate
 * random number that is smaller than the highest number of the range
 * and is greater than the lowest one
 *
 */

#include<stdio.h>
#include<stdlib.h>

int main()
{
  int low=1, high=6;
  int times=100;
  int result[6] = {0};

  // Generate number in 100 times
  for(int i=0; i<times; i++)
  {
    int randomNumber = rand()%(high-low+1) + low;

    // Count the results
    result[randomNumber-1] += 1;
  }

  // Print out the result value
  for(int i=0; i<high; i++)
  {
    printf("%d: %d\n", i+1, result[i]);
  }

  return 0;
}
