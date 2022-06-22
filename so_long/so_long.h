#ifndef SO_LONG_H
# define SO_LONG_H

#include "./mlx/mlx.h"
#include "./gnl/get_next_line.h"
#include <fcntl.h>//open
#include <stdio.h>//printf
#include <stdlib.h>//exit

typedef struct s_node
{
	char			*map_str;
	struct s_node 	*next;
}	t_node;

typedef struct s_map
{
	t_node	*start;
	t_node	*end;
	int		locate[2];
	int		x_size;
	int		y_size;
	int		player;
	int		item;
	int		exit;
	int		trash;
}	t_map;

// liblist.c
t_node	*new_node(char *str);
t_map	*new_map(void);
void	add_node(t_map *map, t_node *node);

// get_map.c
t_map	*make_map(char *map_dir);
void	show_map(t_map *map);
void	ft_strtrim(char *str);
void	set_map_info(t_map *map);

// check_map.c
int check_wall_top_bottom(char	*str);
int	check_wall_middle(char	*str);
int check_wall(t_map *map);
int	check_num(t_map *map);
int	check_map(t_map *map);


///// window ////////////////
#define KEY_ESC		53
#define KEY_W		13
#define KEY_S		1
#define KEY_A		0				
#define KEY_D		2

typedef struct s_param
{
	int	x;
	int	y;
}	t_param;

// evet_manage.c
void	event_manage(void *window_ptr, t_param *param);
int	key_hook(int keycode, t_param *param);
t_param *init_param(t_map *map);


#endif 