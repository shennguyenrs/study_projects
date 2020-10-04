#include<stdio.h>

// Menu of program
int Menu()
{
  int choice;

  // Menu of program
  printf("\n0 = Exit");
  printf("\n1 = Count the time");
  printf("\n2 = Points");
  printf("\n3 = String");
  printf("\n");
  printf("\nChoose an number to start:");

  scanf("%d", &choice);

  return choice;
}
