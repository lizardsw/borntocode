#include "get_next_line.h"

char	*help_split(t_list *ptr)
{
	char	*line;
	char	*temp;
	int	i;
	int	j;
	
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
	temp = ft_strdup(&(ptr -> storage)[i + 1]);
	free(ptr -> storage);
	ptr -> storage = temp;
	return (line);
}

char	*b_line_split(t_list	*ptr)
{
	char	*line;

	if (ptr -> storage == NULL)
		return (NULL);
	if (ft_strchr(ptr -> storage, '\n'))
		line = help_split(ptr);
	else
	{
		line = ft_strdup(ptr -> storage);
		free(ptr -> storage);
		ptr -> storage = NULL;
	}
	return (line);
}

char	*get_next_line(int	fd)
{
	static t_list	*head;
	t_list	*ptr;
	char	buff[BUFFER_SIZE + 1];
	int		read_size;
	
	if (fd <= 0 || BUFFER_SIZE < 1)
		return (NULL);
	ptr = search_add_node(&head, fd);
	while (read_line(fd, buff, &read_size) > 0)
	{
			ptr -> storage = ft_strjoin(ptr -> storage, buff);
			if (ptr -> storage == NULL)
				return (NULL);
			if (ft_strchr(ptr -> storage, '\n'))
				return (b_line_split(ptr));		
	}
	if (read_size < 0)
		return (NULL);
	return (b_line_split(ptr));
}

t_list	*new_node(int fd, char *storage)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new -> fd = fd;
	new -> storage = storage;
	new -> next = NULL;
	return (new);
}

t_list	*search_add_node(t_list **head, int wanted_fd)
{
	t_list	*ptr;

	if ((*head) == NULL)
	{	
		(*head) = new_node(wanted_fd, NULL);
		return ((*head));
	}
	ptr = (*head);
	while (ptr != NULL)
	{
		if (ptr -> fd == wanted_fd)
			return (ptr);
		ptr = ptr -> next;
	}
	ptr = (*head);
	while (ptr -> next != NULL)
		ptr = ptr -> next;
	ptr -> next = new_node(wanted_fd, NULL);
	return (ptr -> next);
}
