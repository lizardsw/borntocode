/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:35:48 by seongwch          #+#    #+#             */
/*   Updated: 2021/11/27 20:03:26 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (lst == NULL || new == NULL)
		return ;
	ptr = ft_lstlast(*lst);
	ptr -> next = new;
}

int	main()
{
	t_list node a1;
	t_list node a2;
	t_list node a3;
	t_list node a4;

	a1.next -> &a2;
	a2.next -> &a3;
	a1.content 


}
