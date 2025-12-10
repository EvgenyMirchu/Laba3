#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct String_iterator 
{
    char * string;
    int str_len;
    int curr;
} Str_iterator;

Str_iterator* new_str_iterator(char* str, int n);
int get_curr(Str_iterator* pointer);
int next(Str_iterator* pointer);