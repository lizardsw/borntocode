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

typedef struct s_pocket
{
    t_deq *A;
    t_deq *B;
    t_deq *rule;
}   t_pocket;

/////get_number.c
int check_number(char *);
char *total_str(char **argv, int argc);
int get_number(char **argv, int argc, t_deq *A);
///////

/////linkedlist.c
t_pocket *new_pocket(t_deq *A, t_deq *B, t_deq *rule);
t_deq *new_deq();
t_node *new_node();
void push_front(t_deq *deq, t_node *node);
void push_back(t_deq *deq, t_node *node);
t_node *pop_front(t_deq *deq);
t_node *pop_back(t_deq *deq);
void show_deq(t_deq *deq);
void delete_node(t_deq *deq, t_node *pt);

////////

////push_rules.c
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
////////

//// push_rules_utils.c
void ft_swap(t_pocket *pocket, int num);
void ft_push(t_pocket *pocket, int num);
void ft_rotate(t_pocket *pocket, int num);
void ft_revrotate(t_pocket *pocket, int num);
void rule_push_back(t_deq *deq, t_node *ptr, int i, int num);
/////

////sort_list.c
void sort_index_deq(t_deq *deq);
void quick(int *arr, int start , int end);
void indexing_node(t_deq *deq, int *arr);
////////

///pivot.c
void AtoB(t_pocket *pocket, int start, int end);
void BtoA(t_pocket *pocket, int start, int end);
int setting_pivot(int start, int end, int *pivot1, int *pivot2);
//////

void AtoB_small_sort(t_pocket *pocket, int start, int end);
void BtoA_small_sort(t_pocket *pocket, int start, int end);
#endif 