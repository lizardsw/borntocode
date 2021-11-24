/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 21:21:26 by seongwch          #+#    #+#             */
/*   Updated: 2021/11/22 17:18:55 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	while (ft_strchar(set, s1[start]) != NULL)
		start++;
	if (start >= ft_strlen(s1))
		return (NULL);
	end = start;
	while (s1[end] != '\0' && ft_strchar(set, s1[end]) == NULL)
		end++;
	return (ft_substr(s1, start, end - start));
}
