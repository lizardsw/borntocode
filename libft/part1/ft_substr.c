/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:21:45 by seongwch          #+#    #+#             */
/*   Updated: 2021/11/13 15:52:35 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		if (i >= start && j < len)
		{
			new[j] = str[i];
			j++;
		}
		i++;
	}
	return (new);
}
