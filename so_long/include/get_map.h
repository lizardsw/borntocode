/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:09:03 by seongwch          #+#    #+#             */
/*   Updated: 2022/06/27 17:21:35 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_MAP_H
# define GET_MAP_H

typedef struct s_node
{
	char			*map_str;
	struct s_node	*next;
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

t_node	*new_node(char *str);
t_map	*new_map(void);
void	add_node(t_map *map, t_node *node);
char	*ptr_map_char(t_map *map, int x, int y);
void	free_map(t_map *map);
void	set_map_member(t_map *map, char c, int x, int y);
t_map	*make_map(char *map_dir);
void	ft_strtrim(char *str);
void	set_map_info(t_map *map);
int		check_wall_top_bottom(char	*str);
int		check_wall_middle(char	*str);
int		check_wall(t_map *map);
int		check_num(t_map *map);
int		check_map(t_map *map);

#endif