/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@Student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:19:33 by seongwch          #+#    #+#             */
/*   Updated: 2022/05/19 22:20:30 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	atob_small_sort(t_pocket *pocket, int start, int end)
{
	int	range;

	range = end - start + 1;
	if (range == 2)
	{	
		if (pocket -> a -> start -> index == end)
			ft_swap(pocket, 1);
	}
}

void	btoa_small_sort(t_pocket *pocket, int start, int end)
{
	int	range;

	range = end - start + 1;
	if (range == 1)
		ft_push(pocket, 1);
	else if (range == 2)
	{
		if (pocket -> b -> start -> index == start)
			ft_swap(pocket, 2);
		ft_push(pocket, 1);
		ft_push(pocket, 1);
	}
}
