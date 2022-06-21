#ifndef SO_LONG_H
# define SO_LONG_H

#include "./minilibx_opengl_20191021/mlx.h"
#include "./gnl/get_next_line.h"
#include "fcntl.h"
#include "stdio.h"

typedef struct s_node
{
	char	*map_char;
	struct s_node *next;
}	t_node;

typedef struct s_map
{
	t_node	*start;
	int size;
}	t_map;

// liblist.c
t_node	*new_node(char *str);
t_map	*new_map(void);
void	add_node(t_map *map, t_node *node);

// get_map.c
t_map	*make_map(void);

#endif 