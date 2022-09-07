/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:41:07 by seongwch          #+#    #+#             */
/*   Updated: 2022/08/22 13:53:28 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	push_syntax(t_list *list, char *str, int index, int len)
{
	t_node	*new;
	char	*temp;

	temp = get_strdup(&str[index], len);
	new = new_node(temp);
	new->group = check_group(str[0]);
	if (get_strchr(&str[index], len, '\'') > -1 \
			|| get_strchr(&str[index], len, '\"') > -1)
		new->group = QUOTE;
	push_node_back(list, new);
	free(temp);
	return (len);
}

static int	label_group_util(char *str)
{
	int	add_index;
	int	i;

	add_index = 0;
	i = 0;
	if (check_group(str[0]) == SPACES)
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		add_index = i;
	}
	return (add_index);
}

static int	label_group(t_list *split_list, char *str)
{
	int		add_index;

	add_index = 0;
	if (check_group(str[0]) == PIP)
	{
		add_index = push_syntax(split_list, str, 0, 1);
		split_list->pipe_num++;
	}
	else if (check_group(str[0]) == REDIR)
	{
		if (str[0] == str[1])
			add_index = push_syntax(split_list, str, 0, 2);
		else
			add_index = push_syntax(split_list, str, 0, 1);
	}
	else
		add_index = label_group_util(str);
	return (add_index);
}

t_list	*shell_split(char *str)
{
	t_list	*split_list;
	int		i;
	int		j;

	i = 0;
	split_list = new_list();
	if (str[0] == '\0')
		split_list->state = BLANK;
	while (str[i] != '\0')
	{
		j = 0;
		if (check_group(str[i + j]) == WORD || check_group(str[i + j] == QUOTE))
			j = dq_strlen(split_list, &str[i]);
		if (j != 0)
			push_syntax(split_list, &str[i], 0, j);
		j += label_group(split_list, &str[i + j]);
		i = i + j;
		if (i > ft_strlen(str))
			break ;
	}
	return (split_list);
}
