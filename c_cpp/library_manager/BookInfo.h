#include <stdlib.h>

struct BookInfor
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
