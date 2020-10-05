#include <stdio.h>
#include <sqlite3.h>

sqlite3 * OpenTable()
{
  // Declare variables
  sqlite3 * table;

  // Open tables
  sqlite3_open("books.db", &table);

  return table;
}
