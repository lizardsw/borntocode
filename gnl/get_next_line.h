/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 21:38:21 by seongwch          #+#    #+#             */
/*   Updated: 2022/01/04 21:42:21 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int	fd;
	char	*storage;
	struct s_list	*next;
}	t_list;

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strdup(const char *str);
char	*b_line_split(t_list *ptr);
char	*line_split(char **storage);
char	*get_next_line(int fd);
int		read_line(int fd, char *buff, int *read_size);

t_list	*new_node(int fd, char *storage);
t_list	*search_add_node(t_list **head, int wanted_fd);

#endif