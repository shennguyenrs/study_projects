#include <stdio.h>
#include <sqlite3.h>

void CreateTable()
{
  // Decare table schema
  sqlite3 * table;
  char * sql = "CREATE TABLE Books("
              "isbn13 INT PRIMARY KEY NOT NULL,"
              "isbn10 TEXT NOT NULL,"
              "title TEXT NOT NULL,"
              "author TEXT NOT NULL,"
              "publisher TEXT NOT NULL,"
              "amount INT NOT NULL,"
              "genre TEX NOT NUL,"
              "language TEXT NOT NULL"
              ");";

  // Declare variables
  int exit = 0;
  char * errmsg;

  // Create Table
  table = OpenTable();
  exit = sqlite3_exec(table, sql, NULL, NULL, &errmsg);

  // Notify if create table has error
  if(exit!=SQLITE_OK)
  {
    printf("Error when create new table!\n");
    sqlite3_free(errmsg);
  }

  // Close table
  sqlite3_close(table);
}
