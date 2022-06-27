/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:08:56 by seongwch          #+#    #+#             */
/*   Updated: 2022/06/27 11:23:33 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_display	*init_image(t_map *map, int x, int y)
{
	t_display	*scr;
	int			ix;
	int			iy;

	scr = (t_display *)malloc(sizeof(t_display));
	if (scr == NULL)
		return (NULL);
	scr->mlx = mlx_init();
	scr->win = mlx_new_window(scr->mlx, 32 * x, 32 * y, "so_long");
	scr->frog = mlx_xpm_file_to_image(scr->mlx, "./xpm/frog1.xpm", &ix, &iy);
	scr->land = mlx_xpm_file_to_image(scr->mlx, "./xpm/land.xpm", &ix, &iy);
	scr->food = mlx_xpm_file_to_image(scr->mlx, "./xpm/shrimp.xpm", &ix, &iy);
	scr->rock = mlx_xpm_file_to_image(scr->mlx, "./xpm/rock.xpm", &ix, &iy);
	scr->door = mlx_xpm_file_to_image(scr->mlx, "./xpm/exit.xpm", &ix, &iy);
	scr->x = map->locate[0];
	scr->y = map->locate[1];
	scr->map = map;
	scr->count = 0;
	return (scr);
}

void	display_map(t_map *map, t_display *display)
{
	display_land(display, map -> x_size, map -> y_size);
	display_struct(display, map);
	display_frog(display);
}
