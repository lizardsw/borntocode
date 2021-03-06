/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@Student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:19:55 by seongwch          #+#    #+#             */
/*   Updated: 2022/05/19 22:19:59 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (-1);
		i++;
	}
	return (1);
}

int	sort_index_deq(t_deq *deq)
{
	t_node	*pt;
	int		*sort_array;
	int		i;

	i = 0;
	pt = deq -> start;
	sort_array = (int *)malloc(deq -> size * sizeof(int));
	if (sort_array == NULL)
		exit(0);
	while (i < deq -> size)
	{
		sort_array[i] = pt -> number;
		pt = pt -> next;
		i++;
	}
	if (check_sorted(sort_array, deq -> size) == 1)
	{
		free(sort_array);
		return (-1);
	}
	quick(sort_array, 0, deq -> size - 1);
	indexing_node(deq, sort_array);
	free(sort_array);
	return (1);
}

void	quick_swap(int *arr, int x, int y)
{
	int	temp;

	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void	quick(int *arr, int start, int end)
{
	int		pivot;
	int		i;
	int		j;

	pivot = start;
	i = pivot + 1;
	j = end;
	if (start >= end)
		return ;
	while (i <= j)
	{
		while (arr[pivot] > arr[i] && i < end)
			i++;
		while (arr[pivot] < arr[j] && j > start)
			j--;
		if (i >= j)
			break ;
		quick_swap(arr, i, j);
	}
	quick_swap(arr, pivot, j);
	quick(arr, start, j - 1);
	quick(arr, j + 1, end);
}

void	indexing_node(t_deq *deq, int *arr)
{
	t_node	*pt;
	int		i;

	pt = deq -> start;
	i = 0;
	while (pt != NULL)
	{
		i = 0;
		while (i < deq -> size)
		{
			if (pt -> number == arr[i])
			{
				pt -> index = i + 1;
			}
			i++;
		}
		pt = pt -> next;
	}
}
