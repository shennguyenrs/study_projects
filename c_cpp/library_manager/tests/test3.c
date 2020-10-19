#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char * str1;
    char * str2;

    str1 = malloc(1024*sizeof(char));
    str2 = malloc(1024*sizeof(char));

    printf("Input anything: ");
    fgets(str1, 1024, stdin);

    printf("Input anything: ");
    fgets(str2, 1024, stdin);

    int len = strlen(str1);
    str1 = realloc(str1, len);

    len = strlen(str2);
    str2 = realloc(str2, len);

    printf("%s", str1);
    printf("%s", str2);

    return 0;
}
