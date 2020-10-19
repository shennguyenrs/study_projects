#include <stdio.h>
#include <string.h>

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
    printf("\nISBN-13 (Without -): ");
    fgets(input.isbn13, 13, stdin);

    // Isbn 10
    printf("\nISBN-10: ");
    fgets(input.isbn10, 10, stdin);

    // Title
    printf("\nTitle: ");
    fgets(input.title, 1024, stdin);
    len = strlen(input.title);
    input.title = realloc(input.title, len);

    // Author
    printf("\nAuthor: ");
    fgets(input.author, 1024, stdin);
    len = strlen(input.author);
    input.author = realloc(input.author, len);
    
    // Publisher
    printf("\nPublisher: ");
    fgets(input.publisher, 1024, stdin);
    len = strlen(input.publisher);
    input.publisher = realloc(input.publisher, len);

    // Amount
    printf("\nAmount: ");
    scanf("%s", input.amount);

    // Genre
    printf("\nGenre: ");
    fgets(input.genre, 1024, stdin);
    len = strlen(input.genre);
    input.genre = realloc(input.genre, len);

    // Language
    printf("\nLanguage: ");
    fgets(input.language, 1024, stdin);
    len = strlen(input.language);
    input.language = realloc(input.language, len);

    return input;
}
