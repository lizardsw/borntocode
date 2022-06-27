/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:29:40 by seongwch          #+#    #+#             */
/*   Updated: 2022/06/27 22:40:50 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_display	*display;
	t_map		*map;

	if (argc != 2)
	{
		printf("error!\n");
		printf("arg error!\n");
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
	display_map(map, display);
	event_manage(display -> win, display);
	mlx_loop(display -> mlx);
	return (0);
}
