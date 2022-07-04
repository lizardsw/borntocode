#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include "../prtf/ft_printf.h"
#include "fcntl.h"

typedef struct s_cmdline
{
	char	*file1;
	char	*file2;
	char	**cmd;
}	t_cmdline;

void	open_file(t_cmdline *cmdline, int argc, char **argv, int *fd);
void	error_exit(char *str);
char	**get_path(char **envp);
int		parsing_cmd(t_cmdline *cmdline, int argc, char **argv, char **envp);


#endif