#include <stdbool.h>


typedef struct Scientific_puclication
{
    char * puclication_name;
    char * author_second_name;
    char * author_initials;
    char * magazine_name;
    short publication_year;
    unsigned short magazine_volume;
    _Bool is_in_RSCI;
    short pages_amount;
    short citations_amount;
} Publication;