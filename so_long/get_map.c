#include "so_long.h"

void	show_map(t_map *map)
{
	t_node	*ptr;

	ptr = map -> start;
	while(ptr != NULL)
	{ 
		printf("%s\n", ptr -> map_str);
		ptr = ptr -> next;
	}
	printf("\nx_size : %d\ny_size : %d\nplayer : %d\nclose : %d\ngift : %d\ntrash : %d\n",
		map->x_size, map -> y_size, map -> player, map -> item, map ->exit, map -> trash);

}

void	ft_strtrim(char *str)
{
	if (str == NULL)
		return;
	if (str[ft_strlen(str) - 1] == '\n')
		str[ft_strlen(str) - 1] = '\0';
}

void	set_map_member(t_map *map, char c, int x, int y)
{
	if (c == 'P')
	{
		map -> locate[0] = x;
		map -> locate[1] = y;
		map -> player++; 
	}
	else if (c == 'C')
		map -> item++;
	else if (c == 'E')
		map -> exit++;
	else if (c != '1' && c != '0')
		map -> trash++;
}

void	set_map_info(t_map *map)
{
	t_node	*node_ptr;
	int		i;
	int		j;

	node_ptr = map -> start;
	map -> x_size = ft_strlen(map -> start -> map_str);
	j =0;
	while (node_ptr != NULL)
	{
		i = 0;
		while (node_ptr -> map_str[i] != '\0')
		{
			set_map_member(map, node_ptr -> map_str[i],i,j);
			i++;
		}
		node_ptr = node_ptr -> next;
		j++;
	}		
}

t_map	*make_map(char *map_dir)
{
	t_map	*map;
	char	*one_line;
	int	fd;

	map = new_map();
	fd = open(map_dir, O_RDONLY);
	one_line = get_next_line(fd);
	ft_strtrim(one_line);
	while (one_line != NULL)
	{
		add_node(map, new_node(one_line));
		free(one_line);
		one_line = get_next_line(fd);
		ft_strtrim(one_line);
	}
	set_map_info(map);
	return (map);
}