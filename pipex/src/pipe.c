/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:19:43 by seongwch          #+#    #+#             */
/*   Updated: 2022/07/07 13:22:20 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	child_setting(int *pipe_fd, int input_fd)
{
	if (dup2(input_fd, STDIN) == -1)
		ft_error("dup2 - error", 0);
	if (dup2(pipe_fd[1], STDOUT) == -1)
		ft_error("dup2 - error", 0);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(input_fd);
}

void	parent_setting(int *pipe_fd, int output_fd)
{
	if (dup2(pipe_fd[0], STDIN) == -1)
		ft_error("dup2 - error ", 0);
	if (dup2(output_fd, STDOUT) == -1)
		ft_error("dup2 - error", 0);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(output_fd);
}

void	parent_process(int *pipe_fd, int argc, char **argv, char **envp)
{
	int		fd;
	char	*path;
	char	**option;

	wait(NULL);
	fd = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	path = get_path(argv[3], envp);
	option = get_option(argv[3]);
	parent_setting(pipe_fd, fd);
	execve(path, option, envp);
}

void	child_process(int *pipe_fd, char **argv, char **envp)
{
	int		fd;
	char	*path;
	char	**option;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error(argv[1], 1);
	path = get_path(argv[2], envp);
	option = get_option(argv[2]);
	child_setting(pipe_fd, fd);
	execve(path, option, envp);
}
