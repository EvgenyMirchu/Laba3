#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

// Вершинка (элемент) стека
typedef struct StackNode 
{
    Publication *publication;
    struct StackNode *next;
} Node;

// Указатель на верхний (последний) элемент стека
typedef struct StackTopPointer
{
    Node *top_pointer;
} Top;

Top* stack_init(void);
short stack_get_size(Top *stack);
Node* stack_get_node(Top *stack, short k);
Node* stack_get_highest(Top *stack);
Node* stack_get_lowest(Top *stack);
Node* stack_get_next(Top *stack, Node *node);
Node* stack_get_previous(Top *stack, Node *node);
Top* stack_push_end(Top *st, Publication *pub);
Top* stack_push_start(Top *st, Publication *pub);
Top* stack_push_node(Top *st, Publication *pub, short k);
Top* stack_pop_end(Top *st);
Top* stack_pop_start(Top *st);
Top* stack_pop_node(Top *st, Node *pop_node);
Top* stack_swap_nodes(Top *st, Node *node_1, Node *node_2);
short stack_is_empty(Top *stack);
void stack_free(Top *stack);