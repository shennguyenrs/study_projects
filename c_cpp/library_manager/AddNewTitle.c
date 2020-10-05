#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#include "BookInfo.h"

#define MAX_STRING 1024

struct BookInfor getValue()
{
    // Declare variables
    struct BookInfor input;

    input.title = malloc(MAX_STRING*sizeof(char));
    input.author = malloc(MAX_STRING*sizeof(char));
    input.publisher = malloc(MAX_STRING*sizeof(char));
    input.genre = malloc(MAX_STRING*sizeof(char));
    input.language = malloc(MAX_STRING*sizeof(char));
    unsigned int len;

    // Isbn 13
    printf("\nISBN-13: ");
    scanf("%d", &input.isbn13);

    // Isbn 10
    printf("\nISBN-10: ");
    scanf("%10[^\n]", input.isbn10);
    fflush(stdin);

    // Title
    printf("\nTitle: ");
    scanf("%1024[^\n]", input.title);
    len = strlen(input.title);
    input.title = realloc(input.title, len);
    fflush(stdin);

    // Author
    printf("\nAuthor: ");
    scanf("%1024[^\n]", input.author);
    len = strlen(input.author);
    input.author = realloc(input.author, len);
    fflush(stdin);
    
    // Publisher
    printf("\nPublisher: ");
    scanf("%1024[^\n]", input.publisher);
    len = strlen(input.publisher);
    input.publisher = realloc(input.publisher, len);
    fflush(stdin);

    // Amount
    printf("\nAmount: ");
    scanf("%d", &input.amount);

    // Genre
    printf("\nGenre: ");
    scanf("%1024[^\n]", input.genre);
    len = strlen(input.genre);
    input.genre = realloc(input.genre, len);
    fflush(stdin);

    // Language
    printf("\nLanguage: ");
    scanf("%1024[^\n]", input.language);
    len = strlen(input.language);
    input.language = realloc(input.language, len);
    fflush(stdin);

    return input;
}

void AddNewTitle()
{
    
    // Prompts
    printf("Add New Book\n");
    printf("------------------------------\n");

    // Declare struct
    struct BookInfor book = getValue();


}
