#include "arguments.h"


/*
Все флаги:

1) Input data
    a) --generate N || -g N
    b) --in="data.csv" || -i data.csv ??????
2) Sort
    a) --sort || -s (сортировка (если не указан типо сортировки, то по возрастранию))
    b) --type=asc || -t A (сортировка по возрастанию)
    c) --type=desc || -t D (сортировка по убыванию)
3) Output
    a) --print || -P
    b) --out="output.csv"
*/



/*
int main(int argc, char *argv[])
{
    
    for (int i = 0; i < argc; i++)
    {
        printf("%s \n", argv[i]);
    } 

    return 0;
}
*/