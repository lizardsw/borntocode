/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblist_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:09:30 by seongwch          #+#    #+#             */
/*   Updated: 2022/06/27 19:18:18 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	free_map(t_map *map)
{
	t_node	*ptr;
	t_node	*temp;

	ptr = map -> start;
	while (ptr != NULL)
	{
		temp = ptr;
		ptr = ptr -> next;
		free(temp -> map_str);
		free(temp);
	}
	free(map);
}

t_node	*new_node(char *str)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		exit(1);
	new_node -> map_str = ft_strdup(str);
	if (new_node -> map_str == NULL)
		exit(1);
	new_node -> next = NULL;
	return (new_node);
}

t_map	*new_map(void)
{
	t_map	*new_map;

	new_map = (t_map *)malloc(sizeof(t_map));
	if (new_map == NULL)
		exit(1);
	new_map -> start = NULL;
	new_map -> end = NULL;
	new_map -> x_size = 0;
	new_map -> y_size = 0;
	new_map -> player = 0;
	new_map -> item = 0;
	new_map -> exit = 0;
	new_map -> trash = 0;
	new_map -> rock = 0;
	return (new_map);
}

char	*ptr_map_char(t_map *map, int x, int y)
{
	t_node	*node_ptr;
	int		i;

	i = 0;
	node_ptr = map -> start;
	while (i < y)
	{
		node_ptr = node_ptr -> next;
		i++;
	}
	return (&(node_ptr -> map_str[x]));
}

void	add_node(t_map *map, t_node *node)
{
	t_node	*ptr;

	map -> y_size++;
	if (map -> start == NULL)
	{
		map -> start = node;
		map -> end = node;
		return ;
	}
	ptr = map -> end;
	ptr -> next = node;
	map -> end = node;
}
