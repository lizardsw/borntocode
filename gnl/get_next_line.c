/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 21:32:22 by seongwch          #+#    #+#             */
/*   Updated: 2022/01/14 15:52:45 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*help_split(char **storage)
{
	char	*line;
	char	*temp;
	int		j;
	int		i;

	i = 0;
	j = -1;
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
	return (line);
}

char	*line_split(char **storage)
{
	char	*line;

	if (*storage == NULL)
		return (NULL);
	if (ft_strchr(*storage, '\n'))
		line = help_split(storage);
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
	char		*temp;
	char		buff[BUFFER_SIZE + 1];
	int			read_size;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (read_line(fd, buff, &read_size) > 0)
	{
		temp = ft_strjoin(storage, buff);
		free(storage);
		storage = temp;
		if (storage == NULL)
			return (NULL);
		if (ft_strchr(buff, '\n'))
			return (line_split(&storage));
	}
	if (read_size < 0)
	{
		free(storage);
		return (NULL);
	}
	return (line_split(&storage));
}
