/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 21:21:26 by seongwch          #+#    #+#             */
/*   Updated: 2021/11/27 18:14:01 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	while (ft_strchr(set, s1[start]) != NULL)
		start++;
	if (start >= ft_strlen(s1))
		return (NULL);
	end = start;
	while (s1[end] != '\0' && ft_strchr(set, s1[end]) == NULL)
		end++;
	return (ft_substr(s1, start, end - start));
}

#include <stdio.h>
int	main()
{
	char name[]= "111dfsdasd22";
	char	set[]= "123";
	char	*ptr;

	ptr = ft_strtrim(name, set);
	printf("%s", ptr);
	return 0;
}
