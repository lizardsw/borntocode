/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 21:32:22 by seongwch          #+#    #+#             */
/*   Updated: 2022/01/04 21:44:02 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line_split(char **storage)
{
	char	*line;
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = -1;
	if (*storage == NULL)
		return (NULL);
	if (ft_strchr(*storage, '\n'))
	{
		while ((*storage)[i] != '\n')
			i++;
		line = (char *)malloc(sizeof(char) * i + 2);
		if (line == NULL)
			return (NULL);
		while (j++ < i)
			line[j] = (*storage)[j];
		line[j] = '\0';
		temp = ft_strdup(&(*storage)[i + 1]);
		free(*storage);
		*storage = temp;
	}
	else
	{
		line = ft_strdup(*storage);
		free(*storage);
		*storage = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		buff[BUFFER_SIZE + 1];
	int			read_size;

	if (fd <= 0 || BUFFER_SIZE < 1)
		return (0);
	while (read_line(fd, buff, &read_size) > 0)
	{
		storage = ft_strjoin(storage, buff);
		if (storage == NULL)
			return (NULL);
		if (ft_strchr(buff, '\n'))
			return (line_split(&storage));
	}
	if (read_size < 0)
		return (NULL);
	return (line_split(&storage));
}
