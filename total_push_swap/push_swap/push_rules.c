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

void	ft_sa(t_deq *a)
{
	t_node	*ptr;
	t_node	*temp;

	if (a -> size <= 2)
	{
		if (a -> size == 2)
			push_back(a, pop_front(a));
		return ;
	}
	ptr = a -> start -> next -> next;
	temp = a -> start -> next;
	ptr -> prev = a -> start;
	a -> start -> next = ptr;
	push_front(a, temp);
	a -> size--;
}

void	ft_pa(t_deq *a, t_deq *b)
{
	t_node	*temp;

	temp = pop_front(b);
	if (temp != NULL)
		push_front(a, temp);
}

void	ft_rra(t_deq *a)
{
	if (a -> size > 1)
		push_front(a, pop_back(a));
}

void	ft_ra(t_deq *a)
{
	if (a -> size > 1)
		push_back(a, pop_front(a));
}
