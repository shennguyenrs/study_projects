#include <stdio.h>
#include <sqlite3.h>

#include "opentable.c"

int main()
{
  // Decare table schema
  sqlite3 * table;
  char * sql = "CREATE TABLE Books("
              "isbn13 INT PRIMARY KEY NOT NULL,"
              "isbn10 INT NOT NULL,"
              "title TEXT NOT NULL,"
              "author TEXT NOT NULL,"
              "publisher TEXT NOT NULL,"
              "amount INT NOT NULL,"
              "genre TEXT NOT NULL,"
              "language TEXT NOT NULL"
              ");";

  // Declare variables
  int exit;
  char * errmsg;

  // Create Table
  table = opentable();
  exit = sqlite3_exec(table, sql, NULL, NULL, &errmsg);

  // Notify if create table has error
  if(exit!=SQLITE_OK)
  {
    printf("Error when create new table!\n");
    sqlite3_free(errmsg);
  }
  else
  {
    printf("Successfully create new database!\n");
  }

  // Close table
  sqlite3_close(table);

  return 0;
}
