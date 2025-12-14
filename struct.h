#pragma once
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>


typedef struct Scientific_puclication
{
    char * publication_name;
    char * author_second_name;
    char * author_initials;
    char * magazine_name;
    unsigned short magazine_volume;
    short publication_year;
    short pages_amount;
    _Bool is_in_RSCI;
    short citations_amount;
} Publication;


void new_pub(Top *stack, int count);
int compare(Publication *a, Publication *b);