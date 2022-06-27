/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:25:07 by seongwch          #+#    #+#             */
/*   Updated: 2022/06/27 11:26:29 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	make_a_b(t_display *display, int *a, int *b)
{
	int	number;

	*a = 0;
	*b = 0;
	number = display->enemy_x * display->count;
	number += display->count + display->x + display->y;
	number = number % 5;
	if (number == 0)
		*a = 1;
	else if (number == 1)
		*a = -1;
	else if (number == 2)
		*b = 1;
	else if (number == 3)
		*b = -1;
}

void	enemy_move(t_display *display)
{
	t_map	*map;
	char	*ptr;
	int		a;
	int		b;

	map = display -> map;
	make_a_b(display, &a, &b);
	ptr = ptr_map_char(map, display->enemy_x + a, display->enemy_y + b);
	if (*(ptr) == '0')
	{
		display->enemy_x += a;
		display->enemy_y += b;
	}
	*ptr_map_char(display->map, display->enemy_x, display->enemy_y) = 'X';
}
