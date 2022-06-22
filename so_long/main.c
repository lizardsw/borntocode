/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:29:40 by seongwch          #+#    #+#             */
/*   Updated: 2022/06/21 20:50:31 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*mlx;
	void	*new_window;
	t_map	*map;

	mlx = mlx_init();
	new_window = mlx_new_window(mlx, 800, 800, "hello!");
	map = make_map();
	show_map(map);
	return (0);
}