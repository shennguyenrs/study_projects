/* Task 11: Print out name of weekday in German
 */

#include<stdio.h>

int main()
{
  char dayName[7][8] = {"Montag", "Dienstag", "Mittwoch", "Freitag", "Samstag", "Sonntag"};
  int dayNumber;

  printf("Input day number: ");
  scanf("%d", &dayNumber);
  printf("Name of the weekday: ");

  // Print out name of weekday
  for(int i=0; i<8; i++)
  {
    printf("%c", dayName[dayNumber-2][i]);
  }

  return 0;
}
