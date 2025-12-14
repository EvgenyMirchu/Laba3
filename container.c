#include "container.h"


// Создаем стек, возвращаем верхушку (инициализация)
Top* stack_init(void)
{
    Top *stack;
    stack->top_pointer = NULL;
    return stack->top_pointer;
}

// Получение размера стека
short stack_get_size(Top *stack) 
{
    short count = 0;
    Node *current = stack->top_pointer;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Получение указателя на произвольный элемент по индексу
Node* stack_get_node(Top *stack, short k)
{
    if (stack_get_size(stack) - 1 < k) return NULL;

    Node *curr_elem = stack->top_pointer;

    for (short i = 0; i < k; ++i)
    { 
        curr_elem = curr_elem->next;
    }
    return curr_elem;
}


Node* stack_get_highest(Top *stack) // Получение указателя на последний (самый верхний) элемент
{
    return stack->top_pointer;
}


Node* stack_get_lowest(Top *stack) // Получение указателя на первый (самый нижний) элемент
{
    stack_get_node(stack, stack_get_size(stack)-1);
}

Node* stack_get_next(Top *stack, Node *node) // Получение следующего элемента по указателю
{
    if (stack_get_size(stack) < 2) return NULL;
    return node->next; 
}

Node* stack_get_previous(Top *stack, Node *node) // Получение предыдущего элемента по указателю
{   
    if (stack_get_size(stack) < 2 || stack->top_pointer == node) return NULL;

    Node *prev_node = stack->top_pointer;
    while (1)
    {
        if (prev_node->next == node) return prev_node;
        else stack_get_next(stack, prev_node);
    }
}



// Дальше будут добавления в начало, конец, и произвольное место



Top* stack_push_end(Top *st, Publication *pub)   // Добавляем элемент в конец (на верхушку)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->publication = *pub; // Присваиваем новую публикацию
    new_node->next = st->top_pointer; // Присваиваем указатель на след. элемент
    st->top_pointer = new_node;
    return st;
}


Top* stack_push_start(Top *st, Publication *pub)     // Добавляем элемент в начало (на дно)
{
    Node *new_node = malloc(sizeof(Node));
    Node *last_node = stack_get_lowest(st);
    new_node->publication = *pub;
    new_node->next = NULL;
    last_node->next = new_node;
    return st;
}


Top* stack_push_node(Top *st, Publication *pub, short k)        // Добавляем элемент в произвольное место по индексу
{
    Node *current_node = stack_get_node(st, k);
    if (current_node == NULL) return NULL;
    if (k == 0) return stack_push_end(st, pub);
    if (k == stack_get_size(st)-1) return stack_push_end(st, pub);

    Node *new_node = malloc(sizeof(Node));
    Node *before_curr_node = stack_get_node(st, k-1);

    before_curr_node->next = new_node;
    new_node->publication = *pub;
    new_node->next = current_node;
    return st;
}


// Теперь все то же самое с удалением элемента


Top* stack_pop_end(Top *st) // Удаляем элемент из конца (cамый верхний элемент). Возвращает указатель на top
{
    if (st->top_pointer == NULL) return NULL;
    Node* popping_node = st->top_pointer;
    st->top_pointer = popping_node->next;
    free(popping_node);

    return st;
}


Top* stack_pop_start(Top *st) // Удаляем элемент из начала (cамый нижний элемент). Возвращает указатель на top
{
    if (st->top_pointer == NULL) return NULL;
    Node* popping_node = stack_get_lowest(st);
    
    if (stack_get_size(st) == 1)
    {   
        st->top_pointer = NULL;
        free(popping_node);
        return NULL;
    }
    Node* prev_node = stack_get_previous(st, popping_node);
    prev_node->next = NULL;
    free(popping_node);
    return st;
}


Top* stack_pop_node(Top *st, Node *pop_node) // Удаляем элемент из начала (cамый нижний элемент). Возвращает указатель на top
{
    if (st->top_pointer == NULL) return NULL;
    if (st->top_pointer == pop_node) return stack_pop_end(st);
    if (pop_node->next == NULL) return stack_pop_start(st);

    Node* prev_node = stack_get_previous(st, pop_node);
    prev_node->next = pop_node->next;
    free(pop_node);
    return st;
}


// Замена пары элементов друг на друга
Top* stack_swap_nodes(Top *st, Node *node_1, Node *node_2)
{
    if (node_1 == node_2) return st;
    Node *prev_node_1 = stack_get_previous(st, node_1);
    Node *prev_node_2 = stack_get_previous(st, node_2);
    if (prev_node_1 == NULL || prev_node_2 == NULL) return NULL;
    Node *next_node_1 = stack_get_next(st, node_1);
    Node *next_node_2 = stack_get_next(st, node_2);
    
    prev_node_1->next = node_2;
    node_2->next = next_node_1;
    prev_node_2->next = node_1;
    node_1->next = next_node_2;
    
    return st;
}

//Очистка стека

// Проверяем пустоту стека
short stack_is_empty(Top *stack) 
{
    if (stack->top_pointer == NULL) return 1;
    return 0;
}

// Удаляем весь стек
void stack_free(Top *stack) 
{
    while (!stack_is_empty(stack)) 
    {
        Publication pub;
        stack_pop(stack, &pub);
    }
}