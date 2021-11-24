/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:34:14 by seongwch          #+#    #+#             */
/*   Updated: 2021/11/24 16:41:44 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*newlst;
	t_list	*newnode;
	t_list	*ptr;

	ft_lstiter(lst, f);
	ptr = lst;
	newnode = NULL;
	while (ptr -> next != NULL)
	{
		newnode = ft_lstnew(ptr -> content);
		if (newnode == NULL)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newnode);
		ptr = ptr -> next;
	}
}
