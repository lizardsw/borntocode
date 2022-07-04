#include "../include/pipex.h"

char	**get_path(char **envp)
{
	char **path;
	char *line;
	char *temp;
	
	int i = 0;
	line = ft_strdup(envp[4]);
	printf("%s\n", line);
	temp = ft_substr(line, 5, ft_strlen(line) - 1);
	free(line);
	line = temp;
	path = ft_split(line, ':');
	while (path[i] != NULL)
	{
		printf("%s\n", path[i]);
		i++;
	}
	return (path);
}

void	init_cmd(t_cmdline *cmdline, int argc, char **argv, char **path)
{
	char	*temp;
	int		i;
	int		j;

	
	j = 0;
	printf("hi!\n");
	while (j < argc - 3)
	{
		i = 0;
		while (path[i] != NULL)
		{
			temp = ft_strjoin("/",argv[j + 2]);
			temp = ft_strjoin(path[i], temp);
			if (access(temp, F_OK | X_OK) == 0)
				cmdline->cmd[j] = ft_strdup(temp);
			free(temp);
			i++;
		}
		j++;
	}
	return ;
}

int	parsing_cmd(t_cmdline *cmdline, int argc, char **argv, char **envp)
{
	char **path;
	int		i;

	i = 0;
	path = get_path(envp);
	cmdline->cmd= (char **)malloc(sizeof(char *) * argc - 2);
	if (cmdline->cmd == NULL)
		error_exit("malloc error!");
	cmdline->cmd[argc - 2] = NULL;
	init_cmd(cmdline, argc, argv, path);
	while (cmdline->cmd[i] != NULL)
	{
		printf("%s\n", cmdline->cmd[i]);
		i++;
	}

	return 1;
}