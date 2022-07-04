#include "../include/pipex.h"

void open_file(t_cmdline *cmdline, int argc, char **argv, int *fd)
{
	printf("%s %s", argv[1], argv[argc - 1]);
	fd[0] = open(argv[1], O_RDONLY);	
	fd[1] = open(argv[argc - 1], O_RDWR);
	if (fd[0] < 0 | fd[1] < 0)
		error_exit("wrong file-!");
	cmdline->file1 = ft_strdup(argv[1]);
	cmdline->file2 = ft_strdup(argv[argc - 1]);
	return ;
}