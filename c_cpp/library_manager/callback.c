#include <stdio.h>

int callback(void * data, int argc, char ** argv, char ** azColName)
{
    int i = 0;

    // Print out data
    for(i=0; i<argc; i++)
    {
        printf("%s: %s\n", azColName[i], argv[i] ? argv[i] : NULL);
    }
    printf("\n");

    return 0;
}
