#include "arguments.h"

Str_iterator* new_str_iterator(char* str, int n)
{
    Str_iterator* tmp = malloc(sizeof(Str_iterator));
    tmp->str_len = n;
    tmp->curr = 0;
    tmp->string = str; 

    return tmp;
}

int get_curr(Str_iterator* pointer)
{
    return(pointer->curr);
}

int next(Str_iterator* pointer)
{
    if (pointer->curr+1 >= pointer->str_len) return 1;
    pointer->curr = pointer->curr + 1;
    return 0;
}