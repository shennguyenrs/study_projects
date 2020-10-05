#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char * str;

    str = malloc(1024*sizeof(char));

    scanf("%[^\n]", str);

    int len = strlen(str);
    str = realloc(str, len);

    printf("%s", str);

    return 0;
}
