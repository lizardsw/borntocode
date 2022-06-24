/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:29:40 by seongwch          #+#    #+#             */
/*   Updated: 2022/06/24 22:31:41 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_map(t_display *display, t_map *map)
{
	t_node	*ptr;

	ptr = map -> start;
	while(ptr != NULL)
	{ 
		printf("%s\n", ptr -> map_str);
		ptr = ptr -> next;
	}
	printf("\nx_size : %d\ny_size : %d\nplayer : %d\nclose : %d\ngift : %d\ntrash : %d\n",
		map->x_size, map -> y_size, map -> player, map -> item, map ->exit, map -> trash);
	printf("enemy_exit : %d\n", display->enemy_exist);
	printf("rock : %d\n", map->rock);
}

int	main(int argc, char **argv)
{
	t_display	*display;
	t_map		*map;

	if (argc != 2)
	{
		printf("error!\n");
		return (0);
	}
	map = make_map(argv[1]);
	if (check_map(map) == -1)
	{
		printf("error!\nwrong-map!");
		free_map(map);
		return (0);
	}
	display = init_image(map, map -> x_size, map -> y_size);
	input_enemey(map, display);
	show_map(display, map);
	display_map(map, display);
	event_manage(display -> win, display);
	mlx_loop(display -> mlx);
	return (0);
}
