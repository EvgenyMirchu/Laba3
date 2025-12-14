#include "gnome_sorting.h"


void gnome_sort(Top *stack, int asc)
{
    short index = 0, rem_index = 0;
    short len = stack_get_size(stack);
    
    if (asc == 1)
    {
        while (index < len-1)
        {
            if (compare(stack_get_node(stack, index), stack_get_node(stack, index+1)) <= 0)
            {
                index ++;
                rem_index ++;
            }
            else
            {
                stack_swap_nodes(stack, stack_get_node(stack, index), stack_get_node(stack, index+1));
                index -= 1;
                if (index < 0) 
                {
                    index = rem_index;
                    rem_index ++;
                }
            }
        }
    }
    
    else
    {
        while (index < len-1)
        {
            if (compare(stack_get_node(stack, index), stack_get_node(stack, index+1)) >= 0)
            {
                index ++;
                rem_index ++;
            }
            else
            {
                stack_swap_nodes(stack, stack_get_node(stack, index), stack_get_node(stack, index+1));
                index -= 1;
                if (index < 0) 
                {
                    index = rem_index;
                    rem_index ++;
                }
            }
        }
    }
}