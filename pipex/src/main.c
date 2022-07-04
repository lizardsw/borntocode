#include "../include/pipex.h"

void	error_exit(char *str)
{
	printf("%s\n", str);
	exit(1);
}



int main(int argc, char **argv, char **envp)
{
	t_cmdline	cmdline;
	int 		fd[2];
	int 		i;

	i = 0;
	if (argc != 5)
		return 0;
	open_file(&cmdline, argc, argv, fd);
	parsing_cmd(&cmdline, argc, argv, envp);
	

	

	return 0;
}