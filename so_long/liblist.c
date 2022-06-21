#include "so_long.h"

t_node	*new_node(char *str)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
		return (NULL);	
	new -> map_char = ft_strdup(str);
	if (new -> map_char == NULL)
		return (NULL);
	new -> next = NULL;
	return (new);
}

t_map	*new_map(void)
{
	t_map	*new;

	new = (t_map *)malloc(sizeof(t_map));
	if (new == NULL)
		return (NULL);
	new -> start = NULL;
	new -> size = 0;
	return (new);
}

void	add_node(t_map *map, t_node *node)
{
	t_node	*ptr;
	
	if (map -> size == 0)
	{
		map -> start = node;
	}
	ptr = map -> start;
	while (ptr -> next != NULL)
		ptr = ptr -> next;
	ptr -> next = node;
}
