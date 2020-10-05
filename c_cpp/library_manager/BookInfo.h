#include <stdlib.h>

struct BookInfor
{
    unsigned int isbn13;
    char isbn10[10];
    char * title;
    char * author;
    char * publisher;
    unsigned int amount;
    char * genre;
    char * language;
    unsigned int len;
};
