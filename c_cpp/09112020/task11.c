/* Task 11: Print out name of weekday in German
 */

#include<stdio.h>

// Save the name of day in an 2D array
#define row 7
#define col 8

int main()
{
  char dayName[row][col] = {"Montag", "Dienstag", "Mittwoch", "Freitag", "Samstag", "Sonntag"};
  int dayNumber;
  int gap=2; // The gap between day number and the numerical order in array
  int i;

  printf("Input day number: ");
  scanf("%d", &dayNumber);
  printf("Name of the weekday: ");

  // Print out name of weekday
  for(i=0; i<col; i++)
  {
    printf("%c", dayName[dayNumber-gap][i]);
  }

  return 0;
}
