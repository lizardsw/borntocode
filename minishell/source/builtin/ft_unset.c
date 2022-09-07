/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:26:06 by junoh             #+#    #+#             */
/*   Updated: 2022/08/22 14:38:38 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	check_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalpha(str[i]) || str[i] == '_' || \
				(str[i] >= 48 && str[i] <= 57))
			i++;
		else
			return (0);
	}
	return (1);
}

static	void	del_env_one(t_state *state, t_node *ptr)
{
	t_node	*node;
	char	**split;

	node = state->env_lst->start;
	while (node != NULL)
	{
		split = split_key_value(node->data);
		if (cmd_compare(ptr->data, split[0]) == 0)
		{
			remove_node(state->env_lst, node);
			free_str(split);
			return ;
		}
		free_str(split);
		node = node->next;
	}
}

static	void	exec_unset(t_node *cmd_node, t_state *state)
{
	t_node	*ptr;

	ptr = cmd_node;
	if (ptr->next == NULL)
		return ;
	ptr = ptr->next;
	while (ptr != NULL)
	{
		if (!ft_isalpha(ptr->data[0]))
			printf("bash: unset: `%c\': not a valid identifier\n", ptr->data[0]);
		else if (ft_strlen(ptr->data) == 1 && ptr->data[0] == '_')
			;
		else if (!check_str(ptr->data))
			printf("bash: unset: `%s\': not a valid identifier\n", ptr->data);
		else
			del_env_one(state, ptr);
		ptr = ptr->next;
	}
}

void	ft_unset(t_list *cmd_list, t_state *state)
{
	g_exit_status = 0;
	exec_unset(cmd_list->start, state);
	return ;
}
