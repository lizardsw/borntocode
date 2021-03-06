/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 21:31:53 by seongwch          #+#    #+#             */
/*   Updated: 2022/01/14 16:04:44 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	ch;

	if (str == NULL)
		return (NULL);
	ch = (unsigned char)c;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
			return ((char *)&str[i]);
		i++;
	}
	if (ch == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 != NULL && s1[0] == '\0')
		return (NULL);
	if (s1 == NULL)
		s1 = "";
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new == NULL)
		return (NULL);
	while (s1[j] != '\0')
	{
		new[i++] = s1[j++];
	}
	j = 0;
	while (s2[j] != '\0')
	{
		new[i++] = s2[j++];
	}
	new[i] = '\0';
	return (new);
}

int	read_line(int fd, char *buff, int *read_size)
{
	*read_size = read(fd, buff, BUFFER_SIZE);
	if (*read_size == 0)
		return (0);
	else if (*read_size < 0)
		return (-1);
	else
	{
		buff[*read_size] = '\0';
		return (*read_size);
	}
}

void	remove_node(t_list **head, int wanted_fd)
{
	t_list	*ptr;
	t_list	*pre;

	ptr = (*head);
	pre = (*head);
	if (ptr -> fd == wanted_fd)
	{
		free(ptr);
		if (pre -> next == NULL)
			(*head) = NULL;
		else
			(*head) = pre -> next;
		return ;
	}
	ptr = (*head);
	while (ptr -> fd != wanted_fd)
	{
		pre = ptr;
		ptr = ptr -> next;
	}
	pre -> next = ptr -> next;
	free(ptr);
}
