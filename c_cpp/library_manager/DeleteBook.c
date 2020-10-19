#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <sqlite3.h>

// Do query with ISBN-10
char * DeleteIsbn10(char isbn[10])
{
    // Query statement
    char * query = "DELETE FROM Books WHERE isbn10=";
    char end[] = ";";

    // Concat the query string
    strcat(query, isbn);
    strcat(query, end);

    return query;
}

// Do query with ISBN-13
char * DeleteIsbn13(char isbn[13])
{
    // Query statement
    char * query = "DELETE FROM Books WHERE isbn13=";
    char end[] = ";";

    // Concat the query string
    strcat(query, isbn);
    strcat(query, end);

    return query;
}

void DeleteBook()
{
    // Declare variables
    char isbn[13];
    unsigned int len;
    unsigned int i;
    bool isTrue = true;

    // Prompts
    printf("Delete a Book in database");
    printf("------------------------------\n");
    printf("\n");

    // Input validation
    do
    {
        printf("Input ISBN-13 or ISBN-10 (Without -): ");
        scanf("%s", isbn);

        len = strlen(isbn);

        // Check dash
        for(i=0; i<len; i++)
        {
            if(isbn[i]=='-')
            {
                isTrue = false;
                break;
            }
        }

        // Is true when string has 13 or 10 characters
        isTrue = (isTrue && len==13) || (isTrue && len==10);

        if(!isTrue)
        {
            printf("You enter wrong format!\n");
            printf("Please try again!\n");
        }

    } while(!isTrue);

    // Prepare sql query bases on result
    char * query;
    sqlite3 * table;

    if(len==10)
    {
        query = DeleteIsbn10(isbn);
    }
    else
    {
        query = DeleteIsbn13(isbn);
    }

    // Open table and excute the statement
    table = OpenTable();

    int exit = sqlite3_exec(table, query, callback, NULL, NULL);

    // Send message if fail to delete record
    if(exit!=SQLITE_OK)
    {
        printf("Fail to delete the book!\n");
    }

    // Close table
    sqlite3_close(table);
}
