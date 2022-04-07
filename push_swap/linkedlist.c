#include "push_swap.h"

t_deq *new_deq()
{
    t_deq *new;
    
    new = (t_deq*)malloc(sizeof(t_deq));
    if(new == NULL)
        return (NULL);
    new -> start = NULL;
    new -> end = NULL;
    new -> size = 0;
    return (new);
}

t_node *new_node(int number)
{
    t_node *new;
    new = (t_node *)malloc(sizeof(t_node));
    if (new == NULL)
        return (NULL);
    new -> next = NULL;
    new -> prev = NULL;
    new -> number = number;
    return (new);
}

void push_front(t_deq *deq, t_node *node)
{
    if (deq -> size == 0)
    {
        deq -> start = node;
        deq -> end = node;
        deq -> size++;
        return ;
    }
    deq-> start -> prev = node;
    node -> next = deq -> start;
    deq -> start = node;
    deq -> size++;
}

void push_back(t_deq *deq, t_node *node)
{
    if (deq -> size == 0)
    {
        deq -> start = node;
        deq -> end = node;
        deq -> size++;
        return ;
    }
    deq -> end -> next = node;
    node -> prev = deq -> end;
    deq -> end = node;
    deq -> size++;
}

t_node *pop_front(t_deq *deq)
{
    t_node *temp;
    
    temp = deq -> start;
    deq -> start -> next -> prev = NULL;
    deq -> start = deq -> start -> next;
    temp -> next = NULL;
    return (temp);
}

t_node *pop_back(t_deq *deq)
{
    t_node *temp;

    temp = deq -> end;
    deq -> end -> prev -> next = NULL;
    deq -> end = deq -> end -> prev;
    temp -> prev = NULL;
    return (temp);
}

void show_deq(t_deq *deq)
{
    t_node *ptr;

    ptr = deq -> start;
    while (ptr != NULL)
    {
        ft_printf("%d -> ", ptr->number);
        ptr = ptr -> next;
    }
    ft_printf("NULL\n");
}



