#pragma once
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


typedef struct Scientific_publication
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


int compare(Publication *a, Publication *b);
char* generate_title();
const char* random_element(const char* array[], int size);
Publication* new_pub();
void free_publication(Publication *pub);