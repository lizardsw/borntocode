/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:09:22 by seongwch          #+#    #+#             */
/*   Updated: 2022/06/27 20:31:27 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	x_button(t_display *display)
{
	mlx_destroy_window(display->mlx, display->win);
	printf("x_button!\n");
	exit(0);
}

int	key_hook(int keycode, t_display *param)
{
	*ptr_map_char(param -> map, param -> x, param -> y) = '0';
	if (keycode == KEY_W)
		up_game(param);
	else if (keycode == KEY_S)
		down_game(param);
	else if (keycode == KEY_A)
		left_game(param);
	else if (keycode == KEY_D)
		right_game(param);
	else if (keycode == KEY_ESC)
	{
		printf("ESC_button!\n");
		exit(0);
	}
	display_map(param -> map, param);
	return (0);
}

void	event_manage(void *window_ptr, t_display *display)
{
	mlx_key_hook(window_ptr, &key_hook, display);
	mlx_hook(window_ptr, X_EVENT, 0, &x_button, display);
}
