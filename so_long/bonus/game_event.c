/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:26:07 by seongwch          #+#    #+#             */
/*   Updated: 2022/06/24 23:45:42 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up_game(t_display *display)
{
	t_map	*map;
	char	*ptr;

	map = display -> map;
	ptr = ptr_map_char(map, display -> x, display -> y - 1);
	display -> count++;
	if (*(ptr) == '0')
		display->y--;
	else if (*(ptr) == 'C')
	{
		display -> map -> item--;
		display->y--;
	}
	else if (*(ptr) == 'E' && display->map->item == 0)
		exit(0);
	else if (*(ptr) == 'X')
		exit(0);
}

void	down_game(t_display *display)
{
	t_map	*map;
	char	*ptr;

	map = display -> map;
	ptr = ptr_map_char(map, display -> x, display -> y + 1);
	display -> count++;
	if (*(ptr) == '0')
		display->y++;
	else if (*(ptr) == 'C')
	{
		display -> map -> item--;
		display->y++;
	}
	else if (*(ptr) == 'E' && display->map->item == 0)
		exit(0);
	else if (*(ptr) == 'X')
		exit(0);
}

void	right_game(t_display *display)
{
	t_map	*map;
	char	*ptr;

	map = display -> map;
	ptr = ptr_map_char(map, display -> x + 1, display -> y);
	display -> count++;
	if (*(ptr) == '0')
		display->x++;
	else if (*(ptr) == 'C')
	{
		display -> map -> item--;
		display->x++;
	}
	else if (*(ptr) == 'E' && display->map->item == 0)
		exit(0);
	else if (*(ptr) == 'X')
		exit(0);
}

void	left_game(t_display *display)
{
	t_map	*map;
	char	*ptr;

	map = display -> map;
	ptr = ptr_map_char(map, display -> x - 1, display -> y);
	display -> count++;
	if (*(ptr) == '0')
		display->x--;
	else if (*(ptr) == 'C')
	{
		display -> map -> item--;
		display->x--;
	}
	else if (*(ptr) == 'E' && display->map->item == 0)
		exit(0);
	else if (*(ptr) == 'X')
		exit(0);
}
