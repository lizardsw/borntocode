/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:42:23 by seongwch          #+#    #+#             */
/*   Updated: 2021/11/13 14:30:36 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	size_t				i;
	unsigned char	*dest_pt;
	unsigned char	*src_pt;

	i = 0;
	dest_pt = (unsigned char *)dest;
	src_pt = (unsigned char *)src;
	while (i < num)
	{
		dest_pt[i] = src_pt[i];
		i++;
	}
	return (dest);
}
