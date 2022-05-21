/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rules_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@Student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:21:26 by seongwch          #+#    #+#             */
/*   Updated: 2022/05/19 22:21:27 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_pocket *pocket, int num)
{
	t_deq	*ptr;

	ptr = pocket -> rule;
	if (num == 1)
		ft_sa(pocket -> a);
	else if (num == 2)
		ft_sa(pocket -> b);
	rule_push_back(ptr, ptr -> end, ptr -> size, num);
}

void	ft_push(t_pocket *pocket, int num)
{
	if (num == 1)
		ft_pa(pocket -> a, pocket -> b);
	else
		ft_pa(pocket -> b, pocket -> a);
	push_back(pocket -> rule, new_node(num + 10));
}

void	ft_rotate(t_pocket *pocket, int num)
{
	t_deq	*ptr;

	ptr = pocket -> rule;
	if (num == 1)
		ft_ra(pocket -> a);
	else if (num == 2)
		ft_ra(pocket -> b);
	rule_push_back(ptr, ptr -> end, ptr -> size, num + 20);
}

void	ft_revrotate(t_pocket *pocket, int num)
{
	t_deq	*ptr;

	ptr = pocket -> rule;
	if (num == 1)
		ft_rra(pocket -> a);
	else if (num == 2)
		ft_rra(pocket -> b);
	rule_push_back(ptr, ptr -> end, ptr -> size, num + 30);
}
