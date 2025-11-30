#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "struct-record.h"

// Вершинка стека
typedef struct Node 
{
    Publication publication;
    Node *next;
} Node;

// Сам стек 
typedef struct Сontainer
{
    Node *node;
} Stack;

// Создаем стек (инициализация)
Stack stack_container_init(void) 
{
    Stack* stack;
    stack->node = NULL;
    return *stack;
}

// Получение размеров стека
int stack_size(Stack *stack) 
{
    int count = 0;
    Node *current = stack->node;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}


// Дальше будут добавления в начало, конец, и произвольное место


// Добавляем элемент в конец
void stack_push_end(Stack *st, Publication pub) 
{
    Node *new_node = malloc(sizeof(Node));
    new_node->publication = pub; // Присваиваем новую публикацию
    new_node->next = st->node; // Присваиваем указаетль на след. элемент
    st->node = new_node;
}


// Теперь все то же самое с удалением элемента


// Удаляем элемент из конца
int stack_pop_end(Stack *sc, Publication *pub) 
{
    if (sc->node == NULL) return 1;
    *pub = sc->node->publication;
    Node *PoppingNode = sc->node; // Вершинка, которую мы удалим
    sc->node = sc->node->next;
    free(PoppingNode);
    return 0;
}


// Замена пары элементов друг на друга
// код


//Очистка стека

// Проверяем пустоту стека
int stack_is_empty(Stack *stack) {
    if (stack->node == NULL) return 1;
    return 0;
}

// Удаляем весь стек
void stack_free(Stack *stack) {
    while (!stack_is_empty(stack)) {
        Publication pub;
        stack_pop(stack, &pub);
    }
}