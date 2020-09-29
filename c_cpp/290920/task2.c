/* Task 2
 */

#include<stdio.h>

// Declare global variables
const int ROW = 11;
const int COL = 2;

int main()
{
  // Declare variables
  int data[11][2] = {
    {1750, 600},
    {1800, 900},
    {1850, 1200},
    {1900, 1600},
    {1950, 2200},
    {1960, 3000},
    {1970, 3800},
    {1980, 4500},
    {1990, 5500},
    {2000, 6100},
    {2010, 6800}
  };
  int year, population=0, i;
  int begin = 0;
  int end = ROW;

  // Welcome screen
  printf("\n==============================");
  printf("\n           TASK 2             ");
  printf("\n==============================");
  printf("\n");
  printf("Input the year: ");
  scanf("%d", &year);

  // Search for population
  if(year<data[ROW-1][0] && year>data[0][0])
  {
    for(i=0; i<ROW; i++)
    {
      int mid = (begin+end)/2;
      int yearOfMid = data[mid][0];

      if(yearOfMid==year)
      {
        population = data[mid][1];
        break;
      }
      else if(yearOfMid>year)
      {
        begin = 0;
        end = mid;
      }
      else
      {
        begin = mid;
      }
    }
  }

  // Print out the result
  if(population==0)
  {
    printf("\nCannot find population from data");
  }
  else
  {
    printf("\nThe population is: %d", population);
  }

  return 0;
}
