#include "struct-record.h"
#include "container_and_methods.h"

int compare(Publication *a, Publication *b);

int compare(Publication *a, Publication *b) // Если 1, то a > b; если 0, то a = b; если -1б то a < b  
{
    int compare_pub_name = strcmp(a->publication_name, b->publication_name);
    if (compare_pub_name == 0)
    {
        int compare_sec_name = strcmp(a->author_second_name, b->author_second_name);
        if (compare_sec_name == 0)
        {
            int compare_initials = strcmp(a->author_initials, b->author_initials);
            if (compare_initials == 0)
            {
                int compare_mag_name = strcmp(a->magazine_name, b->magazine_name);
                if (compare_mag_name == 0)
                { 
                    if (a->magazine_volume == b->magazine_volume)
                    {   
                        if (a->publication_year == b->publication_year)
                        {
                            if (a->is_in_RSCI == b->is_in_RSCI)
                            {
                                if (a->citations_amount == b->citations_amount) return 0;
                                if (a->citations_amount > b->citations_amount) return 1;
                                return -1;
                            }
                            
                            if (a->is_in_RSCI == true) return 1;
                            return -1;
                        }

                        if (a->publication_year > b->publication_year) return 1;
                        return -1;
                    }

                    if (a->magazine_volume > b->magazine_volume) return 1;
                    return -1;
                }
                if (compare_mag_name > 0) return 1;
                return -1;
            }
            if (compare_initials > 0) return 1;
            return -1;
        }

        if (compare_sec_name > 0) return 1;
        return -1;
    }

    if (compare_pub_name > 0) return 1;
    return -1;
}