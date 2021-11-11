/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:51:58 by seongwch          #+#    #+#             */
/*   Updated: 2021/11/11 16:08:02 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strnstr(const char *dest, const char *src, size_t len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len && dest[i] != '\0')
	{
		if (dest[i] == src[j])
		{
			j = 0;
			while (dest[i + j] == src[j] && i + j < len)
				j++;
			if (src[j] == '\0')
				return ((char *)&dest[i]);
		}
		i++;
	}
	return (NULL);
}
