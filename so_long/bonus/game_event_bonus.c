/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_event_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:26:07 by seongwch          #+#    #+#             */
/*   Updated: 2022/06/27 20:40:01 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	finished_game(int game)
{
	if (game == 1)
		printf("SUCCES!\n");
	else if (game == 0)
		printf("FAIL!\n");
	exit(0);
}

void	up_game(t_display *display)
{
	t_map	*map;
	char	*ptr;

	map = display -> map;
	ptr = ptr_map_char(map, display -> x, display -> y - 1);
	if (*(ptr) == '0')
	{
		printf("count: %d\n", ++(display-> count));
		display->y--;
	}
	else if (*(ptr) == 'C')
	{
		printf("count: %d\n", ++(display-> count));
		display -> map -> item--;
		display->y--;
	}
	else if (*(ptr) == 'E' && display->map->item == 0)
		finished_game(1);
	else if (*(ptr) == 'X')
		finished_game(0);
}

void	down_game(t_display *display)
{
	t_map	*map;
	char	*ptr;

	map = display -> map;
	ptr = ptr_map_char(map, display -> x, display -> y + 1);
	if (*(ptr) == '0')
	{
		printf("count: %d\n", ++(display-> count));
		display->y++;
	}
	else if (*(ptr) == 'C')
	{
		printf("count: %d\n", ++(display-> count));
		display -> map -> item--;
		display->y++;
	}
	else if (*(ptr) == 'E' && display->map->item == 0)
		finished_game(1);
	else if (*(ptr) == 'X')
		finished_game(0);
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
		finished_game(1);
	else if (*(ptr) == 'X')
		finished_game(0);
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
		finished_game(1);
	else if (*(ptr) == 'X')
		finished_game(0);
}
