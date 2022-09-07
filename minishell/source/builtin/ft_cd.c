/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:02:13 by junoh             #+#    #+#             */
/*   Updated: 2022/08/22 14:38:29 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	print_err(char *path)
{
	printf("minishell: cd: {%s}: No such file or directory\n", path);
	g_exit_status = 1;
}

static void	replace_data(char *pwd, char *state_pwd, t_node *node)
{
	free(node->data);
	node->data = ft_strjoin(ft_strdup(pwd), state_pwd);
}

static	void	change_env_path(t_state *state, char *key, int flag)
{
	t_node	*node;
	char	*buf;

	buf = NULL;
	node = state->env_lst->start;
	while (node != NULL)
	{
		if (!ft_strncmp(key, node->data, \
		(int)ft_strlen(key)) && (ft_strlen(key) == flag))
		{
			if (flag == 7)
				replace_data("OLDPWD=", state->old_pwd, node);
			else if (flag == 4)
				replace_data("PWD=", state->pwd, node);
			free(buf);
		}
		node = node->next;
	}
	return ;
}

static	void	change_dir(char *path, t_state *state)
{
	int		ret;
	char	*buf;

	ret = chdir(path);
	if (ret == 0)
	{
		buf = state->old_pwd;
		state->old_pwd = ft_strdup(state->pwd);
		free(buf);
		buf = state->pwd;
		state->pwd = getcwd(NULL, 0);
		free(buf);
		change_env_path(state, "OLDPWD=", 7);
		change_env_path(state, "PWD=", 4);
	}
	else
		print_err(path);
	return ;
}

void	ft_cd(t_list *cmd_list, t_state *state)
{
	t_node	*node;
	char	*home;

	home = NULL;
	g_exit_status = 0;
	node = cmd_list->start;
	if (state->pwd == NULL)
		state->pwd = getcwd(NULL, 0);
	if (node->next == NULL || (node->next->data[0] == '~' && \
	ft_strlen(node->next->data) == 1))
	{
		home = get_value(state->env_lst, "HOME");
		change_dir(home, state);
		free(home);
	}
	else if (node->next->data[0] == '\0')
		return ;
	else
		change_dir(node->next->data, state);
	return ;
}
