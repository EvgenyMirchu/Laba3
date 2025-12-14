#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GENERATIONS 9
#define MIN_GENERATIONS 3

typedef struct Mode 
{
    char* curr_mode;
    short amount_of_generatoins; // > 5, <= 100
    char* in_data;
    char* out_data;
    char* sorting_type;
    char generation_status;
    char in_status;
    char out_status;
    char type_status;
} Mode;

Mode* initialize_Mode_struct();
Mode* define_mode(Mode* mode, int argc, char* argv[]);
int str_is_digit(char * str);