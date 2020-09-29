/* Task 3
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

const int MAX_STRING = 1024;

int main()
{
  // Declare variables
  FILE * fptr;
  char * str = malloc(MAX_STRING*sizeof(char));
  int len;
  int i;

  // Welcome screen
  printf("\n==============================");
  printf("\n           TASK 3             ");
  printf("\n==============================");
  printf("\n");

  // Open file
  fptr = fopen("task3_data.txt", "r");

  // Get data
  if(fptr==NULL)
  {
    printf("Missing data file");
  }
  else
  {
    fgets(str, MAX_STRING, fptr);

    // Close file
    fclose(fptr);

    // Resize the memory
    len = strlen(str);
    str = realloc(str, len);

    // Search for the space and replace
    // then save to new file
    fptr = fopen("task3_data.txt", "w");

    for(i=0; i<len; i++)
    {
      if(isspace(*(str+i)))
      {
        *(str+i) = ',';
      }
      fputc(*(str+i), fptr);
    }

    // Print out notification
    printf("Successfully created new file");
    
    // Close file
    fclose(fptr);
  }

  return 0;
}
