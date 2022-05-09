#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "./prtf/ft_printf.h"
typedef struct s_node
{
    int number;
    int index;
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

void ft_sa(t_deq *A);
void ft_sb(t_deq *B);
void ft_ss(t_deq *A, t_deq *B);

void ft_pa(t_deq *A, t_deq *B);
void ft_pb(t_deq *B, t_deq *A);

void ft_ra(t_deq *A);
void ft_rb(t_deq *B);
void ft_rr(t_deq *A, t_deq *B);

void ft_rra(t_deq *A);
void ft_rrb(t_deq *B);
void ft_rrr(t_deq *A, t_deq *B);

void sort_index_deq(t_deq *deq);
void node_index_swap(t_node *A, t_node *B);

void total_function(t_deq *A, t_deq *B);
void push_node(t_deq *A, t_deq *B, int number);
void swap_node(t_deq *B, int pivot1);
void setting_pivot(t_deq *deq, int *pivot1, int *pivot2);
#endif 