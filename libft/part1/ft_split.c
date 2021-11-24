/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:04:26 by seongwch          #+#    #+#             */
/*   Updated: 2021/11/22 17:35:56 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	check_size(char const *s, char c)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c)
				i++;
			size++;
		}
		else
			i++;
	}
	return (size + 1);
}

char	*make_str(char const *str, char c)
{
	size_t	i;
	size_t	len;
	char	*new;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			i++;
		else
			break ;
	}
	len = i;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	**new;

	size = check_size(s, c);
	new = (char **)malloc(sizeof(char *) * size);
	if (new == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			new[j++] = make_str(&s[i], c);
			while (s[i] == c)
				i++;
		}
		else
			i++;
	}
	return (new);
}
