#pragma once
#include "container.h"
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void print_publication_table(Top *stack, FILE *output);
void export_to_csv(Top *stack, FILE *output);
Top* import_from_csv(FILE *input);
