/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:31:03 by seongwch          #+#    #+#             */
/*   Updated: 2021/11/11 14:55:11 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	int	i;
	int	dest_len;
	int	src_len;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (dest_len < size)
	{
		while (i < src_len && src[i] != '\0')
		{
			dest[dest_len + i] = src_len[i]; 
			i++;
		}
		dest[dest_len + i] = '\0';
		return (dest_len + src_len);
	}
	else
	{
		return (dest_len + size);
	}
}
