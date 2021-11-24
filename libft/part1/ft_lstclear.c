/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:05:50 by seongwch          #+#    #+#             */
/*   Updated: 2021/11/24 16:26:58 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*nextnode;

	ptr = *lst;
	while (ptr != NULL)
	{
		nextnode = ptr -> next;
		ft_lstdelone(ptr, del);
		ptr = nextnode;
	}
	*lst = NULL;
}
