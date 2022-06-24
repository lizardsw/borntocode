/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:09:16 by seongwch          #+#    #+#             */
/*   Updated: 2022/06/24 20:21:07 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall_top_bottom(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '1')
			return (-1);
		i++;
	}
	return (1);
}

int	check_wall_middle(char	*str)
{
	if (str[0] != '1')
		return (-1);
	else if (str[ft_strlen(str) - 1] != '1')
		return (-1);
	return (1);
}

int	check_wall(t_map *map)
{
	t_node	*node_ptr;
	int		i;
	int		result;

	i = 1;
	node_ptr = map -> start;
	while (node_ptr != NULL)
	{
		if (i == 1 || i == map -> y_size)
			result = check_wall_top_bottom(node_ptr -> map_str);
		else
			result = check_wall_middle(node_ptr -> map_str);
		if (result == -1)
			return (-1);
		node_ptr = node_ptr -> next;
		i++;
	}
	return (1);
}

int	check_num(t_map *map)
{
	t_node	*node_ptr;

	node_ptr = map -> start;
	if (map -> player != 1 || map -> exit != 1)
		return (-1);
	if (map -> trash > 0)
		return (-1);
	while (node_ptr != NULL)
	{
		if (node_ptr -> map_str == NULL)
			return (-1);
		if (ft_strlen(node_ptr -> map_str) != map -> x_size)
			return (-1);
		node_ptr = node_ptr -> next;
	}
	return (1);
}

int	check_map(t_map *map)
{
	if (check_num(map) == -1)
		return (-1);
	else if (check_wall(map) == -1)
		return (-1);
	return (1);
}
