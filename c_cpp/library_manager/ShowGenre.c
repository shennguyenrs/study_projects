#include <stdio.h>
#include <sqlite3.h>

void ShowGenre()
{
    // Declare variables
    char * query = "SELECT DISTINCT genre FROM Books;";

    // Open sql table
    sqlite3 * table;

    table = OpenTable();

    // Excute query
    sqlite3_exec(table, query, callback, NULL, NULL);

    // Close table
    sqlite3_close(table);
}
