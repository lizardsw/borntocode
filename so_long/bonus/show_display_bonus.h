/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_display_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:09:05 by seongwch          #+#    #+#             */
/*   Updated: 2022/06/27 09:28:16 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOW_DISPLAY_H
# define SHOW_DISPLAY_H

#include "get_map_bonus.h"
///// window ////////////////
#define KEY_ESC		53
#define KEY_W		13
#define KEY_S		1
#define KEY_A		0
#define KEY_D		2

typedef struct s_display
{
	t_map	*map;
	int		x;
	int		y;
	int		enemy_x;
	int		enemy_y;
	int		enemy_exist;
	int		count;
	void	*win;
	void	*mlx;
	void	*frog;
	void	*frog1;
	void	*frog2;
	void	*land;
	void	*food;
	void	*rock;
	void	*door;
	void	*enemy;
	void	*grass;
}	t_display;

// evet_manage.c
void	up_game(t_display *display);
void	down_game(t_display *display);
void	right_game(t_display *display);
void	left_game(t_display *display);
void	event_manage(void *window_ptr, t_display *display);
int		key_hook(int keycode, t_display *param);

// display.c
t_display	*init_image(t_map *map, int x, int y);
void	display_map(t_map *map, t_display *display);
void	display_land(t_display *display, int map_x, int map_y);
void	display_block(void *mlx, void *win, void *image, int *ptr);
void	display_struct(t_display *display, t_map *map);
void	display_frog(t_display *display);
void	display_enemy(t_display *display);

// input_enemy.c
void	input_enemey(t_map *map, t_display *display);
void	enemy_locate(t_map *map, t_display *display, int land_size);
int		enemy_check(t_map *map, int land_size, int i, int j);

// enemy_move.c
void	make_a_b(t_display *display, int *a, int *b);
void	enemy_move(t_display *display);

// make_itoa.c
size_t	make_size(int n);
void	fill_char(char *str, int n, size_t size);
char	*ft_itoa(int n);



#endif 