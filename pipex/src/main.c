/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:19:35 by seongwch          #+#    #+#             */
/*   Updated: 2022/07/07 10:18:29 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_error(char *str, int flag)
{
	if (flag == 0)
		exit(1);
	else if (flag == 1)
	{	
		perror(str);
		exit(1);
	}
	else if (flag == 2)
	{
		write(2, "command not found :", 20);
		write(2, str, ft_strlen(str));
		write(2, "\n", 2);
		exit(1);
	}
	else if (flag == 3)
	{
		write(2, str, ft_strlen(str));
		exit(1);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(pipe_fd) == -1)
			ft_error("pipe - error", 1);
		pid = fork();
		if (pid == -1)
			ft_error("fork - error", 1);
		if (pid == 0)
			child_process(pipe_fd, argv, envp);
		else
			parent_process(pipe_fd, argc, argv, envp);
	}
	else
		ft_error("argc - error!\n", 3);
	return (0);
}
