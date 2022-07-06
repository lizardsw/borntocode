#include "../include/pipex.h"


void	child_setting(int *pipe_fd, t_info info)
{
	if (dup2(info.file1_fd, STDIN) == -1)
		ft_error("dup2 - error!");
	if (dup2(pipe_fd[1], STDOUT) == -1)
		ft_error("dup2 - error!");	
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(info.file1_fd);
}

void	parent_setting(int *pipe_fd, t_info info)
{
	if (dup2(pipe_fd[0], STDIN) == -1)
		ft_error("dup2 - error!");
	if (dup2(info.file2_fd, STDOUT) == -1)
		ft_error("dup2 - error!");	
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(info.file2_fd);
}