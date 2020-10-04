/* Task 4
 */

#include<stdio.h>

int main()
{
  // Declare variables
  FILE * fptr;
  int sum=0, number;

  // Welcome screen
  printf("\n==============================");
  printf("\n           TASK 4             ");
  printf("\n==============================");

  // Open file
  fptr = fopen("task4_data.txt", "r");

  // Get data and sum
  if(fptr==NULL)
  {
    printf("Missing data file");
  }
  else
  {
    while(!feof(fptr))
    {
      fscanf(fptr, "%d\n", &number);
      sum += number;
    }

    // Close file
    fclose(fptr);

    // Print out the result
    printf("\nThe sum of all numbers in file is: %d", sum);
  }

  return 0;
}
