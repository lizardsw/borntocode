/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:19:40 by seongwch          #+#    #+#             */
/*   Updated: 2022/07/06 20:40:54 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	*join_path(char *cmd, char **path)
{
	char	*line;
	char	*temp;
	int		i;

	i = 0;
	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	while (path[i] != NULL)
	{
		temp = ft_strjoin("/", cmd);
		line = ft_strjoin(path[i], temp);
		free(temp);
		if (access(line, F_OK | X_OK) == 0)
			return (line);
		free(line);
		i++;
	}
	return (NULL);
}

char	**split_path(char **envp)
{
	char	**path_split;
	char	*path_line;
	int		button;
	int		i;

	i = 0;
	button = -1;
	while (envp[++i] != NULL)
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
		{	
			button = 1;
			break ;
		}
	}
	if (button == -1)
		ft_error("path-error!", 3);
	path_line = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 1);
	if (path_line == NULL)
		ft_error("NULL GUARD", 0);
	path_split = ft_split(path_line, ':');
	if (path_split == NULL)
		ft_error("NULL GUARD", 0);
	free(path_line);
	return (path_split);
}

char	*get_path(char *cmd, char **envp)
{
	char	**path;
	char	**cmd_temp;
	char	*path_line;
	char	*cmd_line;

	if (cmd[0] == '\0')
		ft_error(cmd, 2);
	path = split_path(envp);
	cmd_line = ft_strtrim(cmd, " ");
	if (cmd_line == NULL)
		ft_error("NULL GUARD", 0);
	cmd_temp = ft_split(cmd_line, ' ');
	free(cmd_line);
	if (cmd_temp == NULL)
		ft_error("NULL GUARD", 0);
	path_line = join_path(cmd_temp[0], path);
	ft_free(cmd_temp);
	ft_free(path);
	if (path_line == NULL)
		ft_error(cmd, 2);
	return (path_line);
}

char	**get_option(char *cmd)
{
	char	**temp;
	char	*line;
	int		i;

	temp = ft_split(cmd, '/');
	i = 0;
	while (temp[i + 1] != NULL)
		i++;
	line = ft_strdup(temp[i]);
	ft_free(temp);
	temp = ft_split(line, ' ');
	free(line);
	return (temp);
}
