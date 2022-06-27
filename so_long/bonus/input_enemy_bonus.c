/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_enemy_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:27:15 by seongwch          #+#    #+#             */
/*   Updated: 2022/06/27 11:27:43 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	enemy_check(t_map *map, int land_size, int i, int j)
{
	if (land_size == 0)
	{
		*ptr_map_char(map, i, j) = 'X';
		return (1);
	}
	if (map->exit_locate[0] - i < 2 && map->exit_locate[1] - j < 2)
	{
		*ptr_map_char(map, i, j) = 'X';
		return (1);
	}
	return (-1);
}

void	enemy_locate(t_map *map, t_display *display, int land_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->x_size)
	{
		j = 0;
		while (j < map->y_size)
		{
			if (*ptr_map_char(map, i, j) == '0')
			{
				land_size--;
				if (enemy_check(map, land_size, i, j) == 1)
				{
					display->enemy_x = i;
					display->enemy_y = j;
					return ;
				}
			}
			j++;
		}
		i++;
	}
}

void	input_enemey(t_map *map, t_display *display)
{
	int	land_size;
	int	ptr[2];

	land_size = (map->x_size) * (map->y_size);
	land_size -= (map->item + map->rock + 2);
	if (land_size <= 0)
		return ;
	display->enemy_exist = 1;
	enemy_locate(map, display, land_size);
}
