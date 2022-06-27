/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:26:07 by seongwch          #+#    #+#             */
/*   Updated: 2022/06/27 19:53:05 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	up_game(t_display *display)
{
	t_map	*map;
	char	*ptr;

	map = display -> map;
	ptr = ptr_map_char(map, display -> x, display -> y - 1);
	if (*(ptr) == '0')
	{
		display->y--;
		printf("count: %d\n", ++(display-> count));
	}
	else if (*(ptr) == 'C')
	{
		printf("count: %d\n", ++(display-> count));
		display -> map -> item--;
		display->y--;
	}
	else if (*(ptr) == 'E' && display->map->item == 0)
	{
		printf("SUCCESS!\n");
		exit(0);
	}
}

void	down_game(t_display *display)
{
	t_map	*map;
	char	*ptr;

	map = display -> map;
	ptr = ptr_map_char(map, display -> x, display -> y + 1);
	if (*(ptr) == '0')
	{
		display->y++;
		printf("count: %d\n", ++(display-> count));
	}
	else if (*(ptr) == 'C')
	{
		printf("count: %d\n", ++(display-> count));
		display -> map -> item--;
		display->y++;
	}
	else if (*(ptr) == 'E' && display->map->item == 0)
	{	
		printf("SUCCESS!\n");
		exit(0);
	}
}

void	right_game(t_display *display)
{
	t_map	*map;
	char	*ptr;

	map = display -> map;
	ptr = ptr_map_char(map, display -> x + 1, display -> y);
	if (*(ptr) == '0')
	{
		printf("count: %d\n", ++(display-> count));
		display->x++;
	}
	else if (*(ptr) == 'C')
	{
		printf("count: %d\n", ++(display-> count));
		display -> map -> item--;
		display->x++;
	}
	else if (*(ptr) == 'E' && display->map->item == 0)
	{	
		printf("SUCCESS!\n");
		exit(0);
	}
}

void	left_game(t_display *display)
{
	t_map	*map;
	char	*ptr;

	map = display -> map;
	ptr = ptr_map_char(map, display -> x - 1, display -> y);
	if (*(ptr) == '0')
	{
		printf("count: %d\n", ++(display-> count));
		display->x--;
	}
	else if (*(ptr) == 'C')
	{
		printf("count: %d\n", ++(display-> count));
		display -> map -> item--;
		display->x--;
	}
	else if (*(ptr) == 'E' && display->map->item == 0)
	{
		printf("SUCCESS!\n");
		exit(0);
	}
}
