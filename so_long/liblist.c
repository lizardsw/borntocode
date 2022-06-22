#include "so_long.h"

t_node	*new_node(char *str)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);	
	new_node -> map_str = ft_strdup(str);
	if (new_node -> map_str == NULL)
		return (NULL);
	new_node -> next = NULL;
	return (new_node);
}

t_map	*new_map(void)
{
	t_map	*new_map;

	new_map = (t_map *)malloc(sizeof(t_map));
	if (new_map == NULL)
		return (NULL);
	new_map -> start = NULL;
	new_map -> x_size = 0;
	new_map -> size = 0;
	new_map -> player = 0;
	new_map -> close = 0;
	new_map -> gift = 0;
	return (new_map);
}

void	add_node(t_map *map, t_node *node)
{
	t_node	*ptr;

	map -> size++;
	if (map -> start == NULL)
	{
		map -> start = node;
		map -> end = node;
		return ;
	}
	ptr = map -> end;
	ptr -> next = node;
	map -> end = node;
}
