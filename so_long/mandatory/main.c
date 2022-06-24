/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:29:40 by seongwch          #+#    #+#             */
/*   Updated: 2022/06/24 20:34:25 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	display_map(map, display);
	event_manage(display -> win, display);
	mlx_loop(display -> mlx);
	return (0);
}
