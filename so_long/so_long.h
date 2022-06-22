#ifndef SO_LONG_H
# define SO_LONG_H

#include "./mlx/mlx.h"
#include "./gnl/get_next_line.h"
#include "fcntl.h"
#include "stdio.h"

typedef struct s_node
{
	char			*map_str;
	struct s_node 	*next;
}	t_node;

typedef struct s_map
{
	t_node	*start;
	t_node	*end;
	int		x_size;
	int		size;
	int		player;
	int		close;
	int		gift;
}	t_map;

// liblist.c
t_node	*new_node(char *str);
t_map	*new_map(void);
void	add_node(t_map *map, t_node *node);

// get_map.c
t_map	*make_map(void);
void	show_map(t_map *map);

#endif 