#include "so_long.h"
void	show_map(t_map *map)
{
	t_node	*ptr;

	ptr = map -> start;
	while(ptr != NULL)
	{ 
		printf("%s", ptr -> map_str);
		ptr = ptr -> next;
	}
}

void	set_map_info(t_map *map)
{
	t_node	*node_ptr;
	int		i;

	node_ptr = map -> start;
	map -> x_size = ft_strlen(map -> start -> map_str);
	while (node_ptr != NULL)
	{
		i = 0;
		while (node_ptr -> map_str[i] != '\0')
		{
			if (node_ptr -> map_str[i] == 'P')
				map -> player++; 
			else if (node_ptr -> map_str[i] == 'C')
				map -> close++;
			else if (node_ptr -> map_str[i] == 'E')
				map -> gift++;
			i++;
		}
		node_ptr = node_ptr -> next;
	}		
}

t_map	*make_map(void)
{
	t_map	*map;
	char	*one_line;
	int	fd;

	map = new_map();
	fd = open("./map.ber", O_RDONLY);
	one_line = get_next_line(fd);
	while (one_line != NULL)
	{
		add_node(map, new_node(one_line));
		one_line = get_next_line(fd);
	}
	set_map_info(map);
	return (map);
}