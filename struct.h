#include <stdbool.h>


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