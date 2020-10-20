#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define MAX_STRING 1024

void ListByGenre()
{
    // Declare variables
    char * keyword = malloc(MAX_STRING*sizeof(char));
    unsigned int len;

    // Prompts
    printf("List all the book in a selected genre\n");
    printf("------------------------------\n");
    printf("\n");

    // Show all Genres
    ShowGenre();

    printf("Input genre: ");
    scanf("%s%*c", keyword);

    len = strlen(keyword);
    keyword = realloc(keyword, len);

    // Prepare SQL statement
    char * query = "SELECT * FROM Books WHERE genre=";
    char end[] = ";";

    strcat(query, keyword);
    strcat(query, end);

    // Open sql table
    sqlite3 * table;

    table = OpenTable();

    // Excute sql statement
    sqlite3_exec(table, query, callback, NULL, NULL);

    // Free memory
    free(keyword);

    // Close table
    sqlite3_close(table);
}
