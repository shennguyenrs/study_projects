#include <stdio.h>
#include <sqlite3.h>

sqlite3 * OpenTable()
{
  // Declare variables
  sqlite3 * table;

  // Open tables
  int exit = sqlite3_open(fileName, &table);

  if(exit!=SQLITE_OK)
  {
    printf("Error when open database!\n");
  }

  return table;
}
