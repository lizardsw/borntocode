/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@Student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:21:14 by seongwch          #+#    #+#             */
/*   Updated: 2022/05/19 22:21:15 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	atob_utils(t_pocket *pocket, int *pivot, int *i, int *j)
{
	while (pivot[2] >= 1)
	{
		if (pocket -> A -> start -> index > pivot[1])
		{
			ft_rotate(pocket, 1);
			(*j)++;
		}
		else
		{
			if (pocket -> A -> start -> index <= pivot[0])
				ft_push(pocket, 2);
			else
			{
				ft_push(pocket, 2);
				ft_rotate(pocket, 2);
				(*i)++;
			}
		}
		pivot[2]--;
	}
}

void	atob(t_pocket *pocket, int start, int end)
{
	int	pivot[3];
	int	i;
	int	j;

	i = 0;
	j = 0;
	setting_pivot(start, end, pivot);
	if (pivot[2] <= 2)
	{
		atob_small_sort(pocket, start, end);
		return ;
	}
	if (pivot[2] == pocket -> A -> size && pivot[2] <= 5)
	{
		small_sort(pocket, start, end);
		return ;
	}
	atob_utils(pocket, pivot, &i, &j);
	while (i-- != 0)
		ft_revrotate(pocket, 2);
	while (j-- != 0)
		ft_revrotate(pocket, 1);
	atob(pocket, pivot[1] + 1, end);
	btoa(pocket, pivot[0] + 1, pivot[1]);
	btoa(pocket, start, pivot[0]);
}

void	btoa_utils(t_pocket *pocket, int *pivot, int *i, int *j)
{
	while (pivot[2] >= 1)
	{
		if (pocket -> B -> start -> index <= pivot[0])
		{
			ft_rotate(pocket, 2);
			(*j)++;
		}
		else
		{
			if (pocket -> B -> start -> index > pivot[1])
				ft_push(pocket, 1);
			else
			{
				ft_push(pocket, 1);
				ft_rotate(pocket, 1);
				(*i)++;
			}
		}
		pivot[2]--;
	}
}

void	btoa(t_pocket *pocket, int start, int end)
{
	int	pivot[3];
	int	i;
	int	j;

	i = 0;
	j = 0;
	setting_pivot(start, end, pivot);
	if (pivot[2] <= 2)
	{
		btoa_small_sort(pocket, start, end);
		return ;
	}
	btoa_utils(pocket, pivot, &i, &j);
	atob(pocket, pivot[1] + 1, end);
	while (i-- != 0)
		ft_revrotate(pocket, 1);
	atob(pocket, pivot[0] + 1, pivot[1]);
	while (j-- != 0)
		ft_revrotate(pocket, 2);
	btoa(pocket, start, pivot[0]);
}

void	setting_pivot(int start, int end, int *pivot)
{
	int	size;

	size = end - start;
	if (size + 1 == 3)
	{
		pivot[0] = start;
		pivot[1] = end - 1;
		pivot[2] = size + 1;
		return ;
	}
	pivot[0] = start + size / 3;
	pivot[1] = start + (size / 3) * 2;
	pivot[2] = size + 1;
	return ;
}
