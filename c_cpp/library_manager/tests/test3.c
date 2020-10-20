#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char * str1;
    char * str2;
    int n;

    str1 = malloc(1024*sizeof(char));
    str2 = malloc(1024*sizeof(char));

    printf("Input a number: ");
    scanf("%d", &n);
    /*scanf("%d%*c", &n);*/
    //getchar();

    printf("Input anything: ");
    scanf(" %[^\n]%*c", str1);
    /*scanf("%[^\n]%*c", str1);*/
    //fgets(str1, 1024, stdin);

    printf("Input anything: ");
    scanf("%[^\n]%*c", str2);
    /*fgets(str2, 1024, stdin);*/

    int len = strlen(str1);
    str1 = realloc(str1, len);

    len = strlen(str2);
    str2 = realloc(str2, len);

    printf("\n");
    printf("%s\n", str1);
    printf("%s\n", str2);

    return 0;
}
