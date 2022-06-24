/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:17:21 by seongwch          #+#    #+#             */
/*   Updated: 2022/06/24 20:51:10 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_block(void *mlx, void *win, void *image, int *ptr)
{
	mlx_put_image_to_window(mlx, win, image, ptr[0] * 32, ptr[1] * 32);
}

void	display_land(t_display *display, int map_x, int map_y)
{
	int	ptr[2];

	ptr[1] = 0;
	while (ptr[1] < map_y)
	{
		ptr[0] = 0;
		while (ptr[0] < map_x)
		{
			display_block(display->mlx, display->win, display->land, ptr);
			ptr[0]++;
		}
		ptr[1]++;
	}
}

void	display_struct(t_display *display, t_map *map)
{
	int	ptr[2];
	int	temp;

	ptr[1] = 0;
	while (ptr[1] < map -> y_size)
	{
		ptr[0] = 0;
		while (ptr[0] < map -> x_size)
		{
			temp = *(ptr_map_char(map, ptr[0], ptr[1]));
			if (temp == '1')
				display_block(display->mlx, display->win, display->rock, ptr);
			else if (temp == 'C')
				display_block(display->mlx, display->win, display->food, ptr);
			else if (temp == 'E')
				display_block(display->mlx, display->win, display->door, ptr);
			ptr[0]++;
		}
		ptr[1]++;
	}
}

void	display_frog(t_display *display)
{
	int	ptr[2];

	ptr[0] = display -> x;
	ptr[1] = display -> y;
	display_block(display->mlx, display->win, display->frog, ptr);
}
