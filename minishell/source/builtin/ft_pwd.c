/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:03:02 by junoh             #+#    #+#             */
/*   Updated: 2022/08/22 13:44:57 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_list *cmd_list, t_state *state)
{
	char	*str;

	g_exit_status = 0;
	(void)(cmd_list);
	(void)(state);
	str = getcwd(NULL, 0);
	if (str == NULL)
		return (-1);
	else
	{
		printf("%s\n", str);
		free(str);
	}
	return (0);
}
