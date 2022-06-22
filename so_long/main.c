/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:29:40 by seongwch          #+#    #+#             */
/*   Updated: 2022/06/22 18:34:58 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*window_ptr;
	t_param	*param;
	t_map	*map;

	if (argc != 2)
		return (0);
	map = make_map(argv[1]);
	show_map(map);
	printf("%d\n",check_map(map));
	
	mlx = mlx_init();
	window_ptr = mlx_new_window(mlx, 800, 800, "hello!");
	param = init_param(map);
	event_manage(window_ptr, param);
	mlx_loop(mlx);
	return (0);
}