/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@Student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:44:26 by seongwch          #+#    #+#             */
/*   Updated: 2022/05/20 19:44:28 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./prtf/ft_printf.h"

typedef struct s_node
{
	int				number;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_deq
{
	t_node	*start;
	t_node	*end;
	int		size;
}	t_deq;

typedef struct s_pocket
{
	t_deq	*a;
	t_deq	*b;
	t_deq	*rule;
}	t_pocket;

int			check_number(char *str);
int			check_num_repeat(t_deq *A);
char		*total_str(char **argv, int argc);
int			get_number(t_deq *A, char *str);
void		free_getnumber(char **new_str);
t_pocket	*new_pocket(t_deq *A, t_deq *B, t_deq *rule);
t_deq		*new_deq(void);
t_node		*new_node(int number);
void		delete_node(t_deq *deq, t_node *pt);
void		push_front(t_deq *deq, t_node *node);
void		push_back(t_deq *deq, t_node *node);
t_node		*pop_front(t_deq *deq);
t_node		*pop_back(t_deq *deq);
void		rule_show_deq(t_deq *deq);
void		rule_push_back(t_deq *deq, t_node *ptr, int i, int num);
void		num_to_rule(int num);
void		ft_sa(t_deq *A);
void		ft_pa(t_deq *A, t_deq *B);
void		ft_ra(t_deq *A);
void		ft_rra(t_deq *A);
void		ft_swap(t_pocket *pocket, int num);
void		ft_push(t_pocket *pocket, int num);
void		ft_rotate(t_pocket *pocket, int num);
void		ft_revrotate(t_pocket *pocket, int num);
void		sort_index_deq(t_deq *deq);
void		quick(int *arr, int start, int end);
void		quick_swap(int *arr, int x, int y);
void		indexing_node(t_deq *deq, int *arr);
void		atob(t_pocket *pocket, int start, int end);
void		btoa(t_pocket *pocket, int start, int end);
void		atob_utils(t_pocket *pocket, int *pivot, int *i, int *j);
void		btoa_utils(t_pocket *pocket, int *pivot, int *i, int *j);
void		setting_pivot(int start, int end, int *pivot);
void		atob_small_sort(t_pocket *pocket, int start, int end);
void		btoa_small_sort(t_pocket *pocket, int start, int end);
void		small_sort(t_pocket *pocket, int start, int end);
void		b_two_sort(t_pocket *pocket, int start);
void		three_sort(t_pocket *pocket, int start, int end);
void		four_sort(t_pocket *pocket, int start, int end);
void		five_sort(t_pocket *pocket, int start, int end);

#endif 
