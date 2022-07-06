#include "../include/pipex.h"

void	ft_error(char	*str)
{
	ft_printf("%s\n", str);
	exit(1);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;
	t_info info;

	info.file1_fd = open(argv[1], O_RDONLY);
	info.file2_fd = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if(pipe(pipe_fd) == -1)
		ft_error("pipe - error!");
	pid = fork();
	if (pid == -1)
		ft_error("fork - error!");
	if (pid == 0)
	{
		child_setting(pipe_fd, info);
		execve(get_path(argv[2], envp), get_option(argv[2]), envp);		
	}
	else
	{
		parent_setting(pipe_fd, info);
		wait(NULL);
		execve(get_path(argv[3], envp), get_option(argv[3]), envp);		
	}
	return 0;
}
