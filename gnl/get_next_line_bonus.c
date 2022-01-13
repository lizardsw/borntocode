/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@Student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:38:19 by seongwch          #+#    #+#             */
/*   Updated: 2022/01/13 13:38:21 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*ptr;
	char			buff[BUFFER_SIZE + 1];
	char			*temp;
	int				read_size;

	if (fd <= 0 || BUFFER_SIZE < 1)
		return (NULL);
	ptr = search_add_node(&head, fd);
	if (ptr == NULL)
		return (NULL);
	while (read_line(fd, buff, &read_size) > 0)
	{
		temp = ft_strjoin(ptr -> storage, buff);
		free(ptr -> storage);
		ptr -> storage = temp;
		if (ptr -> storage == NULL)
			return (NULL);
		if (ft_strchr(ptr -> storage, '\n'))
			return (b_line_split(&head, ptr, fd));
	}
	return (b_line_split(&head, ptr, fd));
}

char	*help_split(t_list *ptr)
{
	char	*line;
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = -1;
	while ((ptr -> storage)[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 2);
	if (line == NULL)
		return (NULL);
	while (j++ < i)
		line[j] = (ptr -> storage)[j];
	line[j] = '\0';
	temp = ft_strjoin(&(ptr -> storage)[i + 1], "");
	free(ptr -> storage);
	ptr -> storage = temp;
	return (line);
}

char	*b_line_split(t_list **head, t_list	*ptr, int wanted_fd)
{
	char	*line;

	if (ptr -> storage == NULL)
	{
		remove_node(head, wanted_fd);
		return (NULL);
	}
	if (ft_strchr(ptr -> storage, '\n'))
		line = help_split(ptr);
	else
	{
		line = ft_strjoin(ptr -> storage, "");
		free(ptr -> storage);
		ptr -> storage = NULL;
		remove_node(head, wanted_fd);
	}
	return (line);
}

t_list	*new_node(int fd)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new -> fd = fd;
	new -> storage = NULL;
	new -> next = NULL;
	printf("new_node : %d\n", new -> fd);
	return (new);
}

t_list	*search_add_node(t_list **head, int wanted_fd)
{
	t_list	*ptr;
	t_list	*check;

	check = (*head);
	if ((*head) == NULL)
	{	
		(*head) = new_node(wanted_fd);
		return ((*head));
	}
	ptr = (*head);
	while (ptr != NULL)
	{
		if (ptr -> fd == wanted_fd)////////////////////
			return (ptr);
		ptr = ptr -> next;
	}
	ptr = (*head);
	while (ptr -> next != NULL)
	{
		ptr = ptr -> next;
	}
	ptr -> next = new_node(wanted_fd);////////////////
	return (ptr -> next);
}
