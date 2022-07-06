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

char	*get_path(char *cmd, char **envp)
{
	char	**path;
	char	**cmd_temp;
	char	*path_line;
	char	*cmd_line;
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
			break;
		i++;
	}
	path_line = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 1);
	path = ft_split(path_line, ':');
	free(path_line);
	cmd_line = ft_strtrim(cmd, " ");
	cmd_temp = ft_split(cmd_line, ' ');
	free(cmd_line);
	path_line = join_path(cmd_temp[0], path);
	ft_free(cmd_temp);
	ft_free(path);
	if (path_line == NULL)
	{
		ft_error("command not found");
	}
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
	return (temp);
}