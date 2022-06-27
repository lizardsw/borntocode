/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:08:56 by seongwch          #+#    #+#             */
/*   Updated: 2022/06/25 13:44:33 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_display	*init_image(t_map *map, int x, int y)
{
	t_display	*scr;
	int			imgx;
	int			imgy;

	scr = (t_display *)malloc(sizeof(t_display));
	if (scr == NULL)
		return (NULL);
	scr->mlx = mlx_init();
	scr->win = mlx_new_window(scr->mlx, 32 * x, 32 * y, "so_long");
	scr->frog = mlx_xpm_file_to_image(scr->mlx, "xpm/frog1.xpm", &imgx, &imgy);
	scr->frog1 = mlx_xpm_file_to_image(scr->mlx, "xpm/frog2.xpm", &imgx, &imgy);
	scr->frog2 = mlx_xpm_file_to_image(scr->mlx, "xpm/frog3.xpm", &imgx, &imgy);
	scr->land = mlx_xpm_file_to_image(scr->mlx, "xpm/land.xpm", &imgx, &imgy);
	scr->food = mlx_xpm_file_to_image(scr->mlx, "xpm/shrimp.xpm", &imgx, &imgy);
	scr->rock = mlx_xpm_file_to_image(scr->mlx, "xpm/rock.xpm", &imgx, &imgy);
	scr->door = mlx_xpm_file_to_image(scr->mlx, "xpm/exit.xpm", &imgx, &imgy);
	scr->enemy = mlx_xpm_file_to_image(scr->mlx, "xpm/enemy.xpm", &imgx, &imgy);
	scr->grass = mlx_xpm_file_to_image(scr->mlx, "xpm/count.xpm", &imgx, &imgy);
	scr->x = map->locate[0];
	scr->y = map->locate[1];
	scr->map = map;
	scr->count = 0;
	scr->enemy_exist = 0;
	return (scr);
}

void	display_string(t_display *display)
{
	char	*str;
	int		ptr[2];

	
	ptr[0] = 0;
	ptr[1] = 0;
	str = ft_itoa(display->count);
	display_block(display->mlx, display->win, display->grass, ptr);
	mlx_string_put(display->mlx, display->win, 8, 20, 0x000000, str);
}


void	display_map(t_map *map, t_display *display)
{
	display_land(display, map -> x_size, map -> y_size);
	display_struct(display, map);
	display_frog(display);
	display_enemy(display);
	display_string(display);
}
