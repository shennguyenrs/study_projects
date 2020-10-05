#include <stdio.h>
#include <sqlite3.h>

/*#include "functions.h"*/

sqlite3 * opentable()
{
    sqlite3 * table;
    sqlite3_open("books.db", &table);
    return table;
}
