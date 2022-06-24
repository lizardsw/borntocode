/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:09:25 by seongwch          #+#    #+#             */
/*   Updated: 2022/06/24 21:27:47 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_strtrim(char *str)
{
	if (str == NULL)
		return ;
	if (str[ft_strlen(str) - 1] == '\n')
		str[ft_strlen(str) - 1] = '\0';
}

void	set_map_member(t_map *map, char c, int x, int y)
{
	if (c == 'P')
	{
		map -> locate[0] = x;
		map -> locate[1] = y;
		map -> player++;
	}
	else if (c == 'C')
		map -> item++;
	else if (c == 'E')
	{
		map -> exit_locate[0] = x;
		map -> exit_locate[1] = y;
		map -> exit++;
	}
	else if (c != '1' && c != '0')
		map -> trash++;
	else if (c == '1')
		map -> rock++;
}

void	set_map_info(t_map *map)
{
	t_node	*node_ptr;
	int		i;
	int		j;

	node_ptr = map -> start;
	if (node_ptr == NULL || node_ptr -> map_str == NULL)
		return ;
	map -> x_size = ft_strlen(map -> start -> map_str);
	j = 0;
	while (node_ptr != NULL)
	{
		i = 0;
		while (node_ptr -> map_str[i] != '\0')
		{
			set_map_member (map, node_ptr->map_str[i], i, j);
			i++;
		}
		node_ptr = node_ptr -> next;
		j++;
	}		
}

t_map	*make_map(char *map_dir)
{
	t_map	*map;
	char	*one_line;
	int		fd;

	fd = open(map_dir, O_RDONLY);
	if (fd < 0)
	{
		printf("error!\nwrong_dir!\n");
		exit(1);
	}
	map = new_map();
	one_line = get_next_line(fd);
	ft_strtrim(one_line);
	while (one_line != NULL)
	{
		add_node(map, new_node(one_line));
		free(one_line);
		one_line = get_next_line(fd);
		ft_strtrim(one_line);
	}
	set_map_info(map);
	return (map);
}
