#include <sqlite3.h>

#ifndef _BOOKS_H_
#define _BOOKS_H_
//#pragma once

// Book's Information
struct BookInfo
{
    char isbn13[13];
    char isbn10[10];
    char * title;
    char * author;
    char * publisher;
    char amount[2];
    char * genre;
    char * language;
};

// Definite database file name
extern const char filename[];

// Definition max string
#define MAX_STRING 1024

/* Main Functions definite */
int MenuOne(); // When the local database is not available

int MenuTwo(); // When the local database is available

void AddNewTitle(); // Insert new titles into database

void SearchKeyword(); // Search book information by using a keyword in the title

void SearchIsbn(); // Search book information by using ISBN code

void DeleteBook(); // Delete a title by using ISBN code
 
void ListByGenre(); // List all the books information in a genre
 
/* Sub-Funtions definite */
int callback(void *data, int argc, char **argv, char **azColName); // Print the sql results

sqlite3 * OpenTable();

int CheckDatabase(); // Count the books in database

void CreateTable();

void ShowGenre(); // List all available genres

struct BookInfo getValue(); // Get the input values to struct

#endif
