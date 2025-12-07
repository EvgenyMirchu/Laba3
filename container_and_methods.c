#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "struct-record.h"

// Вершинка (элемент) стека
typedef struct Node 
{
    Publication publication;
    Node *next;
} Node;

// Указатель на верхний (последний) элемент стека
typedef struct StackTopPointer
{
    Node *top_pointer;
} Top;

// Создаем стек, а возвращаем именно верхушку (инициализация)
Top* stack_container_init(void)
{
    Top *stack;
    stack->top_pointer = NULL;
    return stack->top_pointer;
}

// Получение размера стека
unsigned short stack_get_size(Top *stack) 
{
    unsigned short count = 0;
    Node *current = stack->top_pointer;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Получение указателя на произвольный элемент по индексу
Node* stack_get_node(Top *stack, unsigned short k)
{
    if (stack_get_size(stack) - 1 < k) return NULL;

    Node *curr_elem = stack->top_pointer;

    for (unsigned short i = 0; i < k; ++i)
    { 
        curr_elem = curr_elem->next;
    }
    return curr_elem;
}


Node* stack_get_last(Top *stack) // Получение указателя на последний (самый верхний) элемент
{
    return stack->top_pointer;
}


Node* stack_get_first(Top *stack) // Получение указателя на первый (самый нижний) элемент
{
    stack_get_node(stack, stack_get_size(stack)-1);
}

Node* stack_get_next(Top *stack, Node *node) // Получение следующего элемента по указателю
{
    return node->next;
}

Node* stack_get_previous(Top *stack, Node *node) // Получение предыдущего элемента по указателю
{   
    if (stack_get_size(stack) < 2) return NULL;

    Node *prev_node = stack->top_pointer;
    while (1)
    {
        if (prev_node->next == node) return prev_node;
        else stack_get_next(stack, prev_node);
    }
}



// Дальше будут добавления в начало, конец, и произвольное место



Node* stack_push_end(Top *st, Publication *pub)   // Добавляем элемент в конец
{
    Node *new_node = malloc(sizeof(Node));
    new_node->publication = *pub; // Присваиваем новую публикацию
    new_node->next = st->top_pointer; // Присваиваем указатель на след. элемент
    st->top_pointer = new_node;
    return new_node;
}


Node* stack_push_start(Top *st, Publication *pub)     // Добавляем элемент в начало
{
    Node *new_node = malloc(sizeof(Node));
    Node *last_node = stack_get_first(st);
    new_node->publication = *pub;
    new_node->next = NULL;
    last_node->next = new_node;
    return new_node;
}


Node* stack_push_node(Top *st, Publication *pub, unsigned short k)
{
    Node *new_node = malloc(sizeof(Node));
    Node *current_node = stack_get_node(st, k);
    
}

// Теперь все то же самое с удалением элемента



int stack_pop_end(Top *sc, Publication *pub) // Удаляем элемент из конца
{
    if (sc->top_pointer == NULL) return 1;
    *pub = sc->top_pointer->publication;
    Node *PoppingNode = sc->top_pointer; // Вершинка, которую мы удалим
    sc->top_pointer = sc->top_pointer->next;
    free(PoppingNode);
    return 0;
}


// Замена пары элементов друг на друга
// код


//Очистка стека

// Проверяем пустоту стека
int stack_is_empty(Top *stack) {
    if (stack->top_pointer == NULL) return 1;
    return 0;
}

// Удаляем весь стек
void stack_free(Top *stack) {
    while (!stack_is_empty(stack)) {
        Publication pub;
        stack_pop(stack, &pub);
    }
}