/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:50:31 by seongwch          #+#    #+#             */
/*   Updated: 2021/11/24 20:01:13 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	size_t				i;
	size_t				j;
	char		*dest_pt;
	char		*src_pt;

	dest_pt = (char *)dest;
	src_pt = (char *)src;
	i = 0;
	j = 0;
	if (num == 0)
		return (dest);
	if (dest > src)
	{
		while (i < num)
			dest_pt[i++] = src_pt[j++];
	}
	else
	{
		while (i < num)
			dest_pt[i++] = src_pt[j++];
	}
	return (dest);
}
