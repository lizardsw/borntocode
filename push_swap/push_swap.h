#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "./prtf/ft_printf.h"
typedef struct s_node
{
    int number;
    struct s_node *prev;
    struct s_node *next;
}   t_node;

typedef struct s_deq
{
    t_node *start;
    t_node *end;
    int size;
} t_deq;



int check_number(char *);
char *total_str(char **argv, int argc);
int get_number(char **argv, int argc, t_deq *A);

t_deq *new_deq();
t_node *new_node();
void push_front(t_deq *deq, t_node *node);
void push_back(t_deq *deq, t_node *node);
t_node *pop_front(t_deq *deq);
t_node *pop_back(t_deq *deq);
void show_deq(t_deq *deq);

#endif 