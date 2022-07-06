#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../prtf/ft_printf.h"
#include <fcntl.h>
#include <sys/wait.h>

#define STDIN 0
#define STDOUT 1

typedef struct s_info
{
	int		file1_fd;
	int		file2_fd;
	char	**cmd;
}	t_info;

void	ft_error(char	*str);

char	*get_path(char *cmd, char **envp);
char	*join_path(char *cmd, char **path);
char	**get_option(char *cmd);

void	child_setting(int *pipe_fd, t_info info);
void	parent_setting(int *pipe_fd, t_info info);

#endif