/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:42:23 by seongwch          #+#    #+#             */
/*   Updated: 2021/11/10 13:46:27 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dest, void *src, size_t num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		dest[i] = src[i];
		i++;
	}
}
