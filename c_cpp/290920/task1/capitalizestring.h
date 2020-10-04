#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

// Global variables
const int MAX_STRING = 1024;

// Capitalize string
void CapitalizeString()
{
  // Declare variables
  char * str = (char*)malloc(MAX_STRING*sizeof(char)); // Reserve memory for the string
  int count=0, len, i;

  printf("\n3 - Capitalize String\n");
  printf("\nInput your string (without spaces): ");

  /*
  // Not work on gcc 8 9 10
  // but work on clang 7
  scanf("%1024[^\n]", str);  //Scan a whole line until \n
  fgets(str, MAX_STRING, stdin);
  */

  scanf("%s", str); // Scan without space

  // Len the string 
  len = strlen(str);

  // Resize the memory of the string
  str = (char*)realloc(str, len);

  // Check if the character is small
  // and print out the capital character
  printf("\nThe capitalized string is: ");
  for(i=0; i<len; i++)
  {
    if(!isupper(*(str+i)))
    {
      *(str+i) = toupper(*(str+i));
      count++;
    }
    printf("%c", *(str+i));
  }
  printf("\nThe number of small letters in this string is %d\n", count);

  free(str);
}
