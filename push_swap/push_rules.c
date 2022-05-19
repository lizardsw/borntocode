/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@Student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:19:39 by seongwch          #+#    #+#             */
/*   Updated: 2022/05/19 22:20:40 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_deq *A)
{
	t_node	*ptr;
	t_node	*temp;

	if (A -> size <= 2)
	{
		if (A -> size == 2)
			push_back(A, pop_front(A));
		return ;
	}
	ptr = A -> start -> next -> next;
	temp = A -> start -> next;
	ptr -> prev = A -> start;
	A -> start -> next = ptr;
	push_front(A, temp);
	A -> size--;
}

void	ft_pa(t_deq *A, t_deq *B)
{
	t_node	*temp;

	temp = pop_front(B);
	if (temp != NULL)
		push_front(A, temp);
}

void	ft_rra(t_deq *A)
{
	if (A -> size > 1)
		push_front(A, pop_back(A));
}

void	ft_ra(t_deq *A)
{
	if (A -> size > 1)
		push_back(A, pop_front(A));
}
