#include "so_long.h"

t_map	*make_map(void)
{
	t_map	*map;
	char	*one_line;
	int	fd;

	fd = open("./map.ber", O_RDONLY);
	one_line = get_next_line(fd);
	map = new_map();
	add_node(map, new_node(one_line));
	return (map);
}