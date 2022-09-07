/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_split_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:55:16 by seongwch          #+#    #+#             */
/*   Updated: 2022/08/22 13:52:44 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_group(char c)
{
	if (c == ' ' || c == '\t')
		return (SPACES);
	else if (c == '<' || c == '>')
		return (REDIR);
	else if (c == '\'' || c == '\"')
		return (QUOTE);
	else if (c == '|')
		return (PIP);
	else if (c == '\0')
		return (ZERO);
	return (WORD);
}

void	label_token(t_node *ptr)
{
	char	*temp;

	temp = ptr->data;
	if (ptr->group == REDIR)
	{
		if (temp[0] == '<')
		{
			if (temp[1] == '<')
				ptr->token = RDRDIN;
			else
				ptr->token = RDIN;
		}
		else
		{
			if (temp[1] == '>')
				ptr->token = RDRDOUT;
			else
				ptr->token = RDOUT;
		}
	}
	else if (ptr->group == PIP)
		ptr->token = PIPE;
	else if (ptr->group == QUOTE || ptr->group == WORD)
		ptr->token = CMD;
}

int	dq_strlen(t_list *list, char *str)
{
	int	i;
	int	index;

	i = 0;
	while (check_group(str[i]) == WORD || check_group(str[i]) == QUOTE)
	{
		if (check_group(str[i]) == QUOTE)
		{
			index = i;
			i++;
			while (str[i] != '\0' && str[index] != str[i])
				i++;
			if (str[i] == '\0')
				list->state = ERROR;
			else
				i++;
		}
		else
			i++;
	}
	return (i);
}
