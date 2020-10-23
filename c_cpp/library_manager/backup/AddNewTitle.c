#include <stdio.h>
#include <string.h>
#include <sqlite3.h>

#include "GetValues.c"

void AddNewTitle()
{
    // Prompts
    printf("\n");
    printf("------------------------------\n");
    printf("Add New Book\n");
    printf("------------------------------\n");

    // Declare struct
    struct BookInfor book = getValue();

    // SQL Insert statement
    char * insert = "INSERT INTO Books VALUE(";
    char end[] = ");";

    strcat(insert, book.isbn13);
    strcat(insert, ",");
    strcat(insert, book.isbn10);
    strcat(insert, ",");
    strcat(insert, book.title);
    strcat(insert, ",");
    strcat(insert, book.author);
    strcat(insert, ",");
    strcat(insert, book.publisher);
    strcat(insert, ",");
    strcat(insert, book.amount);
    strcat(insert, ",");
    strcat(insert, book.genre);
    strcat(insert, ",");
    strcat(insert, book.language);
    strcat(insert, end);
    
    // Open database and insert
    char * errmsg;
    sqlite3 * table;

    table = OpenTable();

    int exit = sqlite3_exec(table, insert, NULL, NULL, &errmsg);

    // Check if insert is fine
    if(exit!=SQLITE_OK)
    {
        printf("Error Insert!\n");
        sqlite3_free(errmsg);
    }
    else
    {
        printf("Insert data successfully!\n");
    }

    // Close database
    sqlite3_close(table);
}
