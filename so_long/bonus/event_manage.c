/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:09:22 by seongwch          #+#    #+#             */
/*   Updated: 2022/06/25 00:10:59 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	show_rmap(t_display *display, t_map *map)
{
	t_node	*ptr;

	ptr = map -> start;
	while(ptr != NULL)
	{ 
		printf("%s\n", ptr -> map_str);
		ptr = ptr -> next;
	}
	printf("emeny x: %d y: %d\n",display->enemy_x,display->enemy_y);
}

int	key_hook(int keycode, t_display *param)
{
	*ptr_map_char(param->map, param->x, param->y) = '0';
	*ptr_map_char(param->map, param->enemy_x, param->enemy_y) = '0';
	enemy_move(param);
	if (keycode == KEY_W)
		up_game(param);
	else if (keycode == KEY_S)
		down_game(param);
	else if (keycode == KEY_A)
		left_game(param);
	else if (keycode == KEY_D)
		right_game(param);
	else if (keycode == KEY_ESC)
		exit(0);
	printf("x: %d y: %d\n", param -> x, param -> y);
	display_map(param -> map, param);
	return (0);
}

void	event_manage(void *window_ptr, t_display *display)
{
	mlx_key_hook(window_ptr, &key_hook, display);
}
