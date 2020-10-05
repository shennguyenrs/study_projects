#include <stdio.h>
#include <sqlite3.h>

#include "opentable.c"

int main()
{
    int count = 0;

    char * query = " SELECT COUNT(*) FROM Books;";

    sqlite3 * table;
    sqlite3_stmt * stmt;

    table = opentable();
    sqlite3_prepare_v2(table, query, -1, &stmt, NULL);
    sqlite3_step(stmt);

    count = sqlite3_column_int(stmt, 0);

    printf("%d", count);

    return 0;
}
