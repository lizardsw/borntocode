/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@Student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:21:36 by seongwch          #+#    #+#             */
/*   Updated: 2022/05/19 22:21:37 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_pocket *pocket, int start, int end)
{
	int	range;

	range = end - start + 1;
	if (range == 3)
		three_sort(pocket, start, end);
	else if (range == 4)
		four_sort(pocket, start, end);
	else if (range == 5)
		five_sort(pocket, start, end);
}

void	b_two_sort(t_pocket *pocket, int start)
{
	if (pocket -> b -> start -> index == start)
		ft_swap(pocket, 2);
}

void	three_sort(t_pocket *pocket, int start, int end)
{
	if (pocket -> a -> start -> index == start)
	{
		if (pocket -> a -> start -> next -> index == end)
		{
			ft_swap(pocket, 1);
			ft_rotate(pocket, 1);
		}
	}
	else if (pocket -> a -> start -> index == start + 1)
	{
		if (pocket -> a -> start -> next -> index == start)
			ft_swap(pocket, 1);
		else
			ft_revrotate(pocket, 1);
	}
	else
	{
		if (pocket -> a -> start -> next -> index == start)
			ft_rotate(pocket, 1);
		else
		{
			ft_rotate(pocket, 1);
			ft_swap(pocket, 1);
		}
	}
}

void	four_sort(t_pocket *pocket, int start, int end)
{
	t_node	*ptr;
	int		pt;

	pt = 0;
	ptr = pocket -> a -> start;
	while (ptr -> index != start)
	{
		ptr = ptr -> next;
		pt++;
	}
	if (pt == 3)
		ft_revrotate(pocket, 1);
	else
		while (pt--)
			ft_rotate(pocket, 1);
	ft_push(pocket, 2);
	three_sort(pocket, start + 1, end);
	ft_push(pocket, 1);
}

void	five_sort(t_pocket *pocket, int start, int end)
{
	int		count;

	count = 2;
	while (count > 0)
	{
		if (pocket -> a -> start -> index <= start + 1)
		{
			ft_push(pocket, 2);
			count--;
		}
		else
			ft_rotate(pocket, 1);
	}
	three_sort(pocket, start + 2, end);
	b_two_sort(pocket, start);
	ft_push(pocket, 1);
	ft_push(pocket, 1);
}
